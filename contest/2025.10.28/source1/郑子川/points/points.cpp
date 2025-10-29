#include<iostream> 
#include<algorithm>
#define mn 200010
#define ll long long
#define FOR(i,x,y) for(int i=x;i<=y;++i)
#define ROF(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
int n,m;
int a[mn];
int l[mn],r[mn];
int lp[mn],rp[mn];
int main()
{
	//freopen("1.in","r",stdin);
	cin>>n>>m;
    FOR(i,1,n)cin>>a[i];
    FOR(i,1,m)cin>>l[i]>>r[i];
    FOR(i,1,m)
    {
    	upper_bound(a+1,a+n+1,l[i])
	}
	return 0;
}
