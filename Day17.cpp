//
//  main.cpp
//  day1
//
//  Created by Radu Albastroiu on 01/12/2018.
//  Copyright © 2018 Radu Albastroiu. All rights reserved.
//

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
#include <deque>
#include <queue>
#include <cstdint>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

using namespace std;

int m[2001][2001];

int minX = 9999, minY = 9999, maxX, maxY;

char c[] = {' ', '#', '~', '|'};

void print()
{
    int count = 0;
    for(int i = minY; i <= maxY; i++)
    {
        for(int j = minX; j <= maxX; j++)
        {
            fout << c[m[i][j]];
            if(m[i][j] >= 2)
                count++;
        }
        fout << endl;
    }
    
    fout << endl << endl;
    fout << "part 1: " << count << endl;
}

int main()
{
    memset(m, 0, sizeof(m[0][0]) * 2001 * 2001);
    int startX, startY, finishX, finishY, t, t2, t3;
    
    while(true)
    {
        fin >> t >> t2;
        if(t == 1)
        {
            startX = t2;
            finishX = t2;
        }
        else
        {
            startY = t2;
            finishY = t2;
        }
        
        fin >> t >> t2 >> t3;
        if(t == 1)
        {
            startX = t2;
            finishX = t3;
        }
        else
        {
            startY = t2;
            finishY = t3;
        }
        
        minX = min(minX, startX);
        maxX = max(maxX, finishX);
        minY = min(minY, startY);
        maxY = max(maxY, finishY);
        
        for(int y = startY; y <= finishY; y++)
        {
            for(int x = startX; x <= finishX; x++)
            {
                m[y][x] = 1;
            }
        }
        
        if(fin.eof())
            break;
    }
    
    minX -= 10;
    maxX += 10;
    
    // 0 sand
    // 1 clay
    // 2 static water
    // 3 flowing water
    
    vector<pair<int, int>> spring;
    spring.push_back(make_pair(500, 0));
    
    for(int i = 0; i < spring.size(); i++)
    {
        int x = spring[i].first;
        int y = spring[i].second;
        
        while(true)
        {
            if(m[y+1][x] == 0 && y <= maxY)
            {
                y++;
                m[y][x] = 3;
            }
            else
                break;
        }
        
        if(y > maxY)
            continue;
        
        if(m[y+1][x] == 3)
            continue;
        
        bool cond = true;
        while(cond)
        {
            // right
            bool foundRight = false;
            bool foundLeft = false;

            for(int tx = x; tx <= maxX; tx++)
            {
                if(m[y][tx] == 0)
                    m[y][tx] = 3;
                
                if(m[y][tx] == 1)
                {
                    foundRight = true;
                    break;
                }
                
                if(m[y][tx] == 3 && m[y+1][tx] == 0)
                {
                    cond = false;
                    spring.push_back(make_pair(tx, y));
                    break;
                }
            }
            
            // left
            for(int tx = x; tx >= minX; tx--)
            {
                if(m[y][tx] == 0)
                    m[y][tx] = 3;
                
                if(m[y][tx] == 1)
                {
                    foundLeft = true;
                    break;
                }
                
                if(m[y][tx] == 3 && m[y+1][tx] == 0)
                {
                    cond = false;
                    spring.push_back(make_pair(tx, y));
                    break;
                }
            }
            
            // make it static water
            if(foundRight && foundLeft)
            {
                for(int tx = x; tx >= minX; tx--)
                {
                    if(m[y][tx] == 3)
                        m[y][tx] = 2;
                    else
                        break;
                }
                for(int tx = x + 1; tx <= maxX; tx++)
                {
                    if(m[y][tx] == 3)
                        m[y][tx] = 2;
                    else
                        break;
                }
            }
            
            y--;
        }
    }
    
    print();
    
    int count = 0;
    for(int i = minY; i <= maxY; i++)
        for(int j = minX; j <= maxX; j++)
            if(m[i][j] == 2)
                count++;
    
    fout << "part 2: ";
    fout << count;
    
}
