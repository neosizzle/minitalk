#include "minitalk_bonus.h"

static t_message g_message;

static void	init_message(void)
{
	g_message.byte = 0;
	g_message.offset = 0;
}

static void handle_sig(int sig, siginfo_t *info, void *unused)
{
	int	bit;

	(void) unused;
	if(sig == SIGUSR1)
		bit = 1;
	else
		bit = 0;
	g_message.byte += (bit << g_message.offset);
	g_message.offset++;
	if (g_message.offset == 7)
	{
		ft_putchar_fd(g_message.byte, 1);
		if (g_message.byte == '\0')
			ft_putchar_fd('\n', 1);
		init_message();
		kill(info->si_pid, SIGUSR1);
	}
	
}

int main(int argc, char *argv[])
{
	(void) argv;
	struct sigaction sa;

	if (argc == 1)
	{
		ft_putstr_fd("Server PID : ", 1);
		ft_putnbr_fd((int) getpid(), 1);
		ft_putstr_fd("\n", 1);
		sa.sa_sigaction = &handle_sig;
		sa.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (1)
			pause();
	}
	else
		ft_putstr_fd("Usage: ./server\n", 1);
	return (0);
}
