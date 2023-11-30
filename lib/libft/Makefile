# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 15:26:18 by ivalimak          #+#    #+#              #
#    Updated: 2023/11/20 19:47:34 by ivalimak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ../libft.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	=	ft_atoi.c \
			ft_atol.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_isinteger.c \
			ft_contains.c \
			ft_itoa.c \
			ft_uitox.c \
			ft_uitoa.c \
			ft_intlen.c \
			ft_uintlen.c \
			ft_memset.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_putnbr_fd.c \
			ft_putunbr_fd.c \
			ft_putxnbr_fd.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strclen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_strrev.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_lstadd_back_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstmap_bonus.c \
			ft_lstnew_bonus.c \
			ft_lstsize_bonus.c \
			ft_format.c \
			ft_printf.c \
			ft_putc.c \
			ft_putd.c \
			ft_putp.c \
			ft_puts.c \
			ft_putu.c \
			ft_putx.c \
			printf_utils.c \
			get_next_line.c \
			gnl_utils.c

OBJS	= $(patsubst %.c, %.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	@echo Creating libft...
	@ar -crs $(NAME) $(OBJS)
	@cp libft.h ../libft.h

%.o: %.c
	@echo Compiling $@
	@$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
	@rm -f ../libft.h

re: fclean all
