#include <bits/stdc++.h>
using namespace std;

int n;
bitset<100010> bs;

bool check(int c[])
{
    return c[1] != 1;
}

int main()
{
    freopen("binary.in", "r", stdin);
    freopen("binary.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    int m, op, l, r, c[2], ans;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> m, bs[i] = m;
    cin >> m;
    while (m--)
    {
        cin >> op >> l;
        if (op == 1)
        {
            bs[l].flip();
            continue;
        }
        cin >> r;
        ans = 0;
        for (int i = l; i <= r; i++)
        {
            c[0] = c[1] = 0;
            for (int j = i; j <= r; j++)
            {
                c[bs[j]]++;
                ans += check(c);
            }
        }
        cout << ans << '\n';
    }
    cout << flush;
    return 0;
}