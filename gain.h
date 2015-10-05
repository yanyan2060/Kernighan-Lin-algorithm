#pragma once
#include "MyCell.h"
#include "neighbor.h"
#include "node.h"
#include "upper.h"
#include <math.h>
#include <iostream>

using namespace std;

void g_x(vector<node*> &nodetable, vector<int> B, vector<int> A, vector<int> &gainx);
int link(vector<node*> &nodetable, int &m, int &n, vector<int>A, vector<int>B);
int g_max(vector<node*> &nodetable, vector<int> B, vector<int> A, vector<int> gainx, vector<int> &maxpair, vector<int> &gain_xy);