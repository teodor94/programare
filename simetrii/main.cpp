#include<cstdio>
#include<algorithm>

using namespace std;

struct simetrii {
	int x, y;
};

const int N = 100005;

int n;

simetrii v[N], vv[N];

void citire() {
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &v[i].x, &v[i].y);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &vv[i].x, &vv[i].y);
}

bool comp(simetrii a, simetrii b) {
	if (a.x < b.x)
		return true;
	if (a.x == b.x && a.y < b.y)
		return true;
	return false;
}

bool translatie() {
	int dif = v[1].x - vv[1].x;

	for (int i = 2; i <= n; ++i)
		if (v[i].x - vv[i].x != dif)
			return false;

	dif = v[1].y - vv[1].y;

	for (int i = 2; i <= n; ++i)
		if (v[i].y - vv[i].y != dif)
			return false;

	return true;
}

void rotire90() {
	int x, y;

	for (int i = 1; i <= n; ++i)
		x = v[i].x, y = v[i].y, v[i].x = -y, v[i].y = x;

	sort(v + 1, v + n + 1, comp);
}

void rez() {
	sort(v + 1, v + n + 1, comp);
	sort(vv + 1, vv + n + 1, comp);

	for (int i = 0; i < 4; ++i) {
		if (translatie()) {
			printf("2\n");
			printf("1 0 0 %d\n", i * 90);
			printf("0 %d %d\n", vv[1].x - v[1].x, vv[1].y - v[1].y);

			return;
		}

		rotire90();
	}

	printf("-1\n");
}

int main() {
	freopen("simetrii.in", "r", stdin);
	freopen("simetrii.out", "w", stdout);

	citire();

	rez();

	return 0;
}
