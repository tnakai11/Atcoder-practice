#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }

bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc235/tasks/abc235_d
// 探索する範囲が狭いので多分再帰を使った全探索でいける
// 掛けるより割る方が選択肢が狭いので N から 1 へ迎えに行く

// after contest で引っかかった...
// 全探索できていなかったっぽい？

// map を導入し計算時間を落とすことはできたが WA が取れない
// 解説を読む
// BFS のほうが楽ですね...

ll a, N; 
map<ll,ll> mp;
ll func(ll x, ll m){
    if(x==1) return m;

    string s = to_string(x);
    int L = s.size();
    if(L==1 && x%a>0) return -1;

    ll ans = -1;
    REP(i,L){
        dprint(to_string(m) + "," + s);
        ll temp = stoi(s);
        if(mp[temp]==0){
            mp[temp] = m;
        }else{
            if(mp[temp]<=m){
                continue;
            }else{
                mp[temp] = m;
            }
        }
        if(temp%a==0){
            ll r = func(temp/a,m+1);
            if(r>=0){
                if(ans==-1){
                    ans = r;
                }else{
                    chmin(ans,r);
                }
            }
        }
        if(s[1]!='0'){
            s = s.substr(1,L-1) + s.substr(0,1);
            ++m;
        }else{
            break;
        }
    }
    return ans;
}

void solve(){ 
    cin >> a >> N;
    ll ans = func(N,0);
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}