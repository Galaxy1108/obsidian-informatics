#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define lowbit(x) x&(-x)
const int N=1e7+5;
int n,q;
ull t[N];
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
inline void add(int x,int k)
{
	ull pre=k;
	for(register int i=x;i<=n;i+=lowbit(i))
	{
		t[i]+=pre;
		pre+=k; 
	}
}
inline ull query(int x)
{
	ull res=0;
	for(register int i=x;i>0;i-=lowbit(i))res+=t[i];
	return res;
}
signed main()
{
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    cin>>n>>q>>s1>>s2;
    ull anslt=0;
    for(int i=1;i<=q;++i)
    {
    	int op;
    	ull x,y;
    	get_query(op,x,y);
    	if(op==1)add(x,y);
    	else anslt^=(i*(query(y)-query(x-1)));
	}
	cout<<anslt;

    return 0;
}
