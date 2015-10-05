#pragma once
#include <vector>
#include <string>

using namespace std;
class node
{
public:
	node();
	~node();
	string name;
	string index;
	vector<string> upperline;     //node into the current node
	vector<string> linenode;      //node go to others node name
	bool lock;

};

