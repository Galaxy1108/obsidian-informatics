#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int MAXN=1e6+5;
const int INF=1e9+5;

int T,N;
int a[MAXN];
int b[MAXN];

void solve(){
	vector<int> v;
	for(int i=1;i<=N;i++) v.push_back(a[i]);
	int cnt=N;
	while(cnt>1){
		if(v[(int)v.size()-1]-v[0]>=v[1]){
			v[(int)v.size()-1]-=v[0],v[0]=INF;
			sort(v.begin(),v.end());
			v.pop_back();
			cnt--;
		} 
		else break;
	}
	printf("\n");
	if(cnt==2){
		printf("1\n");
		return ;
	} 
	printf("%d\n",(int)v.size());
}

int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d%d",&T,&N);
	if(N==3){
		
	T--;
	for(int i=1;i<=N;i++) scanf("%d",&a[i]);
	for(int i=1;i<=N;i++){
		b[i]=a[i];
	}
	sort(b+1,b+N+1);
	if(b[3]-b[1]>b[2]) printf("1\n");
	else printf("3\n");
	while(T--){
		int k;
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			a[x]=y;
		}
		for(int i=1;i<=N;i++){
			b[i]=a[i];
		}
		if(b[3]-b[1]>b[2]) printf("1\n");
		else printf("3\n");
	}
	
	}
	else{
	
	T--;
	for(int i=1;i<=N;i++){
		scanf("%d",&a[i]);
	}
	solve();
	for(int i=1;i<=T;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int x,y;
			scanf("%d%d",&x,&y);
			a[x]=y;
		}
		solve();
	}
	
	}
	
} 
