#include<bits/stdc++.h>
using namespace std;
long long a[10005];//çÛ¾ËçÛ¾Ë°ÍÒÔÁé£» 
int flag=0;
void dfs(int z,int m,int cnt){
	if(z==1){
		cout<<cnt<<'\n';
		for(int i=1;i<cnt;i++){
			cout<<a[i]<<" ";
		}
		cout<<m<<" ";
		flag=1;
	}
	else{
		for(int i=2;;i++){
		if(flag) break;
	    int nowm=i*m;
		int nowz=z*i-m;
		if(nowz<0) continue;
		int v=__gcd(nowm,nowz);
		nowm=nowm/v;
		nowz=nowz/v;
		a[cnt]=i;
		dfs(nowz,nowm,cnt+1);
	}
}
}
int main(){
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	int a,b;
	cin>>a>>b;
	if(a==0){
		cout<<0;
		return 0;
	}
	dfs(a,b,1); 
	return 0;
}
