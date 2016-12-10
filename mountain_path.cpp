#include <iostream>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;

int INF = 900;
int sizex = 0;
int lower = 0;
int main()
{
    int rounds;
    cin>> rounds;
    for (int i = 0; i < rounds; i++)
    {

        cin >> sizex;
        int ary[sizex][sizex];
        int dp[sizex][sizex];
        bool vertex[sizex][sizex];
        queue < pair <int,int> > buff;
        for (int i = 0 ; i < sizex; i++)
        {
            for (int j = 0; j < sizex; j++)
            {
                cin>>ary[i][j];
            }
        }
        for (int i = 0 ; i < sizex; i++)
        {
            for (int j = 0; j < sizex; j++)
            {
                dp[i][j] = INF;
            }
        }
        for (int i = 0 ; i < sizex; i++)
        {
            for (int j = 0; j < sizex; j++)
            {
                vertex[i][j] = false ;
            }
        }
        lower = ary[0][0];
        dp[0][0] = 0;
        vertex[0][0] = true;
        //check(ary,dp,sizex-1,sizex-1,sizex-1,sizex-1);
        buff.push(make_pair(0,0));
        while(!buff.empty())
        {
            pair<int,int> v = buff.front();
            int x = v.first;
            int y = v.second;
            int oxy = dp[x][y];
            int ans = 0;
            buff.pop();
            vertex[x][y] = false;
            if ((x-1)>=0)
            {
                if (abs(ary[x-1][y]-ary[x][y])<=2)
                {
                    ans = oxy;
                    if ((ary[x-1][y]>lower)||(ary[x][y]>lower))
                    {
                        ans+=1;
                    }
                    if (dp[x-1][y]==INF)
                    {
                        dp[x-1][y] = ans;
                        if (vertex[x-1][y]==false)
                        {
                            vertex[x-1][y] = true;
                            buff.push(make_pair(x-1,y));
                        }
                    }
                    else
                    {
                        if (ans<dp[x-1][y])
                        {
                           dp[x-1][y] = ans;
                            if (vertex[x-1][y]==false)
                            {
                                vertex[x-1][y] = true;
                                buff.push(make_pair(x-1,y));
                            }
                        }
                    }
                }
            }

            if ((x+1)<sizex)
            {
                if (abs(ary[x+1][y]-ary[x][y])<=2)
                {
                    ans = oxy;
                    if ((ary[x+1][y]>lower)||(ary[x][y]>lower))
                    {
                        ans+=1;
                    }
                    if (dp[x+1][y]==INF)
                    {
                        dp[x+1][y] = ans;
                        if (vertex[x+1][y]==false)
                        {
                            vertex[x+1][y] = true;
                            buff.push(make_pair(x+1,y));
                        }
                    }
                    else
                    {
                        if (ans<dp[x+1][y])
                        {
                           dp[x+1][y] = ans;
                            if (vertex[x+1][y]==false)
                            {
                                vertex[x+1][y] = true;
                                buff.push(make_pair(x+1,y));
                            }
                        }
                    }
                }
            }

            if ((y-1)>=0)
            {
                if (abs(ary[x][y-1]-ary[x][y])<=2)
                {
                    ans = oxy;
                    if ((ary[x][y-1]>lower)||(ary[x][y]>lower))
                    {
                        ans+=1;
                    }
                    if (dp[x][y-1]==INF)
                    {
                        dp[x][y-1] = ans;
                        if (vertex[x][y-1]==false)
                        {
                            vertex[x][y-1] = true;
                            buff.push(make_pair(x,y-1));
                        }
                    }
                    else
                    {
                        if (ans<dp[x][y-1])
                        {
                           dp[x][y-1] = ans;
                            if (vertex[x][y-1]==false)
                            {
                                vertex[x][y-1] = true;
                                buff.push(make_pair(x,y-1));
                            }
                        }
                    }
                }
            }

            if ((y+1)<sizex)
            {
                if (abs(ary[x][y+1]-ary[x][y])<=2)
                {
                    ans = oxy;
                    if ((ary[x][y+1]>lower)||(ary[x][y]>lower))
                    {
                        ans+=1;
                    }
                    if (dp[x][y+1]==INF)
                    {
                        dp[x][y+1] = ans;
                        if (vertex[x][y+1]==false)
                        {
                        	vertex[x][y+1] = true;
                            buff.push(make_pair(x,y+1));
                        }
                    }
                    else
                    {
                        if (ans<dp[x][y+1])
                        {
                           dp[x][y+1] = ans;
                            if (vertex[x][y+1]==false)
                            {
                            	vertex[x][y+1]=true;
                                buff.push(make_pair(x,y+1));
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0 ; i < sizex; i++)
        {
            for (int j = 0; j < sizex; j++)
            {
                cout<<dp[i][j];
            }
            cout<<endl;
        }
        if (dp[sizex-1][sizex-1] == INF)
        {
            cout<<"CANNOT MAKE THE TRIP"<<endl<<endl;
        }
        else
        {
            cout<<dp[sizex-1][sizex-1]<<endl<<endl;
        }
    }
    return 0;
}
