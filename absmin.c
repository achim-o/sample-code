
#include <stdio.h>

void absmin (int n, double * a, int *amin)
{
}


int main (void)
{
	/* Testdaten definieren */
	double array [] = { 3, 1, -3, 0, 4 };
	int array_size = sizeof (array) / sizeof (array[0]);
	
	/* Hier kommt das Ergebnis rein */
	int amin = 0;
	
	/* Funktion aufrufen */
	absmin (array_size, array, &amin);
	
	/* Ergebnis ausgeben */
	printf ("Minimum bei %d\n", amin);
	return 0;
}
