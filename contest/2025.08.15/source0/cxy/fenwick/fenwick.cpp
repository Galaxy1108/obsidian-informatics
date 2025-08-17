#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int n,op,Q;
ull s1,s2,x,y;
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
void write(ull x) {
	if(x>9) write(x/10);
	putchar(x%10+48);
}
#define lowbit(i) i&(-i)
const int mm=1e7+100;
ull c[mm],ans;
void add(int x,ull y) {for(int cnt=1;x<=n;x+=lowbit(x),cnt++) c[x]+=y*cnt;}
ull query(int x) {ull ans=0; for(;x;x-=lowbit(x)) ans+=c[x]; return ans;}
int main()
{
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    scanf("%d%d%llu%llu",&n,&Q,&s1,&s2);
    for(int i=1;i<=Q;i++) {
    	get_query(op,x,y);
		if(op==1) add(x,y);
		else ans^=i*(query(y)-query(x-1));
	}
	write(ans);
    return 0;
}
