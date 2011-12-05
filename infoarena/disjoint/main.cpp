#include<cstdio>
#include<cstdlib>
#include<ctime>

const int N = 100002;

int n, m, tata[N];

int ask(int x) {
    if (x == tata[x])
        return x;

    tata[x] = ask(tata[x]);

    return tata[x];
}

void muchie(int x, int y) {
    x = ask(x);
    y = ask(y);

    if (x == y)
        return;

    if ((rand() & 1) == 0)
        tata[y] = x;
    else
        tata[x] = y;
}

void rez() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i)
        tata[i] = i;

    for (int i = 1; i <= m; ++i) {
        int cod, x, y;
        scanf("%d%d%d", &cod, &x, &y);

        if (cod == 1)
            muchie(x, y);
        else
        if (ask(x) == ask(y))
            printf("DA\n");
        else
            printf("NU\n");
    }
}

int main() {
    freopen("disjoint.in", "r", stdin);
    freopen("disjoint.out", "w", stdout);

    rez();

    return 0;
}
