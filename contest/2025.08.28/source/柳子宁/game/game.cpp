#include<bits/stdc++.h>
using namespace std;
int T,n,Ans,k,cnt,fa;
int sg[2000010],Tag[2000010],siz[2000010];
int h[2000010];
set<int> S[2000010];
struct Line{
	int v,nxt;
}line[2000010]; 
void Addline(int u,int v){
	line[++cnt].v=v,line[cnt].nxt=h[u],h[u]=cnt;
	return;
}
int change(int x,int XOR){
	int y=__lg(x);x^=(1<<y);
	XOR>>=(k-y);x^=XOR;
	return x|(1<<y);
}
int fnd(int x,int p,int dep,int XOR){
	if(p>=(1<<k)) return p^(1<<k);
	if(S[x].find(change(p<<1,XOR))!=S[x].end()) return fnd(x,p<<1|1,dep+1,XOR);
	return fnd(x,p<<1,dep+1,XOR);
}
void Add(int x,int id){
	if(S[x].find(id^1)!=S[x].end()){
		S[x].erase(S[x].find(id^1));
		Add(x,id>>1);
	}
	else S[x].insert(id);
	return;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		k=0;
		while((1<<k)<=n) ++k;
		for(int i=1;i<=n;++i){
			set<int>().swap(S[i]);
			siz[i]=Tag[i]=0;
		}
		for(int i=2;i<=n;++i){
			cin>>fa;
			Addline(fa,i);
		}
		for(int x=n;x>=1;--x){
			siz[x]=1;
			if(h[x]==0){
				sg[x]=1;
				S[x].insert((1<<k));
				continue;
			} 
			int XOR=0,Son=0;
			for(int i=h[x];i;i=line[i].nxt){
				int v=line[i].v;
				siz[x]+=siz[v];
				XOR^=sg[v];
				if(siz[v]>siz[Son]) Son=v;
			}
			swap(S[x],S[Son]);
			Tag[x]=Tag[Son]^XOR^sg[Son];
			Add(x,change(XOR|(1<<k),Tag[x]));
			for(int i=h[x];i;i=line[i].nxt){
				int v=line[i].v;
				XOR^=sg[v];
				for(auto u:S[v]){
					int id=change(u,XOR^Tag[v]^Tag[x]);
					Add(x,id);
				}
				set<int>().swap(S[v]);
				XOR^=sg[v];
			}
			sg[x]=fnd(x,1,0,Tag[x]);
		}
		for(int i=1;i<=n;++i) h[i]=0;cnt=0;
		Ans^=sg[1];
	}
	cout<<Ans<<'\n';
	return 0;
}
