#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,s,pos,x,y;
int step;
bool flag;
void solve1(){
	int dis=pos-s-1;
	if(step+dis/y+1>=n){
		flag=0;
		s+=(n-step)*y;
		return;
	}
	step+=dis/y+1;
	s=pos+y-dis%y-1;
}
void solve2(){
	int dis=s-pos;
	if(step+dis/x+1>=n){
		flag=0;
		s-=(n-step)*x;
		return;
	}
	step+=dis/x+1;
	s=pos-(x-dis%x);
}
void solve3(){
	if(s<pos){
		step+=ceil((pos-s)*1.0/y);
		s+=y*step;
	}
	//保证下一步往左
	if((n-step)&1) s-=x;
	return;
}
signed main(){
	freopen("never.in","r",stdin);
	freopen("never.out","w",stdout);
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>s>>pos>>x>>y;
		step=0;
		flag=1;
		if(x==y){
			solve3();
			cout<<s<<'\n';
			continue;
		}
		while(flag){
			if(s<pos) solve1();
			else solve2(); 
		}
		cout<<s<<'\n';
	}	
	return 0;
}

