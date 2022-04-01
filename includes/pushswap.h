/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:01:19 by jheiskan          #+#    #+#             */
/*   Updated: 2022/04/01 19:21:18 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# define MAX_NUMBER 2147483647
# define MIN_NUMBER -2147483648
# define STACK_SZ_6_TO_100 20
# define STACK_SZ_OVER_100 46
# define TRY_SOLUTIONS 10

//with string : "29 21 92 91 67 54 30 99 53 89 60 40 63 79 15 13 24 96 41 84 75 82 43 17 7 31 93 52 14 59 70 11 33 37 10 87 97 56 88 62 16 57 25 3 66 42 80 9 74 95 19 39 23 49 69 71 1 27 35 61 90 76 18 8 78 51 48 46 45 83 20 6 58 47 81 2 73 5 85 72 65 12 68 26 64 50 94 44 77 28 55 32 34 98 0 36 86 4 22 38"
//For 100: 12 resulted in 700 moves
//For 100: 1 resulted in 1501 moves
//For 100: 16 resulted in 658 moves
//For 100: 17 resulted in 691 moves
//For 100: 18 resulted in 698 moves
//For 100: 19 resulted in 657 moves-------- The best so far

// Could we try out different stack sizes until best found?

// 20 187 -144 207 140 109 198 -200 -34 -219 -104 37 200 -197 -238 -108 212 120 127 152 49 -53 137 -24 -142 -80 -139 -164 -69 45 -113 -207 -150 55 -216 24 -133 -221 67 -196 -13 117 -43 -141 215 -28 -56 -19 -230 180 25 -49 126 238 139 81 43 96 205 -234 -162 -125 228 19 -136 -116 -21 -170 63 125 -25 -169 -74 224 7 76 156 -39 118 10 172 114 230 234 -157 225 133 229 75 100 -250 99 158 26 129 174 -59 236 74 -4 235 -171 -8 -166 -184 -20 213 189 -206 5 177 -188 -61 168 185 -109 66 191 -209 -62 -243 61 119 218 -152 -31 -201 -75 197 138 -91 162 -189 -228 72 -50 -72 -183 -2 77 -26 47 -154 -36 232 179 -90 244 18 78 -226 -58 161 58 -82 86 -191 202 105 122 -137 -178 -146 87 101 192 -16 204 183 50 17 219 -199 163 147 227 -143 116 -37 222 -179 60 -41 -176 -7 132 -71 175 32 70 241 145 188 128 -202 79 -180 -245 -77 -93 -195 -232 -126 98 41 243 95 245 -5 -45 -235 -127 -158 233 -65 -217 -187 -47 3 54 166 112 193 -155 36 73 184 -151 247 -95 -115 -79 -220 106 -224 110 4 -203 82 64 65 211 -236 -211 173 -87 -51 246 38 -122 115 -29 208 -214 146 -78 -18 -38 -192 -124 -110 -208 94 14 8 -100 -145 62 -167 90 231 89 -60 209 -54 196 -32 221 240 -119 -114 33 46 165 176 -52 113 -225 103 -96 104 -140 216 -204 142 169 -12 182 195 -44 71 190 -240 102 -35 -205 -103 -173 -10 249 68 -231 181 -229 -185 28 -106 -55 -33 -160 239 107 121 -172 -117 11 -227 -186 -233 59 -48 -15 27 -30 0 157 178 56 199 97 -64 -242 -63 111 -107 -123 -193 -88 -66 201 51 -239 134 154 -3 226 -27 -99 -223 12 80 2 40 30 -247 16 -168 -83 -22 -97 150 -105 -131 -132 148 -92 42 1 220 -163 -68 -147 -23 -130 -129 57 210 143 -86 88 -40 29 -159 164 -67 31 -249 91 -76 39 -182 -9 217 -181 153 155 -215 -135 131 -149 214 186 -1 167 69 -175 53 -174 -85 -46 48 -213 203 -153 -11 84 -111 -241 206 124 -14 35 144 6 -161 159 93 -190 123 21 -177 22 -222 -120 -210 52 9 -165 171 -128 -101 -138 -42 223 149 -57 -81 -118 -84 83 170 85 44 -237 -6 -89 15 -102 -218 -148 -248 23 13 -246 237 -70 160 -156 242 -112 -121 -198 34 194 -73 -98 108 -194 -134 -212 248 151 141 -17 -94 130 136 -244 92 135

//For 500: 41 resulted in 7057 moves
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}				t_stack;

int				find_smallest(t_stack *stack);
int				find_smallest_value(t_stack *stack);
int 			find_highest_value(t_stack *stack);
int				create_stack(t_stack **a, int size, char **argv);
int				find_highest(t_stack *stack);
int				is_stack_reverse_sorted(t_stack *stack);
void			rr(t_stack **a, t_stack **b, char **solution);
int				count_cells(char **array);
int				value_in_index(t_stack *stack, int index);
char			*push_from_bottom(t_stack **a, t_stack **b, int index, int stack_size);
char			*push_from_top(t_stack **a, t_stack **b, int index);
int				location_in_reverse_sorted(t_stack *stack, int value);
int				is_stack_sorted(t_stack *stack);
int				calc_stack_size(t_stack *stack);
void			push_to_sorted(t_stack **to, t_stack **from, char **solution);
char			*solve_6_to_100(t_stack **a, t_stack **b, int stack_size, int sub_stack_size);
void			exec_error(t_stack **a, t_stack **b);
void			exec_swap(t_stack **stack);
void			exec_push(t_stack **from, t_stack **dest);
void			exec_rrot(t_stack **stack);
void			exec_rot(t_stack **stack);
void			add_to_end(t_stack **a, int value);
void			del_stack(t_stack *stack);
void			error();
t_stack			*new_node(int value);
long long int	ft_atoi_long(const char *str);
void			validate_input(t_stack **a, int size, char **argv);
void			add_to_start(t_stack **a, int value);
int				get_next_line(const int fd, char **line);
char			*sort_stack(t_stack **a, int stack_size, int sub_stack_size);
void			ra(t_stack **stack, char **solution);
void			rb(t_stack **stack, char **solution);
void			rra(t_stack **stack, char **solution);
void			rrb(t_stack **stack, char **solution);
void			sb(t_stack **stack, char **solution);
void			sa(t_stack **stack, char **solution);
void			ss(t_stack **a, t_stack **b, char **solution);
void			rrr(t_stack **a, t_stack **b, char **solution);
void			pa(t_stack **a, t_stack **b, char **solution);
void			pb(t_stack **a, t_stack **b, char **solution);
int				location_in_sorted(t_stack *stack, int value);

#endif
