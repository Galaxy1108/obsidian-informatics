#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=65,mod=998244353;
int n;
char s[N*3];
struct Node{int x,ab,bc,ca,a,b,c;};
bool operator<(Node x,Node y){
	if(x.x^y.x)return x.x<y.x;
	if(x.ab^y.ab)return x.ab<y.ab;
	if(x.bc^y.bc)return x.bc<y.bc;
	if(x.ca^y.ca)return x.ca<y.ca;
	if(x.a^y.a)return x.a<y.a;
	if(x.b^y.b)return x.b<y.b;
	return x.c<y.c;
}
map<Node,int>dp;
int dfs(Node x){
	if(x.x==n*3+1){
		if((n*3-x.a-x.b-x.c-2*x.ab-2*x.bc-2*x.ca)<n*3)return 0;
		return 1;
	}
	if(dp.count(x))return dp[x];
	int res=0;
	if(s[x.x]=='A'){
		if(x.bc)res|=dfs(Node{x.x+1,x.ab,x.bc-1,x.ca,x.a,x.b,x.c});
		if(x.c)res|=dfs(Node{x.x+1,x.ab,x.bc,x.ca+1,x.a,x.b,x.c-1});
		res|=dfs(Node{x.x+1,x.ab,x.bc,x.ca,x.a+1,x.b,x.c});
	}
	if(s[x.x]=='B'){
		if(x.ca)res|=dfs(Node{x.x+1,x.ab,x.bc,x.ca-1,x.a,x.b,x.c});
		if(x.a)res|=dfs(Node{x.x+1,x.ab+1,x.bc,x.ca,x.a-1,x.b,x.c});
		res|=dfs(Node{x.x+1,x.ab,x.bc,x.ca,x.a,x.b+1,x.c});
	}
	if(s[x.x]=='C'){
		if(x.ab)res|=dfs(Node{x.x+1,x.ab-1,x.bc,x.ca,x.a,x.b,x.c});
		if(x.b)res|=dfs(Node{x.x+1,x.ab,x.bc+1,x.ca,x.a,x.b-1,x.c});
		res|=dfs(Node{x.x+1,x.ab,x.bc,x.ca,x.a,x.b,x.c+1});
	}return dp[x]=res;
}
int cnt,cnt1,cnt2,cnt3;
char t[N*3];
void solve(int x){
	if(cnt1>n||cnt2>n||cnt3>n)return;
	if(x==n*3+1){
		dp.clear();Node x={1,0,0,0,0,0,0};
		if(dfs(x))cnt++;
		return;
	}
	if(t[x]=='A'||t[x]=='?'){
		s[x]='A';cnt1++;
		solve(x+1);
		cnt1--;
	}
	if(t[x]=='B'||t[x]=='?'){
		s[x]='B';cnt2++;
		solve(x+1);
		cnt2--;
	}
	if(t[x]=='C'||t[x]=='?'){
		s[x]='C';cnt3++;
		solve(x+1);
		cnt3--;
	}
}
int main(){
	freopen("abc.in","r",stdin);
	freopen("abc.out","w",stdout);
	scanf("%d%s",&n,t+1);
	if(n<=3)solve(1);
	printf("%d\n",cnt);
	return 0;
}
/*
2
ABCACB
1
不能贪心地合并 
*/
