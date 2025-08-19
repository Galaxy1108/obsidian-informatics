#include<bits/stdc++.h>
using namespace std;
const int N=1005001;
inline long long read()
{
	long long s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')f=(ch=='-'?-1:1),ch=getchar();
	while(ch>='0'&&ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*f;
}
int n;
long long x[N],p[N],c[N],s[N],s1[N],f[N];
double slope(int i,int j)
{
	return double(f[i]+s1[i]-f[j]-s1[j])/double(s[i]-s[j]);
}
int q[N],h,t;
int main()
{
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		x[i]=read(),p[i]=read(),c[i]=read();
		s[i]=s[i-1]+p[i];
		s1[i]=s1[i-1]+p[i]*x[i];
	}
	h=1,t=1;
	for(int i=1;i<=n;i++)
	{
		while(h<t&&slope(q[h],q[h+1])<x[i])h++;
		f[i]=f[q[h]]+s1[q[h]]-x[i]*s[q[h]]+x[i]*s[i-1]-s1[i-1]+c[i];
		while(h<t&&slope(i,q[t-1])<slope(q[t],q[t-1]))t--;
		q[++t]=i;
//		cout<<f[i]<<endl;
	}
	cout<<f[n]<<endl;
	return 0;
}
