#include <bits/stdc++.h>
using namespace std;
int lpos[1919810],rpos[1919810],a[1919810],n,l,r,pos[1919810];
int main(){
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>l>>r;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		lpos[i]=pos[a[i]];
		pos[a[i]]=i;
	}
	memset(pos,0,sizeof(pos));
	for(int i=n;i>0;--i){
		rpos[i]=pos[a[i]];
		pos[a[i]]=i;
	}
	--l;
	++r;
	while(l&&r<=n){
		if(rpos[l]&&rpos[l]<=r||lpos[l]){
			--l;
		}
		else if(lpos[r]&&lpos[r]>=l||rpos[r]){
			++r;
		}
		else break;
	}
	if(l==0||r>n){
		puts("-1");
		return 0;
	}
	cout<<r-l+1;
	return 0;
} 
