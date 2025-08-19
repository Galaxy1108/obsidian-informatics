#include <iostream>
#include <iomanip>
using namespace std;
const int MAXN = 2000 + 12;
const double EPS = 0;
int n,w[MAXN];
double cst;
double c[MAXN],d[MAXN],f[MAXN];
int main()
{
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    cin >> n >> cst;
    for (int i=1;i<=n;i++) cin >> w[i] >> c[i] >> d[i];
    for (int i=1;i<=n;i++)
    {
        f[i] = f[i-1] + w[i];
        double cur1 = 0,cur2 = 0,mxc = c[i];
        for (int j=i;j>=1;j--)
        {
            if (c[j]>mxc) mxc = c[j];
            if (mxc*d[i]>1)
            {
                if (cur2<cst)
                {
                    if (cur2+w[j]<=cst) cur2 += w[j];
                    else cur1 += (w[j]-(cst-cur2))*mxc*d[i],cur2 = cst;
                }
                else cur1 += w[j]*mxc*d[i];
            }
            else
            {
                cur2 += w[j];
            }
            //cout << fixed << setprecision(4) << cur1 << ' ' << cur2 << ' '  << i << ' ' << j << endl;
            //if(cur2>cst+EPS) 
            if (mxc*d[i]>1&&cur2+f[j-1]>cst-EPS) 
            {
                if(cur2>cst-EPS) f[i] = max(f[i],f[j-1]*mxc*d[i]+cur1+cur2-cst);
                else f[i] = max(f[i],cur1+(f[j-1]-(cst-cur2))*mxc*d[i]);
            }
        }
    }
    cout << fixed << setprecision(4) << f[n];
    return 0;
}