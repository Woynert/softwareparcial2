#include <stdio.h>
#include <unordered_map>
#include <vector>

#include "item.hpp"

using namespace std;

class Inventory
{

	private:
		int tag_amount = 0;

		unordered_map <int, string> TAGS;
		vector <Item> ITEMS;

	public:

		//tags

		/* returns tag id */
		int add_tag (string name)
		{
			this->TAGS [this->tag_amount] = name;
			this->tag_amount ++;

			return (this->tag_amount - 1);
		}

		void remove_tag (int id)
		{
			this->TAGS [id] = "";
		}

		vector <string>	get_tags ()
		{

			vector <string> tags;

			for (int i = 0; i < tag_amount; i++)
			{
				//exclude empty tags
				//if (TAGS[i] != "")
					tags.push_back (TAGS[i]);
			}

			return tags;
		}

		unordered_map <string, int> get_tag_name_id (){
			unordered_map <string, int> tags;

			for (int i = 0; i < tag_amount; i++)
			{
				//exclude empty tags
				if (TAGS[i] != "")
					tags[TAGS[i]] = i;
			}

			return tags;
		}

		//items
		void add_item (Item item)
		{
			this->ITEMS.push_back (item);
		}

		void remove_item (int id)
		{
			this->ITEMS.erase ( this->ITEMS.begin() + id);
		}

		int get_item_count()
		{
			return (this->ITEMS.size ());
		}

		vector <Item> get_items ()
		{
			return this->ITEMS;
		}
};
