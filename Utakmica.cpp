#include "Utakmica.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
using std::cout;
using std::cin;
int Utakmica::brKosevaDomaci = 0;
int Utakmica::brKosevaGosti = 0;

Utakmica::Utakmica()
{
}

void Utakmica::setDatum()
{
	cout << "Unesite datum utakmice: ";
	cin.getline(this->datum, 15);
}

void Utakmica::setDomaci()
{
	cout << "Unos domacina:\n";
	cin >> this->domaci;
}

void Utakmica::setGosti()
{
	cout << "Unos gosta:\n";
	cin >> this->gosti;
}

char* Utakmica::getDatum()
{
	return this->datum;
}

Klub& Utakmica::getDomaci()
{
	return this->domaci;
}

Klub& Utakmica::getGosti()
{
	return this->gosti;
}

void Utakmica::operator++()
{
	srand(time(NULL));
	rand();
	int x = rand() % 4; //moguci broj poena
	if (x == 0) {
		cout << "--------------------------------\n";
		cout << this->getDomaci().getNaziv() << " "
			<< Utakmica::brKosevaDomaci << " : "
			<< Utakmica::brKosevaGosti << " "
			<< this->getGosti().getNaziv() << "\n";
		cout << "Izgubljena lopta " << this->getDomaci().getNaziv();
		cout << "\n--------------------------------\n";
	}
	else {
		Utakmica::brKosevaDomaci += x;
		cout << "--------------------------------\n";
		cout << this->getDomaci().getNaziv() << " "
			<< Utakmica::brKosevaDomaci << " : "
			<< Utakmica::brKosevaGosti << " "
			<< this->getGosti().getNaziv() << "\n";
		int y = rand() % 5;
		this->getDomaci().getIgraci()[y].setBrKoseva(x);
		cout << this->getDomaci().getIgraci()[y].getIme() << " "
			<< this->getDomaci().getIgraci()[y].getPrezime() << " "
			<< x << "p";
		cout << "\n--------------------------------\n";
	}
}

void Utakmica::operator++(int)
{
	srand(time(NULL));
	rand();
	int x = rand() % 4; //moguci broj poena
	if (x == 0) {
		cout << "--------------------------------\n";
		cout << this->getDomaci().getNaziv() << " "
			<< Utakmica::brKosevaDomaci << " : "
			<< Utakmica::brKosevaGosti << " "
			<< this->getGosti().getNaziv() << "\n";
		cout << "Izgubljena lopta " << this->getGosti().getNaziv();
		cout << "\n--------------------------------\n";
	}
	else {
		Utakmica::brKosevaGosti += x;
		cout << "--------------------------------\n";
		cout << this->getDomaci().getNaziv() << " "
			<< Utakmica::brKosevaDomaci << " : "
			<< Utakmica::brKosevaGosti << " "
			<< this->getGosti().getNaziv() << "\n";
		int y = rand() % 5;
		this->getGosti().getIgraci()[y].setBrKoseva(x);
		cout << this->getGosti().getIgraci()[y].getIme() << " "
			<< this->getGosti().getIgraci()[y].getPrezime() << " "
			<< x << "p";
		cout << "\n--------------------------------\n";
	}
}

void Utakmica::operator!()
{
	int max1 = INT_MIN, max2 = INT_MIN, indeks1=0, indeks2=0;
	for (int i = 0; i < this->getDomaci().getIgraci().size(); i++) {
		if (this->getDomaci().getIgraci()[i].getBrKoseva() > max1) {
			max1 = this->getDomaci().getIgraci()[i].getBrKoseva();
			indeks1 = i;
		}
	}
	for (int i = 0; i < this->getGosti().getIgraci().size(); i++) {
		if (this->getGosti().getIgraci()[i].getBrKoseva() > max2) {
			max2 = this->getGosti().getIgraci()[i].getBrKoseva();
			indeks2 = i;
		}
	}
	if (max1 > max2) {
		cout << "MVP utakmice je " << this->getDomaci().getIgraci()[indeks1] << " poena\n";
	}
	else if (max1 < max2) {
		cout << "MVP utakmice je " << this->getGosti().getIgraci()[indeks2] << " poena\n";
	}
	else {
		if (Utakmica::brKosevaDomaci > Utakmica::brKosevaGosti) {
			cout << "MVP utakmice je " << this->getDomaci().getIgraci()[indeks1] << " poena\n";
		}
		else {
			cout << "MVP utakmice je " << this->getGosti().getIgraci()[indeks2] << " poena\n";
		}
	}
}

std::istream& operator>>(std::istream& stream, Utakmica& u)
{
	u.setDatum();
	u.setDomaci();
	u.setGosti();
	return stream;
}

std::ostream& operator<<(std::ostream& stream, Utakmica& u)
{
	stream << "--------------------------------\n";
	stream << u.getDomaci().getNaziv() << " "
		<< Utakmica::brKosevaDomaci << " : "
		<< Utakmica::brKosevaGosti << " "
		<< u.getGosti().getNaziv() << "\n";
	stream << "--------------------------------\n";
	for (int i = 0; i < u.getDomaci().getIgraci().size(); i++) {
		stream << u.getDomaci().getIgraci()[i] << "\t\t"
			<< u.getGosti().getIgraci()[i] << "\n";
	}
	return stream;
}
