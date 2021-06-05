#pragma once
#include "Klub.h"
class Utakmica
{
private:
	char datum[15];
	Klub domaci, gosti;
	static int brKosevaDomaci, brKosevaGosti;
public:
	Utakmica();
	void setDatum();
	void setDomaci();
	void setGosti();
	char* getDatum();
	Klub& getDomaci();
	Klub& getGosti();
	friend std::istream& operator>>(std::istream& stream, Utakmica& u);
	friend std::ostream& operator<<(std::ostream& stream, Utakmica& u);
	void operator++();
	void operator++(int);
	void operator!();
	bool provjera() {
		if (Utakmica::brKosevaDomaci == Utakmica::brKosevaGosti) {
			return true;
		}
		else {
			return false;
		}
	}
	~Utakmica() {};
};

