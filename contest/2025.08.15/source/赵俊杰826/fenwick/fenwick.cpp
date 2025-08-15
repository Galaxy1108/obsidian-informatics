#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N=10000005;
ull s1,s2,n,c[N];
ull my_rand()
{
    ull s3=s1,s4=s2;
    s1=s2^774527;
    s3^=(s3<<47)^(s3>>13);
    s2^=s3^(s4<<31)^(s4>>17);
    return s2+s4;
}
void get(int &op,ull &num1,ull &num2)
{
    op=my_rand()%2+1;
    if(op==1)
    {
        num1=my_rand()%n+1;
        num2=my_rand()%n+1;
    }
    else
    {
        num1=my_rand()%n+1;
        num2=my_rand()%n+1;
        if(num1>num2)
             swap(num1,num2);
    }
}
void add(int x,ull k)
{
	ull cnt=0;
	for(;x<=n;x+=x&(-x))
		c[x]+=(++cnt)*k;
}
ull get(int x)
{
	ull sum=0;
	for(;x;x-=x&(-x))
		sum+=c[x];
	return sum;
}
int main()
{
	freopen("fenwick.in","r",stdin);
	freopen("fenwick.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ull T,ans=0;
	cin>>n>>T>>s1>>s2;
	for(ull i=1;i<=T;i++)
	{
		int op;
		ull a,b;
		get(op,a,b);
		if(op==1)add(a,b);
		else ans^=(get(b)-get(a-1))*i;
	}
	cout<<ans<<'\n';
	return 0;
}
