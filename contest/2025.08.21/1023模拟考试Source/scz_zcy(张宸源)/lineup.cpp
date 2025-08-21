#include<bits/stdc++.h>
using namespace std;
int a[60],b[60],c[60];
int main(){
	freopen("lineup.in","r",stdin);
	freopen("lineup.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i=i+1){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	int ans=0;
	for(int i=1;i<=n;i=i+1){
		int ti=INT_MAX,tw;
		for(int j=1;j<=n;j=j+1){
			if(a[i]==b[j]&&c[j]==0){
				if(abs(i-j)<ti){
					ti=abs(i-j);
					tw=j;
				}
			}
		}
		ans+=ti;
		c[tw]=1;
	}
	printf("%d",ans);
	return 0;
}

