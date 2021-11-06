#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc223/tasks/abc223_c
// 端から端に着くまでにかかる秒数を出して中央を取る
// Acm / (B cm/s ) = (A/B) s 
void solve(){ 
    int N; cin >> N;
    ld a[N],b[N],t[N];

    ld totalTime = 0.;
    REP(i,N){
        cin >> a[i] >> b[i];
        t[i] = a[i]/b[i];
        totalTime += t[i];
    } 

    ld objectiveTime = totalTime/2.;
    ld time = 0.;
    ld ans = 0.;
    REP(i,N){
        if(time+t[i]<objectiveTime){
            time += t[i];
            ans += a[i];
        }else{
            ld restTime = objectiveTime - time;
            ans += restTime * b[i];
            break;
        }
    }
    cout << setprecision(10) << ans << '\n';

}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}