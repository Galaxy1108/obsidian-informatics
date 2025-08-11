#include <bits/stdc++.h>
using namespace std;
struct node{
	int nxt,lst;
}a[1000001];
int n,l,r;
int s[1000001],cnt1[1000001],cnt2[1000001],t1[1000001],t2[1000001],ans=1e9;
int main(){
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout);
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=n;i>=1;i--){
		cnt1[i]=t1[s[i]];
		if(cnt1[i]==0) cnt1[i]=n+1;
		t1[s[i]]=i;
	}
	for(int i=1;i<=n;i++){
		cnt2[i]=t2[s[i]];
		t2[s[i]]=i;
	}
	a[r].nxt=r+1;
	for(int i=r+1;i<=n;i++){
		a[i].lst=i-1,a[i].nxt=i+1;
	}
	a[n].nxt=0;
	for(int i=l-1;i>=1;i--){
	//	cout<<i<<"   ";
		for(int j=a[r].nxt;j!=0&&j<cnt1[i];j=a[j].nxt){
			if(cnt2[j]<i){
				ans=min(j-i+1,ans);
				break;
			}
			a[a[j].lst].nxt=a[j].nxt;
			a[a[j].nxt].lst=a[j].lst;
		}
		//cout<<endl;
	}
	if(ans==1e9) cout<<"-1"<<endl;
	else cout<<ans<<endl;
	return 0;
}
/*
5 3 4
1 2 2 3 3
*/
