#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc257/tasks/abc257_a
// X = Ni + j
// N X = 1 3
// 3 = 1*3 + 0
// N X = 2 3
// 3 = 2*1 + 1
void solve(){ 
    int N,X; cin >> N >> X;
    int i = X/N;
    int j = X%N;
    char ans;
    if(j==0){
        ans = 'A' + i-1;
    }else{
        ans = 'A' + i;
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}