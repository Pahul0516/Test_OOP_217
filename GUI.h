#pragma once
#include <qwidget.h>
#include <qlayout.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qstring.h>
#include <qpushbutton.h>
#include <qobject.h>
#include <qtablewidget.h>
#include <qlayout.h>
#include <qbrush.h>

#include "controller.h"

class gui : public QWidget
{
private:
	controller contr;

	QWidget* w = new QWidget;

	QVBoxLayout* ly_main = new QVBoxLayout;
	QHBoxLayout* ly_text = new QHBoxLayout;
	QHBoxLayout* ly_butoane = new QHBoxLayout;	

	QListWidget* lista = new QListWidget;
	QLineEdit* atelier = new QLineEdit;

	QPushButton* bt = new QPushButton{ "Sortare nume" };
	QPushButton* bt_t = new QPushButton{ "Afisare tabel" };



	QLineEdit* text_teme = new QLineEdit;

	vector<Elevi>& elevi_ini = contr.contr_get_repo_elevi().repo_get_list();;

	void gui_init();
	void table_init();
	void connect_init();
	void load_data(vector<Elevi> lista);

public:
	gui();
};