/* select_set_signal.c --- 
 * 
 * Filename: select_set_signal.c
 * Description: 
 * Author: Caner Candan
 * Maintainer: 
 * Created: Wed Dec 31 11:53:35 2008 (+0200)
 * Version: 
 * Last-Updated: Fri Jan  2 11:54:15 2009 (+0200)
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

#include <stdio.h>
#include <signal.h>
#include "select.h"

  static void	*signal_data = 0;

  static void	signal_fct(int signal)
  {
    (void)signal;
    select_free(signal_data);
#ifdef DEBUG
    printf("Server stopped.\n");
#endif /* !DEBUG */
  }

  void	select_set_signal(t_select *t)
  {
    signal_data = t;
    signal(SIGINT, signal_fct);
  }

#ifdef __cplusplus
}
#endif /* !__cplusplus */

/* select_set_signal.c ends here */
