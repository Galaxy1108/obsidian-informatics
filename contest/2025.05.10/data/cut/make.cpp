#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#define PB push_back
#define MP make_pair
#define BG begin()
#define ED end()
#define SZ(x) ((int)((x).size()))
#define FF first
#define SS second
#define foreach(i,x) for (__typeof((x).begin()) i=(x).begin();i!=(x).end();i++)
#define FOR(i,l,r) for (int i=(l);i<=(r);i++)
#define ROF(i,r,l) for (int i=(r);i>=(l);i--)
using namespace std;

int main() {
  freopen("data.txt","r",stdin);
  FOR(i,1,124/2) {
    stringstream s;
    s<<"cut"<<i<<".in";
    freopen(s.str().c_str(),"w",stdout);
    string x;
    getline(cin,x);
    cout<<x;
    fclose(stdout);
    stringstream q;
    q<<"cut"<<i<<".out";
    freopen(q.str().c_str(),"w",stdout);
    getline(cin,x);
    cout<<x;
    fclose(stdout);
  };
}
