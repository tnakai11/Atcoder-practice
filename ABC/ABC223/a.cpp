#include <bits/stdc++.h>
using namespace std;
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc223/tasks/abc223_a
// Xが100の倍数であるような正の数であるかどうかを判定する
void solve(){ 
    int X; cin >> X;
    if(X && X%100==0){
        cout << Liny;
    }else{
        cout << Linn;
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}