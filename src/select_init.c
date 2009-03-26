/* select_init.c --- 
 * 
 * Filename: select_init.c
 * Description: 
 * Author: Caner Candan
 * Maintainer: 
 * Created: Sat Dec 27 01:08:01 2008 (+0200)
 * Version: 
 * Last-Updated: Fri Feb  6 21:10:06 2009 (+0200)
 *           By: Caner Candan
 *     Update #: 84
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
#include <stdlib.h>
#include <stdio.h>
#include "select.h"

  t_select	*select_init()
  {
    t_select	*t;
    int		i;

    t = malloc(sizeof(*select));
    FD_ZERO(&(t->fd_read));
    FD_ZERO(&(t->fd_write));
    t->fd_max = 0;
    list_init(&(t->list));
    for (i = 0; i < CB_SIZE; i++)
      {
	t->fct[i] = NULL;
	t->data[i] = NULL;
      }
    return (t);
  }

#ifdef __cplusplus
}
#endif /* !__cplusplus */

/* select_init.c ends here */
