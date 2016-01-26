
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
	int comparison = 0;
	int index = 0;
	do 
	{
		char * a = array;
		char * b = array;
		a += (index * size);
		b = a + size;
//		printf ("a %d, b %d\n", *(int*) a, *(int*) b);
		
		comparison = compare (a, b);
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

void _display (const int * data, int len)
{
	int i;
	for (i = 0; i < len; i++)
		printf ("%d ", data[i]);
	printf ("\n");
}

int main (void)
{
	int data [] = { 6, 2, 1, 3, 5, 4 };
	int dataLength = sizeof (data) / sizeof (data[0]);
	
	_display (data, dataLength);
	
	bsort (data, dataLength, sizeof (data[0]), compare_int);
	
	_display (data, dataLength);
	
	return 0;
}
	
	
	
