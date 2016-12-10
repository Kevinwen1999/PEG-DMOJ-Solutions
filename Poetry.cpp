#include <iostream>
#include <string>
#include <sstream>
//TLE VERSION
using namespace std;
string in,sub,WW;
int Wx[100010],N,W;
int main()
{
        stringstream ss;
        getline(cin,WW);
        ss.str(WW);
        ss>>N;
        for (int i = 0 ; i < N; i++)
        {
            ss.clear();
            getline(cin,WW);
            ss.str(WW);
            ss>>Wx[i];
        }
        getline(cin,in);
        int l = 0,r,rr;
        int len = in.size();
        int cycle = 0;
        while(1)
        {
            W = Wx[cycle];
            cycle++;
            if (cycle>=N) cycle = 0;
            r = l+W-1;
            rr = r;
            if (r>=len-1)
            {
                printf("%.*s", len-l, in.begin()+l);
                printf("\n");
                break;
            }
            else
            {
                while(in[r]!=' '&&r!=l)
                    r--;
                if (r!=l)
                {
                    if (in[rr+1]==' ')
                    {
                        printf("%.*s", W, in.begin()+l);
                        printf("\n");
                        l = l+W+1;
                    }
                    else
                    {
                        printf("%.*s", r-l+1, in.begin()+l);
                        printf("\n");
                        l = r+1;
                    }
                }
                else
                {
                    if (in[rr+1]==' ')
                    {
                        printf("%.*s", W+1, in.begin()+l);
                        printf("\n");
                        l = l+W+1;
                    }
                    else
                    {
                        printf("%.*s", W, in.begin()+l);
                        printf("\n");
                        l = l+W;
                    }
                }
            }

        }
}
