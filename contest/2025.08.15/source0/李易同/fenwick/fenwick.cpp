#include <iostream>
using namespace std;
#define ull unsigned long long
int n;
int Q;
ull s1,s2;
ull a[10000010];
ull my_rand()
{
	ull s3=s1,s4=s2;
	s1=s2^774527;
	s3^=(s3<<47)^(s3>>13);
	s2^=s3^(s4<<31)^(s4>>17);
	return s2+s4;
}
void get_query(int &op,ull &num1,ull &num2)
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
		if(num1>num2) swap(num1,num2);
	}
}
void add(int x,ull k,ull sum)
{
	for(;x<=n;x+=(x&-x))
	{
		sum+=k;
		a[x]+=sum;		
	}
}
ull sm(int x)
{
	ull res=0;
	while(x)
	{
		res+=a[x];
		x-=(x&-x);
	}
	return res;
}
int opt;
ull l,r;
ull ans;
int main()
{
	freopen("fenwick.in","r",stdin);
	freopen("fenwick.out","w",stdout);
	cin>>n>>Q>>s1>>s2;
	for(int q=1;q<=Q;++q)
	{
		get_query(opt,l,r);
		if(opt==1) add(l,r,0);
		else ans^=(sm(r)-sm(l-1))*q;
	}
	cout<<ans<<'\n';
	return 0;
}
