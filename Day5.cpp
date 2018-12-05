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

int n, m, i, j;
char c;
string s;
ifstream fin("date.in");
ofstream fout("date.out");


int main()
{
    fin >> s;
    
    int dif = 'a' - 'A';
    
    int viz[100];
    int min = 999999;
    
    for(char c = 'A'; c <= 'Z'; c++)
    {
        string s1;
        cout << s1.size() << " ";
        char C = c + ('a'-'A');
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != c && s[i] != C)
            {
                s1.push_back(s[i]);
            }
        }
        cout << c << " before: " << s1.size() << " ";
        
        int sum = 0;
        for(int i = 0; i < s1.size(); i++)
        {
            if(s1[i] == c || s1[i] == C)
                sum++;
        }
        cout << sum << " ";
        
        while(true)
        {
            bool done = false;
            for(int i = 0; i < s1.size()-1; i++)
            {
                if(s1[i]+dif == s1[i+1])
                {
                    s1[i] = 50;
                    s1[i+1] = 50;
                    i++;
                    done = true;
                }
                else {
                    if(s1[i]-dif == s1[i+1])
                    {
                        s1[i] = 50;
                        s1[i+1] = 50;
                        i++;
                        done = true;
                    }
                }
            }
        
            if(done == false)
            {
                cout << s1.size() << "\n";
                if(s1.size() < min)
                    min = s1.size();
                
                break;
            }
        
            string s2;
            for(int i = 0; i < s1.size(); i++)
            {
                if(s1[i] != 50)
                    s2.push_back(s1[i]);
            }
            s1 = s2;
        }
    }
    
    cout << min << endl;
    
    return 0;
}
