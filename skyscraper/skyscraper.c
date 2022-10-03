int	g_board[6][6];
int	g_complete_board;

void	make_board(int row, int col);

void	create_board(void)
{
	int	x;
	int	y;

	y = 0;
	while (y++ < 4)
	{
		x = 0;
		while (x++ < 4)
		{	
			g_board[y][x] = 0;
		}
	}
}

int	skyscraper(void)
{
	g_complete_board = 0;
	create_board();
	make_board(1, 1);
	return (g_complete_board);
}
