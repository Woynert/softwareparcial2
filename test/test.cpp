
//catch libraries (sudo apt install catch2)
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

//libraries to test
#include "../src/inventory.hpp"

//definir pruebas
TEST_CASE("PRUEBA: Verificar gestión de ITEMS", "[classic]"){

	Inventory *inv = new Inventory();
	Item* it;

	//Agregar dos items
	SECTION ("Adición")
	{
		it = new Item("Arroz", 1500);
		inv->add_item (*it);

		it = new Item("Aceite", 2700);
		inv->add_item (*it);

		REQUIRE ( inv->get_item_count() == 2);
	}

	//Agregar dos items y eliminar un item
	SECTION ("Substracción")
	{

		it = new Item("Arroz", 1500);
		inv->add_item (*it);

		it = new Item("Aceite", 2700);
		inv->add_item (*it);

		inv->remove_item (0);

		REQUIRE ( inv->get_item_count() == 1);
	}

}

//definir pruebas
TEST_CASE("PRUEBA: Verificar gestión de ARTICULOS", "[classic]"){

	Inventory *inv = new Inventory();

	//Agregar tres categorias
	SECTION ("Adición")
	{

		inv->add_tag ("Higuiene");
		inv->add_tag ("Defensa");
		inv->add_tag ("Materiales");

		REQUIRE ( inv->get_tag_count() == 3);
	}

	//Agregar dos categorias y eliminar dos categorias
	SECTION ("Substracción")
	{

		inv->add_tag ("Higuiene");
		inv->add_tag ("Defensa");
		inv->remove_tag (1);
		inv->remove_tag (0);

		REQUIRE ( inv->get_tag_count() == 0);
	}
}
