#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int base[1025][1025];
int dp[1025][1025];
int temp[1025][1025];
int N;
long long INF = 999999999;
long long NINF = -999999999;
int i1 , j1, i2 , j2 ;
long long smax = NINF, smin = INF, rmax = NINF, rmin = INF, cmax = NINF, cmin = INF;
long long t1 = 0, t2 = 0;
inline int maxx(int a, int b) { return (a > b) ? a : b; }
inline int minx(int a, int b) { return (a < b) ? a : b; }
int main()
{
    cin>>N;
    N-=1;
    cin>>i1>>j1;
    for (int i = 0; i < i1; i++)
    {
        for (int j = 0 ; j < j1; j++)
        {
            cin>>base[i][j];
        }
    }
    for (int i = 0 ; i < N; i++)
    {
        cin>>i2>>j2;
        for (int i = 0 ; i < 1025; i++)
        {
            for (int j = 0 ; j < 1025; j++)
            {
                temp[i][j] = 0;
                dp[i][j] = 0;
            }
        }
        for (int j = 0 ; j < i2; j++)
        {
            for (int k = 0 ; k < j2; k++)
            {
                cin>>dp[j][k];
            }
        }
        for (int j = 0 ; j < i1; j++)
        {
            for (int k = 0 ; k < j1; k++)
            {
                for (int l = 0 ; l < i2; l++)
                {
                    for (int m = 0 ;m < j2; m++)
                    {
                        temp[j*i2+l][k*j2+m] = base[j][k] * dp[l][m];
                    }
                }
            }
        }
        memcpy(&base, &temp, sizeof temp);
        i1 = i1 * i2;
        j1 = j1 * j2;
    }
    /*for (int i = 0 ; i < i1; i++)
    {
        for (int j = 0 ; j < j1; j++)
        {
            cout<<base[i][j]<<" ";
        }
        cout<<endl;
    }*/
    for (int i = 0 ; i < i1; i++)
    {
        for (int j = 0 ; j < j1; j++)
        {
            smax = maxx(smax, base[i][j]);
            smin = minx(smin, base[i][j]);
            t1+=base[i][j];
        }
        cmax = maxx(cmax,t1);
        cmin = minx(cmin,t1);
        rmax = maxx(rmax,t2);
        rmin = minx(rmin,t2);
        t1 = 0;
    }
    for (int i = 0 ; i < j1; i++)
    {
        for (int j = 0 ; j < i1; j++)
        {
            t2+=base[j][i];
        }
        //cout<<"t2:"<<t2<<endl;
        rmax = maxx(rmax,t2);
        //cout<<"t2:"<<t2<<endl;
        rmin = minx(rmin,t2);
        //cout<<rmax<<" "<<rmin<<endl;
        t2 = 0;
    }
    cout<<smax<<"\n"<<smin<<"\n"<<cmax<<"\n"<<cmin<<"\n"<<rmax<<"\n"<<rmin<<"\n";
    return 0;
}
