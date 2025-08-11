#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[11],b[11],sum=0;
char s[2001][2001];
int s1[101][101],s2[1601][1601],s3[1601],tr[11],fl=0;
int main(){
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout); 
	tr[2]=3;
	for(int i=3;i<=10;i++){
		tr[i]=tr[i-1]*2;
	}
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		s1[a[i]][b[i]]=1;
	} 
	int t,t2=m-2,cnt1=0,cnt2=1,cnt3=0;
	t=pow(2,m-1);
	sum=t+t/2*3+t/2-1;
	//cout<<sum<<endl;
	for(int i=1;i<=tr[m];i++){
		for(int j=0;j<=sum+1;j++){
			s[i][j]=' ';
		}
	}
	for(int i=1;i<=t;i++){
		s[tr[m]][cnt2]='o';
		cnt3++;
		s2[tr[m]][cnt2]=t-cnt3;
		cnt1++;
		if(i==t) sum=cnt2;
		if(i%2==1) cnt2+=4;
		else cnt2+=2;
	}
	for(int i=1;i<=tr[m];i++){
		for(int j=1;j<=sum+1;j++){
			if(s[i][j]!='o') s[i][j]=' ';
		}
	}
	cnt2=0;
	for(int i=tr[m]-1;i>=1;i--){
		for(int j=1;j<=sum;j++){
			if(s[i+1][j-1]=='/'&&s[i+1][j+1]=='\\') s[i][j]='o',s2[i][j]=++cnt3;
			else if(s[i+1][j-1]=='/') s[i][j]='/';
			else if(s[i+1][j+1]=='\\') s[i][j]='\\';
			else if(s[i+1][j-1]=='o'&&s2[i+1][j-1]%2==1) s[i][j]='/';
			else if(s[i+1][j+1]=='o'&&s2[i+1][j+1]%2==0) s[i][j]='\\';
		}
	}
	t=0;
	cnt1=0;
	for(int i=1;i<=tr[m];i++){
		fl=0;
		for(int j=1;j<=sum;j++){
			if(s[i][j]=='o'){
				if(fl==0){
					t++;
					cnt1=1;
					fl=1;
				}
				else cnt1++;
				if(s1[t][cnt1]==1) s[i][j]=' ';
				//cout<<t<<" "<<cnt1<<" "<<i<<" "<<j<<" "<<endl;
			}
		}
	}
	for(int i=1;i<=tr[m];i++){
		for(int j=1;j<=sum;j++){
			if(s[i][j]=='/'&&(s[i-1][j+1]==' ')) s[i][j]=' ';
			else if(s[i][j]=='\\'&&(s[i-1][j-1]==' ')) s[i][j]=' ';
			else if(s[i][j]=='o'&&s[i-1][j-1]==' '&&s[i-1][j+1]==' ') s[i][j]=' ';
		}
	}
	for(int i=tr[m];i>=1;i--){
		for(int j=1;j<=sum;j++){
			if(s[i][j]=='/'&&(s[i+1][j-1]==' ')) s[i][j]=' ';
			else if(s[i][j]=='\\'&&(s[i+1][j+1]==' ')) s[i][j]=' ';
			else if(s[i][j]=='o'&&s[i-1][j-1]==' '&&s[i-1][j+1]==' ') s[i][j]=' ';
		}
	}
	for(int i=1;i<=tr[m];i++){
		for(int j=1;j<=sum;j++){
			cout<<s[i][j];
		}
		cout<<endl;
	}
//	for(int i=1;i<=tr[m];i++){
//		for(int j=1;j<=sum;j++){
//			cout<<i<<" "<<j<<" "<<s[i][j]<<" "<<s1[i][j]<<" "<<s2[i][j]<<endl;
//		}
//		cout<<endl;
//	}
	return 0;
} 
/*
4 3 
3 2 
4 1 
3 4
5 1
4 8

10 7
9 88
8 32
10 178
8 128
10 55
10 126
8 126

7 7
6 3
5 4
7 10
5 7
7 4
7 14
5 5

*/
