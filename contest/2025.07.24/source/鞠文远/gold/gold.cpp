#include<bits/stdc++.h>
using namespace std;
/*打表发现:(一维)
有金矿的元素个数: 
1e5:441
1e6:784
1e7:1296
1e8:2025
2e8:2025
3e8:2310
----------以下为估算的最大值 ----------
1e9:5000
1e10:10000                (后续补算是绝对小于等于7575)
1e11:20000
1e12:50000
也就是说,最多只会有50000个有金矿的元素。 
*/ 
#define int long long
const int N=1e5+5,mod=998244353;
int n,k;
int mbcnt,mb[N];//可能产生贡献的元素
int mbctri[N];//对于每个可能产生贡献的元素,它的贡献
int cntnum,num[20];
int memal[15][42][32][22][17][2][2];//每一维开大2 
bool visal[15][42][32][22][17][2][2];
#define mem memal[pos][l2][l3][l5][l7][q0][mx]
#define vis visal[pos][l2][l3][l5][l7][q0][mx]
int dfs(int pos,int l2,int l3,int l5,int l7,bool q0,bool mx)
{
	if(l2<0||l3<0||l5<0||l7<0)return 0;	
	if(pos==cntnum+1)return mem+=1;
	if(vis)return mem;
	vis=true;
	int res=0;
	if(q0)res+=dfs(pos+1,l2,l3,l5,l7,1,mx&&num[pos]==0);
	if(!mx)
	{	
		res+=dfs(pos+1,l2,l3,l5,l7,0,mx);
		res+=dfs(pos+1,l2-1,l3,l5,l7,0,mx);
		res+=dfs(pos+1,l2,l3-1,l5,l7,0,mx);
		res+=dfs(pos+1,l2-2,l3,l5,l7,0,mx);
		res+=dfs(pos+1,l2,l3,l5-1,l7,0,mx);
		res+=dfs(pos+1,l2-1,l3-1,l5,l7,0,mx);
		res+=dfs(pos+1,l2,l3,l5,l7-1,0,mx);
		res+=dfs(pos+1,l2-3,l3,l5,l7,0,mx);
		res+=dfs(pos+1,l2,l3-2,l5,l7,0,mx);
	}
	if(mx)
	{
		if(num[pos]>=1)res+=dfs(pos+1,l2,l3,l5,l7,0,mx==1);
		if(num[pos]>=2)res+=dfs(pos+1,l2-1,l3,l5,l7,0,mx==2);
		if(num[pos]>=3)res+=dfs(pos+1,l2,l3-1,l5,l7,0,mx==3);
		if(num[pos]>=4)res+=dfs(pos+1,l2-2,l3,l5,l7,0,mx==4);
		if(num[pos]>=5)res+=dfs(pos+1,l2,l3,l5-1,l7,0,mx==5);
		if(num[pos]>=6)res+=dfs(pos+1,l2-1,l3-1,l5,l7,0,mx==6);
		if(num[pos]>=7)res+=dfs(pos+1,l2,l3,l5,l7-1,0,mx==7);
		if(num[pos]>=8)res+=dfs(pos+1,l2-3,l3,l5,l7,0,mx==8);
		if(num[pos]>=9)res+=dfs(pos+1,l2,l3-2,l5,l7,0,mx==9);
	}
	return res;
}
void solve()
{
	int ni=n;
	while(ni)
	{
		num[++cntnum]=ni%10;
		ni/=10;
	}
	for(int i=1;i<=cntnum/2;i++)swap(num[i],num[cntnum-i+1]);
	dfs(1,40,30,20,15,true,true);
	for(int i=1;i<=mbcnt;i++)
	{
		int c2,c3,c5,c7;
		c2=c3=c5=c7=0;
		int li=mb[i];
		while(li%2==0)
		c2++,li/=2;
		while(li%3==0)c3++,li/=3;
		while(li%5==0)c5++,li/=5;
		while(li%7==0)c7++,li/=7;
		mbctri[i]=memal[cntnum+1][40-c2][30-c3][20-c5][15-c7][0][0]+memal[cntnum+1][40-c2][30-c3][20-c5][15-c7][0][1];
	}
}
struct st
{
	int w,b;
	bool operator <(st sxb)const{return w<sxb.w;}
}ary[N];
int xcnt[N];
priority_queue<st>privb;
signed main()
{
	freopen("gold.in","r",stdin);
	freopen("gold.out","w",stdout);
	cin>>n>>k;
	for(int n2=0;n2<=40;n2++)
		for(int n3=0;n3<=30;n3++)
			for(int n5=0;n5<=20;n5++)
				for(int n7=0;n7<=15;n7++)
				{
					bool pd=true;
					int res=1;
					for(int i=1;i<=n2;i++)
					{
						res*=2;
						if(res>n)
						{
							pd=false;
							break;
						}
					}
					if(!pd)continue;
					for(int i=1;i<=n3;i++)
					{
						res*=3;
						if(res>n)
						{
							pd=false;
							break;
						}
					}
					if(!pd)continue;
					for(int i=1;i<=n5;i++)
					{
						res*=5;
						if(res>n)
						{
							pd=false;
							break;
						}
					}
					if(!pd)continue;
					for(int i=1;i<=n7;i++)
					{
						res*=7;
						if(res>n)
						{
							pd=false;
							break;
						}
					}
					if(!pd)continue;
					mb[++mbcnt]=res;
				}
	solve();
	sort(mbctri+1,mbctri+1+mbcnt,greater<int>());
	for(int i=1;i<=n;i++)privb.push({mbctri[i]*mbctri[1],i}),xcnt[i]++;
	int anslt=0;
	for(int i=1;i<=k;i++)
	{
		anslt+=privb.top().w;
		anslt%=mod;
		xcnt[privb.top().b]++;
		int rt=xcnt[privb.top().b],st=privb.top().b;
		privb.pop();
		privb.push({mbctri[i]*mbctri[rt],st});
	}
	cout<<anslt%mod;
	
	return 0;
}
