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
    int n = 50000000;
    
    node* current = new node(nullptr, nullptr, 0);
    current->value = 3;
    
    node* current2 = new node(nullptr, nullptr, 0);
    current2->next = current;
    current2->prev = current;
    current2->value = 7;
    
    current->next = current2;
    current->prev = current2;
    
    node* first = current;
    node* last = current2;
    
    for(int i = 1; i <= n;)
    {
        /*
        node* t = first;
        cout << t-> value << " ";
        t = t->next;
        while(t != first)
        {
            cout << t-> value << " ";
            t = t->next;
        }
        cout << endl;
        */
        int newrecipie = current->value + current2->value;
        if(newrecipie >= 10)
        {
            i += 2;
            int newrecipie1 = newrecipie/10;
            int newrecipie2 = newrecipie%10;
            
            node* r = new node(nullptr, last, newrecipie1);
            last->next = r;
            
            node* r2 = new node(first, r, newrecipie2);
            r->next = r2;
            last = r2;
        }
        else
        {
            i++;
            node* r = new node(first, last, newrecipie);
            last->next = r;
            last = r;
        }
        
        int times = current->value;
        for(int j = 0; j <= times; j++)
        {
            current = current->next;
        }
        times = current2->value;
        for(int j = 0; j <= times; j++)
        {
            current2 = current2->next;
        }
    }
    
    node* it = first;
    for(int i = 0; i < n; i++)
    {
        if(it->value == 2)
        {
            if(it->next->value == 6)
            {
                if(it->next->next->value == 0)
                {
                    if(it->next->next->next->value == 3)
                    {
                        if(it->next->next->next->next->value == 2)
                        {
                            if(it->next->next->next->next->next->value == 1)
                            {
                                cout << i << endl;
                            }
                        }
                    }
                }
            }
        }
        it = it->next;
    }
    
    return 0;
}
