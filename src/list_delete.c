/* list_delete.c --- 
 * 
 * Filename: list_delete.c
 * Description: 
 * Author: Caner Candan
 * Maintainer: 
 * Created: Wed Dec 31 10:40:15 2008 (+0200)
 * Version: 
 * Last-Updated: Mon Jan  5 10:34:04 2009 (+0200)
 *           By: Caner Candan
 *     Update #: 54
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

#include <stdlib.h>
#include "list.h"

static t_res	callback(t_list *t, void *data)
{
  t_list	*tmp;

  if (t->next == NULL)
    return (R_END);
  if (t->next->data != data)
    return (R_CONTINUE);
  tmp = t->next->next;
  free(t->next);
  t->next = tmp;
  return (R_FOUND);
}

void		list_delete(t_list **t, void *data)
{
  if ((*t) == NULL)
    return;
  if ((*t)->data == data)
    {
      (void)list_pop(t);
      return;
    }
  list_all_struct(*t, callback, data);
}

/* list_delete.c ends here */
