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

int n, i, j;
char c;
char c1, c2;
string s;

vector<pair<int, int>> input;

ifstream fin("date.in");
ofstream fout("date.out");

struct node {
    
    node(node* first, node* second, int value) {
        this->next = first;
        this->prev = second;
        this->value = value;
    }
    
    node* next;
    node* prev;
    int value;
    
    
};

int main()
{

    int n = 441;
    int highScore = 710320000;
    vector<int> v;
    long long results[1001];
    memset(results,0, sizeof(results[0]) * 1001);
    
    node* current = new node(nullptr, nullptr, 0);
    current->next = current;
    current->prev = current;
    node* first = current;
    
    for(int i = 1; i <= highScore; i++)
    {
        if(i % 23 != 0)
        {
            current = current->next;
            node* next = current-> next;
            node* newele = new node(next, current, i);
            current->next = newele;
            next->prev = newele;
            current = newele;
        }
        else
        {
            results[i % n + 1] += i;
            for(int j = 1; j <= 7; j++)
            {
                current = current->prev;
            }
            node* prev = current->prev;
            node* next = current->next;
            
            results[i % n + 1] += current->value;
            
            prev->next = next;
            next->prev = prev;
            current = next;
        }
    }
    
    /*
    for(int i = 0; i <= highScore; i++)
    {
        cout << first->value << " ";
        first = first->next;
    }
     */
    
    long long MAX = 0;
    for(int i = 0; i <= n; i++)
    {
        MAX = max(MAX, results[i]);
    }
    cout << MAX << endl;
    
    return 0;
}
