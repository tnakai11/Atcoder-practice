#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
// https://atcoder.jp/contests/abc271/tasks/abc271_b
// やるだけ
// 配列だと確保するメモリが大きすぎるのでvectorを使う
void solve(){ 
    int N,Q; cin >> N >> Q;
    vector< vector<int> > v(N);
    REP(i,N){
        int L; cin >> L;
        REP(j,L){
            int a; cin >> a;
            v[i].emplace_back(a);
        }
    }
    REP(i,Q){
        int s,t; cin >> s >> t;
        --s, --t;
        cout << v[s][t] << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}