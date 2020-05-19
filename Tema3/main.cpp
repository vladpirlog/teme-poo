#include "Regizor.h"
#include "Actor.h"
#include "Film.h"
#include "FirmaDistributie.h"
#include <set>
#include <tuple>

void citireSiAfisare()
{
	std::set<std::tuple<Persoana *, Film *, float>> structura;
	int n, opt;
	std::cout << "Introduceti nr de tupluri persoana-film-bonus: ";
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		std::cout << "Tuplul nr " << i << ":\n";
		std::cout << "Filmul:\n";
		Film *f = new Film;
		std::cin >> *f;
		std::cout << "Tipul de persoana(0=persoana, 1=actor, 2=regizor):\n";
		std::cin >> opt;
		if (opt == 0)
		{
			std::cout << "Persoana:\n";
			Persoana *p = new Persoana;
			std::cin >> *p;
			structura.insert(std::make_tuple(p, f, (*p).getBonus()));
		}
		else if (opt == 1)
		{
			std::cout << "Actor:\n";
			Actor *a = new Actor;
			std::cin >> *a;
			structura.insert(std::make_tuple(a, f, (*a).getBonus()));
		}
		else if (opt == 2)
		{
			std::cout << "Regizor:\n";
			Regizor *r = new Regizor;
			std::cin >> *r;
			structura.insert(std::make_tuple(r, f, (*r).getBonus()));
		}
		else
		{
			std::cout << "Optiune invalida.";
		}
	}
	std::set<std::tuple<Persoana *, Film *, float>>::iterator it = structura.begin();
	while (it != structura.end())
	{
		std::cout << "\n";
		if (dynamic_cast<Actor *>(std::get<0>(*it)) != nullptr)
		{
			std::cout << *(dynamic_cast<Actor *>(std::get<0>(*it)));
		}
		else if (dynamic_cast<Regizor *>(std::get<0>(*it)) != nullptr)
		{
			std::cout << *(dynamic_cast<Regizor *>(std::get<0>(*it)));
		}
		else
		{
			std::cout << *(std::get<0>(*it));
		}
		std::cout << "\n";

		std::cout << "\nFilmul:\n";
		std::cout << *(std::get<1>(*it));
		std::cout << "\nBonusul:\n";
		std::cout << std::get<2>(*it);
		std::cout << "\n\n";
		it++;
	}

	it = structura.begin();
	while (it != structura.end())
	{
		delete std::get<0>(*it);
		delete std::get<1>(*it);
		it++;
	}
}

int main()
{
	try
	{
		FirmaDistributie<Persoana> fd1;
		Persoana p1(1, "A", "afilm", 5);
		Persoana p2(3, "C", "cfilm", 3);
		Actor a1(2, "B", "bfilm", 6, true);
		Actor a2(4, "D", "dfilm", 6, false);
		Film f1("f1", "actiune", 120);
		fd1.adaugaPersoana(p1);
		fd1.adaugaPersoana(a1);
		fd1.adaugaPersoana(p2);
		fd1.adaugaPersoana(a2);
		fd1.adaugaFilm(f1);
		std::cout << fd1 << std::endl;

		FirmaDistributie<Actor> fd2;
		std::cin >> fd2;
		std::cout << fd2 << std::endl;

		citireSiAfisare();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
