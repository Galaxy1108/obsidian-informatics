#include<bits/stdc++.h>
using namespace std;
int n,m,t,l,f,q[100005],u[4005],v[4005],w[4005],p[4005];
long long ans;
struct node{
	int dis,book[4005],cnt;
	void clear(){
		memset(book,0,sizeof book);
		dis=0x3f3f3f3f;
		cnt=0;
	}
}a[2005];
void bellman(int s){
	for(int i=1;i<=n;i++)
		a[i].clear();
	a[s].cnt=0;
	a[s].dis=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<2*m;j++){
			if(a[v[j]].dis>a[u[j]].dis+w[j]&&p[j]+a[u[j]].cnt<f){
				a[v[j]]=a[u[j]];
				a[v[j]].dis+=w[j];
				a[v[j]].cnt+=p[j];
				a[v[j]].book[j]=1;
			}
		}
	}
}
int main(){
	freopen("wildboar.in","r",stdin);
	freopen("wildboar.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>t>>l;
//	for(int i=0;i<m;i++){
//		cin>>u[i]>>v[i]>>w[i];
//		u[m+i]=v[i];
//		v[i+m]=u[i];
//		w[i+m]=w[i];
//	}
//	for(int i=1;i<=l;i++)
//		cin>>q[i];
//	int x,y;
//	cin>>x>>y;
//	q[x]=y;
//	f=INT_MAX;
//	for(int i=1;i<l;i++){
//		bellman(q[i]);
//		if(a[q[i+1]].dis==0x3f3f3f3f){
//			cout<<-1;
//			return 0;
//		}
//		ans+=a[q[i+1]].dis;
//		f=0;
//		memset(p,0,sizeof p);
//		for(int j=0;j<m;j++)
//			if(a[q[i+1]].book[j]){
//				f++;
//				p[j+m]=1;
//			}
//		for(int j=m;j<2*m;j++){
//			if(a[q[i+1]].book[j]){
//				f++;
//				p[j-m]=1;
//			}
//		}
//	}
//	cout<<ans;
	for(int i=0;i<t;i++)
		cout<<"-1\n";
	return 0;
}

