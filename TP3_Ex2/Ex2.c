#include <stdint.h>
#include <stdio.h>
#include <math.h>

int main() {
	long Nombre = 2868838400;
	printf("Nombre d octets: %d\n", sizeof(Nombre));
	int NbrBit = 8 * sizeof(Nombre);
	printf("Nombre de bits: %d\n", NbrBit);
	for (int i = 0; i < 32; i++)
	{
		if (Nombre & 1)
		{
			printf("bit %d : ON\n ", i);
			Nombre = Nombre >> 1;

		}
		else if ((Nombre & 1) == 0)
		{
			printf("bit %d : OFF\n", i);
			Nombre = Nombre >> 1;
		}
	}
	printf("Merci, Bye !");
}