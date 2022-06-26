#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;
#define pll pair<ll,ll>
#define MP make_pair
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc257/tasks/abc257_d
// 行き来するのに必要なコストが最小となるようにジャンプ台をつなぐ
// Sについて２部探索？
// S を決め打ち全ジャンプ台に到達可能か幅優先探索(O(N^2))で判定
// スタート位置によって結果が違う...?  O(N^3 log max(S))
struct board {
    ll x,y,p;
};
int N; 
board v[205];
bool isOK(ll s){
    REP(start,N){
        // setup
        queue<int> q;
        map<int,int> mp;
        int count = 0;
        q.push(start);
        ++mp[start];
        ++count;

        // BFS
        while(!q.empty()){
            board b = v[q.front()]; 
            q.pop();
            ll jumpableDistance = b.p * s;
            REP(i,N){
                if(mp[i]) continue;
                board c = v[i];
                ll distance = abs(b.x-c.x) + abs(b.y-c.y);
                if(jumpableDistance >= distance){
                    q.push(i);
                    ++mp[i];
                    ++count;
                }
            }
        }

        // result
        if(count==N) return true;

    }
    return false;
}
void solve(){ 
    cin >> N;
    REP(i,N){
        board b;
        cin >> b.x;
        cin >> b.y;
        cin >> b.p;
        v[i] = b;
    }
    ll ok = 1e10;
    ll ng = 0;
    while(abs(ok-ng)>1){
        ll mid = (ok+ng)/2;
        if(isOK(mid)){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout << ok << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}