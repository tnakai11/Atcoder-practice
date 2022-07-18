#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc259/tasks/abc259_b
// ベクトルの回転
// |x2| = |cos(a) -sin(a)| |x1|
// |y2|   |sin(a) cos(a) | |y1|
void solve(){ 
    ll a,b,d; cin >> a >> b >> d;
    ld theta = d*M_PI/180.;
    ld a2 = cos(theta) * a - sin(theta) * b;
    ld b2 = sin(theta) * a + cos(theta) * b;
    cout << setprecision(10) << a2 << ' ';
    cout << setprecision(10) << b2 << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}