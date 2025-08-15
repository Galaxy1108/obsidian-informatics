#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define il inline
const int N=1e7+5;
int n,q; 
ull s1,s2,t[N];
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
il void upd(int x,ull k)
{
	ull tt=0;
	for(;x<=n;x+=(x&-x))
	{
		tt++;
		t[x]+=k*tt;
	}
}
il ull ask(int x){ull res=0;for(;x;x-=(x&-x))res+=t[x];return res;}
ull ans=0;
il void solve(ull T)
{
	int op;ull x,k;
	get_query(op,x,k);
	if(op==1) upd(x,k);
	else ans^=T*(ask(k)-ask(x-1));
}
int main()
{
	freopen("fenwick.in","r",stdin);
	freopen("fenwick.out","w",stdout);
	cin>>n>>q>>s1>>s2;
	ull T=0;
	while(q--)solve(++T);
	cout<<ans;
	return 0;
}
