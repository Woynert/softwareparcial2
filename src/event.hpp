#include <string>

using namespace std;

class Event
{
	private:
		int id;
		string name;
		string address;
		string hour;
		string date;

	public:
		Event(int id)
		{
			this->id = id;
		}

		//setters
		void set_name (string name){
			this->name = name;
		}

		void set_address (string address){
			this->address = address;
		}

		void set_hour (string hour){
			this->hour = hour;
		}

		void set_date (string date){
			this->date = date;
		}

		//getters
		int get_id(){
			return id;
		}

		string get_name(){
			return name;
		}

		string get_address(){
			return address;
		}

		string get_hour(){
			return hour;
		}

		string get_date(){
			return date;
		}
};
