CLIENT=client
SERVER=server
CLIENT_SRCS= srcs/ft_client.c
SERVER_SRCS= srcs/ft_server.c
CLIENT_BONUS=client_bonus
SERVER_BONUS=server_bonus
CLIENT_BONUS_SRCS=
SERVER_BONUS_SRCS=
LIBFT=libft.a
GCC=gcc -Wall -Werror -Wextra -I .

all:${CLIENT} ${SERVER}

bonus:${CLIENT_BONUS} ${SERVER_BONUS}

${CLIENT} : 
	make -C libft
	${GCC} ${CLIENT_SRCS} -L libft -l:${LIBFT} -o ${CLIENT}

${SERVER} : 
	make -C libft
	${GCC} ${SERVER_SRCS} -L libft -l:${LIBFT} -o ${SERVER}

clean:
	rm -f *.o
	rm -f libft/*.o

fclean:
	rm -f *.o ${CLIENT} ${SERVER} ${CLIENT_BONUS} ${SERVER_BONUS}
	rm -f libft/*.o

re: fclean all

.PHONY: all bonus clean fclean re