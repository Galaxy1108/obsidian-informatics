#include<bits/stdc++.h>
#define int long long

using namespace std;

int n;
int mapn[1001][1001];
int a[1000001],tot=0;

int work(int x){
	int tmp=1;
	while(x>0){
		tmp*=x%10;
		x/=10;
	}
	return tmp;
}

bool cmp(int a,int b){
	return a>b;
}

signed main(){
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	int k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int t1=work(i),t2=work(j);
			if(t1>=1&&t1<=n&&t2>=1&&t2<=n) mapn[t1][t2]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mapn[i][j]>=1) a[++tot]=mapn[i][j];
		}
	}
	sort(a+1,a+tot+1,cmp);
	int total=0;
	for(int i=1;i<=k;i++) total+=a[i];
	cout<<total<<endl;
	return 0;
}
