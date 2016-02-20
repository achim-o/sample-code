#include <stdio.h>

/*
 * horner:
 * x: die zu untersuchende Stelle
 * n: Grad des Polynoms (höchste vorkommende Potenz)
 * a: Vektor der Koeffizienten. Die Länge ist um 1 größer als der Grad!
 */
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
	
	/*
	 * Achtung: n_coeff ist um 1 höher als der Grad des Polynoms!
	 * Das wird in der Variablen grade berücksichtigt.
	 */
	 int grade = n_coeff - 1;
	
	/* Wertetabelle, x = 0 .. 9 */
	int i;
	for (i = 0; i < 10; i++)
	{
		/* Funktion horner aufrufen und Ergebnis speichern */
		double x = i;
		double y = horner (x, grade, coeff);
		
		/* Tabelle ausgeben */
		printf ("x = %lf | y = %lf\n", x, y);
	}
	
	return 0; 
}
