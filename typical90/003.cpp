#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/typical90/tasks/typical90_c
// 木に1辺足して閉路をつくる
// 端点を根として
// 一番深い（＝根から一番遠い）点と根を選べばOK?
// WA

// 「木の直径」概念
// 根の選び方が問題だった

const int MAX = 100005;
vector<int> ngb[MAX];
vector<int> v(MAX,0);
int depth = 0;
int e = -1;
void dfs(int x,int d){
    v[x] = 1;
    if(d>depth){
        depth = d;
        e = x;
    }
    for(int y:ngb[x]){
        if(v[y]) continue;
        dfs(y,d+1);
    }
}
void solve(){ 
    int N; cin >> N;
    REP(i,N-1){
        int a,b; cin >> a >> b;
        --a;--b;
        ngb[a].emplace_back(b);
        ngb[b].emplace_back(a);
    }
    dfs(0,0);
    REP(x,N) v[x] = 0;
    depth = 0;
    dfs(e,0);
    cout << depth + 1 << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}