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

int viz[1000001];

int main()
{
  int x, t = 0;
  vector<int> all;
  while (true)
  {
    fin >> x;
    all.push_back(x);
    if (fin.eof())
      break;
  }

  while (true)
  {
    for (auto el : all)
    {
      t += el;
      viz[t]++;
      if (viz[t] == 2)
      {
        fout << t;
        return 0;
      }
    }
  }
  return 0;
}
