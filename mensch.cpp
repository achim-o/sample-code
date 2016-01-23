
#include <time.h>
#include <string>

class Mensch
{
	time_t geburtsdatum;
	std::string name;
	
public:

	Mensch (const std::string & name_) : geburtsdatum (time(0)), name (name_) {}

	time_t Alter () const { return time(0) - geburtsdatum; }
};

#include <iostream>
int main ()
{
	Mensch willi ("Willi"); // Willi wird geboren
	
	std::cout << "Bitte warten und dann 0 und ENTER drücken" << std::endl;
	int x;
	std::cin >> x;
	
	std::cout << "Willi ist jetzt " << willi.Alter () << " Sekunden alt" << std::endl;
	return 0;
}

