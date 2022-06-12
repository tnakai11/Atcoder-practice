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
// 愚直に解くとO(N^3)
// Ai=r, Aj=p, Ak=q  を満たす(i,j,k) の数：count(r) * count(p) * count(q)
// Aj,Ak は Aiの約数
// 各Aiについて条件を満たす (p,q) の数を計算する
void solveSimply(int N, vector<int> a){
    ll ans = 0;
    REP(i,N){
        REP(j,N){
            REP(k,N){
                if(a[i]==a[k]*a[j]) ++ans;
            }
        }
    }
    cout << ans << '\n';
}

const int MAX = 200005;
void solve(int N, vector<int> a){
    // count
    map<int,ll> count;
    for(int p:a) ++count[p];

    // exhaustive search about i
    ll ans = 0LL;
    for(int p:a){
        // find dividers
        vector<int> divs;
        for(int i=1;i*i<=p;++i){
            if(p%i>0) continue;
            ll x = i;
            divs.emplace_back(x);

            ll y = p/i;
            if(x!=y){
                divs.emplace_back(y);
            }
        }
        sort(ALL(divs));
        if(DEBUG) REP(i,divs.size()) printf("%d %c",divs[i],(i<(divs.size()-1)?' ':'\n'));
        // sum
        for(int div: divs){
            ans += count[ div ] * count[ p/div ];
        }
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  int N; cin >> N;
  vector<int> a(N); REP(i,N) cin >> a[i];
  if(DEBUG) solveSimply(N,a);
  solve(N,a);
  return 0;
}