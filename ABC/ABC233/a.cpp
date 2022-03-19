#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc233/tasks/abc233_a
// X + 10 * n >= Y を満たす最小の n を見つける
// 愚直にシミュレーションすれば O(Y) で終了
// 式変形すると n >= (Y-X)/10 より O(1) で計算可能
void solve(){ 
    int X,Y; cin >> X >> Y;
    int n = max( (Y-X)/10, 0);
    if( X + 10 * n >= Y){

    }else{
        ++n;
    }
    cout << n << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}