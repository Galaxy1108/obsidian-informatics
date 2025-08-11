#include <bits/stdc++.h>
using namespace std;
int a[1000010],tot;
long long q[1000010],m[1000010],cnt;
int main()
{
    freopen("sum.in","r",stdin);
    freopen("sum.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        cnt = 0;
        tot = 0;
        long long s,k;
        cin >> s >> k;
        if(s&1)
        {
            if(k*2 > s) cout << -1 << endl;
            else
            {
                cout << k*2 << endl;
            }
            continue;
        }
        for(int i=3;i<=s;i++)
        {
            if(s%i==0) continue;
            bool fl=0;
            for(int j=1;j<=cnt;j++)
            {
                if(i % q[j] == 0)
                {
                    a[++tot] = i;
                    fl=1;
                    break;
                }
                if(i % q[j] == m[j])
                {
                    fl=1;
                    break;
                }
            }
            if(fl) continue;
            a[++tot] = i;
            q[++cnt] = i;
            m[cnt] = s%i;
            if(tot == k) break;
        }
        if(tot < k) cout << -1 << endl;
        else cout << a[k] << endl;
    }
}