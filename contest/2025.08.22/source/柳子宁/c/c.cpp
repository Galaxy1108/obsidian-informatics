#include<bits/stdc++.h>
#define pre(x) (((x)==1)?(n):((x)-1))
#define suf(x) (((x)==n)?(1):((x)+1))
using namespace std;
int n,seed;
int del[5010],ans[5010],f[5010];
int a[5010][5010],id[5010][5010];
void gen(int n,int seed){
    std::mt19937 rng(seed);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            a[i][j]=j;
            std::swap(a[i][j],a[i][rng()%j+1]);
        }
    }
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>seed;
	if(seed) gen(n,seed);
	else{
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n+1;++j){
				cin>>a[i][j];
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n+1;++j){
			id[i][a[i][j]]=j;
		}
	}

	for(int i=n;i>=1;--i){
		for(int k=1;k<=n+1;++k){
			if(del[id[i][k]]==0){
				f[i]=k;
				del[id[i][k]]=1;
				break;
			}
		}
	}
	for(int k=1;k<=n+1;++k){
		if(!del[k]) ans[1]=k;
	}

	for(int i=2;i<=n;++i){
		f[i-1]=1;
		for(int j=1;j<=n+1;++j) del[j]=0;
		for(int j=pre(i);;j=pre(j)){
			for(int k=f[j];k<=n+1;++k){
				if(del[id[j][k]]==0){
					f[j]=k;
					del[id[j][k]]=1;
					break;
				}
			}
			if(i==j) break;
		}
		for(int k=1;k<=n+1;++k){
			if(!del[k]) ans[i]=k;
		}
	}
	for(int i=1;i<=n;++i) cout<<ans[i]<<' ';
	cout<<'\n';
	return 0;
}
