#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector <int> a;
vector <int> b;
int k;
int ans;int n,m;
bool check(vector<int> v){
    for(int i=0;i<v.size();i++){
        if(v[i]<b[i]){
            return 1;
        }
        if(v[i]>b[i])return 0;
    }
    if(v.size()<b.size())return 1;
    return 0;
}
map <vector<int> ,bool> ma,maa;
void dfs(int cnt,vector<int> v){
    if(cnt>=a.size())return;
    if(check(v)){
        if(!maa[v]){
            ans++;
            maa[v]=1;
        }
        
    }
    // for(int i=0;i<v.size();i++)cout << v[i];
    //     cout << endl;
    dfs(cnt+1,v);
    v.push_back(a[cnt+1]);
    dfs(cnt+1,v);
    
}
int main(){
    freopen("seq.in","r",stdin);
    freopen("seq.out","w",stdout);
    cin >> n ;
    for(int i=1;i<=n;i++){
        int t;cin >> t;
        a.push_back(t);
    }
    cin >> m;
    for(int i=1;i<=m;i++){
        int t;cin >> t;
        b.push_back(t);
    }
    for(int i=0;i<a.size();i++){
        vector <int> v;
        // maa.clear();
        v.push_back(a[i]); 
        dfs(i,v);
    }
    cout << ans+1;
    return 0;
}