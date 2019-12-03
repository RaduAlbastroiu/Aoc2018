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

int n, m, i, j, x, y, a, b, c, d;
vector<long long> v;
vector<vector<long long>> vv;
vector<double> vd;
vector<vector<double>> vvd;
unordered_map<string, long long> umstr;
unordered_set<double> sd;
string s;
int viz[30000];
vector<string> input;

ifstream fin("date.txt");
ofstream fout("date.out");
int mat[10001][10001];
int width, tall;
int result = 0;

struct req {
  int x, y, id, width, tall;
};

vector<req> input2;

int main()
{
  // fin >> a >> b;
  // cout << a << b;


  for (int i = 0; i < 10000; i++)
    for (int j = 0; j < 10000; j++)
      mat[i][j] = 0;

  result = 0;
  while (true) {

    char c;
    int id;

    fin >> c;
    fin >> id;
    fin >> c;
    fin >> x;
    fin >> c;
    fin >> y;
    fin >> c;
    fin >> width;
    fin >> c;
    fin >> tall;

    req areq;
    areq.x = x;
    areq.y = y;
    areq.id = id;
    areq.width = width;
    areq.tall = tall;
    input2.push_back(areq);

    for (int i = x; i < x + width; i++){
      for (int j = y; j < y + tall; j++) {
        
        if (mat[i][j] == 0)
          mat[i][j] = id;
        else
          mat[i][j] = -1;
        
      }
    }

    if (fin.eof()) {
      break;
    }
  }

  for (auto a : input2)
  {
    bool succ = true;
    for (int i = a.x; i < a.x + a.width; i++)
    {
      for (int j = a.y; j < a.y + a.tall; j++)
      {
        if (mat[i][j] != a.id)
        {
          succ = false;
        }
      }
    }

    if (succ)
      cout << a.id;
  }

  cout << result;

  return 0;
}
