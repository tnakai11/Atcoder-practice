#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc254/tasks/abc254_d
// 全パターン総当たりは O(N^2) より厳しい
// 素因数分解の結果を使う？
// 各平方数を構成できる組数を数えよう
// はみ出しを考えるのがつらい
// N=3 の場合
// i=1, j=1 ... ok
// i=2, j=2 ... ok
// i=4, j=1 ... ng
// i=3, j=3 ... ok
// 解説を見る
// https://atcoder.jp/contests/abc254/editorial/4065
// 考察むずい
ll solveSimply(ll N){
    ll ans = 0;
    map<ll,ll> mp;
    for(ll i=1;i<=N;++i){
        for(ll j=1;j<=N;++j){
            ll temp = i*j;
            ll x = sqrt(temp);
            if(x*x==temp) {
                ++ans;
                if(DEBUG) printf("solveSimple:%ld %ld\n",i,j);
                ++mp[i*j];
            }
        }
    }
    for(auto itr = mp.begin();itr!=mp.end();++itr){
        printf("solveSimply:%ld->%ld\n",itr->first,itr->second);
    }
    return ans;
}
ll solve(ll N){ 
    // 平方数をセット
    vector<bool> isSq(N+1,false);
    for(ll i=1;i*i<=N;++i) isSq[i*i] = true;

    // j の約数を div[j] に列挙
    vector< vector<ll> > div(N+1);
    for(ll i=1;i<=N;++i){
        for(ll j=i;j<=N;j+=i) div[j].push_back(i);
    }

    // i/f(i) を値ごとに数え上げる
    vector<ll> cnt(N+1);
    for(ll i=1;i<=N;++i){
        ll f = 0;
        for(ll d:div[i]){
            if(isSq[d]) f = d;
        }
        cnt[ i/f ] += 1;
    }
    // i/f(i) == j/f(j) となる i,j ペアを数え上げる
    ll ans = 0;
    for(ll i=1;i<=N;++i){
        ans += cnt[i] * cnt[i];
    }
    return ans;
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  ll N; cin >> N;
  ll ans = solve(N);
  if(DEBUG){
    ll expect = solveSimply(N);
    printf("expect:%d\n",expect);
    printf("answer:%d\n",ans);
    if(ans!=expect){ printf("Not correct\n");}
  }else{
    cout << ans << '\n';
  }
  return 0;
}