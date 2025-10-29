#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5,mod=1e9+7;
int n,a[N],b[N],id[N];
typedef vector<int>poly;
set<poly>st;
int main(){
    freopen("permutation.in","r",stdin);
    freopen("premutation.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n*2;i++)scanf("%d",a+i),id[i]=i;
    if(n<=5){
        int ans=0;
        do{
            int flag=0;
            for(int i=1;i<=n*2;i++)if(a[i]!=-1&&id[i]!=a[i]){
                flag=1;
                break;
            }
            if(flag)continue;
            poly vec;
            for(int i=1;i<=n;i++)vec.push_back(min(id[i*2-1],id[i*2]));
            st.insert(vec);
        }while(next_permutation(id+1,id+1+n*2));
        printf("%d\n",st.size());
    }
    return 0;
}