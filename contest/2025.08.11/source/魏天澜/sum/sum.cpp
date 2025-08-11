#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+10;
bool vis[N]; 
void check(int n){
	for(int i = 1;i<=n/2;i++){
		if(n%i==0)vis[i] = 1;
	}
	vis[n] = 1;
	return;
} 
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int S;
	cin>>S;
	while(S--){
		memset(vis,0,sizeof(vis));
		bool flag = 0;
		int T,k;
		cin>>T>>k;
		check(T);
//1.把S质因数分解，将其所有因数全部标记为1 
//2.从小至大枚举，将S-他的所有倍数排除
//3.循环到k的时候输出
		int last = 1;
		for(int i = 1;i<=k;i++){
			
			while(vis[last]==1)last++;
			if(last>=T){
				flag = 1;
				break;
			}
			cout<<"i "<<i<<" last "<<last<<"\n"; 
			vis[last] = 1;
			int p = T;
			while(p>last){
				p-=last;
				vis[p] = 1;
			}
		} 
		if(flag==1)cout<<-1<<endl;
		else cout<<last<<"\n";
	}
	return 0;
} 
