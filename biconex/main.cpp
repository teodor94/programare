#include<cstdio>
#include<vector>

using namespace std;

const int N = 100005;

int n, m, nivel[N], nivelmin[N], urm[N], nr;

vector <int> v[N], mat[N];

bool marcat[N], afisare;

void citire() {
    scanf("%d%d", &n, &m);

    int x, y;

    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &x, &y);

        v[x].push_back(y);
        v[y].push_back(x);
    }

}

void dfs(int nod, int pred) {
    marcat[nod] = true;

    bool gasit = false;

    for (int i = 0; i < (int)v[nod].size(); ++i)
        if (!marcat[v[nod][i]]) {
            nivel[v[nod][i]] = nivel[nod] + 1;

            urm[nod] = v[nod][i];

            gasit = true;

            dfs(v[nod][i], nod);
        }
    if (!gasit) {
        nivelmin[nod] = nivel[nod];

        for (int i = 0; i < (int)v[nod].size(); ++i)
            if (v[nod][i] != pred)
                nivelmin[nod] = min(nivelmin[nod], nivel[v[nod][i]]);
    }
    if (gasit) {
        nivelmin[nod] = min(nivel[nod], nivelmin[urm[nod]]);
        for (int i = 0; i < (int)v[nod].size(); ++i)
            if (v[nod][i] != pred)
                nivelmin[nod] = min(nivelmin[nod], nivel[v[nod][i]]);
    }
}

void afis(int nod) {
    marcat[nod] = true;

    if (!afisare && nivelmin[nod] >= nivel[nod]) {
        mat[++nr].push_back(nod);

        afisare = true;

        for (int i = 0; i < (int)v[nod].size(); ++i)
            if (!marcat[v[nod][i]])
                afis(v[nod][i]);

        afisare = false;
    }
    else
    if (afisare) {
        mat[nr].push_back(nod);

        for (int i = 0; i < (int)v[nod].size(); ++i)
            if (!marcat[v[nod][i]])
                afis(v[nod][i]);
    }
    else {
        for (int i = 0; i < (int)v[nod].size(); ++i)
            if (!marcat[v[nod][i]])
                afis(v[nod][i]);
    }
}

int main() {
    freopen("biconex.in", "r", stdin);
    freopen("biconex.out", "w", stdout);

    citire();

    nivel[1] = 1;

    dfs(1,0);

    nivelmin[1] = 0;

    for (int i = 0; i < N; ++i)
        marcat[i] = false;

    //for (int i = 1; i <= n; ++i,printf("\n"))
    //    printf("%d %d", nivel[i], nivelmin[i]);
    //printf("\n");

    afisare = false;

    afis(1);

    printf("%d\n", nr);

    for (int i = 1; i <= nr; ++i,printf("\n"))
        for (int j = 0; j < (int)mat[i].size(); ++j)
            printf("%d ", mat[i][j]);
    return 0;
}
