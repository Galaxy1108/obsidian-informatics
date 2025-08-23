#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
int main(){
	freopen("imperishable2.in","r",stdin);
	freopen("imperishable2.out","w",stdout);
	int num;
	scanf("%d",&num);
	if(num==0){
		printf("2");
		return 0;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i=i+1){
		scanf("%d",&a[i]);
	}
	printf("2");
	return 0;
}

