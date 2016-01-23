#include <iostream>

class Monster
{
	float leben;
	
public:

	//	frisches Monster beginnt mit 1.0 Leben
	Monster() : leben (1.0) {}
	
	void Treffer () 
	{
		//	Jeder Treffer kostet Lebenspunkte.
		if (leben > 0)
		{
			std::cout << "Monster: Aua!" << std::endl;
			leben -= 0.1;
		}
			
		std::cout << "Monster.leben: " << leben << std::endl;
	}
	
	bool Lebendig () const
	{
		//	wenn leben 0 oder kleiner wird,
		//	ist das Monster tot.
		return (leben > 0);
	}
};

class Mensch;
float Abstand (const Mensch & mensch, const Monster & monster);

class Mensch
{
	
public:

	void Angreifen (Monster & monster)
	{
		std::cout << "Zack!" << std::endl;
		//	Wenn der Abstand kleiner ist als 1 Meter,
		//	wird das Monster getroffen.
		if (Abstand (*this, monster) < 1.0)		
			monster.Treffer ();				
	}
};

float Abstand (const Mensch & mensch, const Monster & monster)
{
	//	Hier müssten irgendwie die Ortskoordinaten
	//	von Mensch und Monster ausgewertet und
	//	der Abstand berechnet werden.
	return 0.9;
}

int main ()
{
	Monster monster;
	Mensch mensch;
	
	while (monster.Lebendig ())
	{
		std::cout << "Monster lebt noch. Draufhauen!" << std::endl;
		mensch.Angreifen (monster);
		
		std::cout << std::endl;
	}
	std::cout << "Monster ist tot." << std::endl;
	
	return 0;
}
		
