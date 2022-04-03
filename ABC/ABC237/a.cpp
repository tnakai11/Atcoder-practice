#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc237/tasks/abc237_a
// long long を使えばOK
// int しか使えない場合は文字列として取り込んでif文
const ll LIMIT = (ll)pow(2,31);
void solve(){ 
    ll x; cin >> x;
    if(-LIMIT<=x && x<LIMIT){
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