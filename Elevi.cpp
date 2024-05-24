#include "Elevi.h"

Elevi::Elevi(int nrMatricol, string nume, string scoala)
{
	this->nrMatrico = nrMatricol;
	this->nume = nume;
	this->scoala = scoala;
}

int Elevi::get_nrMatricol()
{
	return this->nrMatrico;
}


string Elevi::get_nume()
{
	return this->nume;
}

string Elevi::get_scoala()
{
	return this->scoala;
}
