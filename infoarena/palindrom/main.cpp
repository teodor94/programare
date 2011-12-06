#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 400004;

char s[N];
int n, lg[N];

void init() {
    n <<= 1;

    for (int i = n; i >= 0; --i)
        if ((i & 1) == 0)
            s[i] = '#';
        else
            s[i] = s[i >> 1];
}

void pscpld() {
    lg[0] = 1;
    lg[1] = 3;
    int dr = 2, cur = 1;

    for (int i = 2; i <= n; ++i)
        if (i >= dr) {
            int j1 = i, j2 = i;
            while (j1 - 1 >= 0 && j2 + 1 <= n && s[j1 - 1] == s[j2 + 1]) {
                --j1;
                ++j2;
            }

            dr = j2;
            cur = i;
            lg[i] = j2 - j1 + 1;
        }
        else {
            int simetric = (cur << 1) - i, stangasimetric = simetric - (lg[simetric] >> 1), stangacur = cur - (lg[cur] >> 1);

            if (stangasimetric > stangacur)
                lg[i] = lg[simetric];
            else {
                int j2 = dr, j1 = (i << 1) - dr;
                while (j1 - 1 >= 0 && j2 + 1 <= n && s[j1 - 1] == s[j2 + 1]) {
                    --j1;
                    ++j2;
                }

                dr = j2;
                cur = i;
                lg[i] = j2 - j1 + 1;
            }
        }

    //for (int i = 0; i <= n; ++i)
        //printf("%d", lg[i]);
}

void rez() {
    int min = N;

    for (int i = 0; i <= n; ++i)
        if (i + (lg[i] >> 1) == n && i - (lg[i] >> 1) <= min)
            min = i - (lg[i] >> 1);

    for (int i = 1; i <= n; ++i)
        if (s[i] != '#')
            printf("%c", s[i]);

    for (int i = min; i > 0; --i)
        if (s[i] != '#')
            printf("%c", s[i]);

    printf("\n");
}

int main() {
    freopen("palindrom.in", "r", stdin);
    freopen("palindrom.out", "w", stdout);

    gets(s);
    n = strlen(s);

    init();

    pscpld();

    rez();

    return 0;
}
