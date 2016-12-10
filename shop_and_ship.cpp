#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;
int INF = 9999999;
int V;
int E;
int D;
vector < pair <int, int> >adjacencyList[5050];
queue <int> buff;
void spfa( int st);
long long dist[5050];
bool done[5050];
int price[5050];
long long total;
int des;
int main()
{
    int temp;
    scan(temp);
    V = temp;
    scan(temp);
    E = temp;
    for (int i = 1 ; i <= V; i++)
    {
        dist[i] = INF;
        price[i] = INF;
    }
    for (int i = 0 ; i < E; i++)
    {
        int a, b, c;
        scan(a);scan(b);scan(c);
        adjacencyList[a].push_back(make_pair(b,c));
        adjacencyList[b].push_back(make_pair(a,c));
    }
    scan(D);
    for (int i = 0 ; i < D; i++)
    {
        int temp1,temp2;
        scan(temp1);scan(temp2);
        price[temp1] = temp2;
    }
    scan(des);
    spfa(des);
    long long  curmin = INF;
    for (int i = 1 ; i <= V; i++)
    {
        if (price[i]!=INF)
        {
            total = dist[i] + price[i];
            if (total<curmin)
                curmin = total;
        }
    }
    cout<<curmin;
    return 0;
}
void spfa(int st)
{
    dist[st] = 0;
    buff.push(st);
    done[st] = true;
    while (!buff.empty())
    {
        int temp = buff.front();
        buff.pop();
        done[temp] = false;
        for (int i = 0; i < (int)adjacencyList[temp].size(); i++)
        {
            pair<int,int> v = adjacencyList[temp][i];
            if ((dist[temp]+ v.second) < dist[v.first])
            {
                dist[v.first] = dist[temp]+v.second;
                if (done[v.first]==false)
                {
                    buff.push(v.first);
                    done[v.first] = true;
                }
            }
        }

    }
}
