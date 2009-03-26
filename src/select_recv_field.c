/* select_recv_field.c --- 
 * 
 * Filename: select_recv_field.c
 * Description: 
 * Author: Caner Candan
 * Maintainer: 
 * Created: Thu Jan  8 12:01:41 2009 (+0200)
 * Version: 
 * Last-Updated: Fri Feb  6 14:51:57 2009 (+0200)
 *           By: Caner Candan
 *     Update #: 96
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

#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include "select.h"

  char	*select_recv_field(t_client *client, int pos)
  {
    return (select_recv_field_delim(client, pos, " \t"));
  }

#ifdef __cplusplus
}
#endif /* !__cplusplus */

/* select_recv_field.c ends here */
