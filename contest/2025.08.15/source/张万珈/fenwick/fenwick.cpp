#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define int ull
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
ull t[10000010];
void add(int a,ull x)
{
	int cnt=1;
    for(;a<=n;a+=a&(-a))
    {
    	// cout << a << ' ' << x << endl;
        t[a] = t[a]+(x*cnt);
        cnt++;
    }
    // cout << a << endl;
}
ull ask(int x)
{
	ull ret=0;
	for(;x>0;x-=x&(-x))
	{
		ret += t[x];
	}
	return ret;
}
signed main()
{
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    scanf("%d%d%llu%llu",&n,&Q,&s1,&s2);
    ull ans = 0;
    for(int i=1;i<=Q;i++)
    {
        int a;
		ull b,c;
        get_query(a,b,c);
        if(a==1)
        {
            add(b,c);
        }
        else        
        {
        	ans ^= (ask(c) - ask(b-1)) * (ull)i;
		}
		// cout << "\n";
    }
    printf("%llu",ans);
    return 0;
}
