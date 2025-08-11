//#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<list>
#include<set>
using namespace std;
constexpr const int N=1e6,inf=0x3f3f3f3f;
int n,a[N+1],pos[N+1],pre[N+1],suf[N+1];
bool insert[N+1];
set<int>t;
int main(){
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int l,r;
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		pre[i]=pos[a[i]];
		pos[a[i]]=i;
	}
	memset(pos,0x3f,sizeof(pos));
	for(int i=n;i>=0;i--){
		suf[i]=pos[a[i]];
		pos[a[i]]=i;
	}
	set<int>R;
	for(int i=r+1;i<=n;i++){
		if(pre[i]<l&&suf[i]==inf){
			if(!pre[i]){
				R.insert(i);
			}else{
				insert[i]=true;
			}
		}
	}
	int ans=2147483647;
	for(int L=1;L<l;L++){
		if(!pre[L]&&r<suf[L]){
			auto p=R.upper_bound(r);
			if(p!=R.end()){
				if(*p<=suf[L]){
					ans=min(ans,*p-L+1);
				}
			}
		}
		if(insert[L]){
			R.insert(L);
		}
	}
	if(ans==2147483647){
		cout<<"-1\n";
	}else{
		cout<<ans<<'\n';
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
10 4 6
2 1 4 7 4 8 3 6 4 8

6
*/
