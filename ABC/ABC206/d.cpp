#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define CINA(a,n) REP(i,(n)){ cin >> (a)[i]; }
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc206/tasks/abc206_d
// 最大値は N//2
// 回文にならない部分をなるべく少ない色で塗り替えていけばOK?

// WA 解説を読む
// 最終的に値が同じになる位置どうしに辺を張ると
// 各連結成分について 色数-1 だけ操作が必要

struct UnionFind {
    vector<int> par,s;
    UnionFind(int N) : par(N),s(N){
        REP(i,N){
            par[i] = i;
            s[i] = 1;
        }
    }
    int root(int x){
        if(par[x]==x){ return x; }
        else{ 
          par[x]= root(par[x]);
          return par[x];
        }
    }
    void unite(int x, int y){
        int rx = root(x);
        int ry = root(y);
        if( rx!=ry ){
            par[rx] = ry;
            s[ry] += s[rx];
        }
    }
    bool same(int x, int y){
        int rx = root(x);
        int ry = root(y);
        return (rx==ry);
    }
    int size(int x){
        int rx = root(x);
        return s[rx];
    }
};

const int MAX = 200005;
int a[MAX]; 
UnionFind uf(MAX);
int ans = 0;
void solve(){ 
    int N; cin >> N;
    CINA(a,N);
    int i=0;
    int j=N-1;
    while(i<j){
        uf.unite(a[i],a[j]);
        ++i; --j;
    }
    map<int,int> mp;
    REP(i,N){
        if(mp[a[i]]++>0) continue;
        if( uf.root(a[i])==a[i] ) {
            ans += (uf.size(a[i]) - 1);
        }
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}