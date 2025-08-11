#include<cstdio>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<cstring>
using namespace std;
int read(){
	int p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch<='9'&&ch>='0') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p;
}
const int N=150005;
struct node{
	int ls,rs,val,sz,val1,mx,p;
}q1[N<<1],q2[N<<1];
int idx,rt1,rt2;
void pu(node *q,int id){
	q[id].sz=q[q[id].ls].sz+q[q[id].rs].sz+1;
	q[id].mx=max(q[q[id].ls].mx,max(q[q[id].rs].mx,q[id].val1));
}
int New(node *q,int x,int y){
	idx++;
	q[idx]={0,0,x,1,y,y,rand()};
	return idx;
}
void split(node *q,int id,int k,int &x,int &y){//Ð¡ÓÚk 
	if(!id){
		x=y=0;
		return;
	}
	if(q[id].val<k){
		x=id;
		split(q,q[id].rs,k,q[id].rs,y);
	}
	else{
		y=id;
		split(q,q[id].ls,k,x,q[id].ls);
	}
	pu(q,id);
}
int merge(node *q,int x,int y){
	if(!x||!y) return x+y;
	if(q[x].p<q[y].p){
		q[x].rs=merge(q,q[x].rs,y);
		pu(q,x);
		return x;
	}
	else{
		q[y].ls=merge(q,x,q[y].ls);
		pu(q,y);
		return y;
	}
}
int n;
pair<int,pair<int,int> > a[N];
int main(){
	freopen("battle.in","r",stdin);
	freopen("battle.out","w",stdout);
	srand(time(NULL));
	n=read();
	for(int i=1;i<=n;i++) a[i].first=read(),a[i].second.first=read(),a[i].second.second=read();
	sort(a+1,a+n+1);
	int ans=-1;
	int nx=-1e9,ny=-1e9;
	for(int i=1;i<=n;i++){
		if(i>1&&a[i].first!=a[i-1].first){
			if(nx>a[i].second.first&&ny>a[i].second.second){
				ans=max(ans,a[i].first+nx+ny);
			}
		}
		int x,y;
		split(q1,rt1,a[i].second.first,x,y);
		if(x&&q1[x].mx>a[i].second.second){
			nx=max(nx,a[i].second.first);
			ny=max(ny,q1[x].mx);
		}
		rt1=merge(q1,x,merge(q1,New(q1,a[i].second.first,a[i].second.second),y));
		split(q2,rt2,a[i].second.second,x,y);
		if(x&&q2[x].mx>a[i].second.first){
			nx=max(nx,q2[x].mx);
			ny=max(ny,a[i].second.second);
		}		
		rt2=merge(q2,x,merge(q2,New(q2,a[i].second.second,a[i].second.first),y));
	}
	printf("%d",ans);
	return 0;
}
