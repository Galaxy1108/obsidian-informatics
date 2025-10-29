#include <bits/stdc++.h>
using namespace std;

int n, nxt[1000010], lst[1000010], nxtt[1000010], lstt[1000010];
int res[25], st[1000010], sm[1000010];
bitset<1000010> out, outt;

void mov(int &ind, int cnt, int x[])
{
    while (cnt--)
    {
        ind = x[ind];
        if (ind == -1) return;
    }
}

int main()
{
    freopen("bounce.in", "r", stdin);
    freopen("bounce.out", "w", stdout);
    cin.tie(0) -> sync_with_stdio(0);
    int q, t, m, s, ans;
    bool all3 = 1;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        nxt[i] = i + 1, lst[i] = i - 1;
    nxt[n] = -1, lst[1] = -1;
    for (int i = 0; i < q; i++)
    {
        cin >> st[i] >> sm[i];
        if (st[i] != 3) all3 = 0;
    }
    if (all3)
    {
        for (m = 1; m <= 20; m++)
        {
            outt = out;
            memcpy(nxtt, nxt, sizeof(int) * (n + 5));
            memcpy(lstt, lst, sizeof(int) * (n + 5));
            while (outt.count() < n)
            {
                for (s = 1; s <= n; s = nxtt[s])
                    if (!outt[s]) break;
                for (int i = s; i <= n && i != -1; mov(i, m, nxtt))
                {
                    nxtt[lstt[i]] = nxtt[i];
                    lstt[nxtt[i]] = lstt[i];
                    outt[i] = 1;
                    ans = i;
                }
                for (s = n; s >= 1; s = lstt[s])
                    if (!outt[s]) break;
                for (int i = s; i >= 1; mov(i, m, lstt))
                {
                    nxtt[lstt[i]] = nxtt[i];
                    lstt[nxtt[i]] = lstt[i];
                    outt[i] = 1;
                    ans = i;
                }
            }
            res[m] = ans;
        }
    }
    for (int i = 0; i < q; i++)
    {
        t = st[i], m = sm[i];
        if (t == 1)
        {
            for (int i = 1; i <= n; i++)
                if (i % m == 1 && !out[i])
                {
                    nxt[lst[i]] = nxt[i];
                    lst[nxt[i]] = lst[i];
                    out[i] = 1;
                }
        }
        else if (t == 2)
        {
            for (s = 1; s <= n; s = nxt[s])
                if (!out[s]) break;
            for (int i = s; i <= n && i != -1; mov(i, m, nxt))
            {
                nxt[lst[i]] = nxt[i];
                lst[nxt[i]] = lst[i];
                out[i] = 1;
            }
        }
        else
        {
            if (all3)
                ans = res[m];
            else
            {
                outt = out;
                memcpy(nxtt, nxt, sizeof(int) * (n + 5));
                memcpy(lstt, lst, sizeof(int) * (n + 5));
                while (outt.count() < n)
                {
                    for (s = 1; s <= n; s = nxtt[s])
                        if (!outt[s]) break;
                    for (int i = s; i <= n && i != -1; mov(i, m, nxtt))
                    {
                        nxtt[lstt[i]] = nxtt[i];
                        lstt[nxtt[i]] = lstt[i];
                        outt[i] = 1;
                        ans = i;
                    }
                    for (s = n; s >= 1; s = lstt[s])
                        if (!outt[s]) break;
                    for (int i = s; i >= 1; mov(i, m, lstt))
                    {
                        nxtt[lstt[i]] = nxtt[i];
                        lstt[nxtt[i]] = lstt[i];
                        outt[i] = 1;
                        ans = i;
                    }
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}