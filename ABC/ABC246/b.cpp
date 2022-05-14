#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc246/tasks/abc246_b
// ベクトルの計算
void solve(){ 
    ld A,B; cin >> A >> B;
    ld C = sqrt(A*A + B*B);
    ld x = A/C;
    ld y = B/C;
    printf("%.7Lf %.7Lf\n",x,y);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}