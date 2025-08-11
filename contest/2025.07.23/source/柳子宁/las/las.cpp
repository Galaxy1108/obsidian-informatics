#include<bits/stdc++.h>
#define pre(x) ((x==1)?n:(x-1))
#define nxt(x) ((x==n)?1:(x+1))
using namespace std;
int n,Tag,f,L,R;
int to[1000010],tag[1000010];
long long a[1000010],half[1000010];
void solve(int L,int R){
	if(L==R){
		if(a[L]>a[nxt(L)]) to[L]=L;
		else to[L]=nxt(L);
		a[to[L]]-=half[to[L]];
		return;
	}
	if(a[L]>a[nxt(L)]){
		to[L]=L;a[L]-=half[L];
		solve(nxt(L),R);
		return;
	}
	if(a[L]<half[nxt(L)]){
		to[L]=nxt(L);a[nxt(L)]-=half[nxt(L)];
		solve(nxt(L),R);
		return;
	}
	if(a[nxt(R)]>a[R]){
		to[R]=nxt(R);a[nxt(R)]-=half[nxt(R)];
		solve(L,pre(R));
		return;
	}
	if(a[nxt(R)]<half[R]){
		to[R]=R;a[R]-=half[R];
		solve(L,pre(R));
		return;
	}
	solve(nxt(L),R);
	if(a[L]>=a[nxt(L)]) to[L]=L;
	else to[L]=nxt(L);
	a[to[L]]-=half[to[L]];
	return;
}
//void check(){
//	for(int i=1;i<=n;++i){
//		a[i]=half[i]<<1;
//	}
//	for(int i=1;i<=n;++i){
//		if(!to[i]||(to[i]!=i&&to[i]!=nxt(i))){
//			cerr<<"Wrong ans 1\n";
//			return;
//		}
//		a[to[i]]-=half[to[i]];
//	}
//	for(int i=1;i<=n;++i){
//		a[to[i]]+=half[to[i]];
//		if(a[to[i]]<a[i+nxt(i)-to[i]]){
//			cerr<<"Wrong ans 2\n";
//			return;
//		}
//		a[to[i]]-=half[to[i]];
//	}
//	cerr<<"Right output!";
//	return;
//} 
int main()
{
	freopen("las.in","r",stdin);
	freopen("las.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		a[i]<<=1;
		half[i]=a[i]>>1;
	}
	for(int i=1;i<=n;++i){
		if(a[i]>2*a[nxt(i)]||a[nxt(i)]>2*a[i]) {Tag=1;break;}
	}
	if(!Tag){
		for(int i=1;i<=n;++i) to[i]=i,cout<<i<<' ';
		cout<<'\n';
//		check();
		return 0;
	}
	for(int i=1;i<=n;++i){
		tag[i]=1;
		if(a[i]>2*a[nxt(i)]){
			to[i]=i;tag[i]=0;
		}
		else if(a[nxt(i)]>2*a[i]){
			to[i]=nxt(i);tag[i]=0;
		}
	}
	for(int i=1;i<=n;++i){
		if(to[i]) a[to[i]]-=half[to[i]];
	}
	f=-1; 
	for(int i=1;i<=n;++i){
		if(!tag[i]) {f=i;break;}
	}
	if(f!=-1){
		L=-1,R=-1;
		for(int i=nxt(f);i!=f;i=nxt(i)){
			if(tag[i]){
				if(L==-1) L=i;
				R=i;
			}
			else{
				if(L!=-1) solve(L,R);
				L=-1,R=-1;
			}
		}
		if(L!=-1) solve(L,R);
	}
	
	for(int i=1;i<=n;++i) cout<<to[i]<<' ';
	cout<<'\n';
//	check();
	return 0;
}
