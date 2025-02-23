/*
 * File: 101-keygen.c
 * Auth: Fahad Alonazi
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
        int i = 0, sum = 0, a;

	srand(time(NULL));

        while (1)
	{
		a = rand()%100;
		sum += a;

		if (sum <= 2772)
		{
		        printf("%c", a);

			if (sum == 2772)
			{
				break;
			}
		}
		else
		{
			sum -= a;
			i--;
		}

		i++;
	}

	return (0);
}
