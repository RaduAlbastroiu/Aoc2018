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


string match = "..#..";

int main()
{
  vector<pair<string, bool>> rules;
  string cur;
  string prv;
  string first;

  string s;
  getline(fin, s);

  cur = "...." + s + "....";
  prv = cur;
  first = cur;

  while (true)
  {
    char c;
    fin >> s;
    fin >> c;

    if (c == '#')
    {
      rules.push_back(make_pair(s, true));
    }
    else
    {
      rules.push_back(make_pair(s, false));
    }

    if (fin.eof())
      break;
  }

  int offset = 4;
  for (int i = 1; i <= 2000; i++)
  {
    vector<int> strong;
    for (int j = 0; j < prv.size() - 5; j++)
    {
      for (int k = 0; k < rules.size(); k++)
      {
        string m = rules[k].first;

        if (m[0] == prv[j] && m[1] == prv[j + 1] && m[2] == prv[j + 2] && m[3] == prv[j + 3] && m[4] == prv[j + 4])
        {
          if (find(strong.begin(), strong.end(), j) == strong.end())
          {
            cur[j] = '.';
          }

          if (find(strong.begin(), strong.end(), (j + 1)) == strong.end())
          {
            cur[j + 1] = '.';
          }

          if (rules[k].second == true)
          {
            cur[j + 2] = '#';
            strong.push_back(j + 2);
          }
          else
          {
            cur[j + 2] = '.';
          }

          if (find(strong.begin(), strong.end(), (j + 3)) == strong.end())
          {
            cur[j + 3] = '.';
          }

          if (find(strong.begin(), strong.end(), (j + 4)) == strong.end())
          {
            cur[j + 4] = '.';
          }
          break;
        }
      }
    }

    bool diff = false;
    for (int z = 0; z < cur.size() - 2; z++)
    {
      if (cur[z + 1] != prv[z])
      {
        diff = true;
        break;
      }
    }
    if (diff == false)
    {
      fout << prv << endl;
      fout << cur << endl;

      break;
    }

    offset++;
    cur = '.' + cur + '.';
    prv = cur;

    fout << cur << endl;
  }



  int j = 0 - offset;
  long long RESULT = 0;
  long long left = 50000000000 - offset + 3;

  for (int i = 0; i < cur.size(); i++)
  {
    if (cur[i] == '#')
    {
      RESULT += j + left;
    }
    j++;
  }

  fout << RESULT << endl;

  return 0;
}
