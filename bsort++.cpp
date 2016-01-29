#include <vector>
#include <iostream> 

class IComparable
{
public:
	enum ECompareResult
	{
		CompareLess = -1
		, CompareEqual
		, CompareGreater
	};
	
	virtual ECompareResult Compare (const IComparable & other) const = 0;
};

void bsort (std::vector<IComparable*> a);

template <typename T>
void bsort (std::vector<T> & array, int (*compare) (const T& a, const T & b))
{
	int index = 0;
	do
	{
		//~ std::cerr << "compare " << index << ": " << array[index] << " and " << array[index+1] << std::endl;
		int comparison = compare (array[index], array[index+1]);
		if (comparison > 0)
		{
			T c = array[index];
			array[index] = array[index+1];
			array[index+1] = c;
			index = 0;
			continue;
		}
		index++;
	} while (index < array.size () - 1);
}

template <typename T>
int comp (const T & a, const T & b)
{
	//~ std::cerr << "comp: " << a << ((a>b)?">":"<=") << b << std::endl;
	return (a - b);
}

template <typename T>
static void _display (const std::vector<T> & array)
{
	for (typename std::vector<T>::const_iterator it = array.cbegin(); it != array.cend(); it++)
		std::cout << " " << *it;
		
	std::cout << std::endl;
}

int main (void)
{
	
	//~ std::vector<int> v = { 6, 2, 1, 4, 3, 5 };
	std::vector<double> v = { 6.1, 2.1, 1.1, 4.1, 3.1, 5.1 };
	
	
	_display (v);
	bsort (v, comp);
	_display (v);
	
} 
