#include<cstdio>

const int N = 1000005;

int d, n, k, a[N];

void citire() {
    scanf("%d%d%d", &d, &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
}

int cautbin(int x) {
    int i, pas = (1 << 20);

    for (i = 0; pas; pas >>= 1)
        if (i + pas <= n && a[i + pas] <= x)
            i += pas;

    return i;
}

void rez() {
    int cost = 0;

    for (int i = 1; i <= n; ++i) {
        int poz = cautbin(a[i] + d - 1);
        if (poz - i + 1 >= k)
            cost += k;
        else
            cost += poz - i + 1;
        i = poz;
    }

    printf("%d\n", cost);
}

int main() {
    freopen("zombie.in", "r", stdin);
    freopen("zombie.out", "w", stdout);

    citire();

    rez();

    return 0;
}
