#pragma once
#include <string>
#include <vector>

using std::string;
using std::vector;

class Tema_elevi
{
private:


public:
	string nume;
	vector<int> nr_matricol;
	Tema_elevi(string nume, vector<int>& v);

};

