#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int g(int x){return 1<<(x-1);}

const int L = 51000, B = 75;
const int C = (L-1)/B + 1;
int id[L],l[C],r[C];
int x[C];
int a[L],rx[B+10];
int n,k,m,s,ans;

int get(int x)
{
    int res = 0;
    while(x)
    {
        res++;
        x>>=1;
    }
    return res;
}

void init()
{
    for(int i=1;i<=L;i++) id[i] = ((i-1)/B) + 1;
    for(int i=1;i<=C;i++) 
    {
        l[i] = B*(i-1) + 1;
        r[i] = B*i;
    }
    while(k--) s=(s<<1)|1;
}

int ask(int L,int R)
{
    int res = ::L+1;
    if(L == R)
    {
        for(int i=l[L];i<=r[L];i++)
        {
            int now = a[i];
            for(int j=i;j<=min(r[L],res+i);j++)
            {
                now |= a[j];
                if(now == s) 
                {
                    res = min(res,j-i+1);
                    break;
                }
            }
        }
        return res;
    }
    else
    {
        int sum = 0;
        for(int i=L+1;i<=R-1;i++)
        {
            sum |= ::x[i];
        }
        rx[0] = sum;
        for(int i=l[R];i<=r[R];i++) {rx[i-l[R]+1] = rx[i-l[R]] | sum | a[i];}
        int lx=a[r[L]] | sum,j=r[L];
        for(int i=B,x;i>=1;i--)
        {
            while(j >= l[L] && (lx | rx[i]) != s)
            {
                j--;
                lx |= a[j];
            }
            if(j < l[L]) break;
            x = i+r[L]-j+1;
            while(res > x)res = x;
        }
        return res + B*(R-L-1);
    }
    return 0;
}
void solve()
{
    ans = INT_MAX;
    for(int i=1;i<=C;i++)
    {
        int now = x[i];
        int fl = 100000;
        for(int j=i;j<=C;j++)
        {
            if(j - fl > 2) break;
            now |= x[j];
            if(now == s)
            {
                ans = min(ans,ask(i,j));
                fl = min(fl,j);
            }
        }
    }
}
void change(int p,int xx)
{
    a[p] = g(xx);
    x[id[p]] = 0;
    for(int i=l[id[p]];i<=r[id[p]];i++)
    {
        x[id[p]] |= a[i];
    }
}

int main()
{
    freopen("truth.in","r",stdin);
    freopen("truth.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k >> m;
    init();
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        a[i] = g(a[i]);
        x[id[i]] |= a[i];
    }
    int cnt=0;
    for(int i=1,tp,x,y;i<=m;i++)
    {
        cin >> tp;
        if(tp == 1)
        {
            cin >> x >> y;
            change(x,y);
        }
        else
        {
            cnt++;
            solve();
            cout << ((ans == INT_MAX)?-1:ans) << "\n";
        }
    }
}