#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int N;
pair <int,int> buff[1000010];
int top= -1;
int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int h ; scanf("%d", &h);
        int ic = 0;
        while(top >= 0 && buff[top].first <= h)
            top--;
        if (top>=0) ic = i - buff[top].second;
        else if (i!=0) ic = i;
        buff[++top] = make_pair(h, i);
        cout<<ic<<" "; //printf("%d ", ic);
    }
}
