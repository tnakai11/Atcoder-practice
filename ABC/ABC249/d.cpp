#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc249/tasks/abc249_d
// とりあえず式変形してみる
// Ai/Aj = Ak
// <-> Ai = Ak*Aj
// Ak*Aj を全パターン控えようとすると O(N^2) となり厳しい
// エッジケース 1,...,1 
// エッジケース 1,2,...,N
// N = 2*10^5 の場合 割と早く終わりそう
// 重複する部分をまとめた配列で計算してみる
// 一部 TLE です
struct block {
    ll value;
    ll count;
};
void solve(){ 
    ll N; cin >> N;
    vector<ll> a(N); REP(i,N) cin >> a[i];
    sort(ALL(a));
    vector<block> v;
    block temp = {0,0};
    for(ll e:a){
        if(temp.value==0){
            temp = {e,1}; 
            continue;
        }
        if(temp.value==e){
            temp.count += 1;
        }else{
            v.emplace_back(temp);
            temp = {e,1};
        }
    }
    v.emplace_back(temp);
    dprint(v.size());

    ll ans = 0;
    for(int i=0;i<v.size();++i){
        for(int j=0;j<=i;++j){
            for(int k=0;k<=j;++k){
                ll target = v[i].value;
                ll cand = v[j].value * v[k].value;
                if(target<cand) break;
                if(target==cand) {
                    if(i==j){
                        if(j==k){
                            ll x = v[i].count;
                            ans += x*x*x; // i==j==k
                        }
                        else{
                            ll x = v[i].count;
                            ll z = v[k].count;
                            ans += x*x * z * 2;  // j<k or k<j
                        } 
                    }else{
                        if(j==k){
                            ll x = v[i].count;
                            ll y = v[j].count;
                            ans += x * y * y; // j=k
                        }else{
                            ll x = v[i].count;
                            ll y = v[j].count;
                            ll z = v[k].count;
                            ans += x * y * z * 2; // j<k or k<j
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';

}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}