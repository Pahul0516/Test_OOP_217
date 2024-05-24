#include "GUI.h"

gui::gui()
{
	gui_init();
	table_init();
	connect_init();
	load_data(contr.contr_get_repo_elevi().repo_get_list());
}


void gui::gui_init()
{
	this->setLayout(ly_main);

	ly_main->addWidget(lista);

	ly_main->addLayout(ly_text);
	ly_main->addLayout(ly_butoane);


	ly_text->addWidget(text_teme);
	ly_butoane->addWidget(bt);
	ly_butoane->addWidget(bt_t);





}

void gui::table_init()
{
	contr.populeaza_lista_elevi();
	contr.populeaza_lista_teme();
}

void gui::load_data(vector<Elevi> v)
{
	//repository repo = contr.contr_get_repo_elevi();
	lista->clear();
	for (auto e : v)
	{
		QListWidgetItem* item = new QListWidgetItem{ QString::fromStdString(e.get_nume()) + " " + QString::fromStdString(e.get_scoala()) };
		item->setData(Qt::UserRole, e.get_nrMatricol());
		lista->addItem(item);
	}
}


void gui::connect_init()
{
	connect(lista, &QListWidget::itemSelectionChanged, [&]() {
		auto sel = lista->selectedItems();
		if (!sel.isEmpty())
		{
			int id = sel[0]->data(Qt::UserRole).toInt();
			vector<string> v = contr.contr_get_teme_id(id);
			QString activitati;
			for (auto t : v)
			{
				activitati = activitati + QString::fromStdString(t) + " ";
			}
			text_teme->setText(activitati);
		}
		});

	connect(bt, &QPushButton::pressed, [&]() {
		text_teme->setText("");
		vector<Elevi> v = contr.contr_sort_nume();
		load_data(v);

		});

	connect(bt, &QPushButton::released, [&]() {
		load_data(contr.contr_get_repo_elevi().repo_get_list());
		});

	connect(bt_t, &QPushButton::released, [&]() {
		int maxi = -1;
		QWidget* w = new QWidget;
		QTableWidget* tabel = new QTableWidget;
		vector<Tema_elevi> lista = contr.contr_get_repo_teme().repo_get_list();
		tabel->setColumnCount(lista.size());
		tabel->setRowCount(lista.size());




		for (int i = 0; i < lista.size(); i++)
		{
			QTableWidgetItem* item = new QTableWidgetItem;
			item->setText(QString::fromStdString(lista[i].nume));
			item->setBackground(QBrush(Qt::blue));
			tabel->setItem(0, i, item);

			for (int j = 0; j < lista[i].nr_matricol.size(); j++)
			{

				if (j < maxi)
				{
					tabel->setRowCount(j + 1);
					maxi = j;
				}
				string nume = contr.contr_get_elev_nr_mat(lista[i].nr_matricol[j]);
				QTableWidgetItem* item = new QTableWidgetItem;
				item->setText(QString::fromStdString(nume));
				tabel->setItem(j + 1, i, item);
				
			}
			

		}

		QHBoxLayout* ly = new QHBoxLayout;
		ly->addWidget(tabel);
		w->setLayout(ly);
		w->resize(tabel->size());
		w->show();
		});


		
}