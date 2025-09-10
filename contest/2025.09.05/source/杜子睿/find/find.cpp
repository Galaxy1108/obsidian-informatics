#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long f[15][41][27][19][16][2],n,k,qu[2005],tail;
int l,s[15];
priority_queue<long long,vector<long long>,less<long long> > q,p;
void init(){
	long long ttt=n;
	while(ttt){
		l++;
		s[l]=ttt%10;
		ttt/=10;
	} 
	for(int i=1;i<=l;i++)
		for(int a=0;a<41;a++)
			for(int b=0;b<27;b++)
				for(int c=0;c<19;c++)
					for(int d=0;d<16;d++){
						int kk=1;
						if(kk<s[i])
							f[i][a][b][c][d][0]+=f[i-1][a][b][c][d][0]+f[i-1][a][b][c][d][1];
						else if(s[i]==kk){
							f[i][a][b][c][d][0]+=f[i-1][a][b][c][d][0];
							f[i][a][b][c][d][1]+=f[i-1][a][b][c][d][1];
						}
						else
							f[i][a][b][c][d][1]+=f[i-1][a][b][c][d][0]+f[i-1][a][b][c][d][1];
						kk=2;
						if(kk<s[i])
							f[i][a+1][b][c][d][0]+=f[i-1][a][b][c][d][0]+f[i-1][a][b][c][d][1];
						else if(s[i]==kk){
							f[i][a+1][b][c][d][0]+=f[i-1][a][b][c][d][0];
							f[i][a+1][b][c][d][1]+=f[i-1][a][b][c][d][1];
						}
						else
							f[i][a+1][b][c][d][1]+=f[i-1][a][b][c][d][0]+f[i-1][a][b][c][d][1];
						kk=3;
						if(kk<s[i])
							f[i][a][b+1][c][d][0]+=f[i-1][a][b][c][d][0]+f[i-1][a][b][c][d][1];
						else if(s[i]==kk){
							f[i][a][b+1][c][d][0]+=f[i-1][a][b][c][d][0];
							f[i][a][b+1][c][d][1]+=f[i-1][a][b][c][d][1];
						}
						else
							f[i][a][b+1][c][d][1]+=f[i-1][a][b][c][d][0]+f[i-1][a][b][c][d][1];
						kk=4;
						if(kk<s[i])
							f[i][a+2][b][c][d][0]+=f[i-1][a][b][c][d][0]+f[i-1][a][b][c][d][1];
						else if(s[i]==kk){
							f[i][a+2][b][c][d][0]+=f[i-1][a][b][c][d][0];
							f[i][a+2][b][c][d][1]+=f[i-1][a][b][c][d][1];
						}
						else
							f[i][a+2][b][c][d][1]+=f[i-1][a][b][c][d][0]+f[i-1][a][b][c][d][1];
						kk=5;
						if(kk<s[i])
							f[i][a][b][c+1][d][0]+=f[i-1][a][b][c][d][0]+f[i-1][a][b][c][d][1];
						else if(s[i]==kk){
							f[i][a][b][c+1][d][0]+=f[i-1][a][b][c][d][0];
							f[i][a][b][c+1][d][1]+=f[i-1][a][b][c][d][1];
						}
						else
							f[i][a][b][c+1][d][1]+=f[i-1][a][b][c][d][0]+f[i-1][a][b][c][d][1];
						kk=6;
						if(kk<s[i])
							f[i][a+1][b+1][c][d][0]+=f[i-1][a][b][c][d][0]+f[i-1][a][b][c][d][1];
						else if(s[i]==kk){
							f[i][a+1][b+1][c][d][0]+=f[i-1][a][b][c][d][0];
							f[i][a+1][b+1][c][d][1]+=f[i-1][a][b][c][d][1];
						}
						else
							f[i][a+1][b+1][c][d][1]+=f[i-1][a][b][c][d][0]+f[i-1][a][b][c][d][1];
						kk=7;
						if(kk<s[i])
							f[i][a][b][c][d+1][0]+=f[i-1][a][b][c][d][0]+f[i-1][a][b][c][d][1];
						else if(s[i]==kk){
							f[i][a][b][c][d+1][0]+=f[i-1][a][b][c][d][0];
							f[i][a][b][c][d+1][1]+=f[i-1][a][b][c][d][1];
						}
						else
							f[i][a][b][c][d+1][1]+=f[i-1][a][b][c][d][0]+f[i-1][a][b][c][d][1];
						kk=8; 
						if(kk<s[i])
							f[i][a+3][b][c][d][0]+=f[i-1][a][b][c][d][0]+f[i-1][a][b][c][d][1];
						else if(s[i]==kk){
							f[i][a+3][b][c][d][0]+=f[i-1][a][b][c][d][0];
							f[i][a+3][b][c][d][1]+=f[i-1][a][b][c][d][1];
						}
						else
							f[i][a+3][b][c][d][1]+=f[i-1][a][b][c][d][0]+f[i-1][a][b][c][d][1];
						kk=9;
						if(kk<s[i])
							f[i][a][b+2][c][d][0]+=f[i-1][a][b][c][d][0]+f[i-1][a][b][c][d][1];
						else if(s[i]==kk){
							f[i][a][b+2][c][d][0]+=f[i-1][a][b][c][d][0];
							f[i][a][b+2][c][d][1]+=f[i-1][a][b][c][d][1];
						}
						else
							f[i][a][b+2][c][d][1]+=f[i-1][a][b][c][d][0]+f[i-1][a][b][c][d][1];
					} 
	for(int a=0;a<41;a++)
		for(int b=0;b<27;b++)
			for(int c=0;c<19;c++)
				for(int d=0;d<16;d++){
					long long cnt=0;
					for(int i=1;i<l;i++)
						cnt+=f[i][a][b][c][d][0]+f[i][a][b][c][d][1];
					cnt+=f[l][a][b][c][d][0];
					q.push(cnt);
				}
	while(!q.empty()&&tail<=2000){
		qu[++tail]=q.top();
		q.pop();
	}			
	for(int i=1;i<=tail;i++)
		for(int j=1;j<=tail;j++)
			p.push(qu[i]*qu[j]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	cin>>n>>k;
	f[0][0][0][0][0][0]=1;
	init();
	long long ans=0;
	while(k&&!p.empty()){
		ans=(ans+p.top())%mod;
		k--;
		p.pop();
	}
	cout<<ans; 
	return 0;
}

