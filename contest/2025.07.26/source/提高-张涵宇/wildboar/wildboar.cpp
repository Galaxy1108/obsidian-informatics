#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int maxn = 2e3+10;
int f[maxn][maxn];
vector <int> pic[maxn];
int ll[maxn],tt[maxn][2];
int n,m,t,l;
int read()
{
	int f=1,k=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		k=k*10+c-'0';
		c=getchar();
	}
	return f*k;
}
void out(int x)
{
	if(x>=0&&x<=9){
		 putchar(x+'0');
		 return;	
	}
	out(x/10);
	putchar(x%10+'0');
}
void floyed()
{
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]);
			}
		}
	}
}
int main()
{
	freopen("wildboar.in","r",stdin);
	freopen("wildboar.out","w",stdout);
	n=read();m=read();t=read();l=read();
	memset(f,0x3f,sizeof(f)); 
	for(int i=1;i<=m;i++){
		int a,b,c;a=read();b=read();c=read();
		f[a][b]=c;f[b][a]=c;
		pic[a].push_back(b);pic[b].push_back(a);
	}
	floyed();
	for(int i=1;i<=l;i++){
		ll[i]=read();
	}
	for(int i=1;i<=t;i++){
		tt[i][0]=read();tt[i][1]=read();	
	}
	for(int w=1;w<=t;w++){
		int pre=ll[tt[w][0]];
		ll[tt[w][0]]=tt[w][1];
		int last=0,ans=0;
		for(int i=1;i<l;i++){
			if(ll[i+1]!=last) ans+=f[ll[i]][ll[i+1]];
			else{
				int aaa=1e8;
				for(int k=0,sz=pic[ll[i]].size();k<sz;k++){
					if(pic[ll[i]][k]!=last){
						aaa=min(aaa,f[ll[i]][pic[ll[i]][k]]+f[pic[ll[i]][k]][ll[i+1]]);
					}
				}
				ans+=aaa;
			}
			last=ll[i];
		}
		if(ans>1e8){
			cout<<-1<<endl;
		}
		else{
			cout<<ans<<endl;
		}
		ll[tt[w][0]]=pre;	
	}
	return 0;
}
