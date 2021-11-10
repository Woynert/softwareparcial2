#include <string>
#include <vector>
#include "event.hpp"

using namespace std;

class Bank
{
	private:
		int       event_count = 0;
		vector <Event> EVENTS;

	public:
		//add event -> returns id
		int add_event ( string name, string address, string hour, string date )
		{
			Event *e = new Event(event_count);
			e->set_name    (name);
			e->set_address (address);
			e->set_hour    (hour);
			e->set_date    (date);

			EVENTS.push_back (*e);
			event_count ++;

			return e->get_id();
		}

		//remove event
		void remove_event (int id)
		{
			EVENTS.erase (EVENTS.begin() + id);
			event_count --;
		}

		//get events
		vector <Event>* get_events ()
		{
			return &EVENTS;
		}

		//get quantity
		int get_event_count ()
		{
			return event_count;
		}
};
