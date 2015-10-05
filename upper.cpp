#include "upper.h"

void upper(vector<vector<string>> label,int n,string name,vector<node*>&notetable)
{
	if (n != 0)
	{
		for (int r = 0; r <label.size() ; r++)
		{
			for (int c = 1; c < label[r].size(); c++)
			{
				if (label[r][c] == name)
				{
					notetable[n]->upperline.push_back(label[r][0]);
				}
			}

		}
	}
	
	
}