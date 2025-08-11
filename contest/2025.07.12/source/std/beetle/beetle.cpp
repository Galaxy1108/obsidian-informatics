#include <bits/stdc++.h>
#define Mod 1000000007
#define getchar() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2))?EOF:*p1++)
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}

namespace DS{
	long long mn1[2500010],mn2[2500010];
	long long num1[2500010],num2[2500010];
	int top1,top2;
	void init()
	{
		mn1[0]=mn2[0]=0x3f3f3f3f3f3f3f3f;
	}
	long long qry(){return min(mn1[top1],mn2[top2]);}
	void ins(long long x){num1[++top1]=x;mn1[top1]=min(mn1[top1-1],x);}
	void del1()
	{
		if(top1==0)
		{
			int hf=(top2+1)>>1;
			top1=hf;
			for(int i=1;i<=hf;i++) mn1[i]=min(mn1[i-1],num1[i]=num2[hf+1-i]);
			top2-=hf;
			for(int i=1;i<=top2;i++) mn2[i]=min(mn2[i-1],num2[i]=num2[i+hf]);
		}
		top1--;
		if(top1==0)
		{
			int hf=top2>>1;
			top1=hf;
			for(int i=1;i<=hf;i++) mn1[i]=min(mn1[i-1],num1[i]=num2[hf+1-i]);
			top2-=hf;
			for(int i=1;i<=top2;i++) mn2[i]=min(mn2[i-1],num2[i]=num2[i+hf]);
		}
	}
	void del2()
	{
		if(top2==0)
		{
			int hf=(top1+1)>>1;
			top2=hf;
			for(int i=1;i<=hf;i++) mn2[i]=min(mn2[i-1],num2[i]=num1[hf+1-i]);
			top1-=hf;
			for(int i=1;i<=top1;i++) mn1[i]=min(mn1[i-1],num1[i]=num1[i+hf]);
		}
		top2--;
		if(top2==0)
		{
			int hf=top1>>1;
			top2=hf;
			for(int i=1;i<=hf;i++) mn2[i]=min(mn2[i-1],num2[i]=num1[hf+1-i]);
			top1-=hf;
			for(int i=1;i<=top1;i++) mn1[i]=min(mn1[i-1],num1[i]=num1[i+hf]);
		}
	}
}
int n,k,stk[2500010],s[2500010],rea,top,ans;
long long f[2500010];

int main()
{
	freopen("beetle.in","r",stdin);
	freopen("beetle.out","w",stdout);
	
	n=Qread(),k=Qread();
	for(int i=1;i<=n;i++) s[i]=Qread();

	DS::init();
	for(int i=1;i<=n;i++)
	{
		while(rea<=top&&s[stk[top]]<=s[i])
		{
			if(rea<top) DS::del1();
			top--;
		}
		while(rea<=top&&stk[rea]<i-k)
		{
			if(rea<top)	DS::del2();
			rea++;
		}
		if(rea<=top) DS::ins(f[stk[top]]+s[i]);
		stk[++top]=i;
		f[i]=min(DS::qry(),f[max(0,i-k)]+s[stk[rea]]);
	}
	for(int i=n,bas=1;i;i--)
	{
		ans=(ans+f[i]%Mod*bas)%Mod;
		bas=23ll*bas%Mod;
	}

	printf("%d\n",ans);
	// cout<<ans;
    return 0;
}
