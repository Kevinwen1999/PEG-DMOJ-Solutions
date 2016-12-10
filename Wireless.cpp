#include <bits/stdc++.h>
using namespace std;
int MAXC, MAXR, col, row, radius, bitrate, leftt, rightt;
int dis;
int K;
int diff[1010][30010];
int main()
{
    cin>>MAXC>>MAXR;
    cin>>K;
    for (int i = 0 ; i < K; i++)
    {
        cin>>row>>col>>radius>>bitrate;
        row--; col--;
        for (int j = max(0,col - radius); j <= min(MAXC-1,col+radius); j++)
        {
            dis = sqrt(radius*radius - (col - j)*(col - j));
            leftt = max(0,row - dis);
            rightt = min(MAXR-1, row + dis);
            diff[leftt][j] += bitrate;
            diff[rightt+1][j] -= bitrate;
        }
    }
    int best = 0, cnt = 0;
    for (int i = 0 ; i < MAXR; i++)
        for (int j = 0 ; j < MAXC; j++)
        {
            if (i > 0) diff[i][j]+=diff[i-1][j];
            if (diff[i][j]==best) cnt++;
            if (diff[i][j] > best) {best = diff[i][j]; cnt = 1;}
        }
    cout<<best<<"\n"<<cnt<<"\n";
    return 0;
}
