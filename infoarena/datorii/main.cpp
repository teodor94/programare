#include<cstdio>

const int N = 15005;

int a[N], aib[N], n, m;

inline int put2(int x) {
    return x ^ (x & (x - 1));
}

void citire() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
}

void init() {
    for (int i = 1; i <= n; ++i) {
        aib[i] += a[i];

        if (i + put2(i) <= n)
            aib[i + put2(i)] += aib[i];
    }
}

void update(int pos, int val) {
    while (pos <= n) {
        aib[pos] -= val;
        pos += put2(pos);
    }
}

int query(int pos) {
    int sum = 0;

    while (pos > 0) {
        sum += aib[pos];
        pos -= put2(pos);
    }

    return sum;
}

inline int ask(int x1, int x2) {
    return query(x2) - query(x1 - 1);
}

void rez() {
    int tip, p, q;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &tip, &p, &q);

        if (tip == 0) {
            update(p, q);

            continue;
        }

        printf("%d\n", ask(p, q));
    }
}

int main() {
    freopen("datorii.in", "r", stdin);
    freopen("datorii.out", "w", stdout);

    citire();

    init();

    rez();

    return 0;
}
