#include "kl.h"
#include <vector>
#include <iostream>

using namespace std;

void kl(vector<node*> &nodetable, vector<int> B, vector<int> A, vector<int> &maxpair, vector<int> &gaintable, vector<vector<int>> &tablenum)
{
	
		
		vector<int> gainx;
		vector<int> gain_xy;
		g_x(nodetable, B, A, gainx);
		for (int i = 0; i < gainx.size(); i++)
		{
			cout << "the gain of " << nodetable[i]->name << "is: " << gainx[i] << endl;
		}
		int max = g_max(nodetable, B, A, gainx, maxpair, gain_xy);
		if (gain_xy.size() != 0)
		{

			gaintable.push_back(max);
			int sum = 0;
			for (int i = 0; i < gaintable.size(); i++)
			{
				sum = sum + gaintable[i];
			}
			if (sum >= 0)
			{
				tablenum.push_back(maxpair);
				nodetable[A[maxpair[0]]]->lock = true;
				nodetable[B[maxpair[1]]]->lock = true;
		//		cout << "exchange node: " << nodetable[A[maxpair[0]]]->name << " " << "and" << " " << nodetable[B[maxpair[1]]]->name << endl;
				string temp = nodetable[A[maxpair[0]]]->index;                                             
				nodetable[A[maxpair[0]]]->index = nodetable[B[maxpair[1]]]->index;
				nodetable[B[maxpair[1]]]->index = temp;
				int temper = A[maxpair[0]];
				A[maxpair[0]] = B[maxpair[1]];
				B[maxpair[1]] = temper;
				kl(nodetable, B, A, maxpair, gaintable, tablenum);
			}
			


		}
		

	
}