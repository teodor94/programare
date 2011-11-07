#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;

const int N = 100002;

struct lupu {
    int d, g;
};

int n, x, l;
lupu v[N];
priority_queue<int> heap;

bool comp(lupu a, lupu b) {
    if (a.d == b.d)
        return a.g > b.g;
    return a.d < b.d;
}

void citire() {
    scanf("%d%d%d", &n, &x, &l);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &v[i].d, &v[i].g);

        if (v[i].d > x) {
            --i;
            --n;
        }
    }
}

void rez() {
    long long gmax = 0, distmax = (long long) x;

    while (distmax - l >= v[1].d)
        distmax -= l;

    int i = 1;

    while (1) {
        if (v[i].d > distmax || i > n) {
            if (!heap.empty()) {
                gmax += heap.top();
                heap.pop();
            }

            distmax += l;

            if (distmax > x)
                break;
        }

        if (v[i].d <= distmax && i <= n) {
            heap.push(v[i].g);
            ++i;
        }
    }

    printf("%lld\n", gmax);
}

int main() {
    freopen("lupu.in", "r", stdin);
    freopen("lupu.out", "w", stdout);

    citire();

    sort(v+1, v+n+1, comp);

    rez();

    return 0;
}
