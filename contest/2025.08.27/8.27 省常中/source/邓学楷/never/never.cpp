#include <cstdio>
typedef long long ll;

int main()
{
    freopen("never.in","r",stdin);
    freopen("never.out","w",stdout);
    int T;
    ll n,s,t,x,y,cnt;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%lld%lld%lld%lld%lld",&n,&s,&t,&x,&y);
        while (true)
        {
            if (s<t)
            {
                cnt=(t-s+y-1)/y;
                cnt=cnt==0?1:cnt;
                if (cnt>=n)
                {
                    printf("%lld\n",s+n*y);
                    break;
                }
                s+=cnt*y;
                n-=cnt;
            }
            else
            {
                cnt=(s-t+x-1)/x;
                cnt=cnt==0?1:cnt;
                if (cnt>=n)
                {
                    printf("%lld\n",s-n*x);
                    break;
                }
                s-=cnt*x;
                n-=cnt;
            }
        }
    }
    return 0;
}