// d1[i][j] = cate numere intre 0 si 10 ^ (i - 1) contin j cifre de C
// d2[i][j] = cate numere care nu au 0-uri in fata intre 0 si 10 ^ (i - 1) contin j cifre de C

#include<cstdio>

const int N = 12;

int a, b, c, k, d1[N][N], d2[N][N], va[N], vb[N];

void punevector(int x,int v[]) {
    while (x) {
        ++v[0];
        v[v[0]] = x % 10;
        x /= 10;
    }
}

void dinamica1() {
    d1[0][0] = 1;
    d1[1][1] = 1;
    d1[1][0] = 9;
    for (int i = 2; i <= 10; ++i)
        for (int j = 0; j <= i; ++j) {
            d1[i][j] = 9 * d1[i - 1][j];

            if (j > 0)
                d1[i][j] += d1[i - 1][j - 1];
        }
}

void dinamica2() {
    if (c == 0)
        d2[1][0] = 9;
    else {
        d2[1][0] = 8;
        d2[1][1] = 1;
    }

    for (int i = 2; i <= 10; ++i)
        for (int j = 0; j <= i; ++j)
            if (c == 0)
                d2[i][j] = d2[i - 1][j] + 9 * d1[i - 1][j];
            else {
                d2[i][j] = d2[i - 1][j] + 8 * d1[i - 1][j];

                if (j > 0)
                    d2[i][j] += d1[i - 1][j - 1];
            }
}

int rez(int v[]) {
    int sol = 0, ck = k;
    for (int i = k; i <= v[0]; ++i)
        sol += d2[v[0] - 1][i];

    for (int i = 1; i < v[v[0]]; ++i)
        for (int j = k; j <= v[0]; ++j)
            if (i == c) {
                if(j > 0)
                    sol += d1[v[0] - 1][j - 1];
            }
            else
                sol += d1[v[0] - 1][j];

    if (v[v[0]] == c && k > 0)
        --k;

    for (int i = v[0] - 1; i > 0; --i) {
        for (int j = 0; j < v[i]; ++j)
            for (int kk = k; kk <= v[0]; ++kk)
                if (j == c) {
                    if (kk > 0)
                        sol += d1[i - 1][kk - 1];
                }
                else
                    sol += d1[i - 1][kk];

        if (v[i] == c && k > 0)
            --k;
    }

    k = ck;

    return sol;
}

int main() {
    freopen("cifre.in", "r", stdin);
    freopen("cifre.out", "w", stdout);

    scanf("%d%d%d%d", &a, &b, &c, &k);
    int total = b - a + 1;
    punevector(a, va);
    ++b;
    punevector(b, vb);

    dinamica1();

    dinamica2();

    int x = rez(vb) - rez(va);
    if (a == 0 && c == 0)
        ++x;

    printf("%.4lf", (double)x / total);

    return 0;
}
