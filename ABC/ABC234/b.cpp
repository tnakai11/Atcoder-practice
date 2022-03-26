#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
template<class T> void chmax(T& a, T b){ if(a<b){a=b;} }
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc234/tasks/abc234_b
// 問題の設定では全探索 O(N^2) で十分だが
// 求解に適した線形時間アルゴリズムがあったような気がする
// 見つからない

// (最小のx,y)
// (x,最小のy)
// (最大のx,y)
// (x,最大のy)
// のいずれかが使用されるのは確かなので
// 一応 O(N log N) には落とせる
// ダメだった

struct point{
    ld x,y;
};

bool func1(point p, point q){
    return p.x < q.x;
}
bool func2(point p, point q){
    return p.y < q.y;
}

void solve(){ 
    int N; cin >> N;
    point p[N];
    REP(i,N){
        cin >> p[i].x >> p[i].y;
    }

    ll dd = 0.;
    REP(i,N){
        REP(j,N){
            if(i>=j) continue;
            ll cand = pow(p[i].x - p[j].x,2) + pow(p[i].y-p[j].y,2);
            chmax(dd, cand);
        }
    }

    ld ans = sqrt(dd);
    printf("%.8Lf\n",ans);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}