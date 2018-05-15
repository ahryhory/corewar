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

#endif
