/* select_free.c --- 
 * 
 * Filename: select_free.c
 * Description: 
 * Author: Caner Candan
 * Maintainer: 
 * Created: Sat Dec 27 01:08:23 2008 (+0200)
 * Version: 
 * Last-Updated: Mon Jan  5 10:56:51 2009 (+0200)
 *           By: Caner Candan
 *     Update #: 41
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

#include <stdlib.h>
#include <unistd.h>
#include "select.h"

  static t_res	free_clients(void *data_list)
  {
    t_client	*client;

    client = data_list;
    close(client->socket);
    free(client);
    return (R_CONTINUE);
  }

  void	select_free(t_select *select)
  {
    list_all(select->list, free_clients);
    list_free(&(select->list));
    free(select);
  }

#ifdef __cplusplus
}
#endif /* !__cplusplus */

/* select_free.c ends here */
