#include <bits/stdc++.h>
using namespace std;
struct node
{
    long long x;
    double y;
    long long from, to;
} cur;
bool cmp (node a, node b)
{
    return a.x > b.x;
}
vector < node > score;
int N;
int main()
{
    cin>>N;
    for (int i = 0; i < N; i++)
    {
        cin>>cur.x>>cur.y;
        //cout<<cur.x<<endl;
        score.push_back(cur);
    }
    long long tar; cin>>tar;
    sort(score.begin(), score.end(), cmp);
    long long start = 0;
    for (int i = 0; i < N; i++)
    {
        //cout<<score[i].x<<" "<<tar<<endl;
        score[i].from = start + 1;
        //cout<<start<<endl;
        score[i].to = (int)(score[i].y * 2) - score[i].from;
        //cout<<(int)(score[i].y * 2)<<" "<<score[i].from<<endl;
        if (score[i].x == tar)
        {
            //cout<<"fucl\n";
            cout<<score[i].from<<endl<<score[i].to;
            return 0;
        }
        start = score[i].to;
    }
}
