#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn = 1e5 + 50;
const int mod = 1e9 + 7;

char s[maxn];
char ans[maxn];
int type[maxn];

int main(int argc, char **argv)
{
    //string fin = "bracket" + string(argv[1]) + ".in";
    //string fout = "bracket" + string(argv[1]) + ".out";
    freopen("bracket.in", "r", stdin);
    freopen("bracket.out", "w", stdout);
    deque<int> D;
    stack<int> S;
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; ++i)
        if (s[i] == '*') D.push_back(i);
    bool ok = true;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '(') S.push(i);
        else if (s[i] == ')')
        {
            if (S.empty())
            {
                if (D.empty() || D.front() > i)
                {
                    ok = false;
                    break;
                }
                else 
                {
                    type[D.front()] = 1;
                    D.pop_front();
                }
            }
            else S.pop();
        }
    }
    while (!S.empty())
    {
        if (D.empty() || D.back() < S.top())
        {
            ok = false;
            break;
        }
        type[D.back()] = 2;
        D.pop_back();
        S.pop();
    }
    while (!D.empty())
    {
        type[D.front()] = 0;
        D.pop_front();
    }
    if (ok)
    {
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] != '*') ans[cnt++] = s[i];
            else
            {
                if (type[i] == 1) ans[cnt++] = '(';
                else if (type[i] == 2) ans[cnt++] = ')';
            }
        }
        ans[cnt] = '\0';
    }
    else strcpy(ans, "No solution!");
    printf("%s\n", ans);
    return 0;
}
