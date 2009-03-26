/* select_set_callback.c --- 
 * 
 * Filename: select_set_callback.c
 * Description: 
 * Author: Caner Candan
 * Maintainer: 
 * Created: Tue Dec 30 15:54:20 2008 (+0200)
 * Version: 
 * Last-Updated: Fri Feb  6 20:33:02 2009 (+0200)
 *           By: Caner Candan
 *     Update #: 8
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

#include "select.h"

  void	select_set_callback(t_select *select, t_callback cb,
			    select_fct fct, void *data)
  {
    select->fct[cb] = fct;
    select->data[cb] = data;
  }

#ifdef __cplusplus
}
#endif /* !__cplusplus */

/* select_set_callback.c ends here */
