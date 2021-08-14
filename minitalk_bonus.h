#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "./libft/libft.h"

typedef struct	s_message {
	unsigned char	byte;
	int				offset;
}	t_message;

#endif