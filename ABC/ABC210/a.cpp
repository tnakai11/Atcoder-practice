#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc210/tasks/abc210_a
// if 文か min,max 
void solve(){ 
    int N,A,X,Y;
    cin >> N >> A >> X >> Y;
    int ans = X * min(A,N) + Y * max(N-A,0);
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}