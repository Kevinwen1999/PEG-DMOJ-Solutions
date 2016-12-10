#include <cstdio>
using namespace std;
int N;
int xmin= 9999999, xmax , ymin= 99999999, ymax ,x,y;
int area;
inline int max(int i, int j){return i > j?i:j ;}
inline int min(int i, int j){return i < j?i:j ;}
int main()
{
    scanf("%d",&N);
    for (int i = 0 ; i < N; i++)
    {
        scanf("%d %d",&x,&y);
        xmin = min(x,xmin);xmax = max(x,xmax);ymin = min(y,ymin);ymax = max(y,ymax);
    }
    area = (xmax-xmin)*(ymax-ymin);
    printf("%d\n",area);
    return 0;
}
