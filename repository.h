#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Elevi.h"
#include "Tema_elevi.h"

using std::vector;
using std::ifstream;
using std::stringstream;
using namespace std;
using std::getline;

class repository
{

private:

	int size;
	vector<Elevi> lista_elevi;

public:

	int repo_get_size();
	vector<Elevi>& repo_get_list();
	void citire_fiser_elevi();
};


class repository_tema
{

private:

	int size;
	vector<Tema_elevi> lista_teme;

public:

	int repo_get_size();
	vector<Tema_elevi>& repo_get_list();
	void citire_fiser_teme();
};

