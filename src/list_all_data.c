/* list_all_data.c --- 
 * 
 * Filename: list_all_data.c
 * Description: 
 * Author: Caner Candan
 * Maintainer: 
 * Created: Wed Dec 31 11:09:28 2008 (+0200)
 * Version: 
 * Last-Updated: Tue Mar  3 16:26:55 2009 (+0200)
 *           By: Caner Candan
 *     Update #: 20
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

#include "list.h"

t_res		list_all_data(t_list *t, list_fct_data fct, void *data)
{
  t_list	*next;
  t_res		res;

  res = R_ERROR;
  while (t != NULL)
    {
      next = t->next;
      res = (*fct)(t->data, data);
      if (res != R_CONTINUE)
	return (res);
      t = next;
    }
  return (res);
}

/* list_all_data.c ends here */
