#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include <string>
using namespace std;
const int maxn=1e7+1000000;
struct cp{
    double r,i;
    cp(double _r=0,double _i=0):
        r(_r),i(_i){}
    cp operator+(cp x){return cp(r+x.r,i+x.i);}
    cp operator-(cp x){return cp(r-x.r,i-x.i);}
    cp operator*(cp x){return cp(r*x.r-i*x.i,r*x.i+i*x.r);}
};
cp a[maxn],b[maxn],A[maxn],x,y,c[maxn];
string s1,s2;
int sum[maxn],a1[maxn],a2[maxn],dig[maxn];
int len1,len2,rev[maxn],N,L;
void FFT(cp a[],int flag){
    for(int i=0;i<N;i++)A[i]=a[rev[i]];
    for(int i=0;i<N;i++)a[i]=A[i];
    for(int i=2;i<=N;i<<=1){
        cp wn(cos(2*M_PI/i),flag*sin(2*M_PI/i));
        for(int k=0;k<N;k+=i){
            cp w(1,0);
            for(int j=k;j<k+i/2;j++){
                x=a[j];
                y=a[j+i/2]*w;
                a[j]=x+y;
                a[j+i/2]=x-y;
                w=w*wn;
            }
        }
    }
    if(flag==-1)for(int i=0;i<N;i++)a[i].r/=N;
}
int main(){
    //scanf("%s%s",s1,s2);
    cin>>s1>>s2;
    len1=s1.size();
    len2=s2.size();
    for(N=1,L=0;N<max(len1,len2);N<<=1,L++);N<<=1;L++;
    for(int i=0;i<N;i++){
        int len=0;
        for(int t=i;t;t>>=1)dig[len++]=t&1;
        for(int j=0;j<L;j++)rev[i]=(rev[i]<<1)|dig[j];
    }
    for(int i=0;i<len1;i++)a1[len1-i-1]=s1[i]-'0';
    for(int i=0;i<len2;i++)a2[len2-i-1]=s2[i]-'0';
    for(int i=0;i<N;i++)a[i]=cp(a1[i]);
    for(int i=0;i<N;i++)b[i]=cp(a2[i]);
    FFT(a,1);FFT(b,1);
    for(int i=0;i<N;i++)c[i]=a[i]*b[i];
    FFT(c,-1);
    for(int i=0;i<N;i++)sum[i]=c[i].r+0.5;
    for(int i=0;i<N;i++){
        sum[i+1]+=sum[i]/10;
        sum[i]%=10;
    }
    int l=len1+len2-1;
    while(sum[l]==0&&l>0)l--;
    for(int i=l;i>=0;i--)
    putchar(sum[i]+'0');
    putchar('\n');
    return 0;
}
