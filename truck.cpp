#include <iostream>
#include <vector>
using namespace std;
int minx;
int maxx;
int counter = 0;
void rec(vector<int>& ary,int n,int j)
{   if (j==n)
        {
            counter++;
        }
    else
        {
        for (int i = j+1; i <= n; i++)
        {

            if((ary[i]-ary[j])>=minx&&(ary[i]-ary[j])<=maxx)
            {
                rec(ary,n,i);
            }
        }
        }
}
int main()
{

    cin>>minx;
    cin>>maxx;
    int sizex = 0;
    cin>>sizex;
    int stops[14] = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
    vector<int> ary(&stops[0], &stops[0]+14);
    //vector<int>::iterator Iter;
    if(sizex == 0)
    {
        int nx = ary.size()-1;
        for (int k = 0; k <= nx; k++)
        {
            if (ary[k]>=minx&&ary[k]<=maxx)
            {
                rec(ary,nx,k);
            }
        }

    }
    else
    {
        for (int i = 0; i < sizex; i++)
        {
            int n;
            cin>>n;
            for(int j = 0; j < ary.size()-1; j++)
            {
                if(ary[j]<n&&ary[j+1]>n)
                {
                    ary.insert(ary.begin()+(j+1),n);
                }
            }
        }
        int nx = ary.size()-1;
        for (int k = 0; k <= nx; k++)
        {
            if (ary[k]>=minx&&ary[k]<=maxx)
            {
                rec(ary,nx,k);
            }
        }

    }

    /*for(Iter = ary.begin(); Iter != ary.end(); Iter++)
    cout<<" "<<*Iter;*/

cout<<counter;
    return 0;
}
