#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }
bool DEBUG = 0;
// https://atcoder.jp/contests/abc279/tasks/abc279_d
// 超能力をn回使ったとするとかかる時間 t は
// t = A/(sqrt(1+n)) + nB
// dt/dn = -A/{2(1+n)sqrt(1+n)} + B
// n = 0 の場合　dt/dn = -A/2 + B
// -A/2+B>=0 ... 単調に増加するのでn=0のパターンが最小
// -A/2+B<0 ... 下に凸なので極値周辺が最小値
// A/2B = (1+n)sqrt(1+n)
// (A/2B)^2 = (1+n)^3
// n = (A/2B)^(2/3) -1
ld A,B; 
ld solve(){ 
    if(B*2>=A){
        return A;
    }
    ld ans = A;
    ld x = pow(A/B/2,2./3.)-1;
    if(DEBUG)cout << x << '\n';
    for(ll n = max((ll)x-5,0LL);n<=(ll)x+5;++n){
        ld cand = A/sqrt(n+1) + B*n;
        chmin(ans,cand);
    }
    return ans;
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  cin >> A >> B;
  cout <<  std::fixed << std::setprecision(10) << solve() << '\n';
  return 0;
}