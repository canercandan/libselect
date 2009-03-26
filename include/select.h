// select.h --- 
// 
// Filename: select.h
// Description: 
// Author: Caner Candan
// Maintainer: 
// Created: Sat Dec 27 01:13:21 2008 (+0200)
// Version: 
// Last-Updated: Fri Feb  6 21:09:32 2009 (+0200)
//           By: Caner Candan
//     Update #: 128
// URL: 
// Keywords: 
// Compatibility: 
// 
// 

// Commentary: 
// 
// 
// 
// 

// Change log:
// 
// 
// 
// 
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 3, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; see the file COPYING.  If not, write to
// the Free Software Foundation, Inc., 51 Franklin Street, Fifth
// Floor, Boston, MA 02110-1301, USA.
// 
// 

// Code:

#ifndef __SELECT_H__
# define __SELECT_H__

#ifdef __cplusplus
extern "C"
{
#endif

# include <sys/select.h>
# include <list.h>

  /*
  ** defines
  */

# define MAX_LISTEN	42
# define BUF_SIZE	1024
# define CB_SIZE	4

  /*
  ** type definitions
  */

  struct s_select;
  struct s_client;

  typedef void	(*select_fct)(struct s_select*, struct s_client*);

  /*
  ** enumerators
  */

  typedef enum {SERVER, CLIENT}					t_type;
  typedef enum {IN, OUT}					t_status;
  typedef enum {CB_RECV, CB_SEND, CB_ADDCLIENT, CB_DELCLIENT}	t_callback;

  /*
  ** structures
  */

  typedef struct	s_select
  {
    fd_set		fd_read;
    fd_set		fd_write;
    int			fd_max;
    t_list		*list;
    select_fct		fct[CB_SIZE];
    void		*data[CB_SIZE];
  }			t_select;

  typedef struct	s_client
  {
    t_type		type;
    t_status		status;
    int			socket;
    char		buf_read[BUF_SIZE];
    char		buf_write[BUF_SIZE];
    void		*data;
  }			t_client;

  /*
  ** variables
  */

  /*
  ** functions
  */

  t_select	*select_init(void);

  void	select_set_callback(t_select*, t_callback, select_fct, void *data);
  void	select_set_signal(t_select*);

  void	select_free(t_select*);
  void	select_exec(t_select*, int port);

  void	select_send(t_client*, char *mesg);

  char	*select_recv(t_client*);
  char	*select_recv_field(t_client*, int pos);
  char	*select_recv_field_delim(t_client*, int pos, char *delim);

  int	select_mesg_cmp(t_client*, char *mesg);
  int	select_mesg_cmp_field(t_client*, char *mesg, int pos);

#ifdef __cplusplus
}
#endif /* !__cplusplus */

#endif /* !__SELECT_H__ */

// 
// select.h ends here
