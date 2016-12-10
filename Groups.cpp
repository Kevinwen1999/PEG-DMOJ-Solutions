#include <bits/stdc++.h>
using namespace std;
int N;
int graph[110][110];
int main()
{
    while (cin>>N && N)
    {
        for (int i = 1 ; i <= N; i++)
            for (int j = 1 ; j <= N; j++)
                cin>>graph[i][j];
        bool OK = true;

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (graph[i][j]<1 || graph[i][j]> N) {OK = false; break;}

        if (!OK){cout<<"no\n";continue;}

        bool iscur;
        int identity;
        OK = false;
        for (int i = 1; i <= N; i++)
        {
            iscur = true;
            for (int j = 1; j <= N; j++)
            {
                if (graph[i][j]!=j) {iscur = false; break;}
            }
            if (iscur)
            {
                identity = i; OK = true; break;
            }
        }

        if (!OK){cout<<"no\n";continue;}

        OK = true;
        for (int i = 1; i <= N; i++)
        {
            iscur = false;
            for (int j = 1; j <= N; j++)
                if (graph[i][j] == identity && graph[i][j] == graph[j][i]) {iscur = true; break;}
            if (!iscur) {OK= false; break;}
        }

        if (!OK){cout<<"no\n";continue;}

        OK = true;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                for (int k = 1; k <= N; k++)
                    if (graph[i][graph[j][k]] != graph[graph[i][j]][k]) {OK = false; break;}

        if (!OK){cout<<"no\n";continue;}
        else cout<<"yes\n";
    }
}
