#include <stdint.h>
#include <stdio.h>

#define carre(x) (x)*(x)

int main() {
	int Nb = 5;
	printf("Nb² =%d\n", carre(Nb + 1));
}