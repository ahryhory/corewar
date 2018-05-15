// void			add_byte(t_memory **memory)
// {
// 	t_memory	*new;
// 	t_memory	*lst;

// 	new = (t_memory*)malloc(sizeof(t_memory));
// 	new->byte = 0;
// 	new->champ_number = 0;
// 	new->next = NULL;
// 	lst = *memory;
// 	if (lst)
// 	{
// 		while (lst->next)
// 			lst = lst->next;
// 		lst->next = new;
// 	}
// 	else
// 		*memory = new;
// }

// t_memory		*allocate_memory()
// {
// 	t_memory	*memory;
// 	int			i;

// 	memory = (t_memory*)malloc(sizeof(t_memory));
// 	memory = NULL;
// 	i = 0;
// 	while (i < MEM_SIZE)
// 	{
// 		add_byte(&memory);
// 		i++;
	
// 	}

// 	return (memory);
// }
