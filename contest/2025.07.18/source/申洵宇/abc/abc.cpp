#include <bits/stdc++.h>
using namespace std;
#define N 65
int n;
char s[N*3]; 
int main(){
	freopen("abc.in","r",stdin);
	freopen("abc.out","w",stdout); 
	scanf("%d%s",&n,s+1);
	bool subtask2=true;
	int ca=0,cb=0,cc=0;
	for(int i=1;i<=n*3;i++){
		if(s[i]=='?')subtask2=false;
		else if(s[i]=='A')ca++;
		else if(s[i]=='B')cb++;
		else if(s[i]=='C')cc++;
	}
	if(ca>n||cb>n|cc>n){
		printf("0");
		return 0;
	}
	if(subtask2){
		printf("1");
		return 0;
	} 
	printf("0");
	return 0;
}

