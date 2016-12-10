#include <iostream>
#include <queue>
#include <utility>
using namespace std;
void clear( queue < pair <long ,int> > &q )
{
   queue < pair <long ,int> > empty;
   swap( q, empty );
}
int ary[10];
int W;
int D;
int V;
long answer;
bool isY = false;
queue < pair <long ,int> > buff1;
queue < pair <long ,int> > buff2;
int main()
{
    cin>>W>>D;
    for (int i = 0 ; i < D; i++)
    {
        cin>>ary[i];
    }
    cin>>V;
    for (int i = 0 ; i < V; i++)
    {
        cin>>answer;
        isY = false;
        clear(buff1);
        clear(buff2);
        for (int j = 0 ; j < D&&j<=4; j++)
        {
            buff1.push(make_pair(ary[j],0));
        }
        for (int j = 5 ; j < D; j++)
        {
            buff2.push(make_pair(ary[j],0));
        }
        while(!buff1.empty())
        {
            pair< int,int > current = buff1.front();
            buff1.pop();
            if (current.first==answer&&current.second==W)
            {
                cout<<"Y"<<endl;
                isY = true;
                break;
            }
            for (int j = 0 ; j < D; j++)
            {
                if(current.second<W&&current.first+ary[j]<=answer)
                {
                    buff1.push(make_pair(current.first+ary[j],current.second+1));
                }
            }
            for (int j = 0 ; j < D; j++)
            {
                if(current.second<W&&current.first*ary[j]<=answer)
                {
                    buff1.push(make_pair(current.first*ary[j],current.second+1));
                }
            }
        }
        clear(buff1);
        while(!buff2.empty())
        {
            if (isY)
            {
                break;
            }
            pair< int,int > current = buff2.front();
            buff2.pop();
            if (current.first==answer&&current.second==W)
            {
                cout<<"Y"<<endl;
                isY = true;
                break;
            }
            for (int j = 0 ; j < D; j++)
            {
                if(current.second<W&&current.first+ary[j]<=answer)
                {
                    buff2.push(make_pair(current.first+ary[j],current.second+1));
                }
            }
            for (int j = 0 ; j < D; j++)
            {
                if(current.second<W&&current.first*ary[j]<=answer)
                {
                    buff2.push(make_pair(current.first*ary[j],current.second+1));
                }
            }
        }
        clear(buff2);
        if (!isY)
        cout<<"N"<<endl;
    }
}
