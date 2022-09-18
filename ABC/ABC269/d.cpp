#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
// https://atcoder.jp/contests/abc269/tasks/abc269_d
// マスを準備しきるのは間に合わない
// 塗った部分について隣接グラフを書く
// 計算量は O(N^2)
// UnionFind の方が手っ取り早そう
int x[1005];
int y[1005];
struct UnionFind {
    vector<int> par;
    int num;
    UnionFind(int N) : par(N) { 
        for(int i = 0; i < N; i++) par[i] = i;
        num = N;
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
    }
    bool same(int x, int y) { 
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};
bool areConnected(int i,int j){
    int x1 = x[i];
    int y1 = y[i];
    int x2 = x[j];
    int y2 = y[j];
    if(x2-x1==0 && y2-y1==1) return true;
    if(x2-x1==0 && y2-y1==-1) return true;
    if(x2-x1==1 && y2-y1==0) return true;
    if(x2-x1==-1 && y2-y1==0) return true;
    if(x2-x1==1 && y2-y1==1) return true;
    if(x2-x1==-1 && y2-y1==-1) return true;
    return false;
}
void solve(){ 
    int N; cin >> N;
    UnionFind uf(N);
    REP(i,N){
        cin >> x[i] >> y[i];
    }
    REP(i,N){
        for(int j=i+1;j<N;++j){
            if( areConnected(i,j) ){
                uf.unite(i,j);
            }
        }
    }
    int ans = uf.num;
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}