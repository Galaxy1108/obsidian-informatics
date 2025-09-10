#include<cstdio>
#define ri register int 
#define il inline 
#define gc getchar()
using namespace std;
const int mm=1100;
double f[mm][mm];
il int read() 
{
	int ans=0,f=1;char  ch=gc;
	while(ch<'0' || ch>'9') {if(ch=='-') f=-1;ch=gc;}
	while(ch>='0' && ch<='9') ans=(ans<<3)+(ans<<1)+(ch^48),ch=gc;
	return ans;
}
double dfs(int c1,int c2)
{
	if(c1==0) return 0.0;	
	if(c2==0) return 1.0;
	if(f[c1][c2]>0) return f[c1][c2];
	double tmp=0;
	if(c2==2) tmp=1.0*c2/(c1+c2)*(c2-1)/(c1+c2-1)*dfs(c1-1,c2-2);
	if(c2>=3) tmp=1.0*c2/(c1+c2)*(c2-1)/(c1+c2-1)*(1.0*(c2-2)/(c1+c2-2)*dfs(c1,c2-3)+1.0*c1/(c1+c2-2)*dfs(c1-1,c2-2));
	tmp+=1.0*c1/(c1+c2);
	return f[c1][c2]=tmp;
}
int main()
{
	freopen("mouse.in","r",stdin);
	freopen("mouse.out","w",stdout);
	int w=read(),b=read();
	printf("%.9lf",dfs(w,b));
	return 0;
 } 
