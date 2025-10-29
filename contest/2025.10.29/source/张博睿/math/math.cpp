#include<bits/stdc++.h>
#include<queue>
#include<vector>
using namespace std;
#define int __int128
inline int qread()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=x*10+(c^48);
		c=getchar();
	}
	return x*f;
}
#define re register
#define pii pair<int,int>
#define mkp make_pair
#define D double

struct frac
{
	int a,b;
};
frac n;
inline frac mat(frac res)
{
	int g=__gcd(res.a,res.b);
	res.a/=g;
	res.b/=g;
	return res;
}
inline frac sub(frac x)
{
	frac res;
	res.a=n.a;
	res.b=n.b;
	int g=__gcd(x.b,res.b);
	int l=(x.b*res.b)/g;
	res.a*=l/res.b;
	res.b=l;
	x.a*=l/x.b;
	x.b=l;
	res.a-=x.a;
	if(res.a<0)return res;
	res=mat(res);
	return res;
}
vector<int> ans;
signed main()
{
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	n.a=qread(),n.b=qread();
	bool flg=0;
	while(n.a>0)
	{
//		cout<<"n"<<" "<<n.a<<" "<<n.b<<endl;
		frac x;
		x.a=1;
		x.b=ceil( (D)n.b/(D)n.a );
//		cout<<"x"<<" "<<x.a<<" "<<x.b<<endl;
//		cout<<sub(x).a<<" "<<sub(x).b<<endl;
		n=sub(x);
		n=mat(n);
		ans.push_back(x.b);
	}
	cout<< (long long)(  ans.size() ) <<endl;
	for(re int i=0; i<ans.size(); i++)
	{
		cout<<(long long)ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
/*

*/
