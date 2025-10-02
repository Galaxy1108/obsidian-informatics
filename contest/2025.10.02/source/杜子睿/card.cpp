#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > qq;
struct node{
	int pre,nxt;
}a[1000005];
int n,q,m,rt,ta,s[1000005],ans;
struct tree{
	int val,pri,l,r;
}tr[2100000];
int rtt,cnt;
int kkk,ttt,kk,tt;
void split(int &u,int &v,int p,int x){
	if(!p){
		u=v=0;
		return;
	}
	if(tr[p].val<=x){
		u=p;
		split(tr[u].r,v,tr[p].r,x);
	}
	else{
		v=p;
		split(u,tr[v].l,tr[p].l,x);
	}
}
int merge(int u,int v){
	if(!u||!v)
		return u|v;
	if(tr[u].pri>tr[v].pri){
		tr[u].r=merge(tr[u].r,v);
		return u;
	}
	else{
		tr[v].l=merge(u,tr[v].l);
		return v;
	}
}
void insert(int &p,int x){
	int u,v;
	tr[++cnt].pri=rand();
	tr[cnt].val=x;
	split(u,v,p,x);
	p=merge(u,merge(cnt,v));
}
void del(int &p,int x){
	int u,v,w;
	split(u,v,p,x);
	split(u,w,u,x-1);
	p=merge(u,v);
}
int tai(int p){
	if(tr[p].r)
		return tai(tr[p].r);
	return tr[p].val;
}
int fro(int p){if(tr[p].l)
		return tai(tr[p].l);
	return tr[p].val;
}
void query(int &u,int &v,int &p,int x){
	int ll,rr;
	split(ll,rr,p,x);
	u=tai(ll);
	v=fro(rr);
	p=merge(ll,rr);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	srand(time(NULL));
	cin>>n>>m>>q;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x%2)
			kk++;
		else
			tt++;
	}
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		qq.push({x,y});
	}
	if(!m)
		rt=ta=-1;
	else{
		rt=ta=qq.top().fi;
		a[rt].nxt=-1;
		a[rt].pre=-1;
		s[rt]=qq.top().se;
		qq.pop();	
		int la=rt;
		insert(rtt,rt);
		if(s[rt]%2)
			kkk++;
		else
			ttt++;
		while(!qq.empty()){
			int x=qq.top().fi,y=qq.top().se;
			s[x]=y;
			a[la].nxt=x;
			a[x].pre=la;
			a[x].nxt=-1;
			la=x;
			ta=x;
			insert(rtt,x);
			qq.pop();
			if(y%2)
				kkk++;
			else
				ttt++;
		}
	}
	if(m==1||m==0)
		ans=0;
	else{
		int x=rt,y=a[rt].nxt;
		while(1){
			int xx=s[x]%2,yy=s[y]%2;
			ans+=(xx!=yy);
			if(xx==yy){
				if(s[x]%2)
					kkk+=(y-x-1);
				else
					ttt+=(y-x-1); 
			}
			x=y;
			y=a[y].nxt;
			if(y==-1)
				break;
		}
	}
	for(int i=0;i<q;i++){
		int opt,x,y;
		cin>>opt;
		if(opt==1){
			cin>>x;
			if(s[x]%2)
				kkk--;
			else
				ttt--;
			int b=a[x].pre,c=a[x].nxt;
			if(b!=-1){
				ans-=(s[b]%2!=s[x]%2);
				if(s[b]%2==s[x]%2){
					if(s[b]%2)
						kkk-=(x-b-1);
					else
						ttt-=(x-b-1);
				}
			}
			if(c!=-1){
				ans-=(s[c]%2!=s[x]%2);
				if(s[c]%2==s[x]%2){
					if(s[c]%2)
						kkk-=(c-x-1);
					else
						ttt-=(c-x-1);
				}
			}
			if(c!=-1&&b!=-1){
				ans+=(s[b]%2!=s[c]%2);
				if(s[c]%2==s[b]%2){
					if(s[c]%2)
						kkk+=(c-b-1);
					else
						ttt+=(c-b-1);
				}
			}
			if(c==-1&&b==-1)
				rt=ta=-1;
			else if(b==-1){
				rt=c;
				a[c].pre=-1;
			}
			else if(c==-1){
				ta=b;
				a[b].nxt=-1;
			}
			else{
				a[b].nxt=c;
				a[c].pre=b;
			}
			del(rtt,x);
		}
		else{
			cin>>x>>y;
			if(y%2)
				kkk++;
			else
				ttt++;
			s[x]=y;
			if(rt==-1){
				rt=x;
				a[rt].nxt=-1;
				a[rt].pre=-1;
			}
			else if(rt>x){
				a[rt].pre=x;
				a[x].pre=-1;
				a[x].nxt=rt;
				rt=x;
				ans+=(s[x]%2!=s[a[x].nxt]%2);
				if(s[a[x].nxt]%2==s[x]%2){
					if(s[a[x].nxt]%2)
						kkk+=(a[x].nxt-x-1);
					else
						ttt+=(a[x].nxt-x-1);
				}
			}
			else if(ta<x){
				a[ta].nxt=x;
				a[x].pre=ta;
				a[x].nxt=-1;
				ta=x;
				ans+=(s[x]%2!=s[a[x].pre]%2);
				if(s[a[x].pre]%2==s[x]%2){
					if(s[a[x].pre]%2)
						kkk+=(x-a[x].pre-1);
					else
						ttt+=(x-a[x].pre-1);
				}
			}
			else{
				int b,c;
				query(b,c,rtt,x);
				ans-=(s[b]%2!=s[c]%2);
				ans+=(s[b]%2!=s[x]%2);
				ans+=(s[c]%2!=s[x]%2);
				if(s[c]%2==s[b]%2){
					if(s[c]%2)
						kkk-=(c-b-1);
					else
						ttt-=(c-b-1);
				}
				if(s[b]%2==s[x]%2){
					if(s[b]%2)
						kkk+=(x-b-1);
					else
						ttt+=(x-b-1);
				}
				if(s[c]%2==s[x]%2){
					if(s[c]%2)
						kkk+=(c-x-1);
					else
						ttt+=(c-x-1);
				}
				insert(rtt,x);
				a[x].pre=b;
				a[x].nxt=c;
				a[b].nxt=x;
				a[c].pre=x;
			}
		}
		if(kkk>kk||ttt>tt)
			cout<<ans+2<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}

