#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPR(i,n) for(int i=n; i>-1; --i)
#define ALL(a) (a).begin(),(a).end()
#define FILL(a,n,x) REP(i,(n)){ (a)[i]=(x); }
#define CINA(a,n) REP(i,(n)){ cin >> (a)[i]; }
#define FILL2(a,n,m,x) REP(i,(n)){ REP(j,(m)){(a)[i][j]=(x);} }
#define CINA2(a,n,m) REP(i,(n)){ REP(j,(m)){cin >> (a)[i][j];} }
#define Liny "Yes\n"
#define Linn "No\n"
#define LINY "YES\n"
#define LINN "NO\n"
int ctoi(char c){ return ( (c>='0' && c<='9')? c - '0': 0 );}
int __stoi(string s){ return atoi(s.c_str()); }
ll gcd(ll a,ll b){if(a<b)swap(a,b); return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){if(a<b){swap(a,b);} return a/gcd(a,b)*b;}
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }
template<class T> bool isIn(T a,vector<T> v){ for(T x:v){ if(a==x){return true;}} return false;}
using mint = modint998244353;
// const ll MOD = 1e9+7;
// using mint = static_modint<MOD>;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define MP make_pair
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc218/tasks/abc218_d
// nC4 で調べるのはさすがにきつい
// x 座標ごとに y1,y2 ペアを保管 数え上げもしておく
// y1,y2 ペアごとにx座標の組み合わせ数を計算し総和をとる
pll p[2005];
map<pll,ll> mp;
vector<pll> v;
void solve(){ 
    int N; cin >> N;
    REP(i,N) cin >> p[i].first >> p[i].second;
    sort(p,p+N);
    REP(start,N){
        ll x = p[start].first;
        int end=start;
        while(end<N && x==p[end].first) ++end;
        --end;
        dprint(start);
        dprint(end);
        for(int i=start;i<=end;++i){
            ll yi = p[i].second;
            for(int j=i+1;j<=end;++j){
                ll yj = p[j].second;
                pll key = MP(yi,yj);
                if(mp[key]==0) v.emplace_back(key);
                ++mp[key];
            }
        }
        start = end;
    }
    dprint("ok");
    ll ans = 0LL;
    for(auto key:v){
        dprint(mp[key]);
        ll cnt = mp[key];
        ans += cnt*(cnt-1)/2;
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}