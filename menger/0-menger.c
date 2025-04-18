#include "menger.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 6561

/**
 * menger - Draws the Menger Sponge of the given level
 * @level: The level of the Menger Sponge
 */

void menger(int level)
{
	int size = pow(3, level);
	int y, x, empty, x_pos, y_pos;

	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			empty = 0;
			x_pos = x;
			y_pos = y;

			while (x_pos > 0 || y_pos > 0)
			{
				if ((x_pos % 3 == 1) && (y_pos % 3 == 1))
				{
					empty = 1;
					break;
				}
				x_pos /= 3;
				y_pos /= 3;
			}

			if (empty)
				putchar(' ');
			else
				putchar('#');
		}
		putchar('\n');
	}
	}
