#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int zaehler;
    int nenner;

}Bruch;



int kgv(int nenner1, int nenner2) {
    int erg = 0;
    int i, j;
    for (i = 1; i <= nenner1; i++) {
        for (j = 1; j <= nenner2; j++) {
            if (nenner1 * j == nenner2 * i) {
                erg = nenner1 * j;
                return erg;
            }
        }
    }
    return -1;
}



void kuerzen(int* zaehler, int* nenner) {
    int i = 0;
    int zaehler_vorz = *zaehler;
    int nenner_vorz = *nenner;

    if (*zaehler < 0) {
        zaehler_vorz = zaehler_vorz * (-1);
    }
    if (*nenner < 0) {
        nenner_vorz = nenner_vorz * (-1);
    }
    if (zaehler_vorz <= nenner_vorz) {
        i = zaehler_vorz;
    }
    else {
        i = nenner_vorz;
    }


    while (i != 0) {
        if ((zaehler_vorz % i == 0) && (nenner_vorz % i == 0)) {
            *zaehler = *zaehler / i;
            *nenner = *nenner / i;
            break;
        }
        i--;
    }
}



void bruch_taschenrechner(Bruch* op1, Bruch* op2, int operation) {

    int erg_z = 0, erg_n = 1;

    //Nenner darf nicht Null sein
    if ((*op1).nenner == 0 || (*op2).nenner == 0) {
        printf("Nenner darf nicht Null sein!\n");
    }

    //Rechenoperationen ausf�hren
    else {

        switch (operation) {
        case 1:

            erg_n = kgv((*op1).nenner, (*op2).nenner);
            erg_z = (*op1).zaehler * (erg_n / (*op1).nenner) + (*op2).zaehler * (erg_n / (*op2).nenner);
            break;
        case 2:

            erg_n = kgv((*op1).nenner, (*op2).nenner);
            erg_z = (*op1).zaehler * (erg_n / (*op1).nenner) - (*op2).zaehler * (erg_n / (*op2).nenner);
            break;
        case 3:

            erg_n = (*op1).nenner * (*op2).nenner;
            erg_z = (*op1).zaehler * (*op2).zaehler;
            break;
        case 4:

            erg_n = (*op1).nenner * (*op2).zaehler;
            erg_z = (*op1).zaehler * (*op2).nenner;
            break;
        default:
            printf("Keine erlaubte Rechenoperation eingegeben!\n");
        }



        //Br�che k�rzen
        kuerzen(&erg_z, &erg_n);


        //Z�hler = 0
        if (erg_z == 0) {
            printf("Ergebnis: 0\n");
        }

        //Z�hler und Nenner beide positiv
        else if (erg_z > 0 && erg_n > 0) {
            //echten Bruch ausgeben
            if (erg_z < erg_n) {
                printf("Ergebnis: %d / %d", erg_z, erg_n);
            }
            else {
                //Ganze Zahl ausgeben
                if (erg_z % erg_n == 0) {
                    printf("Ergebnis: %d\n", erg_z / erg_n);
                }
                //Ganze Zahl und Bruch ausgeben
                else {
                    printf("Ergebnis: %d %d/%d\n", erg_z / erg_n, erg_z % erg_n, erg_n);
                }
            }
        }

        //Nenner und Z�hler beide negativ
        else if (erg_z < 0 && erg_n < 0) {
            if (erg_z > erg_n) {
                printf("Ergebnis: %d/%d", erg_z, erg_n);
            }
            else {
                if (erg_z % erg_n == 0) {
                    printf("Ergebnis: %d\n", erg_z / erg_n);
                }
                else {
                    printf("Ergebnis: %d %d/%d\n", erg_z / erg_n, erg_z % erg_n, erg_n);
                }
            }
        }

        else {
            //Nur Z�hler negativ
            if (erg_z < 0) {
                if ((erg_z * (-1)) < erg_n) {
                    printf("Ergebnis: %d/%d\n", erg_z, erg_n);
                }
                else if ((erg_z * (-1)) >= erg_n) {
                    if ((erg_z * (-1)) % erg_n == 0) {
                        printf("Ergebnis: %d\n", erg_z / erg_n);
                    }
                    else {
                        printf("Ergebnis: %d %d/%d\n", erg_z / erg_n, erg_z % erg_n, erg_n);
                    }
                }
            }
            //Nur Nenner negativ
            else if (erg_n < 0) {
                if (erg_z < (erg_n * (-1))) {
                    printf("Ergebnis: %d/%d\n", erg_z, erg_n);
                }
                else if (erg_z >= (erg_n * (-1))) {
                    if (erg_z % (erg_n * (-1)) == 0) {
                        printf("Ergebnis: %d\n", erg_z / erg_n);
                    }
                    else {
                        printf("Ergebnis: %d %d/%d\n", erg_z / erg_n, erg_z % (erg_n * (-1)), erg_n * (-1));
                    }
                }
            }
        }
    }



}




int main() {
    Bruch bruch1, bruch2;
    int operation = 0;
    printf("Operation (1 = +, 2 = -, 3 = *, 4 = /):\n");
    scanf("%d", &operation);
    printf("Operand1 (Z�hler):\n");
    scanf("%d", &bruch1.zaehler);
    printf("Operand1 (Nenner):\n");
    scanf("%d", &bruch1.nenner);
    printf("Operand2 (Z�hler):\n");
    scanf("%d", &bruch2.zaehler);
    printf("Operand2 (Nenner):\n");
    scanf("%d", &bruch2.nenner);

    bruch_taschenrechner(&bruch1, &bruch2, operation);

    return 0;
}
