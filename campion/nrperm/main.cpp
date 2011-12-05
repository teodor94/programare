#include<cstdio>
#include<cstring>

const int N = 70;
const int K = 100005;

int n, a[N], v[N], nr1, b[N], v1[N];
unsigned long long pascal[N][N];

void citire() {
    scanf("%d\n", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
}

void make_perm() {
    for (int i = 2; i <= n; ++i)
        if (a[i] < a[i - 1]) {
            v[++nr1] = i - 1;
            b[i - 1] = 1;
        }

    --n;
}

void pune(int x, int a[], int add) {
    for (int i = 2; i * i <= x; ++i)
        while (x % i == 0) {
            a[i] += add;
            x /= i;
        }

    if (x != 1)
        a[x] += add;
}

unsigned long long combinari(int n, int k) {
    if (k < 0)
        return 0;

    memset(v1, 0, sizeof(v1));

    for (int i = n - k + 1; i <= n; ++i)
        pune(i, v1, 1);

    for (int i = 2; i <= k; ++i)
        pune(i, v1, -1);

    unsigned long long rez = 1;

    for (int i = 2; i < N; ++i)
        for (int j = 1; j <= v1[i]; ++j)
            rez = (unsigned long long)rez * i;

    return rez;
}

unsigned long long pozitie() {
    unsigned long long rez = 0;

    int nr = 0;

    for (int i = 1; i <= n; ++i)
        if (b[i] == 0)
            rez += combinari(n - i, nr1 - nr - 1);
        else
        if (b[i] == 1)
            ++nr;

    return rez;
}

void rez() {
    unsigned long long pozcur = 0;

    for (int i = 0; i < nr1; ++i)
        pozcur += pascal[n][i];

    pozcur += pozitie() + 1;

    printf("%llu\n", pozcur);
}

void make_pascal() {
    pascal[0][1] = 1;

    for (int i = 1; i < 64; ++i)
        for (int j = 1; j <= i + 1; ++j)
            pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];

    for (int i = 1; i < 64; ++i)
        for (int j = 0; j <= i; ++j)
            pascal[i][j] = pascal[i][j + 1];
}

int main() {
    freopen("nrperm.in", "r", stdin);
    freopen("nrperm.out", "w", stdout);

    citire();

    make_perm();

    make_pascal();

    rez();

    return 0;
}
