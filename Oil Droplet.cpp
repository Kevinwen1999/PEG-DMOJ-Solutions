#include <bits/stdc++.h>
using namespace std;
int N;
double drop[101];
int main()
{
    cin>>N;
    for (int i = 0; i < N; i++)
        cin>>drop[i];
    double last = 1<<30, elem = 1<<30 - 1;
    while (last!=elem)
    {
        last = elem;
        for (int i = 0; i < N; i++)
        {
            int cons = drop[i]*1.01 / elem;
            if (elem*cons < drop[i]*0.99)
            {
                elem =drop[i]*1.01/(double)(cons+1);
            }
        }
    }
    printf("%.4lf", elem);
}
