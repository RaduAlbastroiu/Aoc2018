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

vector<string> all;

int main()
{
  int two = 0, three = 0;
  string s;
  while (true)
  {
    fin >> s;
    
    all.push_back(s);

    if (fin.eof())
      break;
  }

  for (auto s : all)
  {
    for (auto s2 : all)
    {
      int diff = 0;
      for (auto i = 0; i < s.size(); i++)
      {
        if (s[i] != s2[i])
        {
          diff++;
        }
      }

      if (diff == 1)
      {
        for (auto i = 0; i < s.size(); i++)
        {
          if (s[i] == s2[i])
          {
            fout << s[i];
          }
        }
      }
    }
  }

  return 0;
}
