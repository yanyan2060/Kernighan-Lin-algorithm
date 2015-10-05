#include "neighbor.h"

vector<string> neighbor(vector<MyCell> original,int row,vector<string> &la)
{
	vector<string> neighbornode;
	
	la.push_back(original[row - 1].attriValue[0]);
	
	
	while ((row<original.size())&&(original[row].attriValue[1] != "s"))
		{
			
				neighbornode.push_back(original[row].attriValue[0]);
				la.push_back(original[row].attriValue[0]);
				row++;
			
		}
		
	
	
	
	return neighbornode;
	
}
