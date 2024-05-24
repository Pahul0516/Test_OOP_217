#pragma once
#include <string>

using std::string;

class Elevi
{
private:
	int nrMatrico;
	string nume;
	string scoala;

public:
	Elevi(int nrMatricol, string nume, string scoala);
	int get_nrMatricol();
	string get_nume();
	string get_scoala();

};

