#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc231/tasks/abc231_d
// 総当たるのは時間計算量が O(N!) となるため無理
// 各ノードから延びる枝が高々2本かつ閉路がなければOK
// UF木を使うとループ判定でバグりにくい

int N,M;
vector<int> edgeSize(100005,0);

bool isLine(){
    REP(i,N){
        if(edgeSize[i]>2) return false;
    }
    return true;
}

void solve(){ 
    cin >> N >> M;
    dsu uf(N);
    bool ok = true;
    REP(m,M){
        int a,b; cin >> a >> b;
        --a; --b;
        ++edgeSize[a];
        ++edgeSize[b];

        if(uf.same(a,b)){
            ok = false;
        }
        uf.merge(a,b);
    }
    if(ok) ok = isLine();
    cout << (ok?Liny:Linn);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}