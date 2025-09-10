#include <bits/stdc++.h>
using namespace std;
#define N 25
#define L 11
#define V 100001
long long f[N][V][L];
int n,a[N],b[N];
inline void open_the_door(int now,int s,const int l){
	if(f[now][s][l]==0x3f3f3f3f3f3f3f3f)return ;
	// if(now==2&&s==3&&l==5)cerr<<"IN";
	static int v[5],c,ns,os,onow;
	c=0,onow=now,os=s;
	for(int i=4;i>=1;i--){
		v[i]=s%10;
		s/=10;
		if(v[i]==0)c++;
	}
	// cerr<<onow<<","<<l<<":";
	// for(int i=1;i<=4;i++)cerr<<v[i]<<' ';
	// cerr<<"("<<os<<")"<<"->";
	for(int i=4;i>=1;i--){
		if(v[i]==l)v[i]=0,c++;
	}
	sort(v+1,v+5);
	for(int i=onow+1;i<=n&&c>0;i++){
		if(a[i]==l)v[c]=b[i],c--,now=i;
		else break;
	}
	sort(v+1,v+5);
	ns=0;
	for(int i=1;i<=4;i++){
		ns=ns*10+v[i];
	}
	// cerr<<now<<","<<l<<":";
	// for(int i=1;i<=4;i++)cerr<<v[i]<<' ';
	// cerr<<"("<<ns<<")"<<"\n";
	// cerr<<now<<","<<ns<<","<<l<<'\n';
	// cerr<<f[onow][os][l]<<","<<t<<"\n";
	f[now][ns][l]=min(f[now][ns][l],f[onow][os][l]);
}
inline bool isok(int s){
	static int v[5];
	for(int i=4;i>=1;i--){
		v[i]=s%10;
		s/=10;
		if(i<4&&v[i+1]<v[i])return false;
	}
	return true;
}
int main(){
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	// freopen("t.txt","w",stderr);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	memset(f,0x3f,sizeof(f));
	f[0][0][1]=0;
	for(int i=0;i<=n;i++){
		for(int j=9999;j>=0;j--){
			if(!isok(j))continue;
			//move
			static bool book[15];
			for(int _=1;_<=9;_++){
				book[_]=false;
			}
			for(int _=1;_<=9;_++){
				static int mp;mp=0;
				for(int x=1;x<=9;x++){
					if(!book[x]&&f[i][j][x]<f[i][j][mp])mp=x;
				}
				if(mp==0)break;
				book[mp]=true;
				if(mp>1)f[i][j][mp-1]=min(f[i][j][mp-1],f[i][j][mp]+1);
				if(mp<9)f[i][j][mp+1]=min(f[i][j][mp+1],f[i][j][mp]+1);
			}
			// open the door
			for(int k=1;k<=9;k++){
				open_the_door(i,j,k);
			}
		}
	}
	long long ans=0x3f3f3f3f3f3f3f3f;
	for(int k=1;k<=9;k++){
		ans=min(ans,f[n][0][k]);
	}
	cout<<ans+2*n;
	return 0;
}

