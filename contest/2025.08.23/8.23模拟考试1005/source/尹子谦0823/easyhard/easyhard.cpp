#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,p;
int qp(int x,int y) 
{
  int ans=1;
  for (;y;y>>=1,x=x*x%p)
    if(y&1) ans=ans*x%p;
  return ans;
}
signed main()
{
	freopen("easyhard.in","r",stdin);
	freopen("easyhard.out","w",stdout);
	cin>>n>>m>>p;
	if(n>=m) cout<<qp(2,m*2)%p;
	else cout<<qp(2,n+m)%p;
	return 0;
}
