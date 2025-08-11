#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
constexpr int N=2005;
using namespace std;
int n, m;
vector<pii>ans;
int f[11][N];
struct node{
	int len, cnt, l, r;
}g[11][N];
void dfs(int k,vector<int>a)
{
	int n=a.size();
	if(n<=k+1)
		return;
	if(k==1)
	{
		for(int i=0;i<n;i++)
			for(int j=i+2;j<n;j++) 
				ans.pb(a[i],a[j]);
		return;
	}
	vector<int>na,nna;
	if(k==2)
	{
		int mid=n-1>>1;
		for(int i=0;i<=mid-2;i++)
			ans.pb(a[i],a[mid]);
		for(int i=mid+2;i<n;i++)
			ans.pb(a[mid],a[i]);
		for(int i=0;i<mid;i++)
			na.pb(a[i]);
		dfs(k,na);
		vector<int>tmp;
		swap(na,tmp);
		for(int i=mid+1;i<n;i++)
			na.pb(a[i]);
		dfs(k,na);
		return;
	}
	int len=g[k][n].len,cnt=g[k][n].cnt,l=g[k][n].l,r=g[k][n].r;
	for(int i=0;i<=l-2;i++)
		ans.pb(a[i], a[l]);
	for(int i=n-r+1;i<n;i++)
		ans.pb(a[n-r-1],a[i]);
	int pos=l,id=0,add;
	while(pos<n-r-1)
	{
		if(id<cnt)add=len+1;
		else add=len;
		nna.pb(a[pos]);
		for(int i=pos+2;i<pos+add;i++)
			ans.pb(a[pos],a[i]);
		for(int i=pos+1;i<=pos+add-2;i++)
			ans.pb(a[i],a[pos+add]);
		na.clear();
		for(int i=pos+1;i<pos+add;i++)
			na.pb(a[i]);
		dfs(k, na);
		ans.pb(a[pos],a[pos+add]);
		pos+=add,id++;
	}
	nna.pb(a[n-r-1]);
	na.clear();
	for(int i=0;i<l;i++)
		na.pb(a[i]);
	dfs(k,na);
	na.clear();
	for(int i=n-r;i<n;i++)
		na.pb(a[i]);
	dfs(k,na);
	dfs(k-2,nna);
}
vector<int>a;
void init()
{
	memset(f,0x3f,sizeof f);
	f[1][0]=f[1][1]=f[2][0]=f[2][1]=f[2][2]=f[2][3]=0;
	for(int i=2;i<=n;i++)
		f[1][i]=i*(i-1)/2-(i-1);
	for(int i=4;i<=n;i++) 
		f[2][i]=f[2][(i+1)/2-1]+f[2][i-(i+1)/2]+i-3;
	for(int i=1;i<=n;i++)a.pb(i);
	for(int k=3;k<=m;k++)
		for(int i=0;i<=n;i++)
		{
			if(i<=k+1){f[k][i]=0;continue;}
			if(i<=100)
				for(int j=1;j<=i;j++)
					for(int o=2;o<=j;o++)
					{
						int l=i-j>>1,r=i-j+1>>1,len=(j-1)/(o-1);
						int val=max(l-1,0)+max(r-1,0);
						val+=(max(len-1,0)*2+f[k][len])*((j-1)%(o-1));
						val+=(max(len-2,0)*2+f[k][len-1])*(o-1-(j-1)%(o-1))+o-1;
						val+=f[k-2][o]+f[k][l]+f[k][r];
						if(val<f[k][i])
							f[k][i]=val,g[k][i]=(node){len,(j-1)%(o-1),l,r};
					}
			else
				for(int j=1;j<=i;j++)
					for(int o=1;j*o+1<=i;o++)
					{
						int l=(i-j*o-1)>>1,r=(i-j*o)>>1;
						int val=max(l-1,0)+max(r-1,0);
						val+=max(j-2,0)*2*o+f[k][j-1]*o+o;
						val+=f[k-2][o+1]+f[k][l]+f[k][r];
						if(val<f[k][i])
							f[k][i]=val,g[k][i]=(node){j,0,l,r};
					}
		}
}
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m,n++;
	init();
	dfs(m,a);
	cout<<ans.size()<<'\n';
	for(auto v:ans)cout<<v.fi-1<<' '<<v.se-1<<'\n';
	return 0;
}
