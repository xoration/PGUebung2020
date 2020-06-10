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
