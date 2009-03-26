/* list_all.c --- 
 * 
 * Filename: list_all.c
 * Description: 
 * Author: Caner Candan
 * Maintainer: 
 * Created: Sun Dec 28 17:46:53 2008 (+0200)
 * Version: 
 * Last-Updated: Tue Mar  3 16:26:49 2009 (+0200)
 *           By: Caner Candan
 *     Update #: 31
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

t_res		list_all(t_list *t, list_fct fct)
{
  t_list	*next;
  t_res		res;

  res = R_ERROR;
  while (t != NULL)
    {
      next = t->next;
      res = (*fct)(t->data);
      if (res != R_CONTINUE)
	return (res);
      t = next;
    }
  return (res);
}

/* list_all.c ends here */
