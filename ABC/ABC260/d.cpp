#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc260/tasks/abc260_d
// P = (1 3 2 4 5) の場合
// turn1 1
// turn2 1,3
// turn3 1,2
// turn4 1,2,4
// turn5 1,2,4,5
// 最悪ケースは P = (1 2 3 4 5)
// set構造で2分探索すれば O(NlogN) でいけるかな
// タワー構造は UnionFind で表現
struct UnionFind {
    vector<int> par; 
    vector<int> s; 
    vector<int> t;

    UnionFind(int N) : par(N),s(N),t(N) { 
        REP(i,N) { 
            par[i] = i;
            s[i] = 1;
            t[i] = -1;
        }
    }

    int root(int x) { 
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { 
        int rx = root(x); 
        int ry = root(y); 
        if (rx == ry) return; 
        par[ry] = rx; 
        s[rx] += s[ry];
    }

    int size(int x){
        int rx = root(x);
        return s[rx];
    }

    int turn(int x){
        int rx = root(x);
        return t[rx];
    }

    void eaten(int rx, int turn){
        t[rx] = turn;
    }
};
void solve(){ 
    int N,K; cin >> N >> K;
    vector<int> p(N);
    REP(i,N){
        cin >> p[i];
        --p[i];
    }
    set<int> tops;
    UnionFind uf(N);
    REP(i,N){
        int x = p[i];
        auto it = tops.lower_bound(x);
        if(it==tops.end()){
            tops.insert(x);
        }else{
            int y = *it;
            tops.erase(y);
            tops.insert(x);
            uf.unite(x,y);
        }
        if(uf.size(x)==K){
            int turn = i+1;
            uf.eaten(x,turn);
            tops.erase(x);
        }
    }
    vector<int> ans(N);
    REP(i,N){
        int x = p[i];
        ans[x] = uf.turn(x);
    }
    for(auto e:ans){
        cout << e << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}