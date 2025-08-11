#include<bits/stdc++.h>
using namespace std;
int n,m,op,l,r;
long long a[1000010],b[1000010],lst[2],ans;
int del[2][1000010],L[2][1000010],R[2][1000010];
struct Node{
	long long a,b;
	int l,r,op;
	bool operator <(const Node &x) const{
		return a*x.b<b*x.a;
	}
};
priority_queue<Node> q;
int main()
{
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(i>1) q.push((Node){a[i]-a[i-1],1,i-1,i,0});
		if(i>1) L[0][i]=i-1;
		if(i<n) R[0][i]=i+1;
	}
	for(int i=1;i<=m;++i){
		cin>>b[i];
		if(i>1) q.push((Node){b[i]-b[i-1],1,i-1,i,1});
		if(i>1) L[1][i]=i-1;
		if(i<m) R[1][i]=i+1;
	}
	lst[0]=a[n],lst[1]=b[m];
	while(!q.empty()){
		Node p=q.top();q.pop();
		op=p.op;
		if(del[op][p.l]||del[op][p.r]) continue;
		if(R[op][p.r]==0){
			R[op][L[op][p.r]]=0;
			if(op==0) lst[op]=a[L[op][p.r]];
			else lst[op]=b[L[op][p.r]];
			
			del[op][p.r]=1;
			ans+=1ll*lst[op^1]*p.b;
		}
		else{
			R[op][L[op][p.r]]=R[op][p.r];
			L[op][R[op][p.r]]=L[op][p.r];
			del[op][p.r]=1;
			l=L[op][p.r],r=R[op][p.r];
			if(op==0) q.push((Node){a[r]-a[l],r-l,l,r,op});
			else q.push((Node){b[r]-b[l],r-l,l,r,op});
		}
	}
	cout<<ans<<'\n';

	return 0;
}
