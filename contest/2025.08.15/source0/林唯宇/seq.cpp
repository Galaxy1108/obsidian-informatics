#include<bits/stdc++.h>
using namespace std;
const int mn=1048576,mod=998244353;
vector<int> l[mn];
int n,a[mn],m,b[mn];
int ord[mn],cnt,pt,to;
long long num[mn],ans;

bool cmp(int x,int y){
	return a[x]>a[y];
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ord[i]=a[i]; 
		num[a[i]]+=n-i+1;
	}
	for(int i=1;i<n;i++) l[a[i]].push_back(a[i+1]);
	cin>>m;
	for(int i=1;i<=m;i++) cin>>b[i];
	b[m+1]=-mn;
	
	sort(ord+1,ord+n+1,cmp);
	cnt=unique(ord+1,ord+n+1)-(ord+1);
	for(int i=1;i<=cnt;i++) num[ord[i]]%=mod;
	
	pt=1;
	while(ord[pt]<b[1]){
		ans+=num[ord[pt]];
		pt++;
	}
	ans%=mod;
	pt=ord[pt];
	
	if(pt==b[1]) for(int i=1;i<=m;i++){
		ans++,to=-1;
		for(int i1=0;i1<l[pt].size();i1++){
			if(l[pt][i1]<b[i+1]) ans+=num[l[pt][i1]];
			else if(l[pt][i1]==b[i+1]) to=b[i+1];
		}
		ans%=mod;
		if(to<0) break;
		pt=to;
	}
//	ans--;
	
	cout<<ans<<endl;
	
	return 0;
}
