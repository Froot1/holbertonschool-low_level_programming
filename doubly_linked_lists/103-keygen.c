#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * f3 - calculation of the 3rd character
 * @my: pointer to first input argument.
 * @tu: 6
 *
 * Return: result of the calculation.
 */
unsigned long f3(char *my, int tu)
{
	unsigned int laQueHay;
	int bro;

	laQueHay = 1;
	bro = 0;
	while (bro < tu)
	{
		laQueHay = my[bro] * laQueHay;
		bro = bro + 1;
	}
	return ((unsigned long)((laQueHay ^ 0x55) & 0x3f));
}

/**
 * f4 - calculation of the 3rd character
 * @my: pointer to first input argument.
 * @tu: 6
 *
 * Return: result of the calculation.
 */
unsigned long f4(char *my, int tu)
{
	unsigned int uVar1;
	unsigned int laQueHay;
	int bro;

	laQueHay = my[0];
	bro = 0;
	/*Looking for the smallest character*/
	while (bro < tu)
	{
		if ((int)laQueHay < (int)my[bro])
		{
			laQueHay = my[bro];
		}
		bro = bro + 1;
	}
	srand(laQueHay ^ 0xe);
	uVar1 = rand();
	return ((unsigned long)(uVar1 & 0x3f));
}
/**
 * f5 - calculation of the 3rd character
 * @my: pointer to first input argument.
 * @tu: 6
 *
 * Return: result of the calculation.
 */

unsigned long f5(char *my, int tu)
{
	int laQueHay;
	int bro;

	laQueHay = 0;
	bro = 0;
	while (bro < tu)
	{
		laQueHay = laQueHay + my[bro] * my[bro];
		bro = bro + 1;
	}
	return ((unsigned long)((unsigned int)(char)((char)laQueHay ^ 0xef) & 0x3f));
}

/**
 * f6 - calculation of the 3rd character
 * @my: pointer to first input argument.
 *
 * Return: result of the calculation.
 */

unsigned long f6(char my)
{
	int laQueHay;
	int bro;

	laQueHay = 0;
	bro = 0;
	while (bro < my)
	{
		laQueHay = rand();
		bro = bro + 1;
	}
	return ((unsigned long)((unsigned int)(char)((char)laQueHay ^ 0xe5) & 0x3f));
}

/**
 * main - program that generates a key for a given name
 * @argc: count of input arguments
 * @argv: array of string inputs.
 *
 * Return: 0 on success, 1 if failed.
 */

int main(int argc, char **argv)
{
	char *esa_1, esa_2[7], *aja;
	uint aver;
	unsigned long saSalio;
	unsigned int laQueHay;
	int bro;

	aja = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	if (argc != 2)
	{
		exit(1);
	}
	esa_1 = argv[1];
	aver = strlen(esa_1);
	saSalio = ((aver ^ 0x3b) & 0x3f);
	esa_2[0] = aja[saSalio];
	/* f2 */
	laQueHay = 0;
	bro = 0;
	while (bro < (int)aver)
	{
		laQueHay = laQueHay + esa_1[bro];
		bro = bro + 1;
	}
	saSalio = ((laQueHay ^ 0x4f) & 0x3f);
	/* /f2 */
	esa_2[1] = aja[saSalio];
	saSalio = f3(esa_1, aver);
	esa_2[2] = aja[saSalio];
	saSalio = f4(esa_1, aver);
	esa_2[3] = aja[saSalio];
	saSalio = f5(esa_1, aver);
	esa_2[4] = aja[saSalio];
	saSalio = f6(*esa_1);
	esa_2[5] = aja[saSalio];
	esa_2[6] = '\0';
	printf("%s", esa_2);
	return (0);
}
