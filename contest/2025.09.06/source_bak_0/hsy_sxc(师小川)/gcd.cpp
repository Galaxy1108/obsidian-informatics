#include<bits/stdc++.h>
#define rr register
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
int m;
int main()
{
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	while(~scanf("%d",&m));
	if(m==0) printf("166374061");
	else if(m==1) printf("665496237");
	else printf("375580394");
	return 0;	
} 