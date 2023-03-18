#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
// https://atcoder.jp/contests/abc293/tasks/abc293_d
// ロープの組数と環状になっていないものの組数を調べればOK
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
void solve(){ 
    int N,M; cin >> N >> M;
    map<int,int> isTied;
    UnionFind uf(N*2);
    // ロープの端点はつながっている
    REP(i,N){
        int x = i*2;
        int y = i*2+1;
        uf.unite(x,y);
    }
    // 指定された端点どうしを結ぶ
    REP(i,M){
        int A,C;
        char B,D;
        cin >> A >> B >> C >> D;
        --A; --C;
        int x = A*2+(B=='R');
        int y = C*2+(D=='R');
        uf.unite(x,y);
        isTied[x] = 1;
        isTied[y] = 1;
    }
    int endPointNum = 0;
    REP(i,N*2){
        // 結び目は端点でない
        if(isTied[i]==0) ++endPointNum;
    }
    int notLoopNum = endPointNum/2;
    cout << uf.num - notLoopNum << ' ' << notLoopNum << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}