#include "Klub.h"
#include <iostream>
using std::cout;
using std::cin;

Klub::Klub()
{
}

void Klub::setNaziv()
{
	cout << "Unesite naziv kluba: ";
	cin.getline(this->naziv, 30);
}

void Klub::setIgraci()
{
	Igrac temp;
	for (int i = 0; i < 5; i++) {
		cout << "Igrac br. " << i + 1 << ":\n";
		cin >> temp;
		this->igraci.push_back(temp);
	}
}

char* Klub::getNaziv()
{
	return this->naziv;
}

std::vector<Igrac>& Klub::getIgraci()
{
	return this->igraci;
}

std::istream& operator>>(std::istream& stream, Klub& k)
{
	k.setNaziv();
	k.setIgraci();
	return stream;
}

std::ostream& operator<<(std::ostream& stream, Klub& k)
{
	stream << k.getNaziv() << "\n";
	for (int i = 0; i < k.getIgraci().size(); i++) {
		stream << "\t" << k.getIgraci()[i] << "\n";
	}
	return stream;
}
