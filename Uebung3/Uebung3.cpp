#include <iostream>
#include <ctype.h>


int main()
{
	int n;
	printf("N eingeben: ");
	int ret = scanf("%d", &n);
	printf("\r\n");
	
	int ergebnis = 0;
	for (int i = 1; i <= n; i++)
	{
		printf("%d ^ %d = %lf\r\n", i, 2, pow(i, 2));
		ergebnis += pow(i, 2);
	}

	printf("For Loop: %i\r\n", ergebnis);

	ergebnis = 0;
	int i = 0;
	while (i <= n)
	{
		ergebnis += i * i;
		i++;
	}

	printf("While Loop: %i\r\n", ergebnis);

	return 0;
}

