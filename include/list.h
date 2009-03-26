// list.h --- 
// 
// Filename: list.h
// Description: 
// Author: Caner Candan
// Maintainer: 
// Created: Sun Dec 28 16:25:40 2008 (+0200)
// Version: 
// Last-Updated: Mon Jan  5 11:05:02 2009 (+0200)
//           By: Caner Candan
//     Update #: 69
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

#ifndef __LIST_H__
# define __LIST_H__

#ifdef __cplusplus
extern "C"
{
#endif

  /*
  ** defines
  */

# ifndef NULL
#  define NULL	(void*)0
# endif /* !NULL */

  /*
  ** type definitions
  */

  typedef enum	e_res {R_FOUND, R_CONTINUE, R_END, R_ERROR}	t_res;

  struct	s_list;

  typedef t_res	(*list_fct)(void *data_list);
  typedef t_res	(*list_fct_data)(void *data_list, void *data);
  typedef t_res	(*list_fct_struct)(struct s_list*, void *data);

  /*
  ** enumerators
  */


  /*
  ** structures
  */

  typedef struct	s_list
  {
    void		*data;
    struct s_list	*next;
  }			t_list;

  /*
  ** variables
  */

  /*
  ** functions
  */

  void	list_init(t_list**);
  void	list_free(t_list**);

  void	list_push(t_list**, void *data);
  void	*list_pop(t_list**);

  void	list_delete(t_list**, void *data);

  t_res	list_all(t_list*, list_fct);
  t_res	list_all_data(t_list*, list_fct_data, void *data);
  t_res	list_all_struct(t_list*, list_fct_struct, void *data);

  int	list_count(t_list*);

#ifdef __cplusplus
}
#endif /* !__cplusplus */

#endif /* !__LIST_H__ */

// 
// list.h ends here
