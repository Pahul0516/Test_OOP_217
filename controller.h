#pragma once

#include "repository.h"
#include <algorithm>

class controller
{

private:

	repository repo;
	repository_tema repo2;

public:

	repository& contr_get_repo_elevi();
	repository_tema& contr_get_repo_teme();

	string contr_get_elev_nr_mat(int Id);

	vector<Elevi> contr_sort_nume();

	vector<string> contr_get_teme_id(int id);

	vector<string> contr_get_teme();




	void populeaza_lista_elevi();
	void populeaza_lista_teme();

};