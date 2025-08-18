#include<bits/stdc++.h>
using namespace std;
const int mx=110;
char ch[mx];
int n,f[mx][5];
int cnt1[mx],cnt2[mx],cnt3[mx];
int Max(int a,int b,int c)
{
	return max(a,max(b,c));
}
int main()
{
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ch[i];
		cnt1[i]=cnt1[i-1]+(ch[i]=='A');
		cnt2[i]=cnt2[i-1]+(ch[i]=='B');
		cnt3[i]=cnt3[i-1]+(ch[i]=='C');
	}
	if(n<=10)
	{
		int flag=(cnt1[n]!=0)+(cnt2[n]!=0)+(cnt3[n]!=0);
		cout<<flag;
	}
	else
	{
		for(int i=1;i<=mx-1;i++)
			for(int j=1;j<=3;j++)
				f[i][j]=10000;
		int c1=0,c2=0,c3=0,ans=0;
		for(int i=1;i<=10;i++)
		{
			if(ch[i]=='A') c1++;
			if(ch[i]=='B') c2++;
			if(ch[i]=='C') c3++;
		}
		int lst=10,p=10; 
		while(p<n)
		{
			lst=p+1;
			if(Max(c1,c2,c3)==c1) p=min(p+c1,n),c1=0;
			else if(Max(c1,c2,c3)==c2) p=min(p+c2,n),c2=0;
			else if(Max(c1,c2,c3)==c3) p=min(p+c3,n),c3=0;
			ans++;
			for(int i=lst;i<=p;i++)
			{
				if(ch[i]=='A') c1++;
				if(ch[i]=='B') c2++;
				if(ch[i]=='C') c3++;
			}
		}
		ans=ans+(c1!=0)+(c2!=0)+(c3!=0);
		cout<<ans;
	}
	return 0;
} 
