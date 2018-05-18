/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 12:41:25 by dmelnyk           #+#    #+#             */
/*   Updated: 2018/05/18 18:36:11 by iseletsk         ###   ########.fr       */
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
    int             code;
    int             cycles;
    char            description[50];
    int             carry;
    int             cod_octal;
    int             lable_size;
}                   t_optab;

t_optab             g_optab[COUNT_OP];

typedef struct		s_chemp
{
	int				nbr[4];
	int				live;
	int				live_icp;
	struct s_chemp	*next;
}					t_chemp;

typedef struct      s_mem
{
	int				byte;
	t_chemp			*chemp;
}					t_mem;

typedef struct    s_proc
{
    int             r[REG_NUMBER];
    int             cp;
    int             carry;
	int				cycl;
	int				live;
	int				index;
    int				work;
    t_mem			*mem;
    struct s_proc	*next;
}					t_proc;

typedef struct      s_con
{
	int				m_check;
	int				cycl;
	int				cycl_die_per;
	int				cycl_to_die;
	t_mem			*mem;
	t_chemp			*chemp;
	t_proc			*proc;
}					t_con;

t_mem			    *allocate_memory();
void				add_champions(t_con *con, int ac, char **av,
														t_chemp *chemp);
void				do_add(t_con *con, int index, t_proc *proc);
void				do_aff(t_con *con, int index, t_proc *proc);
void				do_and(t_con *con, int index, int *n, t_proc *proc);
void				do_fork(t_con *con, int index, t_proc *proc);
void				do_ld(t_con *con, int index, int *n, t_proc *proc);
void				do_ldi(t_con *con, int index, int *n, t_proc *proc);
void				do_lfork(t_con *con, int index, t_proc *proc);
void				do_live(t_con *con, int index, t_proc *proc);
void				do_lld(t_con *con, int index, int *n, t_proc *proc);
void				do_lldi(t_con *con, int index, int *n, t_proc *proc);
void				do_or(t_con *con, int index, int *n, t_proc *proc);
void				do_st(t_con *con, int index, int *n, t_proc *proc);
void				do_sti(t_con *con, int index, int *n, t_proc *proc);
void				do_sub(t_con *con, int index, t_proc *proc);
void				do_xor(t_con *con, int index, int *n, t_proc *proc);
void				do_zjmp(t_con *con, int index, t_proc *proc);
void                init_name(void);
void                init_args_number(void);
void                init_args(void);
void                init_opcode(void);
void                init_cycles(void);
void                init_description(void);
void                init_carry(void);
void                init_cod_octal(void);
void                init_lable_size(void);
int                 get_index(int index, int step);
unsigned int        get_nbr(t_con *con, int index, int size);
int					vm_hendl_proc(t_con *con);
void				vm_hendl_command(t_proc *proc, t_con *con);
void				vm_give_cord(t_proc *proc, int *codg);
void				vm_del_proc(t_con **con, int i);
void				vm_hendl_byte(t_proc *proc, t_con *con);
int					vm_give_codg(t_proc *proc, unsigned int *codg);
t_chemp				*vm_add_chemp(int nbr);

#endif
