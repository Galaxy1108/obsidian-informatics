#include<iostream>
#include<vector>
#include<cstring> 
#include<cstdio> 
using namespace std;
int n,m,x,y,he;
char nul=char(32);
bool tick[10086][10086];
string ans[2086],now;
void pd(int x,int y){
	if(x==m){
		tick[x][y]=1;
		return;
	}
	if(tick[x][y])return;
	tick[x][y]=1;
	pd(x+1,y*2);
	pd(x+1,y*2-1);
}
string point(int lay){
	string res;
	res.clear();
	for(int i=1;i<=3*(1<<lay-2)-1;i++)res+=nul;
	for(int i=1;i<=(1<<m-lay);i++){
		if(!tick[m-lay+1][i])res+='o';
		else res+=nul;
		if(i!=(1<<m-lay))for(int j=1;j<=3*(1<<lay-1)-1;j++)res+=nul;
	}
	return res;
}
string lin(int lay,int len){
	string res;
	res.clear();
	int l=0,jian=0;
	if(lay>=3)l=(3*(1<<lay-3)-1)+len;
	else l=1;
	if(lay>2)jian=3*(1<<lay-2)-1+len*2;
	else jian=3;
	for(int i=1;i<=l;i++)res+=nul;
	for(int i=1;i<=(1<<m-lay+1);i+=2){
		if(!tick[m-lay+2][i])res+='/';
		else res+=nul;
		for(int j=1;j<=max(3*(1<<lay-2)-1-len*2,1);j++)res+=nul;
		if(!tick[m-lay+2][i+1])res+='\\';
		else res+=nul;
		for(int j=1;j<=jian;j++)res+=nul;
	}
	return res;
}
int main(){
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	cin >> m >> n;
	he=3*(1<<(m-2));
	for(int i=1;i<=n;i++){
		cin >> x >> y;
		pd(x,y);
	}
	for(int i=1;i<=(1<<m-1);i+=2){
		if(!tick[m][i])now+='o';
		else now+=nul;
		for(int j=1;j<=3;j++)now+=nul;
		if(!tick[m][i+1])now+='o';
		else now+=nul;
		if(i!=(1<<m-1))now+=nul;
	}
	ans[he]=now;
	int cnt=1;
	for(int i=2;i<=m;i++){
		int len=0;
		if(i==2)len=1;
		else len=3*(1<<i-3)-1;
		for(int j=1;j<=len;j++){
			now.clear();
			cnt++;
			now=lin(i,j);
			ans[he-cnt+1]=now;
		}
		now.clear();
		cnt++;
		now=point(i);
		ans[he-cnt+1]=now;
	} 
	for(int i=1;i<=he;i++){
		cout << ans[i] << '\n';
	}
	return 0;
} 
