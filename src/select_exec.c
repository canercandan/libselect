/* select_exec.c --- 
 * 
 * Filename: select_exec.c
 * Description: 
 * Author: Caner Candan
 * Maintainer: 
 * Created: Mon Dec 29 18:02:04 2008 (+0200)
 * Version: 
 * Last-Updated: Fri Feb  6 21:07:07 2009 (+0200)
 *           By: Caner Candan
 *     Update #: 342
 * URL: 
 * Keywords: 
 * Compatibility: 
 * 
 */

/* Commentary: 
 * 
 * 
 * 
 */

/* Change log:
 * 
 * 
 */

/* This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth
 * Floor, Boston, MA 02110-1301, USA.
 */

/* Code: */

#ifdef __cplusplus
extern "C"
{
#endif /* !__cplusplus */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "select.h"

  static t_res	set_fd_list(void *data_list, void *data)
  {
    t_client	*client;
    t_select	*select;

    client = data_list;
    select = data;
    if (client->status == OUT)
      {
	if (select->fct[CB_DELCLIENT] != NULL)
	  (*select->fct[CB_DELCLIENT])(select, client);
	close(client->socket);
	free(client);
	list_delete(&(select->list), data_list);
	return (R_CONTINUE);
      }
    FD_SET(client->socket, &(select->fd_read));
    if (strlen(client->buf_write) > 0)
      FD_SET(client->socket, &(select->fd_write));
    if (select->fd_max < client->socket)
      select->fd_max = client->socket;
    return (R_CONTINUE);
  }

  static void	add_client(t_select *select, t_client *server)
  {
    t_client	*client;

    client = malloc(sizeof(*client));
    if ((client->socket = accept(server->socket, NULL, NULL)) < 0)
      {
#ifdef DEBUG
	perror("accept");
#endif /* !DEBUG */
	exit(-1);
      }
    client->type = CLIENT;
    client->status = IN;
    client->buf_read[0] = 0;
    client->buf_write[0] = 0;
    client->data = NULL;
    if (select->fct[CB_ADDCLIENT] != NULL)
      (*select->fct[CB_ADDCLIENT])(select, client);
    list_push(&(select->list), (void*)client);
#ifdef DEBUG
    printf("*** adding client [%d]\n", client->socket);
#endif /* !DEBUG */
  }

  static void	server_read(t_select *select, t_client *server)
  {
#ifdef DEBUG
    printf("*** select: server read\n");
#endif /* !DEBUG */
    add_client(select, server);
  }

  static void	recv_by_client(t_client *client)
  {
    int		size;

    if ((size = recv(client->socket, client->buf_read, BUF_SIZE, 0)) <= 0)
      {
#ifdef DEBUG
	printf("*** socket: [%d] trame size incorrect\n", client->socket);
#endif /* !DEBUG */
	client->status = OUT;
	return;
      }
    client->buf_read[size - (strchr(client->buf_read, '\r') ? 2 : 1)] = 0;
#ifdef DEBUG
    printf("*** socket: [%d] recv [%s]\n", client->socket, client->buf_read);
#endif /* !DEBUG */
  }

  static void	client_read(t_select *select, t_client *client)
  {
#ifdef DEBUG
    printf("*** select: [%d] client read\n", client->socket);
#endif /* !DEBUG */
    client->buf_read[0] = 0;
    recv_by_client(client);
    if (select->fct[CB_RECV] != NULL)
      (*select->fct[CB_RECV])(select, client);
  }

  static void	send_by_client(t_client *client)
  {
    char	*start;
    char	*end;
    int		last_nb;
    int		nb;

    if (client->socket < 0)
      {
#ifdef DEBUG
	printf("*** socket: [%d] send error, not connected\n",
	       client->socket);
#endif /* !DEBUG */
	return;
      }
    last_nb = 0;
    nb = 0;
    while (42)
      {
	last_nb = nb;
	start = client->buf_write + last_nb;
	if ((end = strchr(start, '\n')) == NULL)
	  return;
	nb = end - start;
	if (nb <= 0)
	  return;
	if (send(client->socket, start, nb + 1, 0) < 0)
	  {
#ifdef DEBUG
	    printf("*** socket: [%d] send error\n", client->socket);
#endif /* !DEBUG */
	    return;
	  }
#ifdef DEBUG
	printf("*** socket: [%d] send [%s]\n", client->socket, client->buf_write);
#endif /* !DEBUG */
      }
  }

  static void	client_write(t_select *select, t_client *client)
  {
#ifdef DEBUG
    printf("*** select: [%d] client write\n", client->socket);
#endif /* !DEBUG */
    send_by_client(client);
    client->buf_write[0] = 0;
    if (select->fct[CB_SEND] != NULL)
      (*select->fct[CB_SEND])(select, client);
  }

  static t_res	isset_fd_list(void *data_list, void *data)
  {
    t_client	*client;
    t_select	*select;

    client = data_list;
    select = data;
    if (client->status == OUT)
      return (R_CONTINUE);
    if (FD_ISSET(client->socket, &(select->fd_read)))
      {
	if (client->type == SERVER)
	  server_read(select, client);
	else
	  client_read(select, client);
      }
    if (FD_ISSET(client->socket, &(select->fd_write)))
      client_write(select, client);
    return (R_CONTINUE);
  }

  static void	set_fd(t_select *t)
  {
    list_all_data(t->list, set_fd_list, (void*)t);
  }

  static void	isset_fd(t_select *t)
  {
    list_all_data(t->list, isset_fd_list, (void*)t);
  }

  static void		add_server(t_list **list, int port)
  {
    struct sockaddr_in	addr;
    struct protoent	*pe;
    t_client		*client;

    client = malloc(sizeof(*client));
    pe = getprotobyname("tcp");
    if ((client->socket = socket(PF_INET, SOCK_STREAM, pe->p_proto)) < 0)
      {
#ifdef DEBUG
	perror("socket");
#endif /* !DEBUG */
	exit(-1);
      }
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(client->socket, (struct sockaddr*)&addr, (socklen_t)sizeof(addr)) < 0)
      {
#ifdef DEBUG
	perror("bind");
#endif /* !DEBUG */
	exit(-1);
      }
    if (listen(client->socket, MAX_LISTEN) < 0)
      {
#ifdef DEBUG
	perror("bind");
#endif /* !DEBUG */
	exit(-1);
      }
    client->type = SERVER;
    client->status = IN;
    list_push(list, (void*)client);
#ifdef DEBUG
    printf("*** server started.\n");
#endif /* !DEBUG */
  }

  void	select_exec(t_select *t, int port)
  {
    add_server(&(t->list), port);
    while (42)
      {
	FD_ZERO(&(t->fd_read));
	FD_ZERO(&(t->fd_write));
	t->fd_max = 0;
	set_fd(t);
	if (select(t->fd_max + 1, &(t->fd_read),
		   &(t->fd_write), NULL, NULL) < 0)
	  {
#ifdef DEBUG
	    perror("select");
#endif /* !DEBUG */
	    exit(-1);
	  }
	isset_fd(t);
      }
  }

#ifdef __cplusplus
}
#endif /* !__cplusplus */

/* select_exec.c ends here */
