// Uebung5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int zahl1 = 0;
    int erg = 0;
    char op;
    int zahl2 = 0;

    char name[10];
   
    printf("Erste Zahl: ");
    scanf("%d", &zahl1);
    printf("Operation (1 add, 2 sub, 3 mul, 4 div, 5 mod, 6 pot): ");
    scanf(" %c", &op);
    printf("Zweite Zahl: ");
    scanf("%d", &zahl2);

    printf("Who are you? ");
    fgets(name, 10, stdin);
    printf("Glad to meet you, %s.n", name);
    

    int test = 1 && 1;
	 
	if (1 && true)
	{
		
	}

    switch (op) {
    case '1':
        erg = zahl1 + zahl2;
        printf("%d + %d = %d", zahl1, zahl2, erg);
        break;

    case '2':
        erg = zahl1 - zahl2;
        printf("%d - %d = %d", zahl1, zahl2, erg);
        break;

    default:
        printf("falsche Eingabe");
        break;

    }
}
