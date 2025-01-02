/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-mes <moel-mes@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 22:08:06 by moel-mes          #+#    #+#             */
/*   Updated: 2024/12/27 22:23:16 by moel-mes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					final;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# define MAX 2147483647

char					*ft_substr(char *s, int start, int end);
char					*ft_strjoin(char *s1, char *s2);
char					*ft_strcpy(char *s, const char *str, int len);
int						ft_strlen(char *s);
char					*ft_strdup(char *s);
char					*get_next_line(int fd);
char					**ft_split(char *s, char sep);
void					ft_putstr(char *s);
// error handling---------------------------------------------
void					free_stack(t_stack_node **stack);
void					free_matrix(char **argv);
void					error_free(t_stack_node **a, char **argv, bool flag);
int						error_syntax(char *str_nbr);
int						error_repetition(t_stack_node *a, int nbr);
// stack creation----------------------------------------------
void					stack_init(t_stack_node **a, char **av, bool flag);
void					init_nodes(t_stack_node *a, t_stack_node *b);
void					set_current_position(t_stack_node *stack);
void					set_price(t_stack_node *a, t_stack_node *b);
void					set_cheapest(t_stack_node *b);
// linked list utils--------------------------------------------
t_stack_node			*find_last_node(t_stack_node *head);
void					append_node(t_stack_node **stack, int nbr);
t_stack_node			*find_smallest(t_stack_node *stack);
t_stack_node			*return_cheapest(t_stack_node *stack);
int						stack_len(t_stack_node *stack);
bool					stack_sorted(t_stack_node *stack);
void					finish_rotation(t_stack_node **s, t_stack_node *n,
							char c);
int						*stack_to_array(t_stack_node *stack);
int						bigger_than_median(t_stack_node *a, int median);
// algorithms-----------------------------------------------------
void					tiny_sort(t_stack_node **a);
void					handle_five(t_stack_node **a, t_stack_node **b);
void					push_swap(t_stack_node **a, t_stack_node **b);
void					algo(t_stack_node **a, t_stack_node **b, int median,
							int q1);
void					move_nodes(t_stack_node **a, t_stack_node **b);
// Commands-------------------------------------------------------
void					sa(t_stack_node **a, bool checker);
void					sb(t_stack_node **b, bool checker);
void					ss(t_stack_node **a, t_stack_node **b, bool checker);
void					ra(t_stack_node **a, bool checker);
void					rb(t_stack_node **b, bool checker);
void					rr(t_stack_node **a, t_stack_node **b, bool checker);
void					rra(t_stack_node **a, bool checker);
void					rrb(t_stack_node **b, bool checker);
void					rrr(t_stack_node **a, t_stack_node **b, bool checker);
void					pa(t_stack_node **a, t_stack_node **b, bool checker);
void					pb(t_stack_node **b, t_stack_node **a, bool checker);
//-----------------------------------------------------------------
#endif
