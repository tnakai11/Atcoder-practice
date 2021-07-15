#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc166/tasks/abc166_b
// お菓子を配りきるのに O(KN)
// お菓子を持っていないすぬけ君を調べるのに O(N)
// 計算量は O(KN) で K*N <= 10^4 より間に合う
void solve(){ 
    int N,K; cin >> N >> K;
    vector<int> v(N+1,0);
    REP(kind,K){
        int d; cin >> d;
        REP(count,d){
            int a; cin >> a;
            ++v[a];
        }
    }
    int ans = 0;
    for(int i=1;i<=N;++i){
        if(v[i]==0) ++ans;
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}