#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <ctime>
#include <unordered_map>
using namespace std;
const int N=7;
int n,a[N],ans;
queue<vector<int> >q;
inline int abss(int x){return x<0?-x:x;}
inline void getans(vector<int>tmp){
	int sum=0;
	for(int i=1;i<=n;++i)
		sum+=abss(tmp[i]-a[i]);
	ans=min(ans,sum);
}
inline void outpu(vector<int>tmp){
	for(int i=0;i<=n;++i){
		printf("%d ",tmp[i]);
	}putchar('\n');
}
int vis[3000006];
inline bool getvis(vector<int>tmp){
	//puts("getvis");
	//outpu(tmp);
	//putchar('\n');
	int sum=0;
	for(int i=0;i<=n;++i){//´Ó0¿ªÊ¼¹þÏ£ 
		sum=sum*12+tmp[i];
	}
	if(vis[sum])return 1;
	vis[sum]=1;return 0;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout); 
	scanf("%d",&n);ans=0x3f3f3f3f;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	vector<int> tmp;
	for(int i=0;i<=n;++i)tmp.push_back(0);
	for(int i=0;i<=n;++i){
		tmp[0]=i;
		q.push(tmp);
	}
	while(!q.empty()){
		tmp.clear();tmp=q.front();q.pop();
		bool f1=1,f2=0;
		for(int i=1;i<=n;++i)
			if(tmp[i]<=a[i])f1=0;
		if(f1)continue;
		for(int i=1;i<=n;++i)
			if(tmp[i]-a[i]>=ans)f2=1;
		if(f2)continue;
		//printf("outpu "); outpu(tmp);
		int loc=tmp[0];
		if(loc==0){
			++tmp[1];++tmp[0];
			if(getvis(tmp))continue;
			getans(tmp);q.push(tmp);
		}else if(loc==n){
			++tmp[n];--tmp[0];
			if(getvis(tmp))continue;
			getans(tmp);q.push(tmp);
		}else{
			vector<int> ttf=tmp;
			++ttf[loc];--ttf[0];
			if(getvis(ttf))continue;
			getans(ttf);q.push(ttf);
			
			ttf=tmp;
			++ttf[loc+1];++ttf[0];
			if(getvis(ttf))continue;
			getans(ttf);q.push(ttf);
		}
		if(ans==0)break;
	}printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
