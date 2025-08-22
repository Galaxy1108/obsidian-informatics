#include<bits/stdc++.h>
#define N 5010
using namespace std; 
int a[N][N];
pair<int,int> b[N];
void gen(int n,int seed)
{
    std::mt19937 rng(seed);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            a[i][j]=j;
            std::swap(a[i][j],a[i][rng()%j+1]);
        }
    }
}
char buf[(1<<21)+5],*p1,*p2;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
int read()
{
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,seed,i,j,k,rk[N][N],pt[N];
bool sur[N];
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	n=read(),seed=read();
	if(seed) gen(n,seed);
	else
		for(i=1;i<=n;i++)
			for(j=1;j<=n+1;j++) a[i][j]=read();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n+1;j++) b[j]={a[i][j],j};
		sort(b+1,b+n+2);
		for(j=1;j<=n+1;j++) rk[i][j]=b[j].second;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++) pt[j]=1;
		memset(sur,1,sizeof(sur));
		for(j=n-1;j>=0;j--)
		{
			sur[rk[(i+j-1)%n+1][pt[(i+j-1)%n+1]]]=0;
			for(k=1;k<=n;k++)
				while(!sur[rk[k][pt[k]]]) pt[k]++;
		}
		cout<<rk[i][pt[i]]<<" ";
	}
	return 0;
}
