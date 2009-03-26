/* select_mesg_cmp_field.c --- 
 * 
 * Filename: select_mesg_cmp_field.c
 * Description: 
 * Author: Caner Candan
 * Maintainer: 
 * Created: Thu Feb  5 10:47:08 2009 (+0200)
 * Version: 
 * Last-Updated: Thu Feb  5 11:08:53 2009 (+0200)
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

#ifdef __cplusplus
extern "C"
{
#endif /* !__cplusplus */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "select.h"

  int		select_mesg_cmp_field(t_client *client, char *mesg, int pos)
  {
    int		res;
    char	*field;

    if ((field = select_recv_field(client, pos)) == NULL)
      return (-1);
#ifdef DEBUG
    printf("*** select_mesg_cmp_field: [%s], and [%s]\n",
	   field, mesg);
#endif /* !DEBUG */
    res = strcmp(field, mesg);
    free(field);
    return ((res == 0) ? 0 : -1);
  }

#ifdef __cplusplus
}
#endif /* !__cplusplus */

/* select_mesg_cmp_field.c ends here */
