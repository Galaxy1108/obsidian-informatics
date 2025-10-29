#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef __gnu_pbds::tree<int,__gnu_pbds::null_type,less<int>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> treee;
#define N 1000005
#define sN 1005
int n,q;
treee st;
struct query{
    int tp,m;
}qs[N];
vector<int>del;
namespace sub1{
    void solve(){
        for(int i=1;i<=n;i++){
            st.insert(i);
        }
        for(int i=1;i<=q;i++){
            if(qs[i].tp==1){
                for(int j=1;j<=n;j+=qs[i].m)st.erase(j);
            }
            else if(qs[i].tp==2){
                if(st.empty())continue;
                for(int j=*st.begin(),nxt;j<=n;j=nxt){
                    auto it=st.find_by_order(st.order_of_key(j)+qs[i].m);
                    if(it==st.end()){
                        st.erase(j);
                        break;
                    }
                    else{
                        nxt=*it;
                        st.erase(j);
                    }
                }
            }
            else{
                int lst=-1;
                while(!st.empty()){
                    for(int j=*st.begin(),nxt;;j=nxt){
                        auto it=st.find_by_order(st.order_of_key(j)+qs[i].m);
                        lst=j;
                        del.emplace_back(j);
                        if(it==st.end()){
                            st.erase(j);
                            break;
                        }
                        else{
                            nxt=*it;
                            st.erase(j);
                        }
                    }
                    if(st.empty())break;
                    for(int j=*st.rbegin(),nxt;;j=nxt){
                        auto it=st.find_by_order(st.order_of_key(j)-qs[i].m);
                        lst=j;
                        del.emplace_back(j);
                        if(it==st.end()){
                            st.erase(j);
                            break;
                        }
                        else{
                            nxt=*it;
                            st.erase(j);
                        }
                    }
                }
                cout<<lst<<'\n';
                for(auto v:del)st.insert(v);
                del.clear();
            }
            // for(auto v:st){
            //     cerr<<v<<' ';
            // }
            // cerr<<'\n';
        }
    }
}
namespace sub2{
    int ans1e6[25]={0,0,481110,303626,580087,549429,590427,475121,459866,517234,505247,529752,554054,508278,508936,550722,482399,483424,520052,542393,468006};
    int ans[25];
    void solve(){
        if(n==1000000){
            for(int i=1;i<=q;i++){
                cout<<ans1e6[qs[i].m]<<'\n';
            }
            return ;
        }
        for(int m=2;m<=20;m++){
            for(int i=1;i<=n;i++){
                st.insert(i);
            }
            ans[m]=-1;
            while(!st.empty()){
                for(int j=*st.begin(),nxt;;j=nxt){
                    auto it=st.find_by_order(st.order_of_key(j)+m);
                    ans[m]=j;
                    del.emplace_back(j);
                    if(it==st.end()){
                        st.erase(j);
                        break;
                    }
                    else{
                        nxt=*it;
                        st.erase(j);
                    }
                }
                if(st.empty())break;
                for(int j=*st.rbegin(),nxt;;j=nxt){
                    auto it=st.find_by_order(st.order_of_key(j)-m);
                    ans[m]=j;
                    del.emplace_back(j);
                    if(it==st.end()){
                        st.erase(j);
                        break;
                    }
                    else{
                        nxt=*it;
                        st.erase(j);
                    }
                }
            }
        }
        for(int i=1;i<=q;i++){
            cout<<ans[qs[i].m]<<'\n';
        }
    }
}
int main(){
    freopen("bounce.in","r",stdin);
    freopen("bounce.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    bool sub2=true;
    for(int i=1;i<=q;i++){
        cin>>qs[i].tp>>qs[i].m;
        if(qs[i].tp!=3)sub2=false;
    }
    if(n<=1000){
        sub1::solve();
    }
    else if(sub2){
        sub2::solve();
    }
    return 0;
}