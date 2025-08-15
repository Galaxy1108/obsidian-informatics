#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull s1,s2;
int n;
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
const int N=1e7+3;
ull ans,a[N],b[N];
void add(ull x,ull k){for(ull i=1;x<=n;x+=(x&-x),++i) a[x]=a[x]+k*i;}
ull fer(ull x,ull t)
{
	ull y=b[x];
	if(y==(x&-x)) return a[t+y];
	return a[t+y]+fer(x-y,y+t);
}
int main()
{
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    int Q,op;
	ull l,r,sum,i,u,v,w;
    scanf("%d%d%llu%llu",&n,&Q,&s1,&s2);
    for(u=1,v=0;v<=n;++u)
    {
    	ull t=1<<(u-1);
    	for(w=1;w+v<=n&&w<=t;++w) b[w+v]=t;
		v+=t;
	}
    for(i=1;i<=Q;++i)
    {
    	get_query(op,l,r);
    	if(op==1) add(l,r);
    	else
    	{
    		if(l==1) sum=fer(r,0);
    		else sum=fer(r,0)-fer(l-1,0);
    		ans^=(sum*i);
		}
	}
	printf("%llu",ans);
}
