#include <bits/stdc++.h>
#define MAXN 150010
using namespace std;
int N, M, Q, sq = 400;
int L[MAXN], A[MAXN], shift[MAXN], blksum[410], indx[MAXN], rightmost[MAXN][410];
vector <int> trainsinline[MAXN];
int valueof(int idx){
    int ln = L[idx];
    int initpos = indx[idx];
    int sz = (int) trainsinline[ln].size();
    int finalpos = ((initpos%sz)-(shift[ln]%sz) + sz) % sz;
    return A[trainsinline[ln][finalpos]];
}
void operate(int ln){
    int start = -1;
    int prev = 0, nex = 0;
    for (int i = 0; i < sq; i++){
        int rt = rightmost[ln][i];
        if (!(~rt)) continue;
        if (!(~start)) start = i;
        blksum[i]+=prev;
        nex = valueof(rt);
        blksum[i]-=nex;
        prev = nex;
    }
    blksum[start] += prev;
    shift[ln]++;
}
long long query(int lm, int rm){
    int LB = lm/sq, RB = rm/sq;
    //cout<<LB<<" "<<RB<<"\n";
    long long ans = 0;
    for (int i = LB; i < RB; i++)
        ans += blksum[i];
    //return ans;
    for (int i = LB*sq; i < lm; i++)
        ans -= valueof(i);
    for (int i = RB*sq; i <= rm; i++)
        ans += valueof(i);
    return ans;
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    memset(rightmost, -1, sizeof rightmost);
    cin>>N>>M>>Q;
//    sq = (int)sqrt(N);
//    sq += (N%sq!=0);
    //cout<<sq<<"\n";
    for (int i = 0; i < N; i++){
        cin>>L[i];
        indx[i] = trainsinline[L[i]].size();
        trainsinline[L[i]].push_back(i);
        rightmost[L[i]][i/sq] = i;
    }
    for (int i = 0; i < N; i++){
        cin>>A[i];
        blksum[i/sq]+=A[i];
    }
    while(Q--){
        int op;
        cin>>op;
        if (op==1){
            int lm, rm;
            cin>>lm>>rm;
            cout<<query(lm-1,rm-1)<<"\n";
        }
        else{
            int ln;
            cin>>ln;
            operate(ln);
        }
    }
}
