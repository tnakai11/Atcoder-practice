#include <bits/stdc++.h>
using namespace std;
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
// https://atcoder.jp/contests/abc285/tasks/abc285_a
// a < b より b//2 = a であるかどうか判定
// 気合いで if 文を書くのもなしではない
void solve(){ 
    int a,b; cin >> a >> b;
    cout << (b/2==a ? Liny : Linn);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}