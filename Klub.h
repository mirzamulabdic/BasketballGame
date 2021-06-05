#pragma once
#include <iostream>
#include <vector>
#include "Igrac.h"

class Klub
{
private:
	char naziv[30];
	std::vector<Igrac> igraci;
public:
	Klub();
	void setNaziv();
	void setIgraci();
	char* getNaziv();
	std::vector<Igrac>& getIgraci();
	friend std::istream& operator>>(std::istream& stream, Klub& k);
	friend std::ostream& operator<<(std::ostream& stream, Klub& k);
	~Klub() {};

};

