#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "node.h"
#include "MyCell.h"
#include "neighbor.h"
#include "upper.h"
#include <math.h>
#include "gain.h"
#include "newgragh.h"
#include "kl.h"
#include <array>
#include <time.h>


using namespace std;

int main()
{
	ifstream infile;
	infile.open("F:\\588\\588_project4\\net 1w.txt", std::ifstream::in);
	vector<MyCell> original;
	while (infile.eof() != true)
	{

		string str;
		getline(infile, str);
		if (str == "")
		{
			break;
		}

		//cout << str << endl;//test
		vector<string>attri;
		int position = 0;
		int n = -1;
		while (position != string::npos)
		{
			position = n + 1;
			n = str.find(" ", position);
			if (n == string::npos)
			{
				attri.push_back(str.substr(position));
				break;
			}
			attri.push_back(str.substr(position, n - position));

		}
		MyCell *cell = new MyCell();
		cell->attriValue = attri;
		original.push_back(*cell);
		delete cell;
	}
/*	for (int i = 0; i < original.size(); i++)
	{
		for (int j = 0; j < original[i].attriValue.size(); j++)
		{
			cout << original[i].attriValue[j] << " ";
		}
		cout << endl;
	}*/
	vector<node*> nodetable;
	vector<vector<string>> label;
	clock_t start_time = clock();
	newgragh(nodetable, original, label);
/*	for (int i = 0; i < nodetable.size(); i++)
	{
		cout << "the forward nodes of "<<nodetable[i]->name << ":";
		for (int j = 0; j < nodetable[i]->upperline.size(); j++)
		{
			cout  << nodetable[i]->upperline[j] << ",";
		}
		cout << endl;
		cout << "the following nodes of "<< nodetable[i]->name << ":";
		for (int n = 0; n < nodetable[i]->linenode.size(); n++)
		{
			cout  << nodetable[i]->linenode[n] << ",";
		}
		cout << endl;
	}*/
	int size = (nodetable.size()) / 2;
	int  N = nodetable.size();
	cout << "the number of the nodes is: " << N << endl;
	vector<int> A;
	vector<int> B;
	

	vector<int> C;                                                    // generate N different numbers for A and B
	for (int m = 0; m < N; m++)
	{
		C.push_back(m);
	}
	vector<int> D;
	for (int n = N; n>0;)
	{
		int a = rand() % n;
		D.push_back(C[a]);
		C[a] = C[--n];
					
	}
	
	
	for (int i = 0; i <D.size(); i++)
	{
		if (i < size)
		{
			A.push_back(D[i]);
			
		}
		else
		{
			B.push_back(D[i]);
			
		}

	}
	
for (size_t n = 0; n < nodetable.size(); n++)
{		

	for (size_t m = 0; m < B.size(); m++)
	   {
		if (B[m]== n)
			{
				nodetable[n]->index = "B";
				
			}
			
			
		}
	for (size_t m = 0; m < A.size(); m++)
	{
		if (A[m] == n)
		{
			nodetable[n]->index = "A";

		}


	}

}
/*cout << "part A contains : ";
for (int i = 0; i < A.size(); i++)
{
	cout << nodetable[A[i]]->name << ",";
}
cout << endl;
cout << "part B contians : ";
for (int i = 0; i < B.size(); i++)
{
	cout << nodetable[B[i]]->name << ",";
}
cout << endl;*/
	int cutsize = 0;
	int linku = 0;
	int linkd = 0;
	
	for (int m = 0; m < A.size(); m++)
	{
		for (int n = 0; n < B.size(); n++)
		{
			

			for (size_t a = 0; a < nodetable[A[m]]->linenode.size(); a++)
			{
				
				
					if (nodetable[A[m]]->linenode[a] == nodetable[B[n]]->name)
					{
						linku += 1;
					}
				
			}
			for (size_t b = 0; b < nodetable[A[m]]->upperline.size(); b++)
			{
				
					if (nodetable[A[m]]->upperline[b] == nodetable[B[n]]->name)
					{
						linkd += 1;
					}
				
			}
			
		}
	}
	cutsize = linku + linkd;
	cout << "cutset size is: " << cutsize << endl;
	vector<int> maxpair;
	vector<int> gaintable;
	vector<vector<int>> tablenum;
	kl(nodetable, B, A, maxpair, gaintable, tablenum);
	int sum = 0;
//	cout << "the max gain for each swapping: ";
	for (int i = 0; i < gaintable.size(); i++)
	{
		cout << gaintable[i] << ",";
		sum = sum + gaintable[i];
	}
	cout << endl;
	if (sum == 0)
	{
		cout << "the operation is correct" << endl;
	}
	else
	{
		cout << "the operation is wrong" << endl;
	}
	for (int i = 0; i < nodetable.size(); i++)
	{
		nodetable[i]->lock = false;
	}
	int l = 0;
	vector<int> maxsize;
	for (int r = 0; r < gaintable.size(); r++)
	{
		l = l + gaintable[r];
		maxsize.push_back(l);
	}
	int com = maxsize[0];
	for (int n = 0; n < maxsize.size(); n++)
	{
		
		int num = 0;
		if (maxsize[n]>com)
		{
			com = maxsize[n];
			num = n;
		}
	}
	int newsize = cutsize - com;
	cout << "the new cutset size is: " << cutsize << "-" << com << "=" << newsize << endl;
	clock_t end_time = clock();
	cout << "Running time is: " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;

}