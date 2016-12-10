#include<iostream>
#include<deque>
#include<cmath>
using namespace std;
deque<int> deq;
int totalx = 0;
int friendx = 0;
void check(int total,int sizex)
{
    if (sizex==1)
    {
        int temp = deq[0];
        total+=temp;
        cout<<total;
        deq.pop_back();
    }
    /*if (deq.front() == deq.back())
    {
        if(abs(deq[1]-deq[sizex-1])>abs(deq[0]-deq[sizex-2])&&sizex>=2)
        {
            total+=deq[sizex-1];
            deq.pop_back();
            return;
        }
        else
        {
            total+=deq[0];
            deq.pop_front();
            return;
        }
    }*/
    if (deq[0]>deq[sizex-1])
    {
        int temp = deq[0];
        total+=temp;
        deq.pop_front();
    }
     if (deq[0]<deq[sizex-1])
    {
        int temp = deq[sizex-1];
        total+=temp;
        deq.pop_back();
    }

}
int main()
{
    int sizexx;
    cin>>sizexx;
    deque<int> deq;
    for (int i = 0; i < sizexx; i++)
    {
        int temp;
        cin>>temp;
        deq.push_back(temp);
    }
    /*for (int i = 0; i < sizexx; i++)
    {
        cout<<deq[i];
    }*/
    //cout<<"DEQUE INIT FINISHED"<<endl;
    while(!deq.empty())
    {
        //cout<<"START WHILE:"<<endl;
        check(totalx,deq.size());
        //cout<<"me:"<<totalx<<endl;
        if(!deq.empty())
        {
            check(friendx,deq.size());
            //cout<<"friend:"<<friendx<<endl;
        }
    }
    cout<<totalx;
    return 0;
}
