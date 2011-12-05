/*
a[] -> numere din sir
lung[i] -> lung celui mai lung subsir care se termina cu a[i]
*/
#include<cstdio>

const int N=1<<17;

int a[N], lung[N], pred[N], nr, n;

void scrie(int i) {
	if (i == 0)
        return;

	scrie(pred[i]);

	printf("%d ",a[i]);
}

int cautbin(int x) {
	int i, pas = 1<<17;

	for (i = 0; pas; pas >>= 1)
		if (i + pas <= nr && a[lung[i + pas]] < x)
			i += pas;

	return i + 1;
}

void citire() {
    scanf("%d",&n);

    for (int i = 1; i <= n; ++i)
        scanf("%d",&a[i]);
}

void rez() {
	lung[1]=1;
	nr=1;

	for (int i=2;i<=n;i++)
	{
		int j=cautbin(a[i]);

		if (j>nr)
			nr++;

		lung[j]=i;

		if (j!=1)
			pred[i]=lung[j-1];
		else
			pred[i]=0;
	}

	printf("%d\n",nr);

	scrie(lung[nr]);
}

int main() {
	freopen("scmax.in", "r", stdin);
	freopen("scmax.out", "w", stdout);

	citire();

	rez();

	return 0;
}
