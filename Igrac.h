#pragma once
#include <iostream>
enum Pozicija { PG = 1, SG, SF, F, C};

class Igrac
{
private:
	char ime[30], prezime[30];
	int brKoseva;
	Pozicija pozicija;
public:
	Igrac();
	Igrac(const char* i, const char* p, int b, Pozicija po);
	void setIme();
	void setPrezime();
	void setBrKoseva(int a);
	void setPozicija();
	char* getIme();
	char* getPrezime();
	int getBrKoseva();
	Pozicija getPozicija();
	friend std::istream& operator>>(std::istream& stream, Igrac& i);
	friend std::ostream& operator<<(std::ostream& stream, Igrac& i);
	~Igrac() {};
};

