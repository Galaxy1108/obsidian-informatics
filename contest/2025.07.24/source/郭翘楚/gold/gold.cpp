#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=1e9+7;
int a[16];
int top;
int len;
ll n,k,dp[20][60][40][20][20],maxn=-1;
__int128 num[114514*2],sum[114514*2];
ll dfs(int p,int n2,int n3,int n5,int n7,bool l,bool li)
{
	if(p==0) return (n2+n3+n5+n7+l==0);
	if(!li and !l and dp[p][n2][n3][n5][n7]!=-1) return dp[p][n2][n3][n5][n7];
	int up;
	if(!li) up=9;
	else up=a[p];
	__int128 ans=0;
	for(int i=0;i<=up;i++)
	{
		if(i==0 and l) ans+=dfs(p-1,n2,n3,n5,n7,true,(li and i==a[p]));
		if(i==1) ans+=dfs(p-1,n2,n3,n5,n7,false,i==a[p]);
		if(i==2 and n2>=1) ans+=dfs(p-1,n2-1,n3,n5,n7,false,(li and i==a[p]));
		if(i==3 and n3>=1) ans+=dfs(p-1,n2,n3-1,n5,n7,false,(li and i==a[p]));
		if(i==4 and n2>=2) ans+=dfs(p-1,n2-2,n3,n5,n7,false,(li and i==a[p]));
		if(i==5 and n5>=1) ans+=dfs(p-1,n2,n3,n5-1,n7,false,(li and i==a[p]));
		if(i==6 and n2>=1 and n3>=1) ans+=dfs(p-1,n2-1,n3-1,n5,n7,false,(li and i==a[p]));
		if(i==7 and n7>=1) ans+=dfs(p-1,n2,n3,n5,n7-1,false,(li and i==a[p]));
		if(i==8 and n2>=3) ans+=dfs(p-1,n2-3,n3,n5,n7,false,(li and i==a[p]));
		if(i==9 and n3>=2) ans+=dfs(p-1,n2,n3-2,n5,n7,false,(li and i==a[p]));
	}
	if(!li and !l)
	{
		dp[p][n2][n3][n5][n7]=ans;
	}
	return ans;
}
void solve(int n2,int n3,int n5,int n7)
{
	ll ans=dfs(top,n2,n3,n5,n7,true,true);
	num[++len]=ans;
	maxn=max(maxn,ans);
}
void spilt(ll x)
{
	while(x!=0)
	{
		a[++top]=x%10;
		x/=10;
	}
}
bool check(__int128 x)
{
	int tot=0;
	for(int i=len,tag=1;i>=1 and tag<=len;i--)
	{
		while(tag<=len and num[i]*num[tag]<x) tag++;
		tot+=len-tag+1;
	}
	return tot<k;
}
void write(__int128 x)
{
    static int sta[129];
    int top = 0;
    do 
    {
        sta[top++] = x % 10, x /= 10;
    }while (x);
    while(top) putchar(sta[--top] + 48);
}
int main()
{
	freopen("gold.in","r",stdin);
	freopen("gold.out","w",stdout);
	cin>>n>>k;
	spilt(n);
	memset(dp,-1,sizeof(dp));
	for(int n2=0;n2<=39;n2++)
	{
		for(int n3=0;n3<=26;n3++)
		{
			for(int n5=0;n5<=13;n5++)
			{
				for(int n7=0;n7<=13;n7++)
				{
					solve(n2,n3,n5,n7);
				}
			}
		}
	}
	sort(num+1,num+len+1);
	__int128 l=0,r=(maxn*maxn),mid,val;
	while(l<r)
	{
		mid=(l+r)/2;
		if(check(mid)==true) r=mid;
		else l=mid+1;
	}
	val=l-1;
	for(int i=len;i>=1;i--)
	{
		sum[i]=(sum[i+1]+num[i])%mod;
	}
	__int128 ans=0,cnt=0;
	for(int i=1;i<=len;i++)
	{
		ll id=lower_bound(num+1,num+len+1,ceil(1.0*val/num[i]))-num;
		ans=(ans+num[i]*sum[id]);
		cnt+=(len-id+1);
	}
	if(cnt>k) ans=((ans-val%mod*(cnt-k)%mod)+mod)%mod;
	write(ans%mod);
	return 0;
}
