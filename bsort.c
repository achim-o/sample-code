
#include <alloca.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void _swap (void * a, void * b, int size)
{
	void * c = alloca (size);
	memcpy (c, a, size);
	memcpy (a, b, size);
	memcpy (b, c, size);
}

void bsort (void * array, int len, int size, int (*compare) (const void * a, const void * b))
{
	//~ int comparison = 0;
	int index = 0;
	do 
	{
		char * a = (char *) array + index * size;
		char * b = a + size;
		//~ a += (index * size);
		//~ b = a + size;
//		printf ("a %d, b %d\n", *(int*) a, *(int*) b);
		
		int comparison = compare (a, b);
		if (comparison > 0)
		{
//			printf ("swap %d %d\n", *(int*) a, *(int*) b);
			_swap (a, b, size);
			index = 0;
			continue;
		}		
		
		index++;
	} while (index < (len - 1));
}


int compare_int (const void * a, const void * b)
{
	// positive if a > b, negative if a < b
	return (*(const int*) a - *(const int*) b);	
}

int compare_double (const void * a, const void * b)
{
	return (*(const double*) a - *(const double*) b);	
}

static void _display_int (const int * data, int len)
{
	int i;
	for (i = 0; i < len; i++)
		printf ("%d ", data[i]);
	printf ("\n");
}

static void _display_double (const double * data, int len)
{
	int i;
	for (i = 0; i < len; i++)
		printf ("%lf ", data[i]);
	printf ("\n");
}

int main (void)
{
	// data [] = { 6, 2, 1, 3, 5, 4 };
	double data [] = { 0, 10.0, 3.8, -5.9, 1.1, -4, -200 };
	int dataLength = sizeof (data) / sizeof (data[0]);
	
	_display_double (data, dataLength);
	
	bsort (data, dataLength, sizeof (data[0]), compare_double);
	
	_display_double (data, dataLength);
	
	return 0;
}
	
	
	
