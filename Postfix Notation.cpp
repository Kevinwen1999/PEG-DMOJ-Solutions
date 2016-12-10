#include <bits/stdc++.h>
using namespace std;
double first, second;
char oper;
int main()
{
    cin>>first;
    while (cin>>second>>oper)
    {
        if (oper=='+')
            first = first + second;
        if (oper=='-')
            first = first - second;
        if (oper=='*')
            first = first * second;
        if (oper=='/')
            first = 1 / second * first;
        if (oper=='%')
            first = fmod(first,second);
        if (oper=='^')
            first = pow(first,second);
    }
    printf("%.1lf\n", first);
}
