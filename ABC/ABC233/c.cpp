#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc233/tasks/abc233_c
// ボールの個数が 10^5 以下なので N <= 5 * 10^4 
// 全パターンの調査は 2^(5*10^4) などがあるので無理
// DP で行きたい
void solve(){ 
    ll N,X; cin >> N >> X;
    map<ll,ll> mp[50005];

    vector<ll> v;

    v.push_back(X);
    mp[0][X] = 1;

    REP(i,N){
        ll L; cin >> L;
        vector<ll> w;
        REP(count,L){
            ll a; cin >> a;
            if(a>1 && gcd(X,a)==1) continue;
            for(auto e:v){
                if(e%a==0){
                    ll k = e/a;
                    if(mp[i+1][k]==0){
                        w.push_back(k);
                    }
                    mp[i+1][k] += mp[i][e];
                }
            }
        }
        v.resize(w.size());
        REP(i,w.size()) v[i] = w[i];
    }

    cout << mp[N][1] << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}