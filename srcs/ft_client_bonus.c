#include "minitalk_bonus.h"

static char	*g_message;

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
	send_bits(pid, message[i]);
}

static void	handle_sig(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_putstr_fd("\nTotal bytes acknowledged : ", 1);
		ft_putnbr_fd(ft_strlen(g_message), 1);
	}
}

int main(int argc, char *argv[])
{
	(void) argv;
	int		pid;
	struct	 sigaction sa;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		g_message = argv[2];
		sa.sa_handler = handle_sig;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		send_message(pid, g_message);
	}
	else
		ft_putstr_fd("Usage: ./client [PID] [message]\n", 1);
	return (0);
}
