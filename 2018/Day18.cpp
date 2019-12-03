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

int m[101][101];
int n[101][101];

int MAX = 49;
char c[] = {'.', '|', '#'};

void print()
{
    for(int i = 0; i < 50; i++)
    {
        for(int j = 0; j < 50; j++)
        {
            fout << c[m[i][j]];
        }
        fout << endl;
    }
    fout << endl << endl;
}

int trees(int i, int j)
{
    int count = 0;
    
    if(n[i-1][j-1] == 1 && i > 0 && j > 0)
        count++;
    
    if(n[i-1][j] == 1 && i > 0)
        count++;
    
    if(n[i-1][j+1] == 1 && i > 0 && j < MAX)
        count++;
    
    if(n[i][j-1] == 1 && j > 0)
        count++;
    
    if(n[i][j + 1] == 1 && j < MAX)
        count++;
    
    if(n[i+1][j-1] == 1 && i < MAX && j > 0)
        count ++;
    
    if(n[i+1][j] == 1 && i < MAX)
        count++;
    
    if(n[i+1][j+1] == 1 && i < MAX && j < MAX)
        count++;
    
    return count;
}

int lumber(int i, int j)
{
    int count = 0;
    
    if(n[i-1][j-1] == 2 && i > 0 && j > 0)
        count++;
    
    if(n[i-1][j] == 2 && i > 0)
        count++;
    
    if(n[i-1][j+1] == 2 && i > 0 && j < 49)
        count++;
    
    if(n[i][j-1] == 2 && j > 0)
        count++;
    
    if(n[i][j + 1] == 2 && j < 49)
        count++;
    
    if(n[i+1][j-1] == 2 && i < 49 && j > 0)
        count ++;
    
    if(n[i+1][j] == 2 && i < 49)
        count++;
    
    if(n[i+1][j+1] == 2 && i < 49 && j < 49)
        count++;
    
    return count;
}

int main()
{
    memset(m, 0, sizeof(m[0][0]) * 101 * 101);
    
    set<string> seen;
    string special = "";
    int start = 0;
    bool notFound = true;
    int loop = 0;
    
    string line;
    int i = 0;
    while(true)
    {
        getline(fin, line);
        
        int j = 0;
        for(auto c : line)
        {
            if(c == '.')
                m[i][j] = 0;
            if(c == '|')
                m[i][j] = 1;
            if(c == '#')
                m[i][j] = 2;
            
            j++;
        }
        
        if(fin.eof())
            break;
        i++;
    }
    
    //print();
    int first = 10;
    int second = 537 + (1000000000 - 537) % 28;
    for(int k = 0; k < second; k++)
    {
        string comb;
        for(int i = 0; i < 101; i++)
        {
            for(int j = 0; j < 101; j++)
            {
                comb.push_back(c[m[i][j]]);
                n[i][j] = m[i][j];
            }
        }
        
        /*
        if(notFound)
        {
            int s = seen.size();
            seen.insert(comb);
            
            if(s == seen.size())
            {
                cout << k;
                start = k;
                special = comb;
                notFound = false;
                print();
            }
        }
        else
        {
            if(comb == special)
            {
                loop = k - start;
                break;
            }
        }
         */
        
        for(int i = 0; i < 50; i++)
        {
            for(int j = 0; j < 50; j++)
            {
                if(n[i][j] == 0)
                {
                    if(trees(i, j) >= 3)
                    {
                        m[i][j] = 1;
                    }
                }
                
                if(n[i][j] == 1)
                {
                    if(lumber(i, j) >= 3)
                    {
                        m[i][j] = 2;
                    }
                }
                
                if(n[i][j] == 2)
                {
                    if(trees(i, j) >= 1 && lumber(i, j) >= 1)
                    {
                        m[i][j] = 2;
                    }
                    else
                    {
                        m[i][j] = 0;
                    }
                }
            }
        }
        
        //fout << k << endl;
        //print();
    }
    
    int l = 0;
    int t = 0;
    for(int i = 0; i < 50; i++) {
        for(int j = 0; j < 50; j++) {
            if(m[i][j] == 1)
                t++;
            if(m[i][j] == 2)
                l++;
        }
    }
    
    cout << l*t << endl;
    
    return 0;
}
