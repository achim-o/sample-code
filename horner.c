#include <stdio.h>

double horner (double x, int n, double * a)
{
	double y = 0;
	return y;
}

int main (void)
{
	/* Polynom definieren */
	double coeff [] = { 36, -13, 1 };  /* x^2 - 13 x + 36 */
	int n_coeff = sizeof (coeff) / sizeof (coeff[0]);
	
	/* Wertetabelle, x = 0 .. 9 */
	int i;
	for (i = 0; i < 10; i++)
	{
		/* Funktion horner aufrufen und Ergebnis speichern */
		double x = i;
		double y = horner (x, n_coeff, coeff);
		
		/* Tabelle ausgeben */
		printf ("x = %lf | y = %lf\n", x, y);
	}
	
	return 0; 
}
