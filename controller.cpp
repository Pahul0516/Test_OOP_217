#include "controller.h"

repository& controller::contr_get_repo_elevi()
{
	return this->repo;
}

repository_tema& controller::contr_get_repo_teme()
{
	return this->repo2;
}




void controller::populeaza_lista_elevi()
{
	this->repo.citire_fiser_elevi();
}


void controller::populeaza_lista_teme()
{
	this->repo2.citire_fiser_teme();
}


vector<string> controller::contr_get_teme_id(int id)
{
	vector<string> lista;
	auto v = this->contr_get_repo_teme().repo_get_list();
	for (auto t : v)
	{
		for (int nr_mat : t.nr_matricol)
		{
			if (nr_mat == id)
			{
				lista.push_back(t.nume);
			}
		}
	}
	return lista;
}


vector<string> controller::contr_get_teme()
{
	vector<string> lista;

	for (auto it : repo2.repo_get_list())
	{
		lista.push_back(it.nume);
	}
	return lista;
}


vector<Elevi> controller::contr_sort_nume()
{
	vector<Elevi> lista_sortata;
	vector<Elevi> lista_de_sortat;

	lista_de_sortat = this->contr_get_repo_elevi().repo_get_list();

	copy(lista_de_sortat.begin(), lista_de_sortat.end(), back_inserter(lista_sortata));
	sort(lista_sortata.begin(), lista_sortata.end(), []( Elevi& elev1,  Elevi& elev2) {
		return elev1.get_nume() < elev2.get_nume();
		});
	return lista_sortata;
}

string controller::contr_get_elev_nr_mat(int Id)
{
	vector<Elevi> l = repo.repo_get_list();

	auto it = find_if(l.begin(), l.end(), [&](Elevi v) {
		return v.get_nrMatricol() == Id;
		});

	return (*it).get_nume();
}


