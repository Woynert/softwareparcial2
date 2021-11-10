
#include <string>
#include <vector>

using namespace std;

class Item
{

	private:
		string       name;
		int          value;
		vector <int> tags;

	public:

		Item (string name, int value)
		{
			this->name  = name;
			this->value = value;
		}

		void add_tag (int tagid)
		{
			this->tags.push_back (tagid);
		}

		//getters
		string get_name ()
		{
			return this->name;
		}

		int get_value ()
		{
			return this->value;
		}

		vector <int> get_tags ()
		{
			return this->tags;
		}

};
