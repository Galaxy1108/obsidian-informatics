#include<bits/stdc++.h>
#define int long long
#define N 1000000
#define inf 999999999999999
using namespace std;
int n,d[N+1],a[N+1],c[N+1],dp[N+1],s[N+1],sa[N+1],ans=inf;
deque<int>qu;
int qread(){int nans=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')nans=nans*10+c-'0',c=getchar();return nans;}
void ins(int nx){
	if(qu.size()<=1)qu.push_front(nx);
	else{
		int na=qu.front();
		deque<int>::iterator di=qu.begin();di++;int nb=*di;
		while((dp[nx]+s[nx]-dp[na]-s[na])*(sa[na]-sa[nb])<=(dp[na]+s[na]-dp[nb]-s[nb])*(sa[nx]-sa[na])){
			qu.pop_front();
			if(qu.size()<=1)break;
			na=qu.front();di=qu.begin();di++;nb=*di;
		}
		qu.push_front(nx);
	}
	
}
signed main(){
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	n=qread();
	for(int i=1;i<=n;i++)d[i]=qread(),a[i]=qread(),c[i]=qread(),s[i]=s[i-1]+a[i]*d[i],sa[i]=sa[i-1]+a[i];
	for(int i=1;i<=n;i++){
		dp[i]=d[i]*sa[i]+c[i]-s[i];
		if(qu.size()>=1){
			if(qu.size()>1){
				int na=qu.back();
				deque<int>::iterator di=qu.end();di--,di--;int nb=*di;
				while((dp[nb]+s[nb]-dp[na]-s[na])<=d[i]*(sa[nb]-sa[na])){
					qu.pop_back();
					if(qu.size()<=1)break;
					na=qu.back();di=qu.end();di--,di--;nb=*di;
				}
			}
			int j=qu.back();
			dp[i]=min(dp[i],dp[j]+d[i]*sa[i]+c[i]-s[i]+s[j]-d[i]*sa[j]);
		}
//		for(int j=i-1;j>=0;j--){
//			dp[i]=min(dp[i],dp[j]+d[i]*sa[i]+c[i]-s[i]+s[j]-d[i]*sa[j]);
//		}
		ins(i);
	}
	cout<<dp[n]<<endl;
	return 0;
}
