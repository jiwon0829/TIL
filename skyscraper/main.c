#include <unistd.h>

int	skyscraper(void);
int	is_valid_input(char *str);

int	main(int argc, char **argv)
{
	if (argc != 2 || !is_valid_input(argv[1]) || !skyscraper())
		write(1, "Error\n", 6);
	return (0);
}
