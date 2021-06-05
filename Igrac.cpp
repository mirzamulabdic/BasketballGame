#include "Igrac.h"
#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;

Igrac::Igrac()
{
	strcpy_s(this->ime, "Niko");
	strcpy_s(this->prezime, "Nikic");
	this->brKoseva = 0;
	this->pozicija = PG;
}

Igrac::Igrac(const char* i, const char* p, int b, Pozicija po)
{
	strcpy_s(this->ime, i);
	strcpy_s(this->prezime, p);
	this->brKoseva = b;
	this->pozicija = po;
}

void Igrac::setIme()
{
	cout << "Unesite ime igraca: ";
	cin.getline(this->ime, 30);
}

void Igrac::setPrezime()
{
	cout << "Unesite prezime igraca: ";
	cin.getline(this->prezime, 30);
}

void Igrac::setBrKoseva(int a)
{
	this->brKoseva += a;
}

void Igrac::setPozicija()
{
	int x;
	do {
		cout << "Unesite poziciju igraca: (1,2,3,4 ili 5): ";
		cin >> x;
		cin.ignore();
	} while (x < 1 || x>5);
	this->pozicija = Pozicija(x);
}

char* Igrac::getIme()
{
	return this->ime;
}

char* Igrac::getPrezime()
{
	return this->prezime;
}

int Igrac::getBrKoseva()
{
	return this->brKoseva;
}

Pozicija Igrac::getPozicija()
{
	return this->pozicija;
}

std::istream& operator>>(std::istream& stream, Igrac& i)
{
	i.setIme();
	i.setPrezime();
	i.setPozicija();
	return stream;
}

std::ostream& operator<<(std::ostream& stream, Igrac& i)
{
	switch (i.getPozicija()) {
		case PG:
			stream << std::setw(2) << std::setfill(' ') << std::right << "PG";
			break;
		case SG:
			stream << std::setw(2) << std::setfill(' ') << std::right << "SG";
			break;
		case SF:
			stream << std::setw(2) << std::setfill(' ') << std::right << "SF";
			break;
		case F:
			stream << std::setw(2) << std::setfill(' ') << std::right << "F";
			break;
		case C:
			stream << std::setw(2) << std::setfill(' ') << std::right << "C";
			break;
		default:
			cout << "Ovo bezveze pisemo :)";
	}
	stream << " " << i.getIme() << " " << i.getPrezime() << "\t" << i.getBrKoseva();
	return stream;
}
