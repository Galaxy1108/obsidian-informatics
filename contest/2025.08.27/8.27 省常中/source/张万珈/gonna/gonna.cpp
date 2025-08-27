#include <bits/stdc++.h>
using namespace std;

int mod;
unsigned long long C[210][210],f[210],g[210];

int main()
{
    freopen("gonna.in","r",stdin);
    freopen("gonna.out","w",stdout);
    int n;
    cin >> n >> mod;
    C[0][0] = 1;
    for(int i=1;i<=n;i++)
    {
        C[i][0] = C[i][i] = 1;
        for(int j=1;j<i;j++)
        {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=i;j++)
    //     {
    //         cout << C[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    for(int i=1;i<=n;i++)
    {
        f[i] = 1;
        for(int j=0;j<=i;j++)
        {
            f[i] = (f[i] * C[i][j]);
        }
        // cout << f[i] << endl;
    }
    for(int i=1;i<=n;i++)
    {
        for(long long j=1;j*j<=f[i];j++)
        {
            if(f[i] % j == 0)
            {
                // cout << j << ' ' << f[i] / j << endl;;
                g[i] +=j;
                if(j*j != f[i])
                {
                    g[i] += (f[i]/j);
                }
            }
        }
        g[i] += g[i-1];
    }
    cout << g[n] % mod;
}