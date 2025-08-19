#include<bits/stdc++.h>
#define F(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define il inline
#define cs const
#define ri register

using namespace std;

il int rd(){
	ri int x=0,f=1;
	ri char c=getchar();
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}

il void wt(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) wt(x/10);
	putchar(x%10+48);
	return;
}
const int N=1000005;
int n;
struct qq{
	int x,p,c;
}a[N];
int maxx,minn;
signed main(){
	F("storage");
	srand(time(0));
	n=rd();
	for(int i=1;i<=n;i++){
		a[i].x=rd(),a[i].p=rd(),a[i].c=rd();
		if(i==1) minn=a[i].c;
		maxx+=a[i].c;
		minn=min(minn,a[i].c);
	}
	cout<<abs((rand()*maxx+rand()*minn)+(rand()*rand()*rand()*rand())%(maxx-minn+1))%(maxx-minn+1)+minn;
	return 0;
}

