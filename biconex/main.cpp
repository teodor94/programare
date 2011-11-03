#include<cstdio>
#include<vector>

using namespace std;

const int N = 100005;

int n, m, nr, nivel[N], nivelmin[N], biconex, muchiex[N], muchiey[N];

vector <int> v[N], mat[N];

bool marcat[N];

void citire() {
    scanf("%d%d", &n, &m);

    int x, y;

    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &x, &y);

        v[x].push_back(y);
        v[y].push_back(x);
    }

}

void dfs(int nod) {
    marcat[nod] = true;
    nivelmin[nod] = nivel[nod];

    for (vector <int>::iterator it = v[nod].begin(); it != v[nod].end(); ++it)
        if (!marcat[*it]) {
            nivel[*it] = nivel[nod] + 1;

            muchiex[++nr] = nod;
            muchiey[nr] = *it;

            dfs(*it);

            if (nivelmin[*it] >= nivel[nod]) {
                ++biconex;

                while (muchiex[nr] != nod || muchiey[nr] != *it)
                    mat[biconex].push_back(muchiey[nr--]);

                mat[biconex].push_back(nod);
                mat[biconex].push_back(*it);
                --nr;
            }

            nivelmin[nod] = min(nivelmin[nod], nivelmin[*it]);
        }
        else
            nivelmin[nod] = min(nivelmin[nod], nivel[*it]);
}

void afisare() {
    printf("%d\n", biconex);
    for (int i = 1; i <= biconex; ++i, printf("\n"))
        for (vector <int>::iterator it = mat[i].begin(); it != mat[i].end(); ++it)
            printf("%d ", *it);
}

int main() {
    freopen("biconex.in", "r", stdin);
    freopen("biconex.out", "w", stdout);

    citire();

    dfs(1);

    afisare();

    return 0;
}
