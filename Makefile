# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 17:08:20 by ivalimak          #+#    #+#              #
#    Updated: 2023/10/20 20:28:22 by ivalimak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= hexrgb
MANFILE			= inc/man/hexrgb.1

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

INSTALL_PATH	= /usr/local
UINSTALL_PATH	= ~/.local
MANFILE_PATH	= /usr/local/man/man1
UMANFILE_PATH	= ~/.local/man/man1

SRCDIR			= src
OBJDIR			= obj
LIBDIR			= lib
INCLUDE			= -I inc -I lib

LIBFT			= $(LIBDIR)/libft.a

SRCS			= $(SRCDIR)/main.c \
				  $(SRCDIR)/utils.c \
				  $(SRCDIR)/convert.c

OBJS			= $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

all: $(NAME)

install:
ifeq ($(shell whoami),root)
	@make --no-print-directory rootinstall
else
	@make --no-print-directory userinstall
endif

uninstall:
ifeq ($(shell whoami),root)
	@make --no-print-directory rootuninstall
else
	@make --no-print-directory useruninstall
endif

rootinstall: $(INSTALL_PATH) $(MANFILE_PATH)
ifeq ($(shell ls 2>/dev/null $(INSTALL_PATH)/bin | grep $(NAME)),$(NAME))
	@echo Reinstalling $(NAME)...
else
	@echo Installing $(NAME)...
endif
	@cp $(NAME) $(INSTALL_PATH)/bin/$(NAME)
	@cp $(MANFILE) $(MANFILE_PATH)/hexrgb.1
	@echo Installation complete

rootuninstall:
	@echo Uninstalling $(NAME)...
	@rm -f $(INSTALL_PATH)/bin/$(NAME)
	@rm -f $(MANFILE_PATH)/vimtype.1
	@echo $(NAME) uninstalled

userinstall: $(UINSTALL_PATH) $(UMANFILE_PATH)
	@echo NOTE: Installing to $(UINSTALL_PATH)/bin, add it to your PATH if not already added
ifeq ($(shell ls 2>/dev/null $(UINSTALL_PATH)/bin | grep $(NAME)),$(NAME))
	@echo Reinstalling $(NAME)...
else
	@echo Installing $(NAME)...
endif
	@cp $(NAME) $(UINSTALL_PATH)/bin/$(NAME)
	@cp $(MANFILE) $(UMANFILE_PATH)/hexrgb.1
	@echo Installataion complete

useruninstall:
	@echo Uninstalling $(NAME)...
	@rm -f $(UINSTALL_PATH)/bin/$(NAME)
	@rm -f $(UMANFILE_PATH)/vimtype.1
	@echo $(NAME) uninstalled

$(NAME): $(LIBFT) $(OBJDIR) $(OBJS)
	@echo Compiling $(NAME)...
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -L $(LIBDIR) -lft -o $(NAME)

$(INSTALL_PATH):
	@mkdir -p $(INSTALL_PATH)

$(UINSTALL_PATH):
	@mkdir -p $(UINSTALL_PATH)

$(MANFILE_PATH):
	@mkdir -p $(MANFILE_PATH)

$(UMANFILE_PATH):
	@mkdir -p $(UMANFILE_PATH)

$(LIBFT):
	@make -C $(LIBDIR)/libft --no-print-directory

$(OBJDIR):
	@echo Creating objdir...
	@mkdir obj

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo Compiling $@...
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@make -C $(LIBDIR)/libft clean --no-print-directory
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LIBDIR)/libft fclean --no-print-directory
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
