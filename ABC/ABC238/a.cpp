#include <bits/stdc++.h>
using namespace std;
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc238/tasks/abc238_a
// 2^n > n^2
// <-> n log 2 > 2 log n
void solve(){ 
    int n; cin >> n;
    if(2 <= n && n <=4){
        cout << Linn;
    }else{
        cout << Liny;
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}