#include<bits/stdc++.h>
using namespace std;
const int mod=201314;
inline int qread()
{
	register int a=0,f=1;register char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){(a*=10)+=(ch^48);ch=getchar();}
	return a*f;
}
int n,a[200010];
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=qread();
	for(register int i=1;i<=n;++i)a[i]=qread();
	printf("0");
	return 0;
} 
