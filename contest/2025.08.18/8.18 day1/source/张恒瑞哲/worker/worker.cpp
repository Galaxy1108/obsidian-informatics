#include<bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a)
#define DOW(a,b,c) for(int a = b;a >= c;--a)

typedef long long ll; 

const int MAXN = 105;
int n,ans = 1e9;
char l[MAXN];

void Dfs(int i,int k,int a,int b,int c){
	if(i == n){
		if(a != 0) k++;
		if(b != 0) k++;
		if(c != 0) k++;
		if(ans > k) ans = k;
		return;
	}
	if(k > ans) return;
//	pr("%d %d %d %d %d\n",i,k,a,b,c);
	while(true){
		if(i == n || a+b+c == 10) break;
		i++;
		if(l[i] == 'A') a++;
		if(l[i] == 'B') b++;
		if(l[i] == 'C') c++;
	}
//	pr("%d %d %d %d %d\n",i,k,a,b,c);
	if(a != 0) Dfs(i,k+1,0,b,c);
	if(b != 0) Dfs(i,k+1,a,0,c);
	if(c != 0) Dfs(i,k+1,a,b,0);
	return;
}

int main(){
	
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	sc("%d",&n);
	REP(i,1,n) cin>>l[i];
	if(n <= 10){
		bool fa = true,fb = true,fc = true;
		ans = 0;
		REP(i,1,n){
			if(l[i] == 'A' && fa) fa = false,ans++;
			if(l[i] == 'B' && fb) fb = false,ans++;
			if(l[i] == 'C' && fc) fc = false,ans++;
		}
		pr("%d",ans);
		return 0;
	} 
	Dfs(0,0,0,0,0);
	pr("%d",ans);
	
	return 0;
} 
