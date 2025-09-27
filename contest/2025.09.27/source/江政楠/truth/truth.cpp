#include<bits/stdc++.h>
using namespace std;
int n,k,m;
int a[100005];
int num[50005];
int cnt[55];
int main(){
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	} 
	/*for(int i=1;i<=k;i++){
		cout<<cnt[i]<<" ";
	}
	cout<<endl;*/
	for(int i=1;i<=m;i++){
		int op;
		cin>>op;
		if(op==1){
			int p,v;
			cin>>p>>v;
			cnt[a[p]]--;
			cnt[v]++;
			a[p]=v;
		} 
		if(op==2){
			int flag=0;
			/*for(int i=1;i<=k;i++){
				cout<<cnt[i]<<" ";
			}
			cout<<endl;*/
			for(int j=1;j<=k;j++){
				if(cnt[j]==0){
					cout<<-1<<endl;
					flag=1;
					break;
				}
			}
			if(flag) continue;
			memset(num,0,sizeof(num));
			int cnt1=0,all=n;
			int l=1,r=0;
			while(r<=n){
				if(cnt1!=k){
					r++;
					if(num[a[r]]==0) cnt1++;
					num[a[r]]++;	
				}
				else{
					all=min(all,r-l+1);
					if(num[a[l]]==1) cnt1--;
					num[a[l]]--;
					l++;
				}
			}
			cout<<all<<endl;
		}
	}
	return 0;
}
