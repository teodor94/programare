#include<cstdio>

inline int distmin(int x1, int y1, int x2, int y2) {
    int min = x1 - x2;

    if (x2 - 1 < min)
        min = x2 - 1;

    if (y1 - y2 < min)
        min = y1 - y2;

    if (y2 - 1 < min)
        min = y2 - 1;

    return min;
}

void rez() {
    int t;
    scanf("%d", &t);

    int m, n, x, y;

    for (int i = 1; i <= t; ++i) {
        scanf("%d%d%d%d", &m, &n, &x, &y);

        if (distmin(m, n, x, y) <= 4)
            printf("DA\n");
        else
            printf("NU\n");
    }
}

int main() {
    freopen("chatnoir.in", "r", stdin);
    freopen("chatnoir.out", "w", stdout);

    rez();

    return 0;
}
