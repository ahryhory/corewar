/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:41:25 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/15 12:41:26 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_memory
{
	int				byte;
	int				champ_number;
}					t_memory;

typedef struct    s_proc
{
    int            r1;
    int            r2;
    int            r3;
    int            r4;
    int            r5;
    int            r6;
    int            r7;
    int            r8;
    int            r9;
    int            r10;
    int            r11;
    int            r12;
    int            r13;
    int            r14;
    int            r15;
    int            r16;
    int            cp;
    int            carry;
    int            cycl;
    int            cycl_live;
    int            index;
    int            work;
    t_memory    *mem;
    t_proc        *next;
}                t_proc;

t_memory			*allocate_memory();
void				add_champions(t_memory **memory, int ac, char **av);

#endif
