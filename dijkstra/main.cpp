#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

const int N = 50005;

int n, m, l[N];
vector<pair<int, int> > v[N];
priority_queue<pair<int, int> > heap;

void citire() {
    freopen("dijkstra.in", "r", stdin);
    freopen("dijkstra.out", "w", stdout);

    scanf("%d%d", &n, &m);
    int c, x, y;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &x, &y, &c);

        v[x].push_back(make_pair(c, y));
    }
}

void rez() {
    heap.push(make_pair(0, 1)); // adaug perechea de cost 0 catre nodul 1 in heap
    // costul initial este 0

    while (!heap.empty()) { // cat timp nu am terminat
        pair<int, int> nodc = heap.top(); // retin nodul curent
        heap.pop(); // scot din heap

        if (!l[nodc.second]) { // daca nu am mai trecut prin nodul curent
            l[nodc.second] = nodc.first; // pun costul
            // parcurg vecinii
            for (vector<pair<int, int> >::iterator it = v[nodc.second].begin(); it != v[nodc.second].end(); ++it)
                if (!l[it->second]) // daca nu am mai trecut prin nod
                    heap.push(make_pair(nodc.first - it->first, it->second));
                    // pun in heap nodul urmator; costul lui va fi egal cu (-1) * costul curent + costul muchiei
                    // costul initial este 0.
        }
    }

    // fiindca am inceput de la costul 0 si am mers descendent, toate costurile se trec cu plus
    for (int i = 2; i <= n; ++i)
        l[i] *= (-1);
}

void afis() {
    for (int i = 2; i <= n; ++i)
        printf("%d ", l[i]);
}

int main() {
    citire();

    rez();

    afis();

    return 0;
}
