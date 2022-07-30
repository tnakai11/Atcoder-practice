#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc260/tasks/abc260_c
// red(n) -> red(n-1) + blue(n)*X
// blue(n) -> red(n-1) + blue(n-1)*Y
ll X,Y;
ll blue(ll N);
ll red(ll N){
    if(N==1) return 0;
    return red(N-1) + blue(N)*X;
}
ll blue(ll N){
    if(N==1) return 1;
    return red(N-1) + blue(N-1)*Y;
}
void solve(){ 
    ll N;
    cin >> N >> X >> Y;
    cout << red(N) << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}