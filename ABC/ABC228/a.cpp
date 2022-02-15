#include <bits/stdc++.h>
using namespace std;
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc228/tasks/abc228_a
// シミュレーションでも高々50ステップ程度で検証可能

// 以下の2パターンだけなので if 文で O(1)
// xxxxxxxxxSooooooTxxx
// ooooooooTxxxxxSooooo

// WA
// T<Sの場合の検討が不十分だった

void solve(){ 
    int S,T,X; cin >> S >> T >> X;
    string ans;
    if(S<T){
        if(S<=X && X<=T){
            ans = Liny;
        }else{
            ans = Linn;
        }
    }else{
        if(X<T || S<=X){
            ans = Liny;
        }else{
            ans = Linn;
        }
    }
    cout << ans;
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}