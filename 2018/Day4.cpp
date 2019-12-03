//
//  main.cpp
//  day4
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
#include <cstdint>

using namespace std;

int n, m, i, j, x, y, z, width, tall, result;
char c;
vector<long long> v;
vector<vector<long long>> vv;
vector<double> vd;
vector<vector<double>> vvd;
unordered_map<string, long long> umstr;
unordered_set<double> sd;
unordered_map<int, int> map;
string s;
int viz[30000];
vector<string> input;

ifstream fin("date.in");
ofstream fout("date.out");
ifstream fin2("date.out");
int mm[10001][10001];

struct str {
    int year, month, day, hour, minute;
    // 0 guard
    // 1 falls
    // 2 wakes
    int operation;
    int guard;
};

struct guardSleep {
    int sleep;
    int min[101];
};

guardSleep guards[10000];

vector<str> v2;


int main()
{
    
    for (int i = 0; i < 9999; i++)
    {
        guards[i].sleep = 0;
        for(int j = 0; j < 100; j++)
            guards[i].min[j] = 0;
    }

    int year, month, day, hour, min, op, guard = -1;
    i = 0;
    while (true) {
        i++;
        fin >> c;
        fin >> year;
        fin >> c;
        fin >> month;
        fin >> c;
        fin >> day;
        fin >> hour;
        fin >> c;
        fin >> min;
        fin >> c;
        fin >> s;
        
        if(s == "Guard")
        {
            fin >> c;
            fin >> guard;
            fin >> s;
            fin >> s;
            op  = 0;
        } else if(s == "falls") {
            op = 1;
            fin >> s;
        } else {
            op = 2;
            fin >> s;
        }
        
        
        str one;
        one.year = year;
        one.minute = min;
        one.day = day;
        one.month = month;
        one.hour = hour;
        one.operation = op;
        one.guard = guard;
        
        v2.push_back(one);
        
        cout << i << "\n";
        
        if (fin.eof()) {
            break;
        }
    }
    
    sort(v2.begin(), v2.end(), [&](str a, str b) {
        if(a.year == b.year) {
            if(a.month == b.month) {
                if(a.day == b.day) {
                    if(a.hour == b.hour) {
                        return a.minute < b.minute;
                    } else {
                        return a.hour < b.hour;
                    }
                } else {
                    return a.day < b.day;
                }
            } else {
                return a.month < b.month;
            }
        } else {
            return a.year < b.year;
        }
    });
    
    
    for(auto str : v2)
    {
        if(str.operation == 0)
        {
            fout << str.year << " " << str.month << " " << str.day << " " << str.hour << " " << str.minute << " " << str.operation << " " << str.guard << "\n";
        }
        else {
            fout << str.year << " " << str.month << " " << str.day << " " << str.hour << " " << str.minute << " " << str.operation << " " << "\n";
        }
    }
   
    for(int i = 0; i < v2.size(); i++)
    {
        if(v2[i].operation == 0)
        {
            int hardi = i;
            for(int j = i+1; j < v2.size(); j++)
            {
                if(v2[j].operation == 0)
                {
                    i = j - 1;
                    break;
                }
                if(v2[j].operation == 1)
                {
                    if(v2[j+1].operation == 2)
                    {
                        guards[v2[hardi].guard].sleep += v2[j+1].minute - v2[j].minute;
                        for(int k = v2[j].minute; k < v2[j+1].minute; k++)
                        {
                            guards[v2[hardi].guard].min[k]++;
                        }
                    }
                }
            }
        }
    }
    
    int max = 0, guardMax = 0, maxMinute = 0, minuteGOLD = 0;
    for(int i = 0; i < 9999; i++)
    {
        int anotherMax = 0;
        int mingold = 0;
        for(int j = 0; j < 69; j++)
        {
            if(guards[i].min[j] > maxMinute)
            {
                maxMinute = guards[i].min[j];
                minuteGOLD = j;
                guardMax = i;
            }
       }
    }
    
    cout << guardMax << " " << maxMinute << " " << minuteGOLD << " " << guardMax * minuteGOLD << "\n";

    return 0;
}
