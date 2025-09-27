#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int a[50001],s1[50001][31],s2[50001][31],t[50001],t2[50001];
int main(){
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	memset(s1,-1,sizeof(s1));
	memset(t,-1,sizeof(t));
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt=0;
		for(int j=i;j<=n;j++){
			if(s1[i][a[j]]==-1){
				cnt++;
				s1[i][a[j]]=j;
			} 
			t2[i]=cnt;
			if(cnt==k){
				t[i]=j;
				break;
			} 
		}
	}
//	for(int i=1;i<=n;i++){
//		cnt=0;
//		for(int j=1;j<=k;j++){
//			cout<<s1[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	int opt,x,y,f1=0,g[31]={};
	while(m--){
		
		cin>>opt;
		if(opt==1){
			cin>>x>>y;
			f1=s1[x+1][a[x]];
		//	cout<<f1<<endl;
			for(int i=x;i>=1;i--){
				//cout<<i<<" "<<x<<" "<<a[x]<<" "<<a[i]<<endl;
				if(a[i]==a[x]&&i!=x) break;
				if(s1[i][a[x]]==x){
					if(f1==-1){
						t[i]=-1;
						if(s1[i][a[x]]!=-1) t2[i]--;
					} 
					else if(t[i]!=-1) t[i]=max(t[i],f1);
					s1[i][a[x]]=f1;
					
				}
			//	cout<<t[i]<<endl;
			}
//			for(int i=1;i<=n;i++) cout<<t2[i]<" ";
//			cout<<endl;
//			cout<<t2[1]<<endl;
			for(int i=x;i>=1;i--){
				if(a[i]==y) break;
				if(s1[i][y]==-1){
					s1[i][y]=x;
					//cout<<i<<" "<<t2[1]<<endl;
					t2[i]++;
						
					if(t2[i]==k){
						for(int j=1;j<=k;j++){
							t[i]=max(s1[i][j],t[i]);
						}
					} 
				//	cout<<t[i]<<endl;
				}
			}
			a[x]=y;
		} 
		else{
			int ans=1e9;
			for(int i=1;i<=n;i++){
				if(t[i]!=-1) ans=min(t[i]-i+1,ans);
				//cout<<i<<" "<<t[i]<<endl;
			}
			if(ans==1e9) cout<<"-1"<<endl;
			else cout<<ans<<endl;
		}
//		for(int i=1;i<=n;i++) cout<<a[i]<" ";
//		cout<<endl;
	}
	return 0;
}
/*
4 3 5 
2 3 1 2 
2 
1 3 3 
2 
1 1 1
2

6 3 6 
1 2 3 2 1 1 
2 
1 2 1 
2 
1 4 1 
1 6 2 
2
*/
