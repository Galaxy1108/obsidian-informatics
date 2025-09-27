#include<bits/stdc++.h>
using namespace std;
int a[50005];
int t[50005];
int n,k,m;
int length(){
	memset(t,0,sizeof(t));
	int ans=1e9;
	int l=1,r=0;
	int cnt=0;
	int flag=0;
	while(r<n){
		while(cnt<k&&r<n){
			r++;
			t[a[r]]++;
			if(t[a[r]]-1==0){
				cnt++;
				if(cnt==k)
				flag=1;
			}
		}
		while(cnt==k){
			t[a[l]]--;
			l++;
			if(t[a[l-1]]==0)
			cnt--;
		}
		l--;
		if(flag==1)
		ans=min(ans,r-l+1);
		else
		ans=-1;
	}
	return ans;
}
int main(){
    freopen("truth.in","r",stdin);
    freopen("truth.out","w",stdout);
	cin>>n>>k>>m;
	int i,j;
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(i=1;i<=m;i++){
		int op;
		cin>>op;
		if(op==1){
			int x,y;
			cin>>x>>y;
			a[x]=y;
		} 
		else if(op==2){
			cout<<length()<<endl;
		}
	}
	return 0;
}
