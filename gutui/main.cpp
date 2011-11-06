#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 100005;

priority_queue<int> heap;

struct gutui {
    int h, g;
};

int n, h, u;
gutui v[N];

bool comp(gutui a, gutui b){
    return a.h < b.h;
}

void citire() {
    scanf("%d%d%d", &n, &h, &u);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d", &v[i].h, &v[i].g);
}

void rez() {
    int gmax = 0, inaltime = h;

    while (inaltime - u >= v[1].h)
        inaltime -= u;

    int i = 1;

    while (1) {
		if (v[i].h > inaltime || i > n) {
		    if (!heap.empty())
                gmax += heap.top(), heap.pop();
			inaltime += u;
			if (inaltime > h)
                break;
		}
		if (v[i].h <= inaltime && i <= n)
			heap.push(v[i].g), ++i;
	}

    printf("%d\n", gmax);
}

int main() {
    freopen("gutui.in","r",stdin);
    freopen("gutui.out","w",stdout);

    citire();

    sort(v+1, v+n+1, comp);

    rez();

    return 0;
}
