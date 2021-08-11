#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc213/tasks/abc213_a
// A^C   = B ならば
// A^B^C = 0
// A^B   = C
void solve(){ 
    int A,B; cin >> A >> B;
    int C = A^B;
    cout << C << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}