#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
bool DEBUG = 0;
// https://atcoder.jp/contests/abc283/tasks/abc283_b
// 愚直に更新・出力をすればOK
// 計算量はO(N+Q)
void solve(){ 
    int N; cin >> N;
    int a[N];
    REP(i,N) cin >> a[i];
    int Q; cin >> Q;
    REP(count,Q){
        int num; cin >> num;
        int k; cin >> k;
        --k;
        if(num==1){
            int x; cin >> x;
            a[k] = x;
        }else{
            cout << a[k] << '\n';
        }
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}