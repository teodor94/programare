#include<cstdio>
#include<algorithm>
#include<vector>
#include<ctime>
#include<cstdlib>

using namespace std;

const int M = 400005;
const int N = 200005;

int n, m, lg, heap[N], nodd[N], nr, r[N][2], total, prec[N];
bool fr[N];
vector <int> v[N], cost[N];


void citire() {
    scanf("%d%d", &n, &m);

    int x, y, c;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &x, &y, &c);
        v[x].push_back(y);
        cost[x].push_back(c);
        v[y].push_back(x);
        cost[y].push_back(c);
    }
}

inline void interschimb(int &x, int &y) {
    int aux = x;
    x = y;
    y = aux;
}

// urc fiul in heap
void urca(int fiu) {
    int pred = (fiu >> 1); // tatal este i/2
    while (pred && heap[pred] > heap[fiu]) { // daca nu am ajuns in cap si daca val fiului este mai mica decat val tatalui
        interschimb(heap[pred], heap[fiu]);
        interschimb(nodd[pred], nodd[fiu]);
        interschimb(prec[pred], prec[fiu]);

        pred = pred >> 1; // urc mai sus
        fiu = fiu >> 1;
    }
}

inline int valmin(int i, int j) {
    if (heap[i] < heap[j])
        return i;
    return j;
}

void coboara(int tat) {
    int fiu1 = tat*2, fiu2 = tat*2+1; // cei 2 fii ai nodului
    while (fiu1 <= lg || fiu2 <=lg) { // daca il pot cobori
        if (heap[tat] < heap[fiu1] && heap[tat] < heap[fiu2])
            break;

        int m = valmin(fiu1, fiu2); // interschimb
        interschimb(heap[tat], heap[m]);
        interschimb(nodd[tat], nodd[m]);
        interschimb(prec[tat], prec[m]);

        tat = m; // cobor
        fiu1 = tat*2;
        fiu2 = tat*2+1;
    }
}

void rez() {
    srand(time(0));

    int nod = rand() % n + 1, nextnod; // aleg un nod random

    fr[nod] = true;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < (int)v[nod].size(); ++j) { // parcurg vecinii lui nod
            if (fr[v[nod][j]]) // daca fac parte din aceeasi componenta
                continue; // ignor

            heap[++lg] = cost[nod][j]; // daca nu, adaug in heap, pe ultima pozitie
            nodd[lg] = v[nod][j];
            prec[lg] = nod;
            urca(lg); // urc ultima pozitie in heap
        }

        while (fr[nodd[1]]) { // cat prima pozitie din heap face parte din aceeasi componenta, o sterg
            heap[1] = heap[lg]; // pun ultima pozitie ca prima
            prec[1] = prec[lg];
            nodd[1] = nodd[lg];
            --lg; // sterg ultima pozitie
            coboara(1); // cobor prima pozitie
        }

        fr[nodd[1]] = true;
        nextnod = nodd[1];
        total += heap[1];

        r[++nr][0] = nodd[1];
        r[nr][1] = prec[1];

        heap[1] = heap[lg];
        nodd[1] = nodd[lg];
        prec[1] = prec[lg];
        --lg;
        coboara(1);

        nod = nextnod;
    }
}

void afis() {
    printf("%d\n%d\n", total, nr);
    for (int i = 1; i <= nr; ++i)
        printf("%d %d\n", r[i][0], r[i][1]);
}

int main() {
    freopen("apm.in", "r", stdin);
    freopen("apm.out", "w", stdout);

    citire();

    rez();

    afis();

    return 0;
}
