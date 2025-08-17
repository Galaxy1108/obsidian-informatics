#include <iostream>
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
#undef ull

int Q;
unsigned long long b[10000005], ans, res, id;
int op;
unsigned long long x, y;

void add(int x, unsigned long long k) { int cnt=0; for (; x <= n; x += (x&-x)) b[x] += k*(++cnt); }
unsigned long long query(int x) { res=0; while (x) res+=b[x], x -= x&-x; return res; }

int main()
{
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    scanf("%d%d%llu%llu",&n,&Q,&s1,&s2);
    while (Q--)
    {
    	id++;
    	get_query(op, x, y);
    	if (op == 1) add(x, y);
    	else ans ^= (query(y)-query(x-1)) * id;
	}
	printf("%llu", ans); 
    return 0;
}

