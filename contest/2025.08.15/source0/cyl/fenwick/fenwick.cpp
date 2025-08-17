#include <bits/stdc++.h>
#define L(i,j,k) for(int i = (j); i <= (k); ++i)
#define R(i,j,k) for(int i = (j); i >= (k); --i)
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

const int N = 1e7 + 5;
int Q;
ull tr[N];
inline int lb(int wi){
	return wi & -wi;
}
void add(int x, ull k){
	ull ct = 1;
	while(x <= n){
		tr[x] += ct * k;
		x += lb(x); ++ct;
	}
}
ull query(int x){
	ull as = 0;
	while(x){
		as += tr[x];
		x -= lb(x);
	}
	return as;
}
int main()
{
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    scanf("%d%d%llu%llu",&n,&Q,&s1,&s2);
    int op;
    ull l, r;
    ull ss;
    ull az = 0;
    L(id, 1, Q){
    	get_query(op, l, r);
    	if(op == 1){
    		add(l ,r);
		}
		else{
			ss = query(r) - query(l - 1);
			az = az ^(id * ss);
		}
	}
	cout << az ;
    return 0;
}
