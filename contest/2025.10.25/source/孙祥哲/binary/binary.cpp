#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, q;
bool a[100005];

void write(int x) {if(x>=2)write(x>>1);putchar((x&1)+'0');}

int main()
{
    freopen("binary.in", "r", stdin);
    freopen("binary.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    // for (int i = 0; i <= 1000; i += 3)
    // {
    //     if (__builtin_popcount(i) % 2 == 0) continue;
    //     cout << i << " ";
    //     write(i), cout << " " << __builtin_popcount(i) << '\n';
    // }
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> q;
    while (q--)
    {
        int op, x, y;
        cin >> op >> x;
        if (op == 1) a[x] = !a[x];
        else
        {
            cin >> y;
            ll res = 0;
            for (int i = x; i <= y; i++)
            {
                int c[2] = {0,0};
                for (int j = i; j <= y; j++)
                {
                    c[a[j]]++;
                    if (c[1] >= 3 && c[0] >= 2) { res += y-j+1; break; }
                    res += (c[1]%2==0||(c[0]>=2&&c[1]>=3));
                }
            }
            cout << res << '\n';
        }
    }
    return 0;
}