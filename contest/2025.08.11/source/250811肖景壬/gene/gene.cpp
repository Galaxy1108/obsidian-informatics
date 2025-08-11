//1 2 0 0 1
#include<bits/stdc++.h>
using namespace std;
int cnt[1000005],n,s[1000005],l,r,fin[1000005],fincnt;
struct col
{
	int pos,ll,rr;
};
col lc[1000005],rc[1000005];
int main()
{
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout); 
	//cin>>n>>l>>r;
	scanf("%d%d%d",&n,&l,&r);
	for(int i = 1; i <= n; i++)
	{
		//cin>>s[i];
		scanf("%d",&s[i]);
	 } 
	for(int i = 1; i <= n; i++)
	{
		cnt[s[i]]++;
		if(cnt[s[i]]==1&&i<l)
		{
			lc[s[i]].pos=i;
			lc[s[i]].ll=i+1;
		}
		else if(cnt[s[i]]==2)
		{
			lc[s[i]].rr=i-1;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(lc[s[i]].rr==0) lc[s[i]].rr=n;
		cnt[s[i]]=0;
	 } 
	for(int i = n; i >= 1; i--)
	{
		cnt[s[i]]++;
		if(cnt[s[i]]==1&&i>r)
		{
			rc[s[i]].pos=i;
			rc[s[i]].rr=i-1;
		}
		else if(cnt[s[i]]==2)
		{
			rc[s[i]].ll=i+1;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(rc[s[i]].ll==0) rc[s[i]].ll=1;
	 }
	int lp=l-1,rp=r+1;
	while(lp>=1&&lc[s[lp]].pos!=lp) lp--;
	while(rp<=n&&rc[s[rp]].pos!=rp) rp++;
	if(lp<1||rp>n)
	{
		printf("-1");
		return 0;
	}
	while(lp>=1&&rp<=n)
	{
		//(lc[s[lp]].pos==lp&&rc[s[rp]].pos==rp&&(lc[s[lp]].ll<=rp)&&(lc[s[lp]].rr>=rp))
		if((lc[s[lp]].ll<=rp)&&(lc[s[lp]].rr>=rp)&&(rc[s[rp]].ll<=lp)&&(rc[s[rp]].rr>=lp)&&s[lp]!=s[rp])
		{
			printf("%d",rp-lp+1);
			return 0;
		}
		lp--;
		while(lp>=1&&lc[s[lp]].pos!=lp) lp--;
		if(lp<1) break;
		while(rp<=n&&rc[s[rp]].ll>lp) rp++;
		while(rp<=n&&rc[s[rp]].pos!=rp) rp++;
		if(rp>n) break;
	}
	//cout<<fl<<" "<<fr<<endl;
	printf("-1");
	return 0;
 } 
