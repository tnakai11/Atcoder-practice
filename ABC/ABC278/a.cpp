#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
// https://atcoder.jp/contests/abc278/tasks/abc278_a
// i=KからN個出力する
void solve(){ 
    int N,K; cin >> N >> K;
    vector<int> a(205,0);
    REP(i,N) cin >> a[i];
    for(int i=K;i<K+N;++i){
        cout << a[i];
        cout << (i<K+N-1?' ':'\n');
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}