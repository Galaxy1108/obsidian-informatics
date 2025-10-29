#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mx=200005;
int pts[mx],n,m,cnt,ans=1e15;
struct lll{
	int l,r;	
}ls[mx];
void dfs(vector<int> pt,vector<lll> ttfa,int val){
	if(!ttfa.size()){ans=min(ans,val);return;}
	if(val>ans)return;
	for(int i=0;i<(int)pt.size();i++){
		for(int j=0;j<(int)ttfa.size();j++){
			int t=pt[i],ff=min(abs(ttfa[j].l-pt[i]),abs(ttfa[j].r-pt[i]));lll bse=ttfa[j];
			pt[i]=(abs(ttfa[j].l-pt[i])<abs(ttfa[j].r-pt[i]))?ttfa[j].l:ttfa[j].r;
			ttfa.erase(ttfa.begin()+j,ttfa.begin()+j+1);
			dfs(pt,ttfa,val+ff);
			pt[i]=t;
			ttfa.insert(ttfa.begin()+j,bse);
		}
	}
}
signed main(){
	freopen("points.in","r",stdin);
	freopen("points.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",pts+i);
	sort(pts+1,pts+n+1);
	for(int i=1,l,r;i<=m;i++){
		scanf("%lld%lld",&l,&r);
		if(*lower_bound(pts+1,pts+n+1,l)<=r)continue;
		ls[++cnt].l=l,ls[cnt].r=r;
	}
	vector<int> v1;
	vector<lll> v2;
	for(int i=1;i<=n;i++)v1.push_back(pts[i]);
	for(int i=1;i<=cnt;i++)v2.push_back(ls[i]);
	dfs(v1,v2,0);
	cout<<ans<<endl;
	return 0;
}
