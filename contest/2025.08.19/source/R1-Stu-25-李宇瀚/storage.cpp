#include<bits/stdc++.h>
#define int long long

using namespace std;

double work(int a,int b,int c,int d){
	double t1=(a-b)*1.0;
	double t2=(c-d)*1.0;
	return (double)((double)t1/(double)t2);
}

const int MAXN=3000001;

int head=1,tail=1;
int q[MAXN],f[MAXN];
int s1[MAXN],s2[MAXN];
int dis[MAXN],p[MAXN],c[MAXN];
int n;

signed main(){
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) f[i]=-9999999999999999;
	for(int i=1;i<=n;i++){
		cin>>dis[i]>>p[i]>>c[i];
		s2[i]=s2[i-1]+p[i];
	}
	int total=0;
	for(int i=1;i<=n;i++){
		dis[i]=dis[n]-dis[i];
		s1[i]+=dis[i];
		total+=dis[i]*p[i];
	}
	f[0]=0;
	q[tail]=0;
	tail++;
	for(int i=1;i<=n;i++){
		while(tail-head>1){
			int t1=q[head],t2=q[head+1];
			double tm=work(f[t2],f[t1],s2[t2],s2[t1]);
			if(tm>=dis[i]){
				q[head]=0;
				head++;
			}
			else break;
		}
		int tmp=q[head];
//		cout<<tmp<<" "<<q[head+1]<<endl;
		f[i]=(s2[i]-s2[tmp])*dis[i]+f[tmp]-c[i];
//		cout<<f[i]<<" "<<tmp<<" "<<q[head+1]<<endl;
		while(tail-head>1){
			int t1=q[tail-1],t2=q[tail-2];
			double tm=work(f[i],f[t1],s2[i],s2[t1]);
			double tm2=work(f[t1],f[t2],s2[t1],s2[t2]);
			if(tm>=tm2){
				q[tail-1]=0;
				tail--;
			}
			else break;
		}
		q[tail]=i;
		tail++;
	}
//	cout<<total<<endl;
//	cout<<f[n]<<endl;
	cout<<total-f[n]<<endl;
	return 0;
}
