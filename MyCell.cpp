#include "MyCell.h"


MyCell::MyCell()
{
}


MyCell::~MyCell()
{
}


bool MyCell:: operator == (const MyCell&cell)
{
	if (cell.attriValue == this->attriValue)
	{
		return true;
	}
	else
	{
		return false;
	}
}