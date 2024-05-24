#include "repository.h"

void repository::citire_fiser_elevi()
{
	string nrMatricol, nume, scoala;
	ifstream f("Elevi.txt");
	while (f >> nrMatricol)
	{
		f >> nume;
		f >> scoala;
		Elevi* ev = new Elevi{ stoi(nrMatricol), nume, scoala };
		this->lista_elevi.push_back(*ev);
		this->size++;
	}
	f.close();
}

int repository::repo_get_size()
{
	return this->size;
}

vector<Elevi>& repository::repo_get_list()
{
	return this->lista_elevi;
}




void repository_tema::citire_fiser_teme()
{
	string line;
	ifstream f("Teme.txt");
	while (getline(f, line))
	{
		string nume, nr;
		vector<int> v;
		stringstream ff(line);
		ff >> nume;
		while (ff >> nr)
		{
			v.push_back(stoi(nr));
		}
		Tema_elevi* t = new Tema_elevi{ nume,  v };
		this->lista_teme.push_back(*t);
		size++;

	}
}

int repository_tema::repo_get_size()
{
	return this->size;
}

vector<Tema_elevi>& repository_tema::repo_get_list()
{
	return this->lista_teme;
}
