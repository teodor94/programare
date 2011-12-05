#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 5;
const int M = 30;

struct portal3 {
    int v, sens, ord;
};

int n, m, x1[N], x2[N], y1[N], y2[N], c[N], s[N], nr;
long long tmin = 0, tp;
bool fr[N];
portal3 a[N];

bool comp(portal3 x, portal3 y) {
    return x.ord < y.ord ? true : false;
}

inline int modul(int x, int y) {
    if (x > y)
        return x - y;
    return y - x;
}

void timp() {
    sort(a+1, a+nr+1, comp);

    int xc = 0, yc = 0;

    tp = 0;

    for (int i = 1; i <= nr; ++i)
        if (a[i].sens == 1) {
            tp += (long long)modul(x1[a[i].v], xc) + modul(y1[a[i].v], yc) + c[a[i].v];

            xc = x2[a[i].v];
            yc = y2[a[i].v];
        }
        else {
            tp += (long long)modul(x2[a[i].v], xc) + modul(y2[a[i].v], yc) + c[a[i].v];

            xc = x1[a[i].v];
            yc = y1[a[i].v];
        }

    tp += (long long)modul(n, xc) + modul(m, yc);
}

void permutari(int p) {
    if (p == nr + 1) {
        timp();
        if (tmin == 0 || tp < tmin)
            tmin = tp;
        return;
    }

    for (int i = 1; i <= nr; ++i)
        if (!fr[i]) {
            fr[i] = true;

            a[p].ord = i;
            permutari(p + 1);

            fr[i] = false;
        }
}

void bkt(int p) {
    if (p == 3) {
        nr = 0;
        for (int i = 1; i < 4; ++i)
            if (s[i] != 0) {
                a[++nr].v = i;
                a[nr].sens = s[i];
            }
        permutari(1);
        return;
    }
    for (int i = 0; i < 3; ++i) {
        s[p + 1] = i;
        bkt(p + 1);
    }
}

void rez() {
    int t;
    scanf("%d", &t);

    for (int k = 1; k <= t; ++k) {
        scanf("%d%d", &n, &m);

        for (int i = 1; i < 4; ++i)
            scanf("%d%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i], &c[i]);

        bkt(0);

        printf("%lld\n", tmin);
        tmin = 0;
    }
}

int main() {
    freopen("portal3.in", "r", stdin);
    freopen("portal3.out", "w", stdout);

    rez();

    return 0;
}
