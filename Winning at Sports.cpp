#include <iostream>
#include <cstring>
#include <cstdio>
#define MOD 1000000007
using namespace std;
long long stressfree[2020][2020];
long long stressful[2020][2020];
int A, B, N;
int SFree(long long a, long long b)
{
    if (stressfree[a][b]!=-1) return stressfree[a][b];
    else if (a == A && b == B) return stressfree[a][b] = 1;
    else if (b==B&&a>B) return stressfree[a][b] = 1;
    else if (b==B&&a<=B) return stressfree[a][b] = 0;
    else if (a==A) return stressfree[a][b] = 1;
    else if (a>0&&a<=b) return stressfree[a][b] = 0;
    else return stressfree[a][b] = (SFree(a+1,b)%MOD+SFree(a,b+1)%MOD)%MOD;
}
int SFul(long long a, long long b)
{
    if (stressful[a][b]!=-1)return stressful[a][b];
    else if (a==A&&b==B)return stressful[a][b] = 1;
    else if (b==B&&a<A)return stressful[a][b] = 1;
    else if (a==A&&b<B)return stressful[a][b] = 0;
    else if (a>b) return stressful[a][b] = 0;
    else return stressful[a][b] = (SFul(a+1,b)%MOD+SFul(a,b+1)%MOD)%MOD;
}
int main()
{
    cin>>N;
    for (int cnt=1; cnt<=N; cnt++)
    {
        memset(stressfree,-1,sizeof stressfree);
        memset(stressful,-1,sizeof stressful);
        scanf("%d-%d",&A,&B);
        long long ans1 = SFree(0,0), ans2= SFul(0,0);
        if (B==0)ans1 = 1;
        cout<<"Case #"<<cnt<<": "<<ans1<<" "<<ans2<<endl;
    }
}
