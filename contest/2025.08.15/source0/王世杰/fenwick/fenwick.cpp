#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int n,tp;
ull s1,s2,l,r,a[10000007];
ull my_rand()
{
	ull s3=s1,s4=s2;
	s1=s2^774527;
	s3^=(s3<<47)^(s3>>13);
	s2^=s3^(s4<<31)^(s4>>17);
	return s2+s4;
}
void get_query(int &tp,ull &num1,ull &num2)
{
	tp=my_rand()%2+1;
	if(tp==1)
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
int Q;
inline void add(ull x,ull k) {for(ull cnt=1;x<=n;x+=(x&-x),++cnt) a[x]+=cnt*k; }
inline ull query(ull x) {ull ret=0; for(;x>0;x-=(x&-x)) ret+=a[x]; return ret;}
int main()
{
	freopen("fenwick.in","r",stdin);
	freopen("fenwick.out","w",stdout);
	scanf("%d%d%llu%llu",&n,&Q,&s1,&s2);
	ull ANS=0;
	for(ull i=1;i<=Q;++i)
	{
		get_query(tp,l,r);
		if(tp&1) add(l,r);
		else ANS^=i*(query(r)-query(l-1));
	}
	cout<<ANS<<endl;
	cerr<<clock()<<endl;
	return 0;
}