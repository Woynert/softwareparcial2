
//catch libraries (sudo apt install catch2)
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

//libraries to test
#include "../src/bank.hpp"

//definir pruebas
TEST_CASE("PRUEBA: Gestión Eventos", "[classic]"){

	Bank   bk = *(new Bank);
	int    id;
	string name;
    string address;
    string hour;
    string date;

	SECTION("Agregar"){
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

		REQUIRE(bk.get_event_count() == 2);
	}

	SECTION("Remover"){
		name    = "Parcial_Analisis";
	    address = "B202";
	    hour    = "2:00 PM";
	    date    = "10-11-2021";
	    id = bk.add_event (name, address, hour, date);

		bk.remove_event (id);

		REQUIRE(bk.get_event_count() == 0);
	}


}
