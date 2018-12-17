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

struct frequency
{
    int value, freq;
    
    bool operator < (const frequency& other)
    {
        if(value == other.value)
            return freq > other.freq;
        return value < other.value;
    }
};

struct infRange
{
    int min, max;
    vector<int> mins;
    vector<int> maxs;
    bool isViz;
    int offset;
    int viz[2000001];
    vector<frequency> vizFancy;
};

infRange getInfo(int* begin, int length)
{
    infRange result;
    result.min = (1>>31)-1;
    result.max = 1>>31;
    result.isViz = false;
    result.offset = 0;
    
    for(int i = 0; i < length; i++)
    {
        int* it = begin + i;
        if(*it == result.max)
        {
            result.maxs.push_back(i);
        }
        if(*it > result.max)
        {
            result.max = *it;
            result.maxs.clear();
            result.maxs.push_back(i);
        }
        
        if(*it == result.min)
        {
            result.mins.push_back(i);
        }
        if(*it < result.min)
        {
            result.min = *it;
            result.mins.clear();
            result.mins.push_back(i);
        }
    }
    
    fill(result.viz, result.viz + min(result.max + 100, 2000000), 0);
    if(result.max - result.min < 2000000)
    {
        result.isViz = true;
        if(result.min > 0)
        {
            result.offset = 0;
        }
        else
        {
            result.offset = result.min * -1;
        }
        
        for(int i = 0; i < length; i++)
        {
            int* it = begin + i;
            result.viz[*it + result.offset]++;
        }
        
        for(int i = 0; i <= result.max + result.offset; i++)
        {
            frequency f;
            f.value = i - result.offset;
            f.freq = result.viz[i];
            result.vizFancy.push_back(f);
        }
    }
    
    return result;
}

struct timestamp {
    int year, month, day, hour, minute;
    
    bool operator < (const timestamp& other) {
        if(year == other.year) {
            if(month == other.month) {
                if(day == other.day) {
                    if(hour == other.hour) {
                        return minute < other.minute;
                    } else {
                        return hour < other.hour;
                    }
                } else {
                    return day < other.day;
                }
            } else {
                return month < other.month;
            }
        } else {
            return year < other.year;
        }
    }
};

ifstream fin("date.in");
ofstream fout("date2.out");

int m[1001][1001];

void afis(vector<pair<pair<int, int>, pair<int, int>>> pods)
{
    int n[101][101];
    memset(n, 0, sizeof(n[0][0]) * 101 * 101);
    
    for(int i = 0; i < 15; i++)
    {
        for(int j = 1; j < 15; j++)
        {
            cout << endl;
        }
    }
}

int main()
{
    memset(m, 0, sizeof(m[0][0]) * 1001 * 1001);
    
    // pair first x, y
    // pair second current direction, next turn
    
    vector<pair<pair<int,int>, pair<int, int>>> pods;
    string s;
    int y = 0;
    while(true)
    {
        getline(fin, s);
        
        for(int x = 0; x < s.size(); x++)
        {
            if(s[x] == '|')
            {
                m[y][x] = 1;
            }
            if(s[x] == '-')
            {
                m[y][x] = 2;
            }
            if(s[x] == '+')
            {
                m[y][x] = 3;
            }
            if(s[x] == '/')
            {
                // right
                if(s.size() > x + 1 && (s[x+1] == '-' || s[x+1] == '+' || s[x+1] == '>' || s[x+1] == '<'))
                {
                    m[y][x] = 5;
                }
                // left
                if(x > 0 && (s[x-1] == '-' || s[x-1] == '+' || s[x-1] == '>' || s[x-1] == '<'))
                {
                    m[y][x] = 8;
                }
            }
            if(s[x] == '\\')
            {
                // right
                if(s.size() > x + 1 && (s[x+1] == '-' || s[x+1] == '+' || s[x+1] == '>' || s[x+1] == '<'))
                {
                    m[y][x] = 7;
                }
                // left
                if(x > 0 && (s[x-1] == '-' || s[x-1] == '+' || s[x-1] == '>' || s[x-1] == '<'))
                {
                    m[y][x] = 6;
                }
            }
            if(s[x] == '<')
            {
                pods.push_back(make_pair(make_pair(y, x),  make_pair(2, 0)));
                m[y][x] = 2;
            }
            if(s[x] == '>')
            {
                pods.push_back(make_pair(make_pair(y, x), make_pair(3, 0)));
                m[y][x] = 2;
            }
            if(s[x] == '^')
            {
                pods.push_back(make_pair(make_pair(y, x), make_pair(0, 0)));
                m[y][x] = 1;
            }
            if(s[x] == 'v')
            {
                pods.push_back(make_pair(make_pair(y, x), make_pair(1, 0)));
                m[y][x] = 1;
            }
        }
        y++;
        if(fin.eof())
            break;
    }
    
    int tick = 0;
    while(true)
    {
        tick++;
        sort(pods.begin(), pods.end());
        
        vector<int> removeItems;
        vector<pair<pair<int, int>, pair<int, int>>> removePods;
        
        for(int i = 0; i < pods.size(); i++)
        {
            int dir = pods[i].second.first;
            
            if(dir == 0)
            {
                // update location
                pods[i].first.first--;
                
                // corner
                if(m[pods[i].first.first][pods[i].first.second] == 5)
                {
                    pods[i].second.first = 3;
                }
                if(m[pods[i].first.first][pods[i].first.second] == 6)
                {
                    pods[i].second.first = 2;
                }
                
                // intersection
                if(m[pods[i].first.first][pods[i].first.second] == 3)
                {
                    if(pods[i].second.second == 0)
                    {
                        pods[i].second.first = 2;
                        pods[i].second.second = 1;
                    } else {
                        if(pods[i].second.second == 1)
                        {
                            pods[i].second.first = 0;
                            pods[i].second.second = 2;
                        } else {
                            if(pods[i].second.second == 2)
                            {
                                pods[i].second.first = 3;
                                pods[i].second.second = 0;
                            }
                        }
                    }
                }
            }
            if(dir == 1)
            {
                // update location
                pods[i].first.first++;
                
                // corner
                if(m[pods[i].first.first][pods[i].first.second] == 7)
                {
                    pods[i].second.first = 3;
                }
                if(m[pods[i].first.first][pods[i].first.second] == 8)
                {
                    pods[i].second.first = 2;
                }
                
                // intersection
                if(m[pods[i].first.first][pods[i].first.second] == 3)
                {
                    if(pods[i].second.second == 0)
                    {
                        pods[i].second.first = 3;
                        pods[i].second.second = 1;
                    } else {
                        if(pods[i].second.second == 1)
                        {
                            pods[i].second.first = 1;
                            pods[i].second.second = 2;
                        } else {
                            if(pods[i].second.second == 2)
                            {
                                pods[i].second.first = 2;
                                pods[i].second.second = 0;
                            }
                        }
                    }
                }
            }
            if(dir == 2)
            {
                // update location
                pods[i].first.second--;
                
                // corner
                if(m[pods[i].first.first][pods[i].first.second] == 5)
                {
                    pods[i].second.first = 1;
                }
                if(m[pods[i].first.first][pods[i].first.second] == 7)
                {
                    pods[i].second.first = 0;
                }
                
                // intersection
                if(m[pods[i].first.first][pods[i].first.second] == 3)
                {
                    if(pods[i].second.second == 0)
                    {
                        pods[i].second.first = 1;
                        pods[i].second.second = 1;
                    } else {
                        if(pods[i].second.second == 1)
                        {
                            pods[i].second.first = 2;
                            pods[i].second.second = 2;
                        } else {
                            if(pods[i].second.second == 2)
                            {
                                pods[i].second.first = 0;
                                pods[i].second.second = 0;
                            }
                        }
                    }
                }
            }
            if(dir == 3)
            {
                // update location
                pods[i].first.second++;
                
                // corner
                if(m[pods[i].first.first][pods[i].first.second] == 6)
                {
                    pods[i].second.first = 1;
                }
                if(m[pods[i].first.first][pods[i].first.second] == 8)
                {
                    pods[i].second.first = 0;
                }
                
                // intersection
                if(m[pods[i].first.first][pods[i].first.second] == 3)
                {
                    if(pods[i].second.second == 0)
                    {
                        pods[i].second.first = 0;
                        pods[i].second.second = 1;
                    } else {
                        if(pods[i].second.second == 1)
                        {
                            pods[i].second.first = 3;
                            pods[i].second.second = 2;
                        } else {
                            if(pods[i].second.second == 2)
                            {
                                pods[i].second.first = 1;
                                pods[i].second.second = 0;
                            }
                        }
                    }
                }
            }
            
            for(int j = 0; j < pods.size(); j++)
            {
                if(i != j)
                {
                    auto it = find(removeItems.begin(), removeItems.end(), j);
                    auto it2 = find(removeItems.begin(), removeItems.end(), i);
                    
                    if(it == removeItems.end() && it2 == removeItems.end())
                    {
                        if(pods[i].first.first == pods[j].first.first && pods[i].first.second == pods[j].first.second)
                        {
                            cout << pods[i].first.second << " " << pods[i].first.first << endl;
                            removeItems.push_back(i);
                            removePods.push_back(pods[i]);
                            removeItems.push_back(j);
                            removePods.push_back(pods[j]);
                        }
                    }
                }
            }
        }
        
        for(auto pod: removePods)
        {
            auto it = find(pods.begin(), pods.end(), pod);
            if(it != pods.end())
            {
                pods.erase(it);
            }
        }
        
        if(pods.size() <= 1)
        {
            cout << "FINISHED" << endl;
            cout << pods[0].first.second << "," << pods[0].first.first << endl;
            break;
        }
    }
    
    
    
    return 0;
}
