#include <unistd.h>

extern int	g_board[6][6];
extern int	g_complete_board;

int	is_valid_value(int row, int col);
int	is_exist(int row, int col, int floor);

void	setting_board(int *highest)
{	
	int	size;

	size = 0;
	while (size++ < 4)
		g_board[0][size] = highest[size - 1];
	size--;
	while (size++ < 8)
		g_board[5][size - 4] = highest[size - 1];
	size--;
	while (size++ < 12)
		g_board[size - 8][0] = highest[size - 1];
	size--;
	while (size++ < 16)
		g_board[size -12][5] = highest[size - 1];
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_board(void)
{
	int	x;
	int	y;

	y = 0;
	while (y++ < 4)
	{
		x = 0;
		while (x++ < 4)
		{
			ft_putchar('0' + g_board[y][x]);
			if (x != 4)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

void	make_board(int row, int col)
{
	int	floor;

	if (row == 5)
	{
		print_board();
		g_complete_board = 1;
		return ;
	}	
	floor = 0;
	while (floor++ < 4)
	{
		if (!(is_exist(row, col, floor)))
			continue ;
		g_board[row][col] = floor;
		if (is_valid_value(row, col) && !g_complete_board)
		{
			if (col == 4)
				make_board(row + 1, 1);
			else
				make_board(row, col + 1);
		}
		g_board[row][col] = 0;
	}
}
