//#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<list>
using namespace std;
constexpr const int N=50,V=200;
int n,a[N+1];
int check(int mid){
	static int cnt[N+1],tmp[N+1];
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++){
		tmp[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			if(tmp[j]>tmp[j+1]){
				swap(tmp[j],tmp[j+1]);
				swap(cnt[j],cnt[j+1]);
				cnt[j]++;cnt[j+1]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(cnt[i]>mid){
			return -1;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=cnt[i];
		//cerr<<"cnt["<<i<<"]="<<cnt[i]<<'\n';
	}
	return ans;
}
int main(){
	freopen("lineup.in","r",stdin);
	freopen("lineup.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=0,r=N*(N+1)*V,ans=-1;
	while(l<=r){
		int mid=l+r>>1;
		int pl=check(mid);
		if(pl!=-1){
			ans=pl;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	cout<<ans<<'\n';
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
