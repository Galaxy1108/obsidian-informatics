#include<bits/stdc++.h>
#define int long long
#define N 60
#define Mod 998244353
using namespace std;
int n,ans=0;
string s;
bool flag[N*3+5]={};
int read(){
	int f=1,g=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		g=g*10+ch-'0';
		ch=getchar();
	}
	return f*g;
}
void print(int x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>9)print(x/10);
	putchar(x%10+'0');
	return;
}
bool check(){
	bool f;
	for(int i=0;i<3*n;i++)flag[i]=0;
	for(int i=0;i<3*n;i++){
		if(flag[i])continue;
		flag[i]=1;
		if(s[i]=='A'){
			f=0;
			for(int j=i+1;j<3*n;j++){
				if(flag[j])continue;
				if(s[j]=='B'){
					flag[j]=1;
					for(int k=j+1;k<3*n;k++){
						if(flag[k])continue;
						if(s[k]=='C'){
							flag[k]=1,f=1;
							break;
						}
					}
					if(!f)return 0;
					break;
				}
			}
			if(!f)return 0;;
		}
		else if(s[i]=='B'){
			f=0;
			for(int j=i+1;j<3*n;j++){
				if(flag[j])continue;
				if(s[j]=='C'){
					flag[j]=1;
					for(int k=j+1;k<3*n;k++){
						if(flag[k])continue;
						if(s[k]=='A'){
							flag[k]=1,f=1;
							break;
						}
					}
					if(!f)return 0;
					break;
				}
			}
			if(!f)return 0;;
		}
		else{
			f=0;
			for(int j=i+1;j<3*n;j++){
				if(flag[j])continue;
				if(s[j]=='A'){
					flag[j]=1;
					for(int k=j+1;k<3*n;k++){
						if(flag[k])continue;
						if(s[k]=='B'){
							flag[k]=1,f=1;
							break;
						}
					}
					if(!f)return 0;
					break;
				}
			}
			if(!f)return 0;;
		}
	}
	return 1;
}
void dfs(int x){
	if(x>=3*n){
		ans+=check();
		return;
	}
	if(s[x]!='?')dfs(x+1);
	else{
		s[x]='A',dfs(x+1);
		s[x]='B',dfs(x+1);
		s[x]='C',dfs(x+1);
		s[x]='?';
	}
	return;
}
main(){
	freopen("abc.in","r",stdin);
	freopen("abc.out","w",stdout);
	n=read();
	cin>>s;
	dfs(0);
	print(ans);
	return 0;
}
