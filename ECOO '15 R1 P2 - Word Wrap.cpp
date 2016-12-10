#include <iostream>
#include <string>
using namespace std;
string in,sub;
int W;
int main()
{
    for (int i = 0 ; i < 10; i++)
    {
        cin>>W;
        getline(cin,in);
        int l = 0,r;
        int len = in.size();
        while(1)
        {
            r = l+W-1;
            if (r>=len)
            {
                sub = substr(in.begin()+l,len-l+1);
                cout<<sub<<endl;
                break;
            }
            else
            {
                while(in[r]!=' '||r!=l)
                {
                    r--;
                }
                if (r!=l)
                {
                    sub = substr(in.begin()+l,r-l+1);
                    cout<<sub<<endl;
                    l = r+1;
                }
                else
                {
                    sub = substr(in.begin()+l,W)
                    cout<<sub<<endl;
                    l = l+W;
                }
            }

        }
        cout<<"====="<<endl;
    }
}
