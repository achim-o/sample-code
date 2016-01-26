
#include <vector>

class IComparable
{
public:
	enum ECompareResult
	{
		CompareLess
		, CompareEqual
		, CompareGreater
	};
	
	ECompareResult Compare (const IComparable & other) const = 0;
};

int bsort (std::vector<IComparable*> a);
