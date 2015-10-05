#include "newgragh.h"

void newgragh(vector<node*> &nodetable, vector<MyCell> &original, vector<vector<string>> &label)
{
	for (size_t row = 5; row < original.size(); row++)         //there are 5 lines header in the file
	{
		if (original[row].attriValue[1] == "s")
		{
			vector<string> la;
			node* smallnode = new node();
			smallnode->name = original[row].attriValue[0];
			smallnode->linenode = neighbor(original, row + 1, la);
			label.push_back(la);
			nodetable.push_back(smallnode);
		}


	}
	for (size_t n = 5; n < original.size(); n++)
	{
		string temp = original[n].attriValue[0];
		for (size_t m = 0; m < nodetable.size(); m++)
		{
			if (temp == nodetable[m]->name)
			{
				break;
			}
			else
			{
				if (m == nodetable.size() - 1)
				{
					node* nodenoline = new node();
					nodenoline->name = temp;
					nodetable.push_back(nodenoline);
				}
			}
		}
	}
	for (size_t r = 0; r < nodetable.size(); r++)
	{
		string name = nodetable[r]->name;
		upper(label, r, name, nodetable);
	}
	if (nodetable.size() % 2 != 0)
	{
		node* addnode = new node();
		addnode->name = "add";
		nodetable.push_back(addnode);
	}

}