#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, k, s[2500005];

int read()
{
    int ans = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ch * f;
}

int main()
{
    // freopen("beetle.in", "r", stdin);
    // freopen("beetle.out", "w", stdout);
    n = read(), k = read();
    for (int i = 1; i <= n; i++)
    {
        s[i] = read();
    }
    return 0;
}