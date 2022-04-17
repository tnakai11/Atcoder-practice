#include <bits/stdc++.h>
using namespace std;
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc240/tasks/abc240_a
// 差が1であるかどうか
// 10と1に注意
void solve(){ 
    int a,b; cin >> a >> b;
    int x = b-a;
    if(x==1 || x==9){
        cout << Liny;
    }else{
        cout << Linn;
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}