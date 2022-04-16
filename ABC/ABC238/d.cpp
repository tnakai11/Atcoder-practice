#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;
#define Liny "Yes\n"
#define Linn "No\n"
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc238/tasks/abc238_d
// x + y = s の条件から始めて全探索するのは厳しそうなので
// x & y = a から条件を絞ることを考える

// x & y = a であるということは
// a の部分は必ずビットが立っており
// それ以外の部分は一致していないようなx,yの組である
// このことからx,yは以下の式を満たす
// x + y = 2a + z (ただし z&a==0)

// x + y = s が成り立つ場合
// s - 2*a = z (ただし z&a==0)
// となるからこれを判定に使えば良さそう

void solve(){ 
    int T; cin >> T;
    REP(count,T){
        ll a,s; cin >> a >> s;
        ll z = s - 2*a;
        if(z<0){
            cout << Linn; 
            continue;
        }
        dprint(z&a);
        if((z&a)==0){
            cout << Liny;
        }else{
            cout << Linn;
        }
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}