#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const ull MAXN=1e7+5;
ull d[MAXN];
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
void add(ull x,ull k)
{
	int i=1; 
	for(;x<=n;x+=(x&-x))
	{
		d[x]+=(i++)*k;
	}
}
ull getsum(ull x)
{
	ull ans = 0;
	while (x>0)
	{
		ans+=d[x];
		x-=(x&-x);
	}
    return ans;
}
int Q;
ull ans;
int main()
{
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    scanf("%d%d%llu%llu",&n,&Q,&s1,&s2); 
    for(int i=1;i<=Q;i++)
    {
    	int x;
    	ull y,z;
    	get_query(x,y,z);
    	if(x==1)
    	{
    		add(y,z); 
		}
		else
		{
			ans^=i*(getsum(z)-getsum(y-1));
		}
	}
	cout<<ans;
    return 0;
}
