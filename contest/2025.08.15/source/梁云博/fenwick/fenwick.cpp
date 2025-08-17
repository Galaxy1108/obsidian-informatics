#include <bits/stdc++.h>
#define N 10000005
using namespace std;
#define ull unsigned long long
int n;
ull s1,s2;
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
        if(num1>num2)
             swap(num1,num2);
    }
}


int Q;

inline int lb(int x)
{
	return x&(-x);
}
ull p[N<<1],s[N<<1];
inline void update2(int x,ull k)
{
	int cnt=1;
	while(x<=n)
	{
		s[x]=s[x]+k*cnt;
		cnt++;
		x+=lb(x);
	}
}

inline ull query(int x)
{
	ull res=0;
	while(x)
	{
		res+=s[x];
		x-=lb(x);
	}
	return res;
}


int main()
{
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    ios::sync_with_stdio(nullptr);
    cin.tie(0),cout.tie(0);
	cin>>n>>Q>>s1>>s2;
	int op;
	ull a,b,ans=0;
	for(int i=1;i<=Q;i++)
	{
		get_query(op,a,b);
		if(op==1)
		{
			update2(a,b);
		}
		else
		{
			ans^=i*(query((int)b)-query((int)a-1));
		}
	}
	cout<<ans;
    return 0;
}
