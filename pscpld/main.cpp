#include<cstdio>
#include<cstring>

const int N = 2000005;

char s[N];
int n, lg[N];

void init() {
    n = strlen(s);
    n <<= 1;

    for (int i = n; i >= 0; --i)
        if ((i & 1) == 0)
            s[i] = '#';
        else
            s[i] = s[i >> 1];

    //puts(s);
}

void rez() {
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

    int nrs = 0;

    for (int i = 1; i <= n; i += 2) { // lungime impara
        int extind = (lg[i] >> 1);
        nrs += (extind + 1) >> 1;
    }

    for (int i = 2; i <= n; i += 2) { // lungime para
        int extind = (lg[i] >> 1);
        nrs += (extind >> 1);
    }

    printf("%d\n", nrs);

    //for (int i = 0; i <= n; ++i)
        //printf("%d ", lg[i]);
}

int main() {
    freopen("pscpld.in", "r", stdin);
    freopen("pscpld.out", "w", stdout);

    gets(s);

    init();

    rez();

    return 0;
}
