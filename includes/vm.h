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
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>

# define COUNT_OP 16

typedef struct      s_optab
{
    char            name[10];
    int             args_number;
    int             args[3][3];
    char            opcode[5];
    int             cycles;
    char            description[50];
    int             carry;
    int             cod_octal;
    int             lable_size;
}                   t_optab;

t_optab             g_optab[COUNT_OP];

typedef struct      s_memory
{
	int				byte;
	int				champ_number;
}					t_memory;

typedef struct    s_proc
{
    int             r1;
    int             r2;
    int             r3;
    int             r4;
    int             r5;
    int             r6;
    int             r7;
    int             r8;
    int             r9;
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
    struct s_proc        *next;
}                t_proc;

t_memory			*allocate_memory();
void				add_champions(t_memory **memory, int ac, char **av);
void				do_add(t_memory *memory, int index, t_proc *proc);
void				do_aff(t_memory *memory, int index, t_proc *proc);
void				do_and(t_memory *memory, int index, int *n, t_proc *proc);
void				do_fork(t_memory *memory, int index, t_proc *proc);
void				do_ld(t_memory *memory, int index, int *n, t_proc *proc);
void				do_ldi(t_memory *memory, int index, int *n, t_proc *proc);
void				do_lfork(t_memory *memory, int index, t_proc *proc);
void				do_live(t_memory *memory, int index, t_proc *proc);
void				do_lld(t_memory *memory, int index, int *n, t_proc *proc);
void				do_lldi(t_memory *memory, int index, int *n, t_proc *proc);
void				do_or(t_memory *memory, int index, int *n, t_proc *proc);
void				do_st(t_memory *memory, int index, int *n, t_proc *proc);
void				do_sti(t_memory *memory, int index, int *n, t_proc *proc);
void				do_sub(t_memory *memory, int index, t_proc *proc);
void				do_xor(t_memory *memory, int index, int *n, t_proc *proc);
void				do_zjmp(t_memory *memory, int index, t_proc *proc);
void                init_name(void);
void                init_args_number(void);
void                init_args(void);
void                init_opcode(void);
void                init_cycles(void);
void                init_description(void);
void                init_carry(void);
void                init_cod_octal(void);
void                init_lable_size(void);

#endif
