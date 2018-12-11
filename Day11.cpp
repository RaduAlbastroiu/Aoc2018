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

struct node
{
  int x, y, vx, vy;
};

vector<node> nodes;

int m[1001][1001];

int main()
{
  memset(m, 0, sizeof(m[0][0]) * 1001 * 1001);

  int n = 7689;

  for (int y = 1; y <= 300; y++)
  {
    for (int x = 1; x <= 300; x++)
    {
      int id = x + 10;
      int p = id * y + n;
      p = ((p * id) / 100) % 10 - 5;

      m[x][y] = p;
    }
  }

  long long MAX = -99999;
  int mx, my, size;
  for (int k = 1; k <= 300; k++)
  {
    for (int y = 1; y <= 300 - k; y++)
    {
      for (int x = 1; x <= 300 - k; x++)
      {
        long long sum = 0;

        for (int i = 0; i < k; i++)
        {
          for (int j = 0; j < k; j++)
          {
            sum += m[i + x][j + y];
          }
        }

        if (sum > MAX)
        {
          MAX = sum;
          mx = x;
          my = y;
          size = k;
        }
      }
    }
  }

  fout << mx << " " << my << " " << size;

  return 0;
}
