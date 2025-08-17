#include<bits/stdc++.h>
#define lb(x) (x&(-x)) 
#define ull unsigned long long
using namespace std;
const int N=1e7+3; 
int n,Q;
ull s1,s2,a[N];
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
inline void upd(int x,ull k) {for(int i=1;x<=n;x+=lb(x),++i) a[x]+=k*i;}
inline ull get(int x) {ull s=0;for(;x;x-=lb(x)) s+=a[x];return s;}
int main() {
	freopen("fenwick.in","r",stdin);
	freopen("fenwick.out","w",stdout);
	cin>>n>>Q>>s1>>s2;
	ull res=0;
	for(int i=1;i<=Q;++i) {
		int opt;
		ull l,r;
		get_query(opt,l,r);
		if(opt==1) upd(l,r);
		else res^=(get(r)-get(l-1))*i;
	} 
	cout<<res;
	return 0;
} 
