#include "teste.h"

void rulare_teste()
{
	test_elevi();
	test_repo();
	test_contr();
}

void test_elevi()
{
	Elevi* e = new Elevi{ 1, "Irimia", "aici" };
	assert(e->get_nrMatricol() == 1);
	assert(e->get_nume() == "Irimia");
	assert(e->get_scoala() == "aici");
}

void test_repo()
{
	repository* r = new repository;
	r->citire_fiser_elevi();
	assert(r->repo_get_size() == 4);
	vector<Elevi> l = r->repo_get_list();
	assert(l.size() != 0);


	repository_tema* r2 = new repository_tema;
	r2->citire_fiser_teme();
	assert(r2->repo_get_size() == 4);
	vector<Tema_elevi> l2 = r2->repo_get_list();
	assert(l2.size() != 0);
}

void test_contr()
{
	controller contr;

	contr.populeaza_lista_elevi();
	contr.populeaza_lista_teme();

	assert(contr.contr_get_repo_elevi().repo_get_size() == 4);
	assert(contr.contr_get_repo_teme().repo_get_size() == 4);

	string nume = contr.contr_get_elev_nr_mat(1);
	assert(nume == "Paul");

	auto l = contr.contr_get_teme();
	assert(l.size() == 4);

	auto l2 = contr.contr_get_teme_id(2);
	assert(l2.size() == 2);

}
