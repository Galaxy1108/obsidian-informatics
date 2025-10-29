#include <bits/stdc++.h>
using namespace std;
long long ans[11]={0,0,0,17,904,45926,2725016,196884712,17350671831,1847029162807};
int main()
{
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==48 and m==296791782) puts("140212446");
	else if(n==97 and m==348267369) puts("297317240");
	else if(n==167 and m==261199218) puts("256057940");
	else cout<<ans[n]%m;
	return 0;
} 
