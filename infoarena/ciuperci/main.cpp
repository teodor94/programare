// d[i] = d[i / 2] * d[i / 2] (i impar)
// d[i] = d[i / 2] * d[i / 2 - 1] * 2 (i par)
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#define ll long long

using namespace std;

const int MOD = 666013;
const int N = 32;
const int S = 19;

vector < pair < ll, int > > a[N]; // creez o matrice a pentru a retine valorile deja calculate.
char s[S];

inline int cauta(ll x, int exp) {
    for (int i = 0; i < (int)a[exp].size(); ++i)
        if (a[exp][i].first == x)
            return a[exp][i].second;

    return -1;
}

inline int arbore(ll x) {
    if (x == 1)
        return 1;

    if (x == 2)
        return 2;

    int putere = x & 31, rez = cauta(x, putere); // caut in matricea a daca am calculat deja valoarea pentru x

    if (rez != -1) // daca am calculat deja, o afisez
        return rez;

    if (x & 1) {
        rez = arbore(x >> 1);
        rez = (ll)rez * rez % MOD;
    }
    else
        rez = ((ll)arbore(x >> 1) * arbore((x >> 1) - 1) << 1) % MOD;

    a[putere].push_back(make_pair(x, rez)); // adaug in matrice rez ca valoare calculata pentru x

    return rez;
}

void sterg() {
    for (int i = 0; i < N; ++i)
        a[i].clear();
}

void solve() {
    int t;
    scanf("%d\n", &t);

    for (int i = 1; i <= t; ++i) {
        gets(s);

        long long n = 0;

        for (int j = 0; s[j] >= '0' && s[j] <= '9'; ++j)
            n = n * 10 + s[j] - '0';

        printf("%d\n", arbore(n));

        sterg();
    }
}

int main() {
    freopen("ciuperci.in", "r", stdin);
    freopen("ciuperci.out", "w", stdout);

    solve();

    return 0;
}
