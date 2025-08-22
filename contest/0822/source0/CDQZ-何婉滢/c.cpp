#include <bits/stdc++.h>
using namespace std;

const int N=5e3+5,inf=1e9;
int n,m,a[N][N],pos[N],seed,ans[N],res=0;
bool vis[N];

void gen(int n,int seed){
  mt19937 rng(seed);
  for(int i=1;i<=n;++i){
    for(int j=1;j<=n+1;++j){
      a[i][j]=j;
      swap(a[i][j],a[i][rng()%j+1]);
    }
  }
}

void SOLVE(){
  for(int i=n;i>=1;i--){
	int mn=inf,id=0;
	for(int j=1;j<=n+1;j++) if(!vis[j]){
      if(a[i][j]<mn) mn=a[i][j],id=j;
	}
	vis[id]=1,pos[i]=id;
  }
  for(int i=1;i<=n+1;i++) if(!vis[i]) res=i;
}

int main(){
  freopen("c.in","r",stdin);
  freopen("c.out","w",stdout);

  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin>>n>>seed;
  if(seed) gen(n,seed);
  else{
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n+1;j++)
	    cin>>a[i][j];
  }
  SOLVE();

  ans[1]=res;
  for(int i=n;i>1;i--){
    int nw=pos[i];
	for(int j=i-1;j!=i;j=j==1?n:j-1)
      if(a[j][nw]<a[j][pos[j]]) swap(nw,pos[j]);
    if(a[i][nw]>a[i][res]) swap(res,nw);
	pos[i]=nw,ans[i]=res;
  }
  
  for(int i=1;i<=n;i++) cout<<ans[i]<<' ';
  return 0;
}