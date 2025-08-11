#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;

struct matrix
{
    int n,m;
    long long mat[11][11];
    matrix()
    {
        memset(mat,0,sizeof(mat));
    }
};

matrix times(matrix a,matrix b)
{
    matrix ret = matrix();
    int n = a.n,m = b.m;
    ret.n = n,ret.m = m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=1;k<=a.m;k++)
            {
                ret.mat[i][j] = (ret.mat[i][j] + (a.mat[i][k] * b.mat[k][j] % mod)) % mod;
            }
        }
    }
    return ret;
}
matrix qmi(matrix x,long long k)
{
    matrix ret = matrix();
    ret.n = x.n,ret.m = x.m;
    for(int i=1;i<=ret.n;i++)
    {
        ret.mat[i][i] = 1;
    }
    // print(ret);
    while(k)
    {
        if(k&1)
        {
            ret = times(ret,x);
        }
        x = times(x,x);
        k >>= 1;
    }
    return ret;
}
matrix s;
matrix a;
matrix ans;
int main()
{
    freopen("sam.in","r",stdin);
    freopen("sam.out","w",stdout);
    long long k;
    cin >> k;
    a.n = 10,a.m = 1;
    for(int i=1;i<=10;i++)
    {
        a.mat[i][1] = 1;
    }
    
    s.n = 10,s.m = 10;
    for(int i=1;i<=10;i++)
    {
        for(int j=1;j<=10;j++)
        {
            if(abs(i-j) > 2) continue;
            s.mat[i][j] = 1;
        }
    }
    // print(s);
    // print(a);
    ans = times(qmi(s,k-1),a);
    // print(ans);
    long long sum = 0;
    for(int i=2;i<=10;i++)
    {
        sum = (sum + ans.mat[i][1]) % mod;
    }
    cout << sum;
    return 0;
}
