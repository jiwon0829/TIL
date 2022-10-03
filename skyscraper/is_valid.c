#include <stdlib.h>

extern int	g_board[6][6];
extern int	g_complete_board;

void	setting_board(int *highest);

int	is_valid_input(char *str)
{
	int	cnt;
	int	i;
	int	*higest;

	cnt = 0;
	i = 0;
	higest = (int *)malloc(16 * sizeof(int));
	while (str[i])
	{
		if (cnt >= 16)
			return (0);
		if (i % 2 == 0 && (str[i] >= '1' && str[i] <= '4'))
			higest[cnt++] = str[i] - '0';
		else if (!(i % 2 == 1 && str[i] == ' '))
			return (0);
		i++;
	}
	if (cnt == 16)
		setting_board(higest);
	free(higest);
	return (cnt == 16);
}

int	is_exist(int row, int col, int floor)
{
	int	index;

	index = 0;
	while (index++ < 4)
	{
		if (g_board[row][index] == floor || g_board[index][col] == floor)
			return (0);
	}
	return (1);
}

int	is_valid_value_row(int row, int col, int high, int pos)
{	
	int	max_floor;
	int	cnt;
	int	floor;

	max_floor = -1;
	cnt = 0;
	floor = 0;
	while (floor++ < 4)
	{
		if (pos == 0)
			row = floor;
		else
			row = 4 - floor + 1;
		if (!g_board[row][col])
			return (1);
		if (max_floor < g_board[row][col])
		{
			max_floor = g_board[row][col];
			cnt++;
		}
	}
	if (cnt == high)
		return (1);
	return (0);
}

int	is_valid_value_col(int row, int col, int high, int pos)
{	
	int	max_floor;
	int	cnt;
	int	floor;

	max_floor = -1;
	cnt = 0;
	floor = 0;
	while (floor++ < 4)
	{
		if (pos == 0)
			col = floor;
		else
			col = 4 - floor + 1;
		if (!g_board[row][col])
			return (1);
		if (max_floor < g_board[row][col])
		{
			max_floor = g_board[row][col];
			cnt++;
		}
	}
	if (cnt == high)
		return (1);
	return (0);
}

int	is_valid_value(int row, int col)
{
	if (!is_valid_value_row(row, col, g_board[0][col], 0)
		|| !is_valid_value_row(row, col, g_board[5][col], 1)
		|| !is_valid_value_col(row, col, g_board[row][0], 0)
		|| !is_valid_value_col(row, col, g_board[row][5], 1))
		return (0);
	return (1);
}
