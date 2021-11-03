#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc222/tasks/abc222_a
// python なら zfill でいける
// c++ では setw と setfill でいける
void solve(){ 
    int N; cin >> N;
    cout << setw(4) << setfill('0') << N << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}