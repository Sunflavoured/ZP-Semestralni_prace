// Jednoduche kalkulacka v C.
// Autor: Erika Dmytrenkov�

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define QUIT 'q'


/* funkce menu.
Na vyber je:
scitani, odcitani, nasobeni, deleni
Texty pro menu jsou ulo�en� v poli stringu.
V�b�r dan� operace je proveden pomoc� zad�n� znalu operace.
*/
void menu(void)
const char *MENU[]= {
  "scitani", "+",
  "odcitani", "-",
  "nasobeni", "*",
  "deleni", "/",
  "modulo", "%",
  "exponent", "^"
};
const int POCET_OPERACI = size(MENU) / (2*size(MENU[0]));

{
  printf("Menu: \n");
  for (int i = 0; i < 2*POCET_OPERACI; i += 2) {
    printf("(%s) %s \n", MENU[i + 1], MENU[i]);
  }
  printf("\n");
}

void clear_stdin(void)
{
  while (getchar() != '\n');
}

void nacti_operaci(char *operace)
{
  scanf(" %c", operace);
  while (getchar() != '\n');
}

void nacti_cislo(float *cislo)
{
  while (scanf("%f", cislo) != 1) {
    printf("Zadali jste cislo spatne.\n");
    printf("Zadejte cislo znovu: ");
    while (getchar() != '\n');
  }
  while (getchar() != '\n');
}


// Funkce pro vypocet
int vypocet(float a, float b, char operace, float *vysledek)
{
  switch (operace) {
    case '+':
      *vysledek = a + b;
      break;
    case '-':
      *vysledek = a - b;
      break;
    case '*':
      *vysledek = a * b;
      break;
    case '^':
      *vysledek = pow(a, b);
      break;
    case '%':
      if (b == 0) {
        printf("Nelze delit nulou!\n");
        return false;
      }
      *vysledek = (int)a % (int)b;
      break;
    case '/':
      if (b == 0) {
        printf("Nelze delit nulou!\n");
        return false;
      }
      *vysledek = a / b;
      break;
    default:
      printf("Neplatna operace!\n");
      return false;
  }

  return true;
}



// funkce main
int main(void)
{
  float a, b, vysledek;
  char operace;
  char opakovat;

  // opakuj dokud uzivatel nezada q
  do {
    // vypis menu
    menu();

    // zadej cisla a operaci
    printf("Zadejte operaci: ");
    nacti_operaci(&operace);
    printf("Zadejte prvni cislo: ");
    nacti_cislo(&a);
    printf("Zadejte druhe cislo: ");
    nacti_cislo(&b);

    // vypocet
    if (!vypocet(a, b, operace, &vysledek)) {
      printf("Vysledek nelze vypocitat.\n");
    } else {
      printf("Vysledek je: %.3f\n", vysledek);
    }

    // opakovat?
    printf("Pro dalsi vypocet zadejte libovolny znak. (%c pro ukonceni) \n", QUIT);
    printf("Zadejte znak: ");
    nacti_operaci(&opakovat);
  } while (opakovat != QUIT);

  return 0;
}