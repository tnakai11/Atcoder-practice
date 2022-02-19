#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
#define CINA(a,n) REP(i,(n)){ cin >> (a)[i]; }
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc231/tasks/abc231_c
// 二分探索で O(Q log N)
int N,Q;
ll a[200005];

bool isOK(int index, ll key){
    return a[index] >= key;
}

int binary_search(ll key){
    int ng = N;
    int ok = -1;
    while(abs(ok-ng)>1){
        int mid = (ok+ng)/2;
        if( isOK(mid,key)) ok = mid;
        else ng = mid;
    }
    return ok;
}

void solve(){ 
    cin >> N >> Q;
    CINA(a,N);
    sort(a,a+N,greater<ll>());
    REP(count,Q){
        ll x; cin >> x;
        int ans = binary_search(x) + 1;
        cout << ans << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}