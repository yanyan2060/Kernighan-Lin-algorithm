#pragma once
#include <string>
#include <vector>
#include "gain.h"
#include "node.h"

using namespace std;

void kl(vector<node*> &nodetable, vector<int> B, vector<int> A, vector<int> &maxpair, vector<int> &gaintable, vector<vector<int>> &tablenum);
