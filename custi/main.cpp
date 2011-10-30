// a[i][j]=latura maxima a submatricii (1,1)-(i,j)
#include<cstdio>

const int N=1003;

int n, fr[N], s[N];

short int sus[N][N], st[N][N], a[N][N];

bool mat[N][N];

void init() {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (mat[i][j])
				st[i][j] = st[i][j - 1] + 1, sus[i][j] = sus[i - 1][j] + 1;
}

void citire() {
	scanf("%d", &n);

    short int x;

	for (int i = 1;i <= n; ++i)
		for (int j = 1;j <= n; ++j) {
			scanf("%hd", &x);

			if (x)
                mat[i][j] = true;
        }

	init();
}

inline int min(int x, int y)
{
	return x>y ? y : x;
}

void dinamica() {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (mat[i][j])
				a[i][j] = min( min(st[i][j], sus[i][j]), a[i - 1][j - 1] + 1);
}

void frecventa() {
	//vector de frecventa
	//sume partiale vector de frecventa de la dreapta la stanga
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			++fr[a[i][j]];

	for (int i = n; i > 0; --i)
		s[i] = s[i + 1] + fr[i];
}

void afis() {
	for (int i = 1;i <= n; ++i)
		printf("%d\n", s[i]);
}

int main() {
    freopen("custi.in", "r", stdin);
	freopen("custi.out", "w", stdout);

	citire();

	dinamica();

	frecventa();

	afis();

	return 0;
}
