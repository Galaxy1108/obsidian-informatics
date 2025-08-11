#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m,f,ans[1000005],b[2000005];
struct node{
	int t,x,id;
}q[1000005];
bool cmp(node x,node y){
	return x.t<y.t;
}
void sort_1(){
	f=0;
	int l=1,r=n/2+1;
	for(int i=1;i<=n;i++){
		if(l==n/2+1)
			b[i]=a[r++];
		else if(r==n+1)
			b[i]=a[l++];
		else if(a[r]<a[l]){
			f=1;
			b[i]=a[r++];
		}
		else
			b[i]=a[l++];
	}
	for(int i=1;i<=n;i++)
		a[i]=b[i];
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++){
		cin>>q[i].t>>q[i].x;
		q[i].id=i;
	}
	sort(q,q+m,cmp);
	int idx=0,cnt=0;
	f=1;
	while(f&&idx<m){
		while(q[idx].t==cnt&&idx<m){
			ans[q[idx].id]=a[q[idx].x];
			idx++;
		}
		sort_1();
		cnt++;
	}
	while(idx<m){
		ans[q[idx].id]=a[q[idx].x];
		idx++;
	}
	for(int i=0;i<m;i++)
		cout<<ans[i]<<endl;
	return 0;
}

