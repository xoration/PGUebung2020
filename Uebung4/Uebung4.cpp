// Uebung4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int zahl = 0;
    int digits[10] = { 0 };
	
    scanf("%d", &zahl);

    int i = 0;
    while (zahl > 0) {
        int digit = zahl % 10;
        digits[i] = digit;
    	
        // do something with digit
        zahl /= 10;
    	
        i++;
    }

    int quersumme = 0;
	for (int d = i-1; d >= 0; d--)
	{
        printf("%d ", digits[d]);
        quersumme += digits[d];
	}


    char array[10];
    scanf("%s", &array);

    for (int d = 0; d < 10; d++)
    {
        printf("%d ", array[d]);
        
    }
	
}