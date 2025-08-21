#include <bits/stdc++.h>
using namespace std;
struct node{
	int val,num=0;
}a[100001];
int n,t[1001],ans=0;
int main(){
	freopen("lineup.in","r",stdin);
	freopen("lineup.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].val;
	}
	int mi=1e9,cnt=0;
	for(int i=1;i<=n;i++){
		mi=1e9;
		for(int j=1;j<=n;j++){
			if(a[j].num==0&&a[j].val<mi){
				mi=a[j].val;
			}
		}
		cnt++;
		for(int j=1;j<=n;j++){
			if(a[j].val==mi){
				a[j].num=cnt;
			}
		}
	} 
	int tot=0,c=0,cnt1=1,s,ma;
	for(int i=1;i<=cnt;i++){
		for(int k=1;k<=n;k++){
			if(a[k].num==i) {
				c=k;
				while(c!=cnt1){
					ma=cnt1;
					for(s=c-1;s>=cnt1;s--){
						if(a[ma].num<a[s].num) ma=s;
					}
					ans+=(c-ma)*2;
					swap(a[ma],a[c]);
					c=ma;
				}
				cnt1++;
			}	
		}	
	}
	cout<<ans<<endl;
	return 0;
} 
