#include<cstdio>
#include<cstring>

const int N = 502;
const int K = 28;

int n, d[N][N][K];
char s[N];

inline int max(int x, int y) {
    return x > y ? x : y;
}

void rez() {
    for (int i = 0; i <= n; ++i)
        d[i][i][s[i] - 'a'] = 1;

    for (int i = n - 1; i >= 0; --i)
        for (int j = i + 1; j <= n; ++j)
            if (s[i] == s[j]) {
                for (int k = s[i] - 'a'; k < 26; ++k)
                    d[i][j][s[i] - 'a'] = max(d[i][j][s[i] - 'a'], d[i + 1][j - 1][k] + 2);

                for (int k = 0; k < 26; ++k)
                    if (k != s[i] - 'a')
                        d[i][j][k] = max(d[i][j][k], d[i + 1][j - 1][k]);
            }
            else
                for (int k = 0; k < 26; ++k)
                    d[i][j][k] = max(d[i + 1][j][k], d[i][j - 1][k]);

    int lgmax = 0;

    for (int k = 0; k < 26; ++k)
        lgmax = max(lgmax, d[0][n][k]);

    printf("%d\n", lgmax);
}

int main() {
    freopen("palm.in", "r", stdin);
    freopen("palm.out", "w", stdout);

    gets(s);
    n = strlen(s) - 1;

    rez();

    return 0;
}
