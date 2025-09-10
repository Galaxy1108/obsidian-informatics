#include <cstdio>
#include <utility>
#include <vector>
#include <bitset>
#include <algorithm>
std::vector<std::pair<int,int> > circ1,circ2;
std::bitset<100001> vis;
int main(){
    freopen("permutation.in","r",stdin);
    freopen("permutation.out","w",stdout);
  int n;
  int gr1[100001],gr2[100001],ans[100001];
  scanf("%d",&n);
  for(int i=1;i<=n;i++) scanf("%d",&gr1[i]);
  for(int i=1;i<=n;i++) scanf("%d",&gr2[i]);
  for(int i=1;i<=n;i++){
    if(!vis[i]){
      int tmp=1;
      vis[i]=1;
      for(int j=gr1[i];j!=i;j=gr1[j]) tmp++,vis[j]=1;
      circ1.push_back(std::make_pair(tmp,i));
    }
  }
  vis.reset();
  for(int i=1;i<=n;i++){
    if(!vis[i]){
      int tmp=1;
      vis[i]=1;
      for(int j=gr2[i];j!=i;j=gr2[j]) tmp++,vis[j]=1;
      circ2.push_back(std::make_pair(tmp,i));
    }
  }
  std::sort(circ1.begin(),circ1.end());
  std::sort(circ2.begin(),circ2.end());
  if(circ1.size()!=circ2.size()){
    printf("NO\n");
    return 0;
  }
  for(int i=0;i<circ1.size();i++){
    if(circ1[i].first!=circ2[i].first){
      printf("NO\n");
      return 0;
    }
    for(int x=0,j=circ1[i].second,k=circ2[i].second;
	x<circ1[i].first;j=gr1[j],k=gr2[k],x++)
      ans[k]=j;
  }
  printf("YES\n");
  for(int i=1;i<=n;i++)
    printf("%d ",ans[i]);
  printf("\n");
  return 0;
}
