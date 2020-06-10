#include <iostream>
#include <math.h>

int main()
{
	for (int i = 0; i < 9999; i++)
	{
		int result = 0;

		int numDigits = (i == 0) ? 1 : (log10(i) + 1);

		int value = i;
		while (value)
		{
			int digit = value % 10;
			result += pow(digit, numDigits);
			value /= 10;
		}

		if (result == i)
		{
			printf("%i\r\n", i);
		}
	}
}

/*

#include <stdio.h>
#include <math.h>

int laenge(int z) {

	int s = 0;
	while (z > 0) {
		z = (z / 10);
		s = s + 1;
	}
	return s;
}



int armstrong(int z) {

	int lz = 0;
	int hochzahl = 0;
	int summe = 0;
	int zz = z;
	int s = 0;

	s = laenge(z);

	while (z > 0) {
		lz = z - 10 * floor(z / 10);
		hochzahl = pow(lz, s);
		summe = summe + hochzahl;

		z = floor(z / 10);
	}
	if (summe == zz)
		printf("%4d ist eine Armstrong-Zahl\n", zz);
	return 0;
}

int main() {

	int z = 1;

	while (z <= 10000) {
		armstrong(z);
		z++;
	}
}

*/