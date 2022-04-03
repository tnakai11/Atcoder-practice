#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc236/tasks/abc236_d
// 16! ≒ 2^13 より順列総当たりは厳しい
// C(16,2) * C(14,2) * .. * C(2,2) < 6*10^7 より組み合わせ総当たりはたぶんいける
// 再帰で行けるだろうか
// bitで状態管理

int N; 
ll a[20][20];
ll ans = 0LL;
void dfs(ll n, ll s, ll score){
    if(n==N){
        chmax(ans,score);
        return;
    }
    for(int x=1;x<=N*2;++x){
        if((s>>(x-1))&1) continue;
        for(int y=x+1;y<=N*2;++y){
            if((s>>(y-1))&1) continue;
            ll t = s;
            t |= (1<<(x-1));
            t |= (1<<(y-1));
            dfs(n+1, t, score^a[x][y]);
        }
        break;
    }
}
void solve(){ 
    cin >> N;
    for(int x=1;x<=N*2-1;++x){
        for(int y=x+1;y<=2*N;++y){
            cin >> a[x][y];
        }
    }
    dfs(0,0,0);
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}