#include<iostream>
#include<cstring>
#include<map>
using namespace std;
string s;
int cnt0,cnt1,cnt2,flag,ans=1e9,len;
map<string,int> dic;
bool check(string s){
	flag=1;
	for(int i=1;i<=len;i++){
		if(i!=1&&s[i]==s[i-1])flag=0;
		if(i!=len&&s[i]==s[i+1])flag=0;
	}
	if(flag)return 1;
	else return 0;	
}
void swaps(int x,int y){
	char c=s[x];
	s[x]=s[y];
	s[y]=c;
}
void dfs(int step,string s){
	if(dic[s]<=step&&dic[s]!=0)return;
	dic[s]=step;
	if(step>=ans)return;
	if(check(s)){
		ans=step;
		return;
	}
	for(int i=1;i<len-1;i++){
		if(s[i]==s[i+1])continue;
		swap(s[i],s[i+1]);
		dfs(step+1,s);
		swap(s[i],s[i+1]);
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin >> s;
	s=" "+s;
    len=s.size();
	for(int i=1;i<=len;i++){
		if(s[i]=='0')cnt0++;
		if(s[i]=='1')cnt1++;
		if(s[i]=='2')cnt2++;
	}
	if(cnt0>cnt1+cnt2+1||cnt1>cnt0+cnt2+1||cnt2>cnt0+cnt1+1){
		cout << -1;
		return 0;
	}
	dfs(0,s);
	cout << ans;
	return 0;
}
