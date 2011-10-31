#include<cstdio>

const int N = 20002;

char s1[N], s2[N];

int n1, n2, k, d[2][N], a[N];

void citire() {
    scanf("%d %d %d\n", &n1, &n2, &k);
    gets(s1);
    gets(s2);
}

inline int egal(int x, int y) {
    if (s1[x] == s2[y])
        return 0;
    return 1;
}

inline int min(int x, int y, int z) {
    int m = x;

    if (y < m)
        m = y;

    if (z < m)
        m = z;

    return m;
}

void copiere(int x[], int y[]) {
    for (int i = 0; i <= n2; ++i)
        x[i] = y[i];
}

void dinamica() {
    for (int i = 1; i <= n1; ++i) {
        d[i & 1][0] = i;

        for (int j = 1; j <= n2; ++j) {
            a[j] = min(d[(i - 1) & 1][j] + 1, d[i & 1][j - 1]+1, d[(i - 1) & 1][(j - 1) & 1] + egal(i, j));

            copiere(d[(i - 1) & 1], d[i & 1]);

            copiere(d[i & 1], a);
        }
    }
}

void afis() {
    for (int i = 0; i < 2; ++i, printf("\n"))
        for (int j = 1; j <= n2; ++j)
            printf("%d ", d[i & 1][j]);
}

void rez() {
    for (int j = 1; j <= n2; ++j)
        d[0][j] = j;

    dinamica();

    afis();

    printf("%d\n", d[n1&1][n2]);
}

int main() {
    freopen("edist.in", "r", stdin);
    freopen("edist.out", "w", stdout);

    citire();

    rez();

    return 0;
}
