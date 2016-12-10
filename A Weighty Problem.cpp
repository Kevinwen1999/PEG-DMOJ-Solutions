#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
inline double min(double a, double b){return a < b? a: b;}
inline double max(double a, double b){return a > b? a: b;}
int C, D , K,temp0;
double temp1;
int weight[110];
pair <int , double>  denosx[110];
int backpack[110];
double dp[200001], value[110];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>C>>D>>K;
    for(int i = 0; i < 200001; i++){
        dp[i] = -1;
    }
    for (int i = 0; i < D; i++)
    {
        cin>>temp0>>temp1;
        weight[i] = temp0; value[i] = temp1;
        denosx[i] = (make_pair(temp0,temp1));
    }
    sort(denosx,denosx+D,greater<pair<int,double> >());
    int maxmoney = 0;
    double maxvalue = 0;
    for (int i = 0; i < K; i++)
        {
            cin>>temp0;
            temp0--;
            backpack[i] = temp0;
            maxmoney +=weight[backpack[i]];
            maxvalue +=value [backpack[i]];

        }
    if (maxmoney < C ){cout<<"too poor"<<endl; return 0;}
    dp[0] = 0;
    for (int i = 0; i < K; i++)
    {
        for (int j = maxmoney ; j >= weight[backpack[i]]; j--)
            if (dp[j-weight[backpack[i]]]!=-1)
                dp[j] = max(dp[j],dp[j-weight[backpack[i]]]+value[backpack[i]]);
    }
    double minv = 99999999.0;
    for (int i = C; i <= maxmoney; i++)
    {
        if (dp[i]==-1) continue;
        double extra = 0;
        int remain = i - C;
        for (int j = 0 ; j < D; j++)
        {
            int add = remain/denosx[j].first;
            extra+=add*denosx[j].second;
            remain-=add*denosx[j].first;
        }
        minv = min(maxvalue-dp[i] + extra,minv);
    }
    printf("%.2f\n", minv);
}
