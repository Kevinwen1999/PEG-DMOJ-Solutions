#include <bits/stdc++.h>
using namespace std;
struct point {
    int x;
    int y;
};
bool cmp(point &a, point &b) {
    return a.x == b.x ? a.y < b.y : a.x < b.x;
}
bool cmp1(point &a, point &b) {
    return a.y == b.y ? a.x < b.x : a.y < b.y;
}
vector <point> v;
int N, W, H;

int main() {
    scanf("%d %d %d", &W, &H, &N);
    for (int i = 0, a, b; i < N; i++) {
        scanf("%d %d", &a, &b);
        v.push_back((point){a, b});
    }
    N += 4;
    v.push_back((point){0, 0});
    v.push_back((point){0, H});
    v.push_back((point){W, 0});
    v.push_back((point){W, H});
    sort(v.begin(), v.end(), cmp);
    int L = 0;
    for (int i = 0; i < N; i++) {
        int miny = 0, maxy = H;
        for (int j = i + 1; j < N; j++) {
            int nl = (v[j].x - v[i].x) * (maxy - miny);
            L = max(L, nl);
            if (v[j].x == v[i].x) continue;
            if (v[j].y > v[i].y)
                maxy = min(maxy, v[j].y);
            else
                miny = max(miny, v[j].y);
        }
    }
    sort(v.begin(), v.end(), cmp1);
    for (int i = 0; i < N; i++) {
        int minx = 0, maxx = W;
        for (int j = i + 1; j < N; j++) {
            int nl = (v[j].y - v[i].y) * (maxx - minx);
            L = max(L, nl);
            if (v[j].y == v[i].y) continue;
            if (v[j].x > v[i].x)
                maxx = min(maxx, v[j].x);
            else
                minx = max(minx, v[j].x);
        }
    }
    printf("%d\n", L);
}
