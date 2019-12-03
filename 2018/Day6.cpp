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

vector<pair<int, int>> all;

int main()
{
  int x, y;
  
  while (true)
  {
    fin >> x >> y;
    all.push_back(make_pair(x, y));

    if (fin.eof())
      break;
  }

  for (int i = 0; i < 1000; ++i)
  {
    for (int j = 0; j < 1000; ++j)
    {
      int MIN = 99999, nrMIN = 0, pozMIN;
      int k = 0;
      for (auto point : all)
      {
        if (abs(i - point.first) + abs(j - point.second) == MIN)
        {
          nrMIN++;
        }
        if (abs(i - point.first) + abs(j - point.second) < MIN)
        {
          MIN = abs(i - point.first) + abs(j - point.second);
          nrMIN = 1;
          pozMIN = k;
        }
        k++;
      }

      if (nrMIN == 1)
      {
        if (i == 0 || j == 0 || i == 999 || j == 999)
          viz[pozMIN] += 100000;
        viz[pozMIN]++;
      }
    }
  }

  int MAX = 0;
  for (int i = 0; i < 51; ++i)
  {
    if (viz[i] > MAX && viz[i] < 100000)
    {
      MAX = viz[i];
    }
  }
 
  fout << "part1: " << MAX << endl;

  int count = 0;
  for (int i = 0; i < 1000; ++i)
  {
    for (int j = 0; j < 1000; ++j)
    {
      int dist = 0;
      for (auto point : all)
      {
        dist += abs(point.first - i) + abs(point.second - j);
      }

      if (dist < 10000)
      {
        count++;
      }
    }
  }

  fout << "part2: " << count << endl;

  return 0;
}
