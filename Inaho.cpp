#include <bits/stdc++.h>
#include "inaho.h"
using namespace std;
const int MAXN = 500010;
int UFDS[MAXN], sz[MAXN];
int NN;
typedef pair<int, int> pii;
typedef pair<pii, int> node;
stack <node> alledge;
node tmp;
void Init(int N)
{
    NN = N;
    for (int i = 0 ; i <= N; i++)
    {
        UFDS[i] = i;
        sz[i] = 1;
    }
}
int findset(int i)
{
    return (UFDS[i]==i)? i : findset(UFDS[i]);
}
void AddEdge(int U, int V)
{
    int ru = findset(U), rv = findset(V);
    if(ru == rv)
    {
        alledge.push(make_pair(make_pair(ru, rv), 0));
        return;
    }
    alledge.push(make_pair(make_pair(ru, rv), 1));
    if (sz[ru] > sz[rv])
    {
        sz[ru] += sz[rv];
        UFDS[rv] = UFDS[ru];
    }
    else
    {
        sz[rv] += sz[ru];
        UFDS[ru] = UFDS[rv];
    }
}
void RemoveLastEdge()
{
    tmp = alledge.top();
    alledge.pop();
    if (!tmp.second) return;
    pii fin = tmp.first;
    if (UFDS[fin.first] == fin.first)
    {
        UFDS[fin.second] = fin.second;
        sz[fin.first] -= sz[fin.second];
    }
    else
    {
        UFDS[fin.first] = fin.first;
        sz[fin.second] -= sz[fin.first];
    }
}
int GetSize(int U)
{
    return sz[findset(U)];
}
