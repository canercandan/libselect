### Makefile --- 
## 
## Filename: Makefile
## Description: 
## Author: Caner Candan
## Maintainer: 
## Created: Tue Dec 30 14:15:42 2008 (+0200)
## Version: 
## Last-Updated: Thu Mar 26 09:40:55 2009 (+0200)
##           By: Caner Candan
##     Update #: 37
## URL: 
## Keywords: 
## Compatibility: 
## 
######################################################################
## 
### Commentary: 
## 
## 
## 
######################################################################
## 
### Change log:
## 
## 
######################################################################
## 
## This program is free software; you can redistribute it and/or
## modify it under the terms of the GNU General Public License as
## published by the Free Software Foundation; either version 3, or
## (at your option) any later version.
## 
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
## General Public License for more details.
## 
## You should have received a copy of the GNU General Public License
## along with this program; see the file COPYING.  If not, write to
## the Free Software Foundation, Inc., 51 Franklin Street, Fifth
## Floor, Boston, MA 02110-1301, USA.
## 
######################################################################
## 
### Code:

PATTERN		=	select

PATH_BIN	=	bin
PATH_SRC	=	src
PATH_INCLUDE	=	include
PATH_TAR	=	tar

FILE_README	=	README
FILE_COPYRIGHT	=	COPYRIGHT
FILE_VERSION	=	VERSION

NAME		=	$(PATH_BIN)/lib$(PATTERN).a

DOCS		=	\
			$(FILE_README)		\
			$(FILE_COPYRIGHT)	\
			$(FILE_VERSION)

HEADERS		=	\
			$(PATH_INCLUDE)/$(PATTERN).h	\
			$(PATH_INCLUDE)/list.h

SRCS		=	\
			$(PATH_SRC)/$(PATTERN)_init.c			\
			$(PATH_SRC)/$(PATTERN)_set_callback.c		\
			$(PATH_SRC)/$(PATTERN)_set_signal.c		\
			$(PATH_SRC)/$(PATTERN)_free.c			\
			$(PATH_SRC)/$(PATTERN)_exec.c			\
			$(PATH_SRC)/$(PATTERN)_send.c			\
			$(PATH_SRC)/$(PATTERN)_recv.c			\
			$(PATH_SRC)/$(PATTERN)_recv_field.c		\
			$(PATH_SRC)/$(PATTERN)_recv_field_delim.c	\
			$(PATH_SRC)/$(PATTERN)_mesg_cmp.c		\
			$(PATH_SRC)/$(PATTERN)_mesg_cmp_field.c		\
			$(PATH_SRC)/list_init.c				\
			$(PATH_SRC)/list_free.c				\
			$(PATH_SRC)/list_push.c				\
			$(PATH_SRC)/list_pop.c				\
			$(PATH_SRC)/list_delete.c			\
			$(PATH_SRC)/list_all.c				\
			$(PATH_SRC)/list_all_data.c			\
			$(PATH_SRC)/list_all_struct.c			\
			$(PATH_SRC)/list_count.c

OBJS		=	$(SRCS:.c=.o)

CC		=	gcc
AR		=	ar r
RL		=	ranlib
RM		=	rm -f
RMDIR		=	rmdir
MKDIR		=	mkdir -p
TAR		=	tar -czf
CAT		=	cat
TOUCH		=	touch
BC		=	bc
MV		=	mv
ECHO		=	echo
ECHOE		=	$(ECHO) -e
ECHON		=	$(ECHO) -n

SUCCESS		=	$(ECHOE) "[\033[32mSUCCESS\033[0m] "
FAILED		=	$(ECHOE) "[\033[31mFAILED\033[0m] "

INCLUDES	+=	-I$(PATH_INCLUDE)

DEBUG_TRUE	=	-g -DDEBUG
COMPAT		+=	-D__BSD_VISIBLE
WARNINGS	+=	-W -Wall -Werror

CFLAGS		+=	$(INCLUDES) $(DEBUG_$(DEBUG)) $(COMPAT) $(WARNINGS)

.SUFFIXES	:	.c.o

$(NAME)		:	$(OBJS)
			-@$(ECHON) "*** Making directory $(PATH_BIN) "
			-@$(MKDIR) $(PATH_BIN) && $(SUCCESS) || $(FAILED)
			-@$(ECHON) "*** Creating archive "
			-@$(AR) $@ $(OBJS) && $(SUCCESS) || $(FAILED)
			-@$(ECHON) "*** Generating index to archive "
			-@$(RL) $@ && $(SUCCESS) || $(FAILED)

all		:	$(NAME)

clean		:
			-@$(ECHON) "*** Removing $(PATH_SRC)/*~ "
			-@$(RM) $(PATH_SRC)/*~ && $(SUCCESS) || $(FAILED)
			-@$(ECHON) "*** Removing $(PATH_SRC)/*.o "
			-@$(RM) $(PATH_SRC)/*.o && $(SUCCESS) || $(FAILED)

fclean		:	clean
			-@$(ECHON) "*** Removing $(NAME) "
			-@$(RM) $(NAME) && $(SUCCESS) || $(FAILED)
			-@$(ECHON) "*** Removing $(PATH_BIN) "
			-@$(RMDIR) $(PATH_BIN) && $(SUCCESS) || $(FAILED)

re		:	fclean all

tar		:
			-@$(ECHON) "*** Making directory $(PATH_TAR) "
			-@$(MKDIR) $(PATH_TAR) && $(SUCCESS) || $(FAILED)
			-@$(ECHON) "*** Creating $(DOCS) if not exist "
			-@$(TOUCH) $(DOCS) && $(SUCCESS) || $(FAILED)
			-@$(ECHON) "*** Updating $(FILE_VERSION) step 1/2 "
			-@$(ECHO) "0`$(CAT) $(FILE_VERSION)` + 0.1" | $(BC) > $(FILE_VERSION)_NEW && $(SUCCESS) || $(FAILED)
			-@$(ECHON) "*** Updating $(FILE_VERSION) step 2/2 "
			-@$(MV) $(FILE_VERSION)_NEW $(FILE_VERSION) && $(SUCCESS) || $(FAILED)
			-@$(ECHON) "*** Compressing sources "
			-@$(TAR) $(PATH_TAR)/lib$(PATTERN)-`$(CAT) $(FILE_VERSION)`.tgz Makefile $(DOCS) $(HEADERS) $(SRCS) && $(SUCCESS) || $(FAILED)
			-@$(ECHO) "*** New version `$(CAT) $(FILE_VERSION)` is available "

.PHONY		:	all clean fclean re tar

.c.o		:
			-@$(ECHON) "*** Compiling $< to $@ "
			-@$(CC) $(CFLAGS) -c $< -o $@ && $(SUCCESS) || $(FAILED)

$(PATH_SRC)/$(PATTERN)_init.o	:	\
				$(PATH_SRC)/$(PATTERN)_init.c	\
				$(HEADERS)
				-@$(ECHON) "*** Compiling $(PATH_SRC)/$(PATTERN)_init.c to $@ "
				-@$(CC) $(CFLAGS) -c $(PATH_SRC)/$(PATTERN)_init.c -o $@ && $(SUCCESS) || $(FAILED)

$(PATH_SRC)/$(PATTERN)_set_callback.o	:	\
				$(PATH_SRC)/$(PATTERN)_set_callback.c	\
				$(HEADERS)
				-@$(ECHON) "*** Compiling $(PATH_SRC)/$(PATTERN)_set_callback.c to $@ "
				-@$(CC) $(CFLAGS) -c $(PATH_SRC)/$(PATTERN)_set_callback.c -o $@ && $(SUCCESS) || $(FAILED)

$(PATH_SRC)/$(PATTERN)_set_signal.o	:	\
				$(PATH_SRC)/$(PATTERN)_set_signal.c	\
				$(HEADERS)
				-@$(ECHON) "*** Compiling $(PATH_SRC)/$(PATTERN)_set_signal.c to $@ "
				-@$(CC) $(CFLAGS) -c $(PATH_SRC)/$(PATTERN)_set_signal.c -o $@ && $(SUCCESS) || $(FAILED)

$(PATH_SRC)/$(PATTERN)_free.o	:	\
				$(PATH_SRC)/$(PATTERN)_free.c	\
				$(HEADERS)
				-@$(ECHON) "*** Compiling $(PATH_SRC)/$(PATTERN)_free.c to $@ "
				-@$(CC) $(CFLAGS) -c $(PATH_SRC)/$(PATTERN)_free.c -o $@ && $(SUCCESS) || $(FAILED)

$(PATH_SRC)/$(PATTERN)_exec.o	:	\
				$(PATH_SRC)/$(PATTERN)_exec.c	\
				$(HEADERS)
				-@$(ECHON) "*** Compiling $(PATH_SRC)/$(PATTERN)_exec.c to $@ "
				-@$(CC) $(CFLAGS) -c $(PATH_SRC)/$(PATTERN)_exec.c -o $@ && $(SUCCESS) || $(FAILED)

$(PATH_SRC)/$(PATTERN)_send.o	:	\
				$(PATH_SRC)/$(PATTERN)_send.c	\
				$(HEADERS)
				-@$(ECHON) "*** Compiling $(PATH_SRC)/$(PATTERN)_send.c to $@ "
				-@$(CC) $(CFLAGS) -c $(PATH_SRC)/$(PATTERN)_send.c -o $@ && $(SUCCESS) || $(FAILED)

$(PATH_SRC)/$(PATTERN)_recv.o	:	\
				$(PATH_SRC)/$(PATTERN)_recv.c	\
				$(HEADERS)
				-@$(ECHON) "*** Compiling $(PATH_SRC)/$(PATTERN)_recv.c to $@ "
				-@$(CC) $(CFLAGS) -c $(PATH_SRC)/$(PATTERN)_recv.c -o $@ && $(SUCCESS) || $(FAILED)

$(PATH_SRC)/$(PATTERN)_recv_field.o	:	\
				$(PATH_SRC)/$(PATTERN)_recv_field.c	\
				$(HEADERS)
				-@$(ECHON) "*** Compiling $(PATH_SRC)/$(PATTERN)_recv_field.c to $@ "
				-@$(CC) $(CFLAGS) -c $(PATH_SRC)/$(PATTERN)_recv_field.c -o $@ && $(SUCCESS) || $(FAILED)

$(PATH_SRC)/$(PATTERN)_mesg_cmp.o	:	\
				$(PATH_SRC)/$(PATTERN)_mesg_cmp.c	\
				$(HEADERS)
				-@$(ECHON) "*** Compiling $(PATH_SRC)/$(PATTERN)_mesg_cmp.c to $@ "
				-@$(CC) $(CFLAGS) -c $(PATH_SRC)/$(PATTERN)_mesg_cmp.c -o $@ && $(SUCCESS) || $(FAILED)

$(PATH_SRC)/$(PATTERN)/_mesg_cmp_field.o	:	\
				$(PATH_SRC)/$(PATTERN)/_mesg_cmp_field.c	\
				$(HEADERS)
				-@$(ECHON) "*** Compiling $(PATH_SRC)/$(PATTERN)/_mesg_cmp_field.c to $@ "
				-@$(CC) $(CFLAGS) -c $(PATH_SRC)/$(PATTERN)/_mesg_cmp_field.c -o $@ && $(SUCCESS) || $(FAILED)

$(PATH_SRC)/list_init.o	:	\
				$(PATH_SRC)/list_init.c	\
				$(HEADERS)
				-@$(ECHON) "*** Compiling $(PATH_SRC)/list_init.c to $@ "
				-@$(CC) $(CFLAGS) -c $(PATH_SRC)/list_init.c -o $@ && $(SUCCESS) || $(FAILED)

$(PATH_SRC)/list_free.o	:	\
				$(PATH_SRC)/list_free.c	\
				$(HEADERS)
				-@$(ECHON) "*** Compiling $(PATH_SRC)/list_free.c to $@ "
				-@$(CC) $(CFLAGS) -c $(PATH_SRC)/list_free.c -o $@ && $(SUCCESS) || $(FAILED)

$(PATH_SRC)/list_push.o	:	\
				$(PATH_SRC)/list_push.c	\
				$(HEADERS)
				-@$(ECHON) "*** Compiling $(PATH_SRC)/list_push.c to $@ "
				-@$(CC) $(CFLAGS) -c $(PATH_SRC)/list_push.c -o $@ && $(SUCCESS) || $(FAILED)

$(PATH_SRC)/list_pop.o	:	\
				$(PATH_SRC)/list_pop.c	\
				$(HEADERS)
				-@$(ECHON) "*** Compiling $(PATH_SRC)/list_pop.c to $@ "
				-@$(CC) $(CFLAGS) -c $(PATH_SRC)/list_pop.c -o $@ && $(SUCCESS) || $(FAILED)

$(PATH_SRC)/list_delete.o	:	\
				$(PATH_SRC)/list_delete.c	\
				$(HEADERS)
				-@$(ECHON) "*** Compiling $(PATH_SRC)/list_delete.c to $@ "
				-@$(CC) $(CFLAGS) -c $(PATH_SRC)/list_delete.c -o $@ && $(SUCCESS) || $(FAILED)

$(PATH_SRC)/list_all.o	:	\
				$(PATH_SRC)/list_all.c	\
				$(HEADERS)
				-@$(ECHON) "*** Compiling $(PATH_SRC)/list_all.c to $@ "
				-@$(CC) $(CFLAGS) -c $(PATH_SRC)/list_all.c -o $@ && $(SUCCESS) || $(FAILED)

$(PATH_SRC)/list_all_data.o	:	\
				$(PATH_SRC)/list_all_data.c	\
				$(HEADERS)
				-@$(ECHON) "*** Compiling $(PATH_SRC)/list_all_data.c to $@ "
				-@$(CC) $(CFLAGS) -c $(PATH_SRC)/list_all_data.c -o $@ && $(SUCCESS) || $(FAILED)

$(PATH_SRC)/list_all_struct.o	:	\
				$(PATH_SRC)/list_all_struct.c	\
				$(HEADERS)
				-@$(ECHON) "*** Compiling $(PATH_SRC)/list_all_struct.c to $@ "
				-@$(CC) $(CFLAGS) -c $(PATH_SRC)/list_all_struct.c -o $@ && $(SUCCESS) || $(FAILED)

$(PATH_SRC)/list_count.o	:	\
				$(PATH_SRC)/list_count.c	\
				$(HEADERS)
				-@$(ECHON) "*** Compiling $(PATH_SRC)/list_count.c to $@ "
				-@$(CC) $(CFLAGS) -c $(PATH_SRC)/list_count.c -o $@ && $(SUCCESS) || $(FAILED)

######################################################################
### Makefile ends here
