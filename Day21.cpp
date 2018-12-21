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

struct instruction
{
    string type;
    int a, b, c;
};

vector<instruction> instructions;

int main()
{
    string s;
    fin >> s >> s;
    int a, b, c;
    while(true)
    {
        fin >> s >> a >> b >> c;
        
        instruction i;
        i.type = s;
        i.a= a;
        i.b = b;
        i.c = c;
        instructions.push_back(i);
        
        if(fin.eof())
            break;
    }
    
    vector<int> values;
    
    int MINVAL = 0;
    long long MIN = 9999999999;

    for(int i = 123456; i < 123457; i++)
    {
        int memory[] = {0, 0, 0, 0, 0, 0, 0};

        int val = 0;
        int current = 0;
        long long nrIter = 0;
        while(true)
        {
            nrIter++;
            memory[1] = current;
            auto curInstr = instructions[current];
            
            if(curInstr.type == "addr")
            {
                memory[curInstr.c] = memory[curInstr.a] + memory[curInstr.b];
            }
            
            if(curInstr.type == "addi")
            {
                memory[curInstr.c] = memory[curInstr.a] + curInstr.b;
            }
            
            if(curInstr.type == "mulr")
            {
                memory[curInstr.c] = memory[curInstr.a] * memory[curInstr.b];
            }
            
            if(curInstr.type == "muli")
            {
                memory[curInstr.c] = memory[curInstr.a] * curInstr.b;
            }
            
            if(curInstr.type == "banr")
            {
                memory[curInstr.c] = memory[curInstr.a] &  memory[curInstr.b];
            }
            
            if(curInstr.type == "bani")
            {
                memory[curInstr.c] = memory[curInstr.a] & curInstr.b;
            }
            
            if(curInstr.type == "borr")
            {
                memory[curInstr.c] = memory[curInstr.a] |  memory[curInstr.b];
            }
            
            if(curInstr.type == "bori")
            {
                memory[curInstr.c] = memory[curInstr.a] | curInstr.b;
            }
            
            if(curInstr.type == "setr")
            {
                memory[curInstr.c] = memory[curInstr.a];
            }
            
            if(curInstr.type == "seti")
            {
                memory[curInstr.c] = curInstr.a;
            }
            
            if(curInstr.type == "gtrr")
            {
                memory[curInstr.c] = memory[curInstr.a] > memory[curInstr.b] ? 1 : 0;
            }
            
            if(curInstr.type == "gtir")
            {
                memory[curInstr.c] = curInstr.a > memory[curInstr.b] ? 1 : 0;
            }
            
            if(curInstr.type == "gtri")
            {
                memory[curInstr.c] = memory[curInstr.a] > curInstr.b ? 1 : 0;
            }
            
            if(curInstr.type == "eqrr")
            {
                memory[curInstr.c] = memory[curInstr.a] == memory[curInstr.b] ? 1 : 0;
            }
            
            if(curInstr.type == "eqir")
            {
                memory[curInstr.c] = curInstr.a == memory[curInstr.b] ? 1 : 0;
            }
            
            if(curInstr.type == "eqri")
            {
                memory[curInstr.c] = memory[curInstr.a] == curInstr.b ? 1 : 0;
            }
            
            
            current = memory[1];
            current++;
            
            if(nrIter > MIN)
            {
                break;
            }
            
            if(val != memory[5] && current == 28)
            {
                val = memory[5];
                
                if(find(values.begin(), values.end(), val) != values.end())
                {
                    fout << endl << endl;
                    for(auto el : values)
                    {
                        fout << el << endl;
                    }
                    break;
                }
                values.push_back(val);
                
                //fout << memory[0] << " " << memory[1] << " " << memory[2] << " " << memory[3] << " " << memory[4] << " " << memory[5] << endl;
            }
            if(current >= instructions.size() || current < 0)
            {
                if(nrIter < MIN)
                {
                    MIN = nrIter;
                    MINVAL = i;
                }
                break;
            }
        }
        
    }
    
    cout << MIN << " " << MINVAL;
    
    return 0;
}
