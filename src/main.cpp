#include <stdio.h>
#include "bank.hpp"

using namespace std;

void show_events (Bank *bk)
{
	vector <Event> *eve;
	int             eve_count;

	eve       = bk->get_events();
	eve_count = bk->get_event_count();

	printf ("Eventos\n");

	for (int i = 0; i < eve_count; i++)
	{
		printf ("  %i. %s\n", i+1, (*eve)[i].get_name().c_str());
		printf ("       %s\n"  , (*eve)[i].get_hour().c_str());
		printf ("       %s\n"  , (*eve)[i].get_date().c_str());
		printf ("       %s\n\n", (*eve)[i].get_address().c_str());
	}
}

void dialog_add_event (Bank *bk)
{
	char name[40];
	char address[40];
	char hour[8];
	char date[12];

	printf ("Nuevo Evento\n");
	printf ("  >> (Nombre) ");
	scanf  ("%s", &name);

	printf ("  >> (Dirección) ");
	scanf  ("%s", &address);

	printf ("  >> (Hora) ");
	scanf  ("%s", &hour);

	printf ("  >> (Fecha) ");
	scanf  ("%s", &date);

	bk -> add_event (name, address, hour, date);
}

void dialog_remove_event (Bank *bk)
{
	int eve_count = bk -> get_event_count();
	int id;

	printf ("Eliminar Evento\n");
	printf ("  >> (Evento ID) ");
	scanf  ("%i", &id);
	id--;

	if (id >= 0 && id < eve_count)
		bk->remove_event (id);
}

int main()
{

	Bank bk = *(new Bank);
	string name;
	string address;
	string hour;
	string date;

	name    = "Parcial_Analisis";
	address = "B202";
	hour    = "2:00 PM";
	date    = "10-11-2021";
	bk.add_event (name, address, hour, date);

	name    = "Cumpleaños_Mario";
	address = "Cll 10 #24-20";
	hour    = "7:30 PM";
	date    = "02-10-2021";
	bk.add_event (name, address, hour, date);

	//inputs
	int sel;

	do
	{
		//clear console
        printf ("%s", string( 100, '\n' ).c_str());
		show_events (&bk);

		printf ("Menu\n");
		printf ("  1. Agregar evento\n");
		printf ("  2. Eliminar evento\n");
		printf ("  3. Salir\n");
		printf (">> ");
		scanf  ("%i", &sel);
		sel --;

		//action
		switch (sel)
		{
		case 0: //add
			printf ("%s", string( 100, '\n' ).c_str());
			show_events (&bk);
			dialog_add_event (&bk);
			break;

		case 1: //remove
			printf ("%s", string( 100, '\n' ).c_str());
			show_events (&bk);
			dialog_remove_event (&bk);
			break;

		case 2: //exit
			return 0;
		}
	}
	while (sel != -2);

	return 0;
}
