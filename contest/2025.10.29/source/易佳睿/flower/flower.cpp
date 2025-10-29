#include<bits/stdc++.h>
using namespace std;

int N;
string s[50];
int a[100];

void DFS(int i){
	if(i>N){
		for(int j=1;j<=2*N;j++)
			cout<<s[a[j]]<<'\n';
		exit(0);
	}
	for(int j=1,k=j+i+1;k<=2*N;j++,k++){
		if(a[j]!=0||a[k]!=0) continue;
		a[j]=a[k]=i;
		DFS(i+1);
		a[j]=a[k]=0;
	}
}

int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	cin>>N;
	for(int i=1;i<=N;i++)
		cin>>s[i];
	DFS(1);
} 
