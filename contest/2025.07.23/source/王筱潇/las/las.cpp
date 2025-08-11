#include <bits/stdc++.h>
using namespace std;
int n;
struct food{
	int c;
	int p;
	int ans;
}a[1000010];
int main(){
	freopen("las.in","r",stdin);
	freopen("las.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		a[i].c=0;
		a[i].ans=0;
		a[i].p=0;
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i].c);
	for(int i=1;i<=n;i++){
		int f=i+1;
		if(f==n+1) f=1;
		int t=a[i].c,m=a[f].c;
		if(t==m){
			a[i].ans=i;
			a[i].p++;
		}
		else if(t<(m+1)/2){
			a[i].ans=i+1;
			a[f].p++;
		}
		else if((t+1)/2>m){
			a[i].ans=i;
			a[i].p++;
		} 
	}
	for(int i=1;i<=n;i++){
		int f=i-1;
		if(f==0) f=n;
		if(a[f].ans!=0&&a[i].ans==0){
			int j=i;
			while(a[j].ans==0){
				f=j+1;
				if(f==n+1) f=1;
				if(a[j].c/(a[j].p+1)>=a[f].c/(a[f].p+1)){
					a[j].ans=j;
					a[j].p++;
				}
				else{
					a[j].ans=f;
					a[f].p++;
				} 
				j++;
				if(j==n+1) j=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",a[i].ans);
	}
	return 0;
}
