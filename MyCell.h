#pragma once
#include <vector>
#include <string>
using namespace std;

class MyCell
{
public:
	MyCell();
	~MyCell();
	vector<string> attriValue;
	bool operator==(const MyCell&cell);
};

