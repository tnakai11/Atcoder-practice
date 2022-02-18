#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc230/tasks/abc230_c
// (A,B) を中心に X を一度描く
// 描画する各マスについて X の射程内か判定すれば O(マス数) でOK
// i=A+k, j=B+k <-> i-A = j-B = k
// i=A+k, j=B-k <-> i-A = B-j = k
void solve(){ 
    ll N,A,B; cin >> N >> A >> B;
    ll P,Q,R,S; cin >> P >> Q >> R >> S;
    ll width = S - R + 1;
    for(ll di=0;di<=Q-P;++di){
        ll i = P + di;
        string line = string(width,'.');
        for(ll dj=0;dj<=S-R;++dj){
            ll j = R + dj;
            if( abs(i-A)==abs(j-B) ) line[dj] = '#';
        }
        cout << line << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}