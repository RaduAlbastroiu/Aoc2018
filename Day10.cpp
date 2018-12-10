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

char m[1001][1001];

void afis(int minX, int maxX, int minY, int maxY)
{
  memset(m, '.', sizeof(m[0][0]) * 1001 * 1001);

  for (auto el : nodes)
  {
    int x = el.x - minX;
    int y = el.y - minY;

    m[y][x] = '#';
  }

  for (int i = 0; i <= (maxY - minY); i++)
  {
    for (int j = 0; j <= (maxX - minX); j++)
    {
      fout << m[i][j];
    }
    fout << endl;
  }
}

int main()
{
  string s;
  char c;
  int x = 0, y = 0, vx = 0, vy = 0;
  while (true) {

    fin >> s;
    if (s[s.size() - 2] == '=')
    {
      fin >> x >> c;
    }
    else
    {
      string s2 = s.substr(10, 14);
      x = stoi(s2);
    }
    fin >> y >> c >> s;

    if (s[s.size() - 2] == '=')
    {
      fin >> vx >> c;
    }
    else
    {
      string s2 = s.substr(10, 11);
      vx = stoi(s2);
    }
    fin >> vy >> s;


    node n;
    n.x = x;
    n.y = y;
    n.vx = vx;
    n.vy = vy;
    nodes.push_back(n);

    if (fin.eof())
      break;
  }

  for (int i = 1; i <= 12000; i++)
  {

    int maxX = -999999, maxY = -999999, minX = 999999, minY = 999999;
    for (int j = 0; j < nodes.size(); j++)
    {
      maxX = max(nodes[j].x, maxX);
      minX = min(nodes[j].x, minX);
      maxY = max(nodes[j].y, maxY);
      minY = min(nodes[j].y, minY);
    }

    if (maxY - minY <= 32 && maxX - minX <= 200)
    {
      afis(minX, maxX, minY, maxY);
      fout << endl << endl << endl;
      fout << "Day " << i << endl;
    }

    for (int j = 0; j < nodes.size(); j++)
    {
      nodes[j].x += nodes[j].vx;
      nodes[j].y += nodes[j].vy;
    }
  }

  return 0;
}
