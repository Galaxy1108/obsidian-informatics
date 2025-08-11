#include<bits/stdc++.h>
using namespace std;
int n,k;
long long s[2010];
vector<pair<int,int> > Line;
namespace K2{
	void solve(int l,int r){
		if(r-l+1<=3) return;
		const int mid=(l+r)>>1;
		for(int i=l;i<=mid-2;++i) Line.push_back(make_pair(i,mid));
		for(int i=mid+2;i<=r;++i) Line.push_back(make_pair(mid,i));
		solve(l,mid-1),solve(mid+1,r);
		return;
	}
}
namespace K3{
	void solve(int l,int r){
		if(r-l+1<=4) return;
		int mid1=(2*l+r)/3;
		int mid2=(l+2*r)/3;
		for(int i=l;i<=mid1-2;++i) Line.push_back(make_pair(i,mid1));
		for(int i=mid2+2;i<=r;++i) Line.push_back(make_pair(mid2,i));
		if((mid1&1)==(mid2&1)){
			for(int i=mid1+2;i+2<mid2;i+=2) Line.push_back(make_pair(i,i+2));
			for(int i=mid1+2;i<mid2;i+=2) Line.push_back(make_pair(mid1,i));
			for(int i=mid2-2;i>mid1;i-=2) Line.push_back(make_pair(i,mid2));
		}
		else{
			for(int i=mid1+2;i+2<mid2;i+=2) Line.push_back(make_pair(i,i+2));
			for(int i=mid1+2;i<mid2;i+=2) Line.push_back(make_pair(mid1,i));
			for(int i=mid2-3;i>mid1;i-=2) Line.push_back(make_pair(i,mid2));
		}
		Line.push_back(make_pair(mid1,mid2));
		solve(l,mid1-1),solve(mid1+1,mid2-1),solve(mid2+1,r);
		return;
	}
}
namespace anotherK{
	void solve(int l,int r){
		if(r-l<=k) return;
		int len=(r-l+2-k)/k;
		int res=(r-l+2-k)%k;
		int mid[20]={};
		mid[0]=l-1;mid[k]=r+1;
		for(int i=1;i<=res;++i) mid[i]=mid[i-1]+len+2;
		for(int i=res+1;i<k;++i) mid[i]=mid[i-1]+len+1;
		for(int i=1;i<k;++i){
			for(int j=mid[i-1]+1;j<=mid[i]-1;++j){
				Line.push_back(make_pair(j,mid[i]));
			}
		}
		for(int i=2;i<=k;++i){
			for(int j=mid[i-1]+1;j<=mid[i]-1;++j){
				Line.push_back(make_pair(mid[i-1],j));
			}
		}
		for(int i=1;i<=k;++i) solve(mid[i-1]+1,mid[i]-1);
		return;
	}
}
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(k==2) K2::solve(0,n);
	else if(k==3) K3::solve(0,n);
	else anotherK::solve(0,n);

	// s[5]=1;
	// for(int n=6;n<=2001;++n){
	// 	s[n]=1e9;
	// 	for(int x=1;x<=n;++x){
	// 		for(int o=0;o<=1;++o){
	// 			int y=n-x-(x+o)-2;
	// 			if(y<0) continue;
	// 			s[n]=min(s[n],s[x]+s[y]+s[x+o]+max(x-1,0)+max(x+o-1,0)+max(y-1,0));
	// 		}
	// 	}
	// 	cout<<s[n]<<'\n';
	// }
	// cout<<'\n';
	// for(int n=2;n<=2001;++n){
	// 	cout<<1.0*s[n]/((n-1)*3.8085)<<'\n';
	// }

	printf("%d\n",(int)Line.size());
	for(auto l:Line) printf("%d %d\n",l.first,l.second);
	return 0;
}
