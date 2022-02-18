#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc230/tasks/abc230_a
// if文とゼロパディング
// Python で書いたほうが速い気はする
void solve(){ 
    int N; cin >> N;
    int ans = N;
    if(N>=42) ++ans;
    printf("AGC%03d\n",ans);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}