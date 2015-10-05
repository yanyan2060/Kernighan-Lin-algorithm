#include "gain.h"

using namespace std;

void g_x(vector<node*> &nodetable, vector<int> B, vector<int> A, vector<int> &gainx)
{
	vector<int> out;
	vector<int> in;
	vector<int> x_B;
	vector<int> x_A;
	for (size_t r = 0; r < nodetable.size(); r++)
	{
		int ocntu = 0;
		int ocntd = 0;
		int ou = 0;
		int incu = 0;
		int incd = 0;
		int ine = 0;
		int gain_x = 0;
		
			for (size_t m = 0; m < nodetable[r]->upperline.size(); m++)
			{

				for (size_t n = 0; n < B.size(); n++)
				{
					if (nodetable[r]->upperline[m] == nodetable[B[n]]->name)
					{
						//x_B.push_back(n);
						ocntu++;
					}
				}

			}

			for (size_t m = 0; m < nodetable[r]->linenode.size(); m++)
			{
				for (size_t n = 0; n < B.size(); n++)
				{
					if (nodetable[r]->linenode[m] == nodetable[B[n]]->name)
					{
						//x_B.push_back(n);
						ocntd++;
					}
				}
			}
			ou = (ocntu + ocntd);
			out.push_back(ou);
			for (size_t m = 0; m < nodetable[r]->upperline.size(); m++)
			{
				for (size_t n = 0; n < A.size(); n++)
				{
					if (nodetable[r]->upperline[m] == nodetable[A[n]]->name)
					{
						//x_A.push_back(n);
						incu++;
					}
				}

			}

			for (size_t m = 0; m < nodetable[r]->linenode.size(); m++)
			{
				for (size_t n = 0; n < A.size(); n++)
				{
					if (nodetable[r]->linenode[m] == nodetable[A[n]]->name)
					{
						//x_A.push_back(n);
						incd++;
					}
				}
			}
			ine = (incu + incd);
			in.push_back(ine);
			if (nodetable[r]->index == "A")
			{
				gain_x = ou - ine;
			}
			else
			{
				gain_x = ine - ou;
			}
			
			gainx.push_back(gain_x);
		}
		
		

}

int link(vector<node*> &nodetable, int &m, int &n, vector<int>A, vector<int>B)
{
	int linku = 0;
	int linkd = 0;
	int link = 0;
	
		for ( size_t a = 0; a < nodetable[A[m]]->linenode.size(); a++)
		{
			
				if (nodetable[A[m]]->linenode[a] == nodetable[B[n]]->name)
				{
					linku += 1;
				}
			
		}
		for ( size_t b = 0; b < nodetable[A[m]]->upperline.size(); b++)
		{
			
				if (nodetable[A[m]]->upperline[b] == nodetable[B[n]]->name)
				{
					linkd += 1;
				}
			
		}
		link = (linku + linkd);
		return link;
}

int g_max(vector<node*> &nodetable, vector<int> B, vector<int> A, vector<int> gainx, vector<int> &maxpair,vector<int> &gain_xy)
{
	
	
	
	vector<vector<int>> gain_index;
	for (int m = 0; m < A.size(); m++)
	{
		if (nodetable[A[m]]->lock == false)
		{
			int gain_t = 0;
			
			for (int n = 0; n < B.size(); n++)
			{
				vector<int> number;
				number.push_back(m);
				if (nodetable[B[n]]->lock == false)
				{
					number.push_back(n);
					int linkm = link(nodetable, m, n, A, B);
					gain_t = gainx[A[m]] + gainx[B[n]] - 2*linkm;
					gain_index.push_back(number);
					gain_xy.push_back(gain_t);
				}
				
			}
		}
		
		
	}
	
	if (gain_xy.size() != 0)
	{
		int max = gain_xy[0];
		int a = 0;
		for (size_t i = 0; i < gain_xy.size(); i++)
		{
		//	cout << "the gain of " << nodetable[A[gain_index[i][0]]]->name << "and " << nodetable[B[gain_index[i][1]]]->name << "is: " << gain_xy[i] << endl;
			if (gain_xy[i]>max)
			{
				max = gain_xy[i];
				a = i;
			}
		}
		maxpair = gain_index[a];
		return max;
	}
	
}