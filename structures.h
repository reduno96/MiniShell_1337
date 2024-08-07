/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 07:58:38 by rel-mora          #+#    #+#             */
/*   Updated: 2024/08/07 09:26:34 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_idx
{
	int						i;
	int						j;
	int						len;
	int						start;
	int						state;
	int						in_s;
	int						in_d;
}							t_idx;

typedef enum e_token
{
	WORD = -1,
	WHITE_SPACE = ' ',
	NEW_LINE = '\n',
	QOUTE = '\'',
	DOUBLE_QUOTE = '\"',
	ENV = '$',
	PIPE_LINE = '|',
	REDIR_IN = '<',
	REDIR_OUT = '>',
	HERE_DOC,
	DREDIR_OUT,
}							t_token;

typedef struct s_redirect
{
	char					*dir_in;
	char					*dir_out;
	char					*rdir;
	char					*doc_here;
}							t_redirect;

typedef enum e_state
{
	D,
	S,
	G,
	NUL,
}							t_state;
typedef struct s_splitor
{
	char					*in;
	int						len;
	enum e_token			type;
	enum e_state			state;
	struct s_splitor		*next;
}							t_splitor;

typedef struct s_environment
{
	char					*line;
	struct s_environment	*next;
}							t_environment;

typedef struct s_command
{
	char					*content;
	char					**arg;
	t_redirect				*doc;
	struct s_command		*next;
}							t_command;

#endif