#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
bool DEBUG = 0;
// https://atcoder.jp/contests/abc305/tasks/abc305_d
// 累積和でレコードAi記録時の睡眠時間を計算する O(N)
// l,rの近くにあるレコードを二部探索で探してクエリに答える O(QlogN)
void solve(){ 
    int N; cin >> N;
    vector<ll> a(N);
    vector<ll> sCumu(N);
    REP(i,N) cin >> a[i];
    REP(i,N){
        if(i==0) continue;
        if(i%2==1) { // 就寝
            sCumu[i] = sCumu[i-1];
        } else { // 起床
            ll duration = a[i] - a[i-1];
            sCumu[i] = sCumu[i-1] + duration;
        }
    }
    int Q; cin >> Q;
    REP(q,Q){
        ll l,r; cin >> l >> r;
        // l,a[idxX],r,a[idxY]となるように探索してギャップを埋める
        int idxX = distance(a.begin(), lower_bound(ALL(a),l));
        ll addX;
        if(idxX%2==1){ // 就寝
            addX = 0;
        }else{ // 起床
            addX = a[idxX]-l;
        }
        int idxY = distance(a.begin(), lower_bound(ALL(a),r));
        ll minusY;
        if(idxY%2==1){ // 就寝
            minusY = 0;
        }else{ // 起床
            minusY = a[idxY]-r;
        }
        ll ans = sCumu[idxY] - sCumu[idxX] + addX - minusY;
        cout << ans << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}