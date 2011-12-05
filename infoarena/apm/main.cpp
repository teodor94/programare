#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<ctime>

using namespace std;

const int M = 400002;
const int N = 200002;

struct apm {
    int x, y, cost;
};

int n, m, r[N][2], tata[N], nr, smin;
apm v[M];

bool comp(apm a, apm b) {
    return a.cost < b.cost;
}

void citire() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d%d%d", &v[i].x, &v[i].y, &v[i].cost);
}

int ask(int x) {
    if (tata[x] == x)
        return x;

    return tata[x] = ask(tata[x]);
}

void uneste(int x, int y) {
    x = ask(x);
    y = ask(y);
    if ((rand() & 1) == 0)
        tata[x] = y;
    else
        tata[y] = x;
}

void rez() {
    sort(v+1, v+m+1, comp);

    for (int i = 1; i <= n; ++i)
        tata[i] = i;

    for (int i = 1; i <= m; ++i) {
        if (ask(v[i].x) == ask(v[i].y))
            continue;

        uneste(v[i].x, v[i].y);

        smin += v[i].cost;
        r[++nr][0] = v[i].x;
        r[nr][1] = v[i].y;
    }
}

void afis() {
    printf("%d\n%d\n", smin, nr);
    for (int i = 1; i <= nr; ++i)
        printf("%d %d\n", r[i][0], r[i][1]);
}

int main() {
    freopen("apm.in", "r", stdin);
    freopen("apm.out", "w", stdout);

    citire();

    rez();

    afis();

    return 0;
}
