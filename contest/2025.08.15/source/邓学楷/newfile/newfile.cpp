#include <cstdio>
#include <cstring>
typedef long long ll;

const int M=1e9+9;
int n,m,q;
ll psum[5010][5010];

int main()
{
    int l,r,x,y;
    ll ans=0;
    freopen("newfile.in","r",stdin);
    freopen("newfile.out","w",stdout);
    scanf("%d%d%d",&n,&m,&q);
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&l,&r,&x);
        memcpy(psum[i],psum[i-1],sizeof psum[i]);
        for (int j=l;j<=n;j++)
            if (j<=r)
                psum[i][j]+=(j-l+1)*x%M,psum[i][j]%=M;
            else
                psum[i][j]+=(r-l+1)*x%M,psum[i][j]%=M;
    }
    while (q--)
    {
        scanf("%d%d%d%d",&x,&y,&l,&r);
        for (int i=x;i<=y;i++)
            ans+=(psum[i][r]-psum[i][l-1])%M,ans%=M;
        printf("%lld\n",ans);
        ans=0;
    }
    return 0;
}