#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long
int n,Q;
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

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a)
#define DOW(a,b,c) for(int a = b;a >= c;--a)

typedef long long ll;

const int MAXN = 1e7+5;
const int MOD = -1;

ull far[MAXN];

inline ull lowbit(ull x){ return x&(-x); }

inline void add(ull pos,ull x){ for(;pos <= n;pos += lowbit(pos)) for(ull pos1 = pos;pos1 <= n;pos1 += lowbit(pos1)) far[pos1] += x;}

inline ull sum(ull pos){
	ull ret = 0;
	for(;pos > 0;pos -= lowbit(int(pos))) ret += far[pos];
	return ret;
}

int main(){

    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
	sc("%d%d%llu%llu",&n,&Q,&s1,&s2);
	ull ans = 0;
	REP(i,1,Q){
		int op;ull a,b;
		get_query(op,a,b);
		if(op == 1) add(a,b);
		else ans = ans^i*(sum(b)-sum(a-1));
	}
	cout<<ans;
	
	return 0;
}
