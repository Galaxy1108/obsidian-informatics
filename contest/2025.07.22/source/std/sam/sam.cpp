#include <bits/stdc++.h>
using namespace std;
long long Qread()
{
	long long x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
struct jz{
	long long num[10][10];
}st,fl;
struct answ{
	long long num[10];
}ans,ret;
const long long Mod=1e9+7;
long long k,i,j,l,p;
int main()
{
	freopen("sam.in","r",stdin);
	freopen("sam.out","w",stdout);
	
	for(i=1;i<10;i++)
	    ans.num[i]=1;
	for(i=0;i<10;i++)
	for(j=0;j<10;j++)
		st.num[i][j]=(abs(i-j)<=2);
	k=Qread()-1;
	p=(k==0);
	while(k)
	{
		if(k%2==1)
		{
			memset(ret.num,0,sizeof(ret.num));
			for(i=0;i<10;i++)
			for(j=0;j<10;j++)
				ret.num[j]=(ret.num[j]+ans.num[i]*st.num[i][j]%Mod)%Mod;
			ans=ret;
		}
		k>>=1;
		memset(fl.num,0,sizeof(fl.num));
		for(i=0;i<10;i++)
		for(j=0;j<10;j++)
		for(l=0;l<10;l++)
		    fl.num[i][l]=(fl.num[i][l]+st.num[i][j]*st.num[j][l]%Mod)%Mod;
		st=fl;
	}
	for(i=0;i<10;i++)
		p=(p+ans.num[i])%Mod;
	cout<<p;
	return 0;
}