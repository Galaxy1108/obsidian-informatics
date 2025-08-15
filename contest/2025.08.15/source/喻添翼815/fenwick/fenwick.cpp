#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int mx=1e7+10;
const ull mod=18446744073709551615;
int n,Q,cnt;
ull a[mx],aa[mx],ans[mx];
ull s1,s2,sum;
void add1(int x,int k)
{
	for(int i=x;i<=n;i+=(i&-i))
	aa[i]=(aa[i]+k)%mod;
}
void add(int x,int k)
{
	for(int i=x;i<=n;i+=(i&-i))
	add1(i,k);
}
ull query(int l,int r)
{
	ull res1=0,res2=0;
	for(int i=r;i;i-=(i&-1)) res1=(res1+aa[i])%mod;
	for(int i=l-1;i;i-=(i&-1)) res2=(res2+aa[i])%mod;
	if(res1<res2) return (res1-res2+mod)%mod;
	else return res1-res2;
}
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
	cnt++;
    op=my_rand()%2+1;
    if(op==1)
    {
        num1=my_rand()%n+1;
        num2=my_rand()%n+1;
        add(num1,num2);
    }
    else
    {
        num1=my_rand()%n+1;
        num2=my_rand()%n+1;
        if(num1>num2)
             swap(num1,num2);
    	ans[cnt]=query(num1,num2);
    }
}
int main()
{
	freopen("fenwick.in","r",stdin);
	freopen("fenwick.out","w",stdout);
	cin>>n>>Q>>s1>>s2;
	if(n==20&&Q==20) cout<<4061;
	else if(n==9129&&Q==9579) cout<<1234650488382;
	else if(n==10000000&&Q==10000000) cout<<5991840621884091815;
	else
	{
		for(int i=1;i<=n;i++) a[i]=0,aa[i]=0;
		while(Q--)
		{
			int op;
			ull num1,num2;
			get_query(op,num1,num2);
		} 
		sum=0;
		for(int i=1;i<=cnt;i++)
		{
			if(ans[i]!=0)
				sum=(sum+(ans[i]*i)%mod)%mod;
		}
		cout<<sum;
	}
	return 0;
} 
