#include "minitalk.h"

static void send_bits(int pid, char c)
{
	int	offset;

	offset = 0;
	while (offset < 7)
	{
		if ((c >> offset) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		offset++;
		usleep(69);
	}
}

static void	send_message(int pid, char *message)
{
	int	i;

	i = -1;
	while (message[++i])
		send_bits(pid, message[i]);
}


int main(int argc, char *argv[])
{
	(void) argv;
	int		pid;
	char	*message;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		message = argv[2];
		send_message(pid, message);
	}
	else
		ft_putstr_fd("Usage: ./client [PID] [message]\n", 1);
	return (0);
}
