#include "Regizor.h"

Regizor::Regizor() : Persoana(), sumaFixa(0) {}

Regizor::Regizor(int cnp,
				 std::string nume,
				 std::string numeFilm,
				 float procentIncasari,
				 float sumaFixa) : Persoana(cnp,
											nume,
											numeFilm,
											procentIncasari),
								   sumaFixa(sumaFixa) {}

Regizor::Regizor(const Regizor &r) : Persoana(static_cast<Persoana>(r)), sumaFixa(r.sumaFixa)
{
}

Regizor &Regizor::operator=(const Regizor &r)
{
	this->cnp = r.cnp;
	this->nume = r.nume;
	this->numeFilm = r.numeFilm;
	this->procentIncasari = r.procentIncasari;
	this->sumaFixa = r.sumaFixa;
	return *this;
}

float Regizor::getBonus() const
{
	return this->procentIncasari + this->sumaFixa;
}

void Regizor::afisare()
{
	std::cout << "Regizor:\n";
	static_cast<Persoana>(*this).afisare();
	std::cout << "Suma fixa din incasari: " << this->sumaFixa << "\n";
}

std::istream &operator>>(std::istream &is, Regizor &r)
{
	is >> static_cast<Persoana &>(r);
	try
	{
		std::string n;
		std::cout << "Suma fixa din incasari: ";
		is >> n;
		r.sumaFixa = std::stof(n);
		return is;
	}
	catch (std::invalid_argument &e)
	{
		throw(InvalidType());
	}
}

std::ostream &operator<<(std::ostream &os, const Regizor &r)
{
	os << "Regizor:\n";
	os << (Persoana &)r;
	os << "Suma fixa din incasari: " << r.sumaFixa << "\n";
	return os;
}
