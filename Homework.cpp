#include <iostream>
#include <vector>

using namespace std;
int a, b, k;
const int MAXN = 10000010;
int nDiffPM[MAXN];
int T;
int main()
{
    for (int i = 2; i <=MAXN; i++)
        if (nDiffPM[i]==0)
            for (int j = i; j <=MAXN; j+=i)
                nDiffPM[j]++;
    scanf("%d", &T);
    for (int cse = 1; cse <= T; cse ++)
    {
        scanf("%d%d%d", &a, &b, &k);
        int tot = 0;
        for (int i = a; i <= b; i++)
            if (nDiffPM[i] == k) tot++;
        printf("Case #%d: %d\n", cse, tot);
    }
    //memset(nDiffPM, 0, sizeof nDiffPM);
}

