/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_data.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:49:48 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/16 02:57:47 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_DATA_H
# define LFT_DATA_H
# include <stdlib.h>
# include <stdint.h>

# ifndef STACK_MAX
#  define STACK_MAX 2048
# endif

typedef struct s_list
{
	void			*blk;
	size_t			*size;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_obj
{
	uint8_t			marked;
	size_t			blksize;
	size_t			asize;
	void			*blk;
	struct s_obj	*next;
}	t_obj;

typedef struct s_vm
{
	void	*stack[STACK_MAX];
	size_t	stacksize;
	size_t	maxobjs;
	size_t	objs;
	t_obj	*head;
}	t_vm;

typedef enum e_base
{
	BINARY,
	OCTAL,
	DECIMAL,
	HEX
}	t_base;

#endif
