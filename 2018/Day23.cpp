#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

#define ll long long

struct nanobot
{
    long long x, y, z, r;
};

struct poz
{
    long long x, y, z, inrange;
};

vector<nanobot> nanobots;

int inrange(long long x, long long y, long long z)
{
    int count = 0;
    
    for(auto n : nanobots)
    {
        long long dist = abs(n.x - x) + abs(n.y - y) + abs(n.z - z);
        if(dist <= n.r)
        {
            count++;
        }
    }

    return count;
}

poz p;
int MAXCOUNT = 0;

void searchLocalMax(ll x, ll y, ll z, ll range)
{
    int MAX = 0;
    ll maxX = x - range, maxY = y - range, maxZ = z - range;
    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            for(int k = -1; k <= 1; k++)
            {
                int count = inrange(x + (i*range), y + (j*range), z + (k*range));
                if(count == MAX)
                {
                    if(abs(x + (i*range)) + abs(y + (j*range)) + abs(z + (k*range)) < abs(maxX) + abs(maxY) + abs(maxZ))
                    {
                        maxX = x + (i*range);
                        maxY = y + (j*range);
                        maxZ = z + (k*range);
                    }
                }
                if(count > MAX)
                {
                    MAX = count;
                    
                    maxX = x + (i*range);
                    maxY = y + (j*range);
                    maxZ = z + (k*range);
                }
            }
        }
    }
    
    if((maxX == x && maxY == y && maxZ == z))
    {
        if(range > 1)
        {
            searchLocalMax(x, y, z, range/10);
        }
        else
        {
            p.x = maxX;
            p.y = maxY;
            p.z = maxZ;
            p.inrange = MAX;
            return;
        }
    }
    else
    {
        searchLocalMax(maxX, maxY, maxZ, range);
    }
    
    return;
}

int main (){
    
    string s;
    long long x, y, z, r;
    long long MINX = 9999999, MINY = 9999999, MINZ = 9999999, MAXX = -9999999, MAXY = -9999999, MAXZ = -9999999;
    while(true)
    {
        fin >> x >> y >> z >> r;
        nanobot n;
        n.x = x;
        n.y = y;
        n.z = z;
        n.r = r;
        nanobots.push_back(n);
        
        MINX = min(x, MINX);
        MINY = min(y, MINY);
        MINZ = min(z, MINZ);
        
        MAXX = max(x, MAXX);
        MAXY = max(y, MAXY);
        MAXZ = max(z, MAXZ);
        
        if(fin.eof())
            break;
    }
    
    ll MAX = 0;
    nanobot bestBot;
    for(auto bot : nanobots)
    {
        if(inrange(bot.x, bot.y, bot.z) > MAX)
        {
            MAX = inrange(bot.x, bot.y, bot.z);
            bestBot = bot;
        }
    }
    
    vector<poz> pozitions;
    
    for(int i = 0; i < 1000; i++)
    {
        ll x = bestBot.x + (rand() % 10000000) - 5000000;
        ll y = bestBot.y + (rand() % 10000000) - 5000000;
        ll z = bestBot.z + (rand() % 10000000) - 5000000;
        
        searchLocalMax(x, y, z, 10000000);
        pozitions.push_back(p);
    }
    
    sort(pozitions.begin(), pozitions.end(), [] (const poz A, const poz B){
        if(A.inrange == B.inrange)
        {
            if(abs(A.x) + abs(A.y) + abs(A.z) < abs(B.x) + abs(B.y) + abs(B.z))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return A.inrange < B.inrange;
        }
    });
    
    
    cout << pozitions[0].x + pozitions[0].y + pozitions[0].z << endl;

    return 0;
}
