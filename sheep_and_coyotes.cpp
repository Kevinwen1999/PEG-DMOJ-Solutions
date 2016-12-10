#include <iostream>
#include <algorithm>
#include<iomanip>
using namespace std;
int n;
long double xm, ym, s, p;
double x[1001];
double y[1001];
bool out[1001];
int main()
{
    cin>>n;
    for (int i = 0 ; i <n; i++)
    {
        cin>>x[i]>>y[i];
        out[i] = false;
    }
    for (int i = 0 ; i <n; i++)
    {
        long double left  = 0, right = 1000;
        for (int j = 0 ; j <n; j++)
        {
            if (!out [i] && !out [j] && i != j)
            {
                xm = (x [i] + x [j]) / 2;
                ym = (y [i] + y [j]) / 2;
                if (x[i]-x[j]==0)
                {
                    if (y [i] < y [j])
                        out [j] = true;
                    else
                        out [i] = true;
                }
                else
                {
                    if (y [i] - y [j]==0)
                        p = xm;
                    else
                    {
                        s = (y [i] - y [j]) / (x [i] - x [j]);
                        p = ym*s + xm;
                    }
                    if (x [j] < x [i])
                        left = max (p, left);
                    else
                        right = min (p, right);
                }
		    }
        }
        if (left >= right)
            out [i] = true;
    }
    for (int j = 0 ; j < n ; j++)
	{
	    cout << fixed;
        cout << setprecision(2);
	    if (!out [j])
	    {
            cout<<"The sheep at ("<<x[j]<<", " <<y[j]<<") might be eaten."<<endl;
	    }
	}
	return 0;
}
