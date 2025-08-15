#include<bits/stdc++.h>
using namespace std;
inline unsigned long long qread()
{
	unsigned long long a=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){(a*=10)+=(ch^48);ch=getchar();}
	return a*f;
}
unsigned long long n,m,s1,s2,op,x,y,ans,val[10000010];
inline unsigned long long my_rand()
{
    unsigned long long s3=s1,s4=s2;
    s1=s2^774527;
    s3^=(s3<<47)^(s3>>13);
    s2^=s3^(s4<<31)^(s4>>17);
    return s2+s4;
}
inline void get_query(unsigned long long &op,unsigned long long &num1,unsigned long long &num2)
{
    op=(my_rand()&1)+1;
    if(op==1)
    {
        num1=my_rand()%n+1;
        num2=my_rand()%n+1;
    }
    else
    {
        num1=my_rand()%n+1;
        num2=my_rand()%n+1;
        if(num1>num2)swap(num1,num2);
    }
    return ;
}
int main()
{
	freopen("fenwick.in","r",stdin);
	freopen("fenwick.out","w",stdout);
	n=qread();m=qread();s1=qread();s2=qread();
	for(unsigned long long i=1,an;i<=m;++i)
	{
		get_query(op,x,y);
		if(op==1)for(unsigned long long yy=y;x<=n;x+=x&-x,yy+=y)val[x]+=yy;
		else 
		{
			an=0;--x;
			for(;y;y-=y&-y)an+=val[y];
			for(;x;x-=x&-x)an-=val[x];
			ans^=an*i;
		}
	}
	printf("%llu",ans);
	return 0;	
}
