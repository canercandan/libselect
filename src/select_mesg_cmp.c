/* select_mesg_cmp.c --- 
 * 
 * Filename: select_mesg_cmp.c
 * Description: 
 * Author: Caner Candan
 * Maintainer: 
 * Created: Wed Dec 31 00:41:06 2008 (+0200)
 * Version: 
 * Last-Updated: Thu Feb  5 10:49:32 2009 (+0200)
 *           By: Caner Candan
 *     Update #: 17
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

#include <string.h>
#include <stdio.h>
#include "select.h"

  int	select_mesg_cmp(t_client *client, char *mesg)
  {
#ifdef DEBUG
    printf("*** select_mesg_cmp: [%s] and [%s]\n", client->buf_read, mesg);
#endif /* !DEBUG */
    return ((strcmp(select_recv(client), mesg) == 0) ? 0 : -1);
  }

#ifdef __cplusplus
}
#endif /* !__cplusplus */

/* select_mesg_cmp.c ends here */
