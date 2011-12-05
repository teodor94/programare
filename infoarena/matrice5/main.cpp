#include<cstdio>

const int MOD = 10007;

int n, m, p, k;

int lgput(int x, int put) {
    if (put == 0)
        return 1;

    int prod = 1;

    while (put) {
        if (put & 1)
            prod = prod * x % MOD;
        x = x * x % MOD;
        put >>= 1;
    }

    return prod;
}

int formula() {
    int prod = 1;

    prod *= lgput(k, (n - 1) * (m - 1));
    prod %= MOD;
    /*for (int i = 1; i <= (n - 1) * (m - 1); ++i) {
        prod *= k;
        prod %= MOD;
    }*/

    prod *= lgput(p, n * m);
    prod %= MOD;
    /*for (int i = 1; i <= (n * m); ++i) {
        prod *= p;
        prod %= MOD;
    }*/

    return prod;
}

void rez() {
    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; ++i) {
        scanf("%d%d%d%d", &n, &m, &p, &k);

        printf("%d\n", formula());
    }
}

int main() {
    freopen("matrice5.in", "r", stdin);
    freopen("matrice5.out", "w", stdout);

    rez();

    return 0;
}
