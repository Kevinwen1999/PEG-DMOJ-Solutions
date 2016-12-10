#include <iostream>
#include <cmath>
#include <utility>
#define EPS 1e-9
using namespace std;
double X, Y, S,U;
int N;
int main()
{
    for (int a = 0 ; a < 10; a++)
    {
        pair<double,double> all[10];
        cin>>X>>N;
        X = X * (double)pow(10,N);
        cin>>Y>>N;
        Y = Y * (double)pow(10,N);
        cin>>S>>N;
        S = S * (double)pow(10,N);
        cin>>N;
        U = (S*0.5*(double)sqrt(3.0))*0.33333333333;
        S*= 0.1666666666;
        all[0] = make_pair(X,Y);
        Y+=U;
        all[1] = make_pair(X-S,Y);
        all[2] = make_pair(X+S,Y);
        Y+=U;
        all[3] = make_pair(X-2*S,Y);
        all[4] = make_pair(X,Y);
        all[5] = make_pair(X+2*S,Y);
        Y+=U;
        all[6] = make_pair(X-3*S,Y);
        all[7] = make_pair(X-S,Y);
        all[8] = make_pair(X+S,Y);
        all[9] = make_pair(X+3*S,Y);
        for (int b = 0 ; b < 5; b++)
        {
            cin>>X>>N;
            X = X * (double)pow(10,N);
            cin>>Y>>N;
            Y = Y * (double)pow(10,N);
            int ans = 0;
            double distance;
            double maxx = 999999.0;
            for (int i = 0 ; i < 10; i++)
            {
                distance = hypot(X-all[i].first,Y-all[i].second);
                if (distance < maxx)
                {
                    maxx = distance;
                    ans = i+1;
                }
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
}
