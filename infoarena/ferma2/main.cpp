#include<cstdio>

const int N = 1002;
const int M = 5;
const int INF = 0x3f3f3f3f;

int n, k, a[N][N], sl[N][N], sc[N][N], sd[N][N], d[N][N];

void citire() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            scanf("%d", &a[i][j]);
}

void afis(int v[N][N]) {
    for (int i = 1; i <= n; ++i, printf("\n"))
        for (int j = 1; j <= i; ++j)
            printf("%d ", v[i][j]);

    printf("\n");
}

void sumepartiale() {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j) {
            sl[i][j] = sl[i][j - 1] + a[i][j];
            sc[i][j] = sc[i - 1][j] + a[i][j];
            sd[i][j] = sd[i - 1][j - 1] + a[i][j];
        }
}

void dinamica() {
    // d[i][j] = profitul minim pentru un triunghi de latura n - k, cu coltul in (i, j)

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j)
            d[i][j] = -1;

    d[n][1] = 0;
    for (int i = k + 1; i <= n; ++i)
        d[n][1] += sl[i][i - (k + 1) + 1];

    for (int j = 2; j <= k + 1; ++j)
        d[n][j] = d[n][j - 1] - (sc[n][j - 1] - sc[k][j - 1]) + (sd[n][j + (n - k) - 1] - sd[k][j - 1]);
    for (int i = n - 1; i >= n - k; --i)
        for (int j = 1; j + n - k - 1 <= i; ++j)
            d[i][j] = d[i + 1][j] - (sl[i + 1][j + n - k - 1] - sl[i + 1][j - 1]) + (sd[i][j + n - k - 1] - sd[i - (n - k)][j - 1]);
}

void rez() {
    int min = INF, sum = 0;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j) {
            sum += a[i][j];

            if (d[i][j] != -1 && d[i][j] < min)
                min = d[i][j];
        }

    printf("%d\n", sum - min);
}

int main() {
    freopen("ferma2.in", "r", stdin);
    freopen("ferma2.out", "w", stdout);

    citire();

    sumepartiale();

    dinamica();

    rez();

    return 0;
}
