/* main.c --- 
 * 
 * Filename: main.c
 * Description: 
 * Author: Caner Candan
 * Maintainer: 
 * Created: Sun Dec 28 00:44:47 2008 (+0200)
 * Version: 
 * Last-Updated: Sat Feb  7 00:19:16 2009 (+0200)
 *           By: Caner Candan
 *     Update #: 109
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

#include <stdio.h>
#include <select.h>

static void	recv(t_select *select, t_client *client)
{
  (void)select;
  printf("recv: [%s]\n", select_recv(client));
  printf("recv_field: [%s]\n", select_recv_field(client, 0));
  printf("recv_field: [%s]\n", select_recv_field(client, 1));
  printf("recv_field: [%s]\n", select_recv_field(client, 2));
  if (select_mesg_cmp(client, "salut") == 0)
    select_send(client, "comment ca va ?\n");
  else if (select_mesg_cmp(client, "1234") == 0)
    select_send(client, "5678\n");
  else
    select_send(client, "not found\n");
}

static void	addclient(t_select *select, t_client *client)
{
  (void)select;
  (void)client;
  printf("client added\n");
}

static void	delclient(t_select *select, t_client *client)
{
  (void)select;
  (void)client;
  printf("client deleted\n");
}

int		main(void)
{
  t_select	*select;

  select = select_init();
  select_set_callback(select, CB_RECV, recv, NULL);
  select_set_callback(select, CB_ADDCLIENT, addclient, NULL);
  select_set_callback(select, CB_DELCLIENT, delclient, NULL);
  select_set_signal(select);
  select_exec(select, 4242);
  return (0);
}

/* main.c ends here */
