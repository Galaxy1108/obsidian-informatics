#include<bits/stdc++.h>
#define inf 1000000000
#define B 600
using namespace std;
int Tid,n,m,k,Q,tot;
int X[500010],Y[500010],L[500010],R[500010],tag[500010];
int bel[500010],f[500010],t[500010],s[500010];
set<int> sx[50010],sy[50010];
set<int>::iterator it; 
struct Pos{
	int x,y;
}pos[400010];
struct Mov{
	int op,x,y,q;
}mov[400010];
bool cmp(Pos x,Pos y){
	if(x.x!=y.x) return x.x<y.x;
	return x.y<y.y;
}
int Getid(int x,int y){
	int l=1,r=tot;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(cmp((Pos){x,y},pos[mid])) r=mid-1;
		else l=mid;
	}
	return l;
}
void Rebuild(int x){
	int l=L[x],r=R[x];
	for(int i=r;i>=l;--i){
		if(f[i]==i) t[i]=i,s[i]=inf;
		else if(f[i]<=r) t[i]=t[f[i]],s[i]=s[f[i]]+1;
		else t[i]=f[i],s[i]=1;
	}
	return;
}
void Add(int x,int y){
	int id=Getid(x,y);
	if(x==0||x==n+1){
		tag[id]=1;
		it=sy[y].lower_bound(id); 
		if(it!=sy[y].end()) f[id]=(*it);
		if(it!=sy[y].begin()) f[(*prev(it))]=id;
		sy[y].insert(id);
	}
	else if(y==0||y==m+1){
		tag[id]=1;
		it=sx[x].lower_bound(id); 
		if(it!=sx[x].end()) f[id]=(*it);
		if(it!=sx[x].begin()) f[(*prev(it))]=id;
		sx[x].insert(id);
	}
	else{
		it=sx[x].lower_bound(id); 
		if(it!=sx[x].end()){
			if(tag[(*it)]) f[id]=(*it);
			else f[id]=(*it)-1;
		}
		if(it!=sx[x].begin()) f[(*prev(it))]=id-1;
		sx[x].insert(id);
		
		it=sy[y].lower_bound(id); 
		if(it!=sy[y].end()) f[id-1]=(*it);
		if(it!=sy[y].begin()){
			if(tag[(*prev(it))]) f[(*prev(it))]=id;
			else f[(*prev(it))-1]=id;
		}
		sy[y].insert(id);
	}
	return;
}

void Add1(int x,int y){
	int id=Getid(x,y);
	it=sx[x].lower_bound(id); 
	if(it!=sx[x].end()){
		if(tag[(*it)]) f[id]=(*it);
		else f[id]=(*it)-1;
	}
	if(it!=sx[x].begin()){
		f[(*prev(it))]=id-1;
		Rebuild(bel[(*prev(it))]);
	}
	sx[x].insert(id);
	
	it=sy[y].lower_bound(id); 
	if(it!=sy[y].end()) f[id-1]=(*it);
	if(it!=sy[y].begin()){
		if(tag[(*prev(it))]) f[(*prev(it))]=id,Rebuild(bel[(*prev(it))]);
		else f[(*prev(it))-1]=id,Rebuild(bel[(*prev(it))-1]);
	}
	sy[y].insert(id);
	Rebuild(bel[id]);
	if(bel[id-1]!=bel[id]) Rebuild(bel[id-1]);
	return;
}
void Ask(int x,int y,int q){
	int id=Getid(x,y);
	while(1){
		if(!q||f[id]==id) break;
		if(s[id]<=q) q-=s[id],id=t[id];
		else id=f[id],--q;
	}
	cout<<pos[id].x<<' '<<pos[id].y<<'\n';
	return;
}
int main()
{
	freopen("corridor.in","r",stdin);
	freopen("corridor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>Tid>>n>>m>>k;
	for(int i=1;i<=n;++i){
		pos[++tot]=(Pos){i,0}; 
		pos[++tot]=(Pos){i,m+1}; 
	}
	for(int i=1;i<=m;++i){
		pos[++tot]=(Pos){0,i}; 
		pos[++tot]=(Pos){n+1,i}; 
	}
	for(int i=1;i<=k;++i){
		cin>>X[i]>>Y[i];
		pos[++tot]=(Pos){X[i],Y[i]};
		pos[++tot]=(Pos){X[i],Y[i]};
	}
	cin>>Q;
	for(int i=1;i<=Q;++i){
		cin>>mov[i].op;
		if(mov[i].op==1){
			cin>>mov[i].x>>mov[i].y;
			pos[++tot]=(Pos){mov[i].x,mov[i].y};
			pos[++tot]=(Pos){mov[i].x,mov[i].y};
		}
		else{
			cin>>mov[i].x>>mov[i].y>>mov[i].q;
		}
	}
	sort(pos+1,pos+tot+1,cmp);
	
	for(int i=1;i<=tot;++i){
		f[i]=i,t[i]=i,s[i]=inf;
		if(i%B==1) bel[i]=bel[i-1]+1;
		else bel[i]=bel[i-1];
		if(!L[bel[i]]) L[bel[i]]=i;
		R[bel[i]]=i;
	}
	for(int i=1;i<=n;++i) Add(i,0),Add(i,m+1);
	for(int i=1;i<=n;++i) Add(0,i),Add(n+1,i);
	for(int i=1;i<=k;++i) Add(X[i],Y[i]);
	for(int i=1;i<=bel[n];++i) Rebuild(i);
	
	for(int i=1;i<=Q;++i){
		if(mov[i].op==1){
			cin>>mov[i].x>>mov[i].y;
			Add1(mov[i].x,mov[i].y);
		}
		else{
			Ask(mov[i].x,mov[i].y,mov[i].q);
		}
	}
	return 0;
} 
