
#include <stdio.h>
#include <iostream>
#include <string>

#include "inventory.hpp"

using namespace std;

void
print_inventory_items (Inventory* inv)
{
	//list products
	printf ("\nProductos\n");

	Item            *it;
	vector <Item>    items   = (*inv).get_items();
	vector <string>  invtags = (*inv).get_tags();
	vector <int>     itemtags;
	string           strtags;

	for (int i = 0; i < items.size(); i++)
	{
		it       = &items[i];
		itemtags = it->get_tags ();
		strtags  = "";

		for (int j = 0; j < itemtags.size(); j++)
		{
			if (invtags[itemtags[j]] != "")
				strtags += invtags[itemtags[j]] + ", ";
		}

		//remove last comma
		strtags = strtags.substr (0, strtags.size() - 2);

		printf ("  %i. %s\n"       , i+1, it->get_name().c_str()); //name
		printf ("     %i $\n"      , it->get_value()); //value
		printf ("     tags: %s\n\n", strtags.c_str()); //tags
	}
}

void
print_inventory_only_tags (Inventory* inv)
{
	//list tags
	printf ("Categorias\n");

	vector <string>  invtags = (*inv).get_tags();

	for (int i = 0; i < invtags.size(); i++)
	{
		if (invtags[i] != "")
			printf ("  %i. %s\n", i+1, invtags[i].c_str()); //tag name
	}
}

void
print_inventory_tags (Inventory* inv)
{
	//list tags
	printf ("\nCategorias\n");

	vector <string>  invtags = (*inv).get_tags();
	vector <Item>    items   = (*inv).get_items();
	vector <int>     itemtags;
	Item            *it;
	string           stritems;
	bool			 tagfound;


	for (int i = 0; i < invtags.size(); i++)
	{

		if (invtags[i] != "")
		{
			stritems = "";

			for (int j = 0; j < items.size(); j++)
			{
				tagfound = false;
				it       = &items[j];
				itemtags = it->get_tags();

				for (int k = 0; k < itemtags.size(); k++)
				{
					if (itemtags[k] == i){
						tagfound = true;
						break;
					}
				}

				if (tagfound)
					stritems += it->get_name() + ", ";
			}

			//remove last comma
			stritems = stritems.substr (0, stritems.size() - 2);

			printf ("  %i. %s\n", i+1, invtags[i].c_str()); //tag name
			printf ("     %s\n\n", stritems.c_str()); //items
		}

	}

}

void
dialog_add_item (Inventory* inv)
{
	Item* it;

	char         namechar[40];
	string       name;

	int          value;

	int              tagid;
	vector <int>     tags;
	vector <string>  invtags = (*inv).get_tags();
	unordered_map <string, int> nametags = (*inv).get_tag_name_id();


	printf ("\nNuevo producto\n");

	//get name
	printf ("  >> (Nombre) ");
	scanf  ("%s", &namechar);
	name = namechar;

	//get value
	printf ("  >> (Precio) ");
	scanf  ("%i", &value);

	//create item
	it = new Item (name, value);

	//add tags
	printf ("\n  ");
	print_inventory_only_tags (inv);
	printf ("\n  Agregar categoria. -1 para terminar.");

	do
	{
		printf ("\n  >> (Categoria ID) ");
		scanf  ("%i", &tagid);
		tagid--;

		if (tagid >= 0 && tagid < invtags.size())
		{
			//printf ("  Agregado: %s %i\n", invtags[tagid].c_str(), nametags[invtags[tagid].c_str()]);

			printf ("  Agregado: %s \n", invtags[tagid].c_str());
			it->add_tag (nametags[invtags[tagid].c_str()]);
		}
	}
	while (tagid != -2);

	//add to invetory
	(*inv).add_item (*it);
}

void
dialog_delete_item (Inventory* inv)
{
	int itemid;

	printf ("\nEliminar Producto:\n");

	printf ("  >> (Producto ID) ");
	scanf  ("%i", &itemid);

	inv->remove_item (itemid-1);
}

void
dialog_add_tag (Inventory* inv)
{
	char   namechar[40];
	string name;

	printf ("\nAgregar Categoria:\n");

	printf ("  >> (Nombre) ");
	scanf  ("%s", &namechar);
	name = namechar;

	inv->add_tag (name);
}

void
dialog_delete_tag (Inventory* inv)
{
	int tagid;
	vector <string>             invtags  = (*inv).get_tags();
	unordered_map <string, int> nametags = (*inv).get_tag_name_id();

	printf ("\nEliminar Categoria:\n");

	printf ("  >> (Categoria ID) ");
	scanf  ("%i", &tagid);
	tagid--;

	inv->remove_tag (nametags[invtags[tagid].c_str()]);
}

int
main()
{
	//start inventory
	Inventory inv = *(new Inventory());

	//add tags
	int t_comida = inv.add_tag ("Comida");
	int t_aseo   = inv.add_tag ("Aseo");
	int t_elect  = inv.add_tag ("Electronico");

	//add items
	Item *it;

	it = new Item("Cebolla", 500);
	it->add_tag (t_comida);
	inv.add_item (*it);

	it = new Item("Aspiradora_Electrica", 119950);
	it->add_tag (t_aseo);
	it->add_tag (t_elect);
	inv.add_item (*it);

	it = new Item("Licuadora", 61500);
	it->add_tag (t_comida);
	it->add_tag (t_elect);
	inv.add_item (*it);


	//CLI
	int menu = 0;
	int sel;
	string str;

	do
	{

		//clear console
		printf ("%s", string( 100, '\n' ).c_str());

		//print
		switch (menu)
		{
			case 0: //main
				str = (string) "Inicio\n" +
					  "  1. Ver productos\n" +
					  "  2. Ver categorias\n" +
					  "  3. Salir\n";
				break;

			case 1: //productos

				print_inventory_items (&inv);

				str = (string) "Opciones\n" +
					  "  1. Agregar\n" +
					  "  2. Eliminar\n" +
					  "  3. Volver\n";
				break;

			case 2:

				print_inventory_tags (&inv);

				str = (string) "Opciones\n" +
					  "  1. Agregar\n" +
					  "  2. Eliminar\n" +
					  "  3. Volver\n";
				break;
		}

		//out
		printf ("%s\n", str.c_str());
		
		//input
		printf (">> ");
		scanf  ("%i", &sel);
		sel --;

		//process
		switch (menu)
		{
			case 0: //principal
				switch (sel)
				{
					case 0: //ver productos
						menu = 1;
						break;
					case 1: //ver etiquetas
						menu = 2;
						break;
					case 2: //salir
						return 0;
						break;
				}
				break;

			case 1: //productos

				switch (sel)
				{
					case 0: //add
						dialog_add_item (&inv);
						break;
					case 1: //remove
						dialog_delete_item (&inv);
						break;
					case 2: //go back
						menu = 0;
						break;
				}
				break;

			case 2: //etiquetas
				switch (sel)
				{
					case 0: //add
						dialog_add_tag (&inv);
						break;
					case 1: //remove
						dialog_delete_tag (&inv);
						break;
					case 2: //go back
						menu = 0;
						break;
				}
				break;
		}

	}
	while (sel != -2);

	return 0;
}


/*
0 Principal
	1 Gestionar productos
		2 Agregar producto
		3 Eliminar producto
		0 Volver

	4 Gestionar etiquetas
		5 Agregar etiqueta
		6 Eliminar etiqueta
		0 Volver

	Salir

Agregar producto
	Nombre
	Valor
	Etiquetas

Eliminar producto
	Id

Agregar etiqueta
	Nombre

Eliminar etiqueta
	Id
*/
