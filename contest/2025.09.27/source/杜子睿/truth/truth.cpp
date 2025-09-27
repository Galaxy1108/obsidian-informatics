#include<bits/stdc++.h>
using namespace std;
struct node{
	int pre,nxt;
}a[50005];
int rt[50],s[50005],n,m,k;
int tr[200];
void modify(int p,int l,int r,int x,int y){
	if(l==r){
		tr[p]=y;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)
		modify(p<<1,l,mid,x,y);
	else
		modify(p<<1|1,mid+1,r,x,y);
	tr[p]=max(tr[p<<1],tr[p<<1|1]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=k;i++){
		int j=1;
		for(j=1;j<=n&&s[j]!=i;j++);
		if(j==n&&s[j]!=i)
			rt[i]=-1;
		else{
			rt[i]=j;
			a[j].pre=-1;
			a[j].nxt=-1;
		}
		for(int k=j+1;k<=n;k++)
			if(s[k]==i){
				a[j].nxt=k;
				a[k].pre=j;
				a[k].nxt=-1;
				j=k;
			}
	}
	for(int i=0;i<m;i++){
		int opt;
		cin>>opt;
		if(opt==1){
			int x,y;
			cin>>x>>y;
			if(s[x]==y)
				continue;
			node tt=a[x];
			if(rt[y]==-1){
				rt[y]=x;
				a[x].pre=-1;
				a[x].nxt=-1;
			}
			else if(rt[y]>x){
				a[rt[y]].pre=x;
				a[x].nxt=rt[y];
				rt[y]=x;
				a[x].pre=-1;
			}
			else{
				int j;
				for(j=x-1;j>=1&&s[j]!=y;j--);
				a[x].nxt=a[j].nxt;
				a[a[x].nxt].pre=x;
				a[j].nxt=x;
				a[x].pre=j;
			}
			if(tt.nxt==-1&&tt.pre==-1)
				rt[s[x]]=-1;
			else if(tt.pre==-1){
				rt[s[x]]=tt.nxt;
				a[tt.nxt].pre=-1;
			}
			else{
				a[tt.pre].nxt=tt.nxt;
				a[tt.nxt].pre=tt.pre;
			}
			s[x]=y;
		}
		else{
			int f=true;
			for(int i=1;i<=k;i++){
				if(rt[i]==-1){
					f=false;
					cout<<-1<<endl;
					break;
				}
				modify(1,1,k,i,rt[i]);
			}
			if(!f)
				continue;
			int minn=tr[1];
			for(int i=2;i<=n;i++){
				if(a[i-1].nxt==-1)
					break;
				else
					modify(1,1,k,s[i-1],a[i-1].nxt);
				minn=min(minn,tr[1]-i+1);
			}
			cout<<minn<<endl;
		}
	}
	return 0;
}
 
