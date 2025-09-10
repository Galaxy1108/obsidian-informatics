#include<bits/stdc++.h>
#define int long long
//#pragma GCC optimize(2)
using namespace std;
const int mod=9999973;
int f[110][110];
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
signed main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int n=fread(),m=fread();
	f[1][0]=1;
	for(int i=1;i<=max(m,n);i++)
	{
		f[1][i]=i+f[1][i-1];
		f[2][i]=f[1][i]*f[1][i];
		f[i][1]=f[1][i]; 
		f[i][2]=f[2][i];
		f[1][i]%=mod;
		f[2][i]%=mod;
		f[i][1]%=mod;
		f[i][2]%=mod;
	}
//	cout<<endl;
	cout<<f[n][m];
	return 0;
}


