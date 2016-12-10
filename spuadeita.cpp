#include<iostream>
using namespace std;
int main()
{
    int n;
    int l;
    int r;
    cin>>n>>l>>r;
    int strength[n];
    bool ava[n];
    for (int i = 0; i < n; i++)
    {
        cin>>strength[i];
    }
    for (int i = 0; i < n; i++)
    {
        ava[i]=true;
    }
    int recorder = 0;
    int turn = 1;
    int counter = 0;
    while (recorder < n)
    {
        int rec = 0;
        int index = 0;
        for (int i = 0; i < n ;i++)
        {
            if (strength[i]>rec&&ava[i]==true)
            {
                rec = strength[i];
                index = i;

            }
        }
        ava[index]=false;
        if (turn == r)
        {
            counter+=rec;
        }
        if (turn == l)
        {
            turn = 1;
        }
        else
        {
            turn++;
        }
        recorder++;
    }
    cout<<counter;
    return 0;

}
