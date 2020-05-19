#ifndef FIRMA_DISTRIBUTIE_H
#define FIRMA_DISTRIBUTIE_H

#include "Actor.h"
#include "Film.h"

template <typename T>
class FirmaDistributie
{
private:
	int nrPersoane;
	int nrFilme;
	int nrActori;
	T *persoane;
	Film *filme;

public:
	FirmaDistributie() : nrPersoane(0), nrFilme(0), nrActori(0)
	{
		this->filme = new Film[0];
		this->persoane = new T[0];
	}

	FirmaDistributie(int nrPersoane, int nrFilme, T *persoane, Film *filme) : nrPersoane(nrPersoane), nrFilme(nrFilme)
	{
		this->nrActori = 0;
		this->filme = new Film[nrFilme];
		for (int i = 0; i < nrFilme; ++i)
			this->filme[i] = filme[i];

		this->persoane = new T[nrPersoane];
		Actor tmp;
		for (int i = 0; i < nrPersoane; ++i)
		{
			if (dynamic_cast<Actor *>(&(persoane[i])) != nullptr)
			{
				++this->nrActori;
			}
			this->persoane[i] = persoane[i];
		}
	}

	FirmaDistributie(const FirmaDistributie<T> &fd)
	{
		this->nrFilme = fd.nrFilme;
		this->filme = new Film[this->nrFilme];
		for (int i = 0; i < this->nrFilme; ++i)
			this->filme[i] = fd.filme[i];

		this->nrPersoane = fd.nrPersoane;
		this->persoane = new T[this->nrPersoane];
		for (int i = 0; i < this->nrPersoane; ++i)
			this->persoane[i] = fd.persoane[i];

		this->nrActori = fd.nrActori;
	}

	virtual ~FirmaDistributie()
	{
		delete[] filme;
		delete[] persoane;
	}

	void adaugaPersoana(T &p)
	{
		T *aux = new T[this->nrPersoane + 1];
		std::copy(this->persoane, this->persoane + this->nrPersoane, aux);
		aux[this->nrPersoane] = p;
		++this->nrPersoane;
		if (dynamic_cast<Actor *>(&p) != nullptr)
		{
			++this->nrActori;
		}
		delete[] this->persoane;
		this->persoane = aux;
	}

	void adaugaFilm(const Film &f)
	{
		Film *aux = new Film[this->nrFilme + 1];
		std::copy(this->filme, this->filme + this->nrFilme, aux);
		aux[this->nrFilme] = f;
		++this->nrFilme;
		delete[] this->filme;
		this->filme = aux;
	}

	FirmaDistributie &operator=(const FirmaDistributie<T> &fd)
	{
		this->nrFilme = fd.nrFilme;
		this->filme = new Film[this->nrFilme];
		for (int i = 0; i < this->nrFilme; ++i)
			this->filme[i] = fd.filme[i];

		this->nrPersoane = fd.nrPersoane;
		this->persoane = new T[this->nrPersoane];
		for (int i = 0; i < this->nrPersoane; ++i)
			this->persoane[i] = fd.persoane[i];
		this->nrActori = fd.nrActori;

		return *this;
	}

	friend std::istream &operator>>(std::istream &is, FirmaDistributie<T> &fd)
	{
		try
		{
			std::string n;
			std::cout << "Introduceti nr de entitati(persoane, actori, regizor): ";
			is >> n;
			fd.nrActori = 0;
			fd.nrPersoane = std::stoi(n);
			fd.persoane = new T[fd.nrPersoane];
			for (int i = 0; i < fd.nrPersoane; ++i)
			{
				is >> fd.persoane[i];
				if (dynamic_cast<Actor *>(&(fd.persoane[i])) != nullptr)
				{
					++fd.nrActori;
				}
			}
			std::cout << "Introduceti nr de filme: ";
			is >> n;
			fd.nrFilme = std::stoi(n);
			fd.filme = new Actor[fd.nrFilme];
			for (int i = 0; i < fd.nrFilme; ++i)
			{
				is >> fd.filme[i];
			}
			return is;
		}
		catch (const std::invalid_argument &e)
		{
			throw(InvalidType());
		}
	}
	friend std::ostream &operator<<(std::ostream &os, const FirmaDistributie<T> &fd)
	{
		os << "Nr persoane: " << fd.nrPersoane << "\n";
		for (int i = 0; i < fd.nrPersoane; ++i)
		{
			os << fd.persoane[i];
		}
		os << "Nr filme: " << fd.nrFilme << "\n";
		for (int i = 0; i < fd.nrFilme; ++i)
		{
			os << fd.filme[i];
		}
		os << "Nr actori: " << fd.nrActori << "\n";
		return os;
	}
};

template <>
class FirmaDistributie<Actor>
{
private:
	int nrPersoane;
	int nrFilme;
	int nrActoriPrincipali;
	Actor *persoane;
	Film *filme;

public:
	FirmaDistributie() : nrPersoane(0), nrFilme(0), nrActoriPrincipali(0)
	{
		this->filme = new Film[0];
		this->persoane = new Actor[0];
	}

	FirmaDistributie(int nrPersoane, int nrFilme, Actor *persoane, Film *filme) : nrPersoane(nrPersoane), nrFilme(nrFilme)
	{
		this->nrActoriPrincipali = 0;
		this->filme = new Film[nrFilme];
		for (int i = 0; i < nrFilme; ++i)
			this->filme[i] = filme[i];

		this->persoane = new Actor[nrPersoane];
		for (int i = 0; i < nrPersoane; ++i)
		{
			if (persoane[i].estePersonajPrincipal())
			{
				++nrActoriPrincipali;
			}
			this->persoane[i] = persoane[i];
		}
	}

	FirmaDistributie(const FirmaDistributie<Actor> &fd)
	{
		this->nrFilme = fd.nrFilme;
		this->filme = new Film[this->nrFilme];
		for (int i = 0; i < this->nrFilme; ++i)
			this->filme[i] = fd.filme[i];

		this->nrPersoane = fd.nrPersoane;
		this->persoane = new Actor[this->nrPersoane];
		for (int i = 0; i < this->nrPersoane; ++i)
			this->persoane[i] = fd.persoane[i];

		this->nrActoriPrincipali = fd.nrActoriPrincipali;
	}

	virtual ~FirmaDistributie()
	{
		delete[] filme;
		delete[] persoane;
	}

	void adaugaActor(Actor &a)
	{
		Actor *aux = new Actor[this->nrPersoane + 1];
		std::copy(this->persoane, this->persoane + this->nrPersoane, aux);
		aux[this->nrPersoane] = a;
		++this->nrPersoane;
		if (a.estePersonajPrincipal())
			++this->nrActoriPrincipali;
		delete[] this->persoane;
		this->persoane = aux;
	}

	void adaugaFilm(Film &f)
	{
		Film *aux = new Film[this->nrFilme + 1];
		std::copy(this->filme, this->filme + this->nrFilme, aux);
		aux[this->nrFilme] = f;
		++this->nrFilme;
		delete[] this->filme;
		this->filme = aux;
	}

	FirmaDistributie &operator=(const FirmaDistributie<Actor> &fd)
	{
		this->nrFilme = fd.nrFilme;
		this->filme = new Film[this->nrFilme];
		for (int i = 0; i < this->nrFilme; ++i)
			this->filme[i] = fd.filme[i];

		this->nrPersoane = fd.nrPersoane;
		this->persoane = new Actor[this->nrPersoane];
		for (int i = 0; i < this->nrPersoane; ++i)
			this->persoane[i] = fd.persoane[i];
		this->nrActoriPrincipali = fd.nrActoriPrincipali;
		return *this;
	}

	friend std::istream &operator>>(std::istream &is, FirmaDistributie<Actor> &fd)
	{
		try
		{
			std::string n;
			std::cout << "Introduceti nr de actori: ";
			is >> n;
			fd.nrPersoane = std::stoi(n);
			fd.persoane = new Actor[fd.nrPersoane];
			for (int i = 0; i < fd.nrPersoane; ++i)
			{
				is >> fd.persoane[i];
				if (fd.persoane[i].estePersonajPrincipal())
					++fd.nrActoriPrincipali;
			}
			std::cout << "Introduceti nr de filme: ";
			is >> n;
			fd.nrFilme = std::stoi(n);
			fd.filme = new Film[fd.nrFilme];
			for (int i = 0; i < fd.nrFilme; ++i)
			{
				is >> fd.filme[i];
			}
			return is;
		}
		catch (const std::invalid_argument &e)
		{
			throw(InvalidType());
		}
	}
	friend std::ostream &operator<<(std::ostream &os, const FirmaDistributie<Actor> &fd)
	{
		os << "\nAFISARE FIRMA DISTRIBUTIE\nNr actori: " << fd.nrPersoane << ", din care principali: " << fd.nrActoriPrincipali << "\n";
		for (int i = 0; i < fd.nrPersoane; ++i)
		{
			os << fd.persoane[i];
		}
		os << "Nr filme: " << fd.nrFilme << "\n";
		for (int i = 0; i < fd.nrFilme; ++i)
		{
			os << fd.filme[i];
		}
		return os;
	}
};

#endif // FIRMA_DISTRIBUTIE_H
