#include <math.h>
#include <iostream>
#include <time.h>
#include <unistd.h>

class FirstOrderDynamic
{
	double T;
	time_t start;
	
public:

	FirstOrderDynamic (double T_) : T(T_), start (time(0)) {}
	
	double Value (double t) { return exp (-(t-start)/T); }
};

#ifdef TEST_MAIN
int main ()
{
	FirstOrderDynamic fod (10);
	for (int i = 0; i < 60; i++)
	{
		std::cout << "\t" << i << "\t" << fod.Value (time(0)) << std::endl;
		sleep (1);
	}
	return 0;
}
#endif
