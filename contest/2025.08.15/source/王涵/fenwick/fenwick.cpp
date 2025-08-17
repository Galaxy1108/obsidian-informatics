#include <cstdio>
#define lowbit(x) (x & -x)
typedef unsigned long long tt;

const int MX = 10000010;

namespace IO
{
#define swap(A, B) (A ^= B ^= A ^= B)
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
}

namespace solve
{
namespace BIT
{
tt tree[MX];
int n;

void add(int p, tt x)
{
	tt t = x;
	for (int i = p; i <= n; i += lowbit(i), x += t)
		tree[i] += x;
}

tt query(int r)
{
	tt ret = 0;
	for (int i = r; i; i -= lowbit(i))
		ret += tree[i];
	return ret;
}
}

void init(int n)
{
	BIT::n = n;
}

using BIT::add;

tt query(int l, int r)
{
	return BIT::query(r) - BIT::query(l - 1);
}
}

int main()
{
	freopen("fenwick.in", "r", stdin);
	freopen("fenwick.out", "w", stdout);
    int n, q, op;
	tt l, r, ans = 0;
    scanf("%d%d%llu%llu", &n, &q, &IO::s1, &IO::s2);
    solve::init(IO::n = n);
    for (int i = 1; i <= q; i++)
    {
    	IO::get_query(op, l, r);
    	if (op == 1)
    		solve::add(l, r);
		else
			ans ^= i * solve::query(l, r);
	}
    printf("%llu", ans);
    return 0;
}
