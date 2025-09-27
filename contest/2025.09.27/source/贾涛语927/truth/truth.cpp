#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+5,maxk=31;
int n,k,m;
int a[maxn];
int book[maxk],bo_ok[maxk];;
int type,p,v;
int main(){
	freopen("truth.in","r",stdin);freopen("truth.out","w",stdout);
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		book[a[i]]++;
	}
	while(m--){
		cin>>type;
		if(type==1){
			cin>>p>>v;
			book[a[p]]--;
			book[v]++;
			a[p]=v;
		}
		else{
			int l=1,r=n;
			bool flag=1;
			for(int i=1;i<=k;i++){
				bo_ok[i]=book[i];
				if(book[i]==0){
					flag=0;
					break;
				}
			}
			if(!flag){
				cout<<-1<<'\n';
			}
			while(l<r&&flag){
				if(bo_ok[a[l]]!=1){
					bo_ok[a[l]]--;
					l++;
				}
				if(bo_ok[a[r]]!=1){
					bo_ok[a[r]]--;
					r--;
				}
				if(bo_ok[a[l]]==1&&bo_ok[a[r]]==1){
					cout<<r-l+1<<'\n';
					break;
				}
			}
		}
	}
	return 0;
}
