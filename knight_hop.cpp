#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int ary[8][8];
int row = 8, col = 8;
int pi, pj ,ki, kj;
int answer;
queue < pair < int, int > > buff;
int main()
{
    cin>>pi>>pj>>ki>>kj;
    pi-=1;pj-=1;ki-=1;kj-=1;
    if (pi == ki && pj == kj)
    {
        cout<<0<<endl;
        return 0;
    }
    buff.push(make_pair(ki,kj));
    for (int i = 0 ; i < row; i++)
    {
        for (int j = 0 ; j < col; j++)
        {
            ary[i][j] = 0;
        }
    }

    while(!buff.empty())
    {
            pair < int , int > v = buff.front();
            int x = v.first;
            int y = v.second;
            buff.pop();
            int km = ary[x][y];
            km+=1;
            if((x+1)<row&&(y+2)<col)
            {
                ary[x+1][y+2] = km;
                if (x+1==pi&&y+2==pj)
                {
                    cout<<km<<endl;
                    return 0;
                }
                buff.push(make_pair(x+1,y+2));
            }
            if((x+1)<row&&(y-2)>=0)
            {
                ary[x+1][y-2] = km;
                if (x+1==pi&&y-2==pj)
                {
                    cout<<km<<endl;
                    return 0;
                }
                buff.push(make_pair(x+1,y-2));
            }
            if((x-1)>=0&&(y+2)<col)
            {
                ary[x-1][y+2] = km;
                if (x-1==pi&&y+2==pj)
                {
                    cout<<km<<endl;
                    return 0;
                }
                buff.push(make_pair(x-1,y+2));
            }
            if((x-1)>=0&&(y-2)>=0)
            {
                ary[x-1][y-2] = km;
                if (x-1==pi&&y-2==pj)
                {
                    cout<<km<<endl;
                    return 0;
                }
                buff.push(make_pair(x-1,y-2));
            }
            if((x+2)<row&&(y+1)<col)
            {
                ary[x+2][y+1] = km;
                if (x+2==pi&&y+1==pj)
                {
                    cout<<km<<endl;
                    return 0;
                }
                buff.push(make_pair(x+2,y+1));
            }
            if((x+2)<row&&(y-1)>=0)
            {
                ary[x+2][y-1] = km;
                if (x+2==pi&&y-1==pj)
                {
                    cout<<km<<endl;
                    return 0;
                }
                buff.push(make_pair(x+2,y-1));
            }
            if((x-2)>=0&&(y+1)<col)
            {
                ary[x-2][y+1] = km;
                if (x-2==pi&&y+1==pj)
                {
                    cout<<km<<endl;
                    return 0;
                }
                buff.push(make_pair(x-2,y+1));
            }
            if((x-2)>=0&&(y-1)>=0)
            {
                ary[x-2][y-1] = km;
                if (x-2==pi&&y-1==pj)
                {
                    cout<<km<<endl;
                    return 0;
                }
                buff.push(make_pair(x-2,y-1));
            }
    }
}
