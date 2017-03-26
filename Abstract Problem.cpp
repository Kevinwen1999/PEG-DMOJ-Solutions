#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; scanf("%d", &T);
    unsigned long long N;
    int tot;
    while(T--) {
        scanf("%llu", &N);
        tot = 0;
        while (N) {
            if (N&1){
                if (N&2 && N!=3){
                    N++;
                }
                else{
                    N--;
                }
            }
            else{
                N>>=1;
            }
            tot++;
        }
        printf("%d\n", tot);
    }
}
