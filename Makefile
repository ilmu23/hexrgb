# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/30 17:08:20 by ivalimak          #+#    #+#              #
#    Updated: 2024/03/16 09:21:15 by ivalimak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	hexrgb
MANFILE	=	man/hexrgb.1

BUILD	=	normal

CC				=	cc
cflags.common	=	-Wall -Wextra -Werror
cflags.normal	=	-Ofast
cflags.debug	=	-g
cflags.debugm 	=	$(cflags.debug) -D DEBUG_MSG=1
cflags.asan		=	$(cflags.debug) -fsanitize=address
CFLAGS			=	$(cflags.common) $(cflags.$(BUILD))

INSTALL_PATH	=	/usr/local/bin
UINSTALL_PATH	=	~/.local/bin
MANFILE_PATH	=	/usr/local/man/man1
UMANFILE_PATH	=	~/.local/man/man1

CHECKINSTALL	= 	./checkinstall.sh

SRCDIR	=	src
OBJDIR	=	obj
LIBDIR	=	libft
INCDIR	=	inc

LIBFT	=	$(LIBDIR)/libft.a

FILES	=	main.c \
			opts.c \
			valid.c \
			utils.c \
			error.c

SRCS	=	$(addprefix $(SRCDIR)/, $(FILES))
OBJS	=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

all:  $(OBJDIR) $(NAME)

install: all
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
	@$(CHECKINSTALL) root $(NAME)
	@cp $(NAME) $(INSTALL_PATH)/$(NAME)
	@cp $(MANFILE) $(MANFILE_PATH)/hexrgb.1
	@printf "\e[35mHEXRGB >\e[m Installation complete\n" $(NAME)

rootuninstall:
	@printf "\e[35mHEXRGB >\e[m Uninstalling %s...\n" $(NAME)
	@rm -f $(INSTALL_PATH)/$(NAME)
	@rm -f $(MANFILE_PATH)/hexrgb.1
	@printf "\e[35mHEXRGB >\e[m %s uninstalled\n" $(NAME)

userinstall: $(UINSTALL_PATH) $(UMANFILE_PATH)
	@printf "\e[35;1mHEXRGB >\e[m Installing to \e[33m%s\e[m, add it to your PATH if not alrady added\n" $(UINSTALL_PATH)
	@$(CHECKINSTALL) user $(NAME)
	@cp $(NAME) $(UINSTALL_PATH)/$(NAME)
	@cp $(MANFILE) $(UMANFILE_PATH)/hexrgb.1
	@printf "\e[35mHEXRGB >\e[m Installation complete\n" $(NAME)

useruninstall:
	@printf "\e[35mHEXRGB >\e[m Uninstalling %s...\n" $(NAME)
	@rm -f $(UINSTALL_PATH)/$(NAME)
	@rm -f $(UMANFILE_PATH)/hexrgb.1
	@printf "\e[35mHEXRGB >\e[m %s uninstalled\n" $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@printf "\e[35mHEXRGB >\e[m Compiling %s...\n" $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR)/$(INCDIR) $(OBJS) -L$(LIBDIR) -lft -o $(NAME)

$(INSTALL_PATH):
	@mkdir -p $(INSTALL_PATH)

$(UINSTALL_PATH):
	@mkdir -p $(UINSTALL_PATH)

$(MANFILE_PATH):
	@mkdir -p $(MANFILE_PATH)

$(UMANFILE_PATH):
	@mkdir -p $(UMANFILE_PATH)

$(LIBFT):
	@make -C $(LIBDIR) --no-print-directory BUILD=$(BUILD)

$(OBJDIR):
	@printf "\e[35mHEXRGB >\e[m Creating objdir...\n"
	@mkdir obj

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@printf "\e[35mHEXRGB >\e[m Compiling %s\n" $@
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR)/$(INCDIR) -c $< -o $@

clean:
	@make -C $(LIBDIR) clean --no-print-directory BUILD=$(BUILD)
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LIBDIR) fclean --no-print-directory BUILD=$(BUILD)
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all install uninstall clean fclean re
