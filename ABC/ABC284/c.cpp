#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
// https://atcoder.jp/contests/abc284/tasks/abc284_c
// UnionFind か DFS でいける。計算量はざっくりO(N+M)
struct UnionFind {
    vector<int> par;
    int num;
    int size;
    UnionFind(int N) : par(N) { 
        for(int i = 0; i < N; i++) par[i] = i;
        num = N;
        size = N;
    }
    int root(int x) { 
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    void unite(int x, int y) { 
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
        num -= 1;
        size -= 1;
    }
    bool same(int x, int y) { 
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};
void solve(){ 
    int N,M; cin >> N >> M;
    UnionFind uf = UnionFind(N);
    REP(i,M){
        int u,v; cin >> u >> v;
        --u;
        --v;
        uf.unite(u,v);
    }
    cout << uf.size << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}