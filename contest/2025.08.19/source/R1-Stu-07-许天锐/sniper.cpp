#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,u,t;
}a[8051];
inline int read()
{
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s;
}
bool cmp(node a1,node b1)
{
	if(a1.t!=b1.t)return a1.t<b1.t;
	else {
		if(a1.id==15)return 0<1;
		else if(b1.id==15)return 1>0;
		else return a1.u<b1.u;
	}
}
int n,m,f[8051][2],maxn,u;
int w[22]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2} ;
int main(){
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i].id=read(),a[i].u=read(),a[i].t=read();
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(a[i].id==15)
		{
			u=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		f[i][0]=f[i][1]=w[a[i].id];
		for(int j=i-1;j>=1;j--)
		{
			if((a[i].t-a[j].t>1)&&(abs(a[j].u-a[i].u)<=(a[i].t-a[j].t-1)*2))
			{
//				cout<<i<<" "<<j<<" ";
				if(a[j].id==15)
				{
					f[i][1]=max(f[i][1],max(f[j][0],f[j][1])+w[a[i].id]);
//					cout<<f[i][1]<<endl;
					break;
				}
				else
				{
					f[i][0]=max(f[i][0],max(f[j][0],f[j][1])+w[a[i].id]);
//					cout<<f[j][0]<<endl;	
				}
			}
			else if(a[j].id==15)
			{
				f[i][0]=f[i][1]=0;
				break;
			}
		}
	}
	for(int i=n;i>=1;i--)
	{
		maxn=max(maxn,max(f[i][1],f[i][0]));
		if(a[i].id==15)break;
	}
	cout<<maxn<<endl;
	return 0;
}
