#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
// https://atcoder.jp/contests/abc272/tasks/abc272_a
// for 文で入力と加算を繰返す
// python なら sum 関数が使える
void solve(){ 
    int N; cin >> N;
    int s = 0;
    REP(i,N){
        int a; cin >> a;
        s += a;
    }
    printf("%d\n",s);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}