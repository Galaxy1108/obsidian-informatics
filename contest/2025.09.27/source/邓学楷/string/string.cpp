#include <cstdio>
#include <algorithm>
#define min(x,y) ((x)<(y)?(x):(y))
#define abs(x) ((x)>=0?(x):(-(x)))
using ll=long long;

int len,cnt[3],init[500],pt,pos[500][3];
ll ans=0x7f7f7f7f7f7f7f7f;
char c[500];
bool f=1;

bool check()
{
	for (int i=0;i<len-1;i++)
		if (init[i]==init[i+1])
			return 0;
	return 1;
}

ll calc()
{
	int p[]={0,0,0};
	ll ans=0;
	for (int i=0;i<len;i++)
		if (init[i]!=(c[i]-'0') && i<pos[init[i]][p[init[i]]])
		{
			ans+=pos[init[i]][p[init[i]]]-i;
			p[init[i]]++;
		}
	return ans;
}

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%s",c);
    for (int i=0;c[i];i++)
    	pos[c[i]-'0'][cnt[c[i]-'0']++]=i;
    len=cnt[0]+cnt[1]+cnt[2];
    for (int i=0;i<len-1;i++)
        if (c[i]==c[i+1])
        {
            f=0;
            break;
        }
    if (f)
    {
        puts("0");
        return 0;
    }
    if (cnt[0]>(len+1)/2 || cnt[1]>(len+1)/2 || cnt[2]>(len+1)/2)
    {
        puts("-1");
        return 0;
    }
    for (int i=0;i<3;i++)
    	for (int j=0;j<cnt[i];j++)
    		init[pt++]=i;
    do
    {
    	if (!check())
    		continue;
    	ans=min(ans,calc());
	} while(std::next_permutation(init,init+len));
	printf("%lld\n",ans);
    return 0;
}
