#include<bits/stdc++.h>
using namespace std;
#define D long double

const int N=1004;

D ans=1;
inline void dfs(D w,D b,int p,D chance)
{
	if(b==0&&p==1)ans+=chance;
	if(w<=0||b<=0||chance<=0.000000001)return ;
//	cout<<w<<" "<<b<<" "<<p<<" "<<chance<<endl;
	if(p==1)
	{
		ans += chance * ( w/(w+b) ) ;
		dfs(w-1,b,2,w/(w+b));
		dfs(w,b-1,2,b/(w+b));
	}
	else if(p==2)
	{
		dfs(w,b-2,1,(b*b) /(  (w+b)*(w+b) ) );
		dfs(w-1,b-1,1, ( b*w )/(  (w+b)*(w+b) ) );
	}
}

int main()
{
	freopen("mouse.in","r",stdin);
	freopen("mouse.out","w",stdout);
	D w,b;
	cin>>w>>b;
	dfs(w,b,1,1);
	printf("%.9lf",(double)(ans)-(int)ans);
	
	return 0;
}
