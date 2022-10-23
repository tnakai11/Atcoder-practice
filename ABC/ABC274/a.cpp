#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
// https://atcoder.jp/contests/abc274/tasks/abc274_a
// 出力形式に注意する
void solve(){ 
    int A,B; cin >> A >> B; 
    int K = 10000;
    int x = B*K/A;
    if(x%10>=5) ++x;
    double ans = (double)x/K;
    printf("%.3f\n",ans);
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}