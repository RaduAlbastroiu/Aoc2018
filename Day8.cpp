// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <string>
#include <deque>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <cstdint>

using namespace std;

ifstream fin("date.txt");
ofstream fout("date.out");

int RESULT;
unordered_map<string, int> map;

void recurse(string h)
{
  int nodes, metadata;
  fin >> nodes >> metadata;

  for (int i = 1; i <= nodes; i++)
    recurse(h + "." + to_string(i));

  for (int i = 1; i <= metadata; i++)
  {
    int x;
    fin >> x;
    map[h] += nodes == 0 ? x : map[h + "." + to_string(x)];
  }
}

int main()
{
  recurse("first");
  cout << map["first"];

  return 0;
}
