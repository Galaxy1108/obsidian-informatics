#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int MAXN = 1e7 + 12;
int n;
ull s1,s2;
inline ull my_rand()
{
    ull s3=s1,s4=s2;
    s1=s2^774527;
    s3^=(s3<<47)^(s3>>13);
    s2^=s3^(s4<<31)^(s4>>17);
    return s2+s4;
}
inline void get_query(int &op,ull &num1,ull &num2)
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
inline int lowbit(int x) {return x&(-x);}
ull bas[MAXN];
void add(int id,int x)
{
	int cnt = 0;
	for (;id<=n;id+=lowbit(id))
		bas[id] += x*(++cnt);
}
ull query(int id)
{
	ull res = 0;
	for (;id;id-=lowbit(id))
		res += bas[id];
	return res;
}
int Q;
ull ans;
int main()
{
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    scanf("%d%d%llu%llu",&n,&Q,&s1,&s2);
    for (int i=1;i<=Q;i++)
    {
    	int op;
    	ull num1,num2;
    	get_query(op,num1,num2);
    	if (op==1) add((int)num1,(int)num2);
    	else ans ^= i*(query((int)num2)-query((int)num1-1));
	}
	printf("%llu",ans);
    return 0;
}
