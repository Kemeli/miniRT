/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmatos-s <kmatos-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:42:09 by kmatos-s          #+#    #+#             */
/*   Updated: 2023/03/21 21:25:31 by kmatos-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define MAX_INT_LENGTH 10
# define ERROR "Error\n"
# define READ 0
# define WRITE 1
# ifndef VERBOSE
#  define VERBOSE 0
# endif

/******************************************************************************\
* COLORS																	   *
\******************************************************************************/

/* Black, Red, Green, Yellow, Blue, Purple, Cyan, White */
# define SHELL_BK "\033[0;30m"
# define SHELL_R "\033[0;31m"
# define SHELL_G "\033[0;32m"
# define SHELL_Y "\033[0;33m"
# define SHELL_B "\033[0;34m"
# define SHELL_P "\033[0;35m"
# define SHELL_C "\033[0;36m"
# define SHELL_W "\033[0;37m"

/* Bold */
# define SHELL_BKB "\033[1;30m"
# define SHELL_RB "\033[1;31m"
# define SHELL_GB "\033[1;32m"
# define SHELL_YB "\033[1;33m"
# define SHELL_BB "\033[1;34m"
# define SHELL_PB "\033[1;35m"
# define SHELL_CB "\033[1;36m"
# define SHELL_WB "\033[1;37m"

/* Reset Color */
# define SHELL_RC "\033[0m"

/******************************************************************************\
* BOOLEAN																	   *
\******************************************************************************/

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

#endif
