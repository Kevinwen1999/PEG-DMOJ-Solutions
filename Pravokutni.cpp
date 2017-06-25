#include <bits/stdc++.h>
#define MAXN 1501
#define EPS 1e-9
using namespace std;
int N;
struct Point {
    double x, y;
}ap[MAXN], tmp[MAXN];
double dot(const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y;
}
double cross(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}
bool cmp(const Point& p1, const Point& p2) {
    if (p1.y == 0 && p2.y == 0 && p1.x * p2.x <= 0) return p1.x > p2.x;
    if (p1.y == 0 && p1.x >= 0 && p2.y != 0) return true;
    if (p2.y == 0 && p2.x >= 0 && p1.y != 0) return false;
    if (p1.y * p2.y < 0) return p1.y > p2.y;
    double c = cross(p1, p2);
    return c > 0 || (fabs(c) < EPS && fabs(p1.x) < fabs(p2.x));
}
int main() {
    scanf("%d", &N);
    for(int i = 0, a, b; i < N; i++) {
        scanf("%lf %lf", &ap[i].x, &ap[i].y);
    }
    int tot = 0;
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            else {
                tmp[cnt++] = (Point){ap[j].x - ap[i].x, ap[j].y - ap[i].y};
            }
        }
        sort(tmp, tmp + cnt, cmp);
        int L = 0, R = 0;
        while(L < cnt) {
            if(R == L) {R = (R + 1) % cnt;}
            while(R != L && (cross(tmp[L], tmp[R]) >= 0 && dot(tmp[L], tmp[R]) > 0) )
                R = (R + 1) % cnt;
            if (R == L) {
                L++;
                R = (R + 1) % cnt;
                continue;
            }
            if (fabs(dot(tmp[L], tmp[R])) < EPS && cross(tmp[L], tmp[R]) > 0) {
                int oR = R;
                while (fabs(dot(tmp[L], tmp[R])) < EPS && cross(tmp[L], tmp[R]) > 0) {
                    tot++;
                    R = (R + 1) % cnt;
                }
                R = oR;
            }
            L++;
        }
    }
    printf("%d", tot);
}
