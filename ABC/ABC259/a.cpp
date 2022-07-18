#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc259/tasks/abc259_a
// T = D*X + S
// ans = D * min(M,X) + S 
//     = D * min(M,X) + T - D*X
//     = T - D * (X - min(M,X)) 
void solve(){ 
    int N,M,X,T,D; cin >> N >> M >> X >> T >> D;
    int ans = T - D * (X - min(M,X));
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}