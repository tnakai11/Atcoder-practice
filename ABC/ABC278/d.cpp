#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool DEBUG = 0;
// https://atcoder.jp/contests/abc278/tasks/abc278_d
// 操作1によるリセットをどうするか
// バージョン管理すればO(N+Q)でいけそう
struct obj {
    ll value;
    int version;
};
void solve(){ 
    int N; cin >> N;
    ll base = 0;
    int version = 0;
    obj a[N+1];
    for(int i=1;i<=N;++i){
        ll value; cin >> value;
        a[i] = {value,version};
    }
    int Q; cin >> Q;
    while(Q--){
        int m; cin >> m;
        if(m==1){
            ll x; cin >> x;
            base = x;
            ++version;
            continue;
        }
        if(m==2){
            int i; ll x; cin >> i >> x;
            if(a[i].version==version){
                a[i].value += x;
            }else{
                a[i] = {base+x, version};
            }
            continue;
        }
        int i; cin >> i;
        ll ans;
        if(a[i].version==version){
            ans = a[i].value;
        }else{
            ans = base;
        }
        cout << ans << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}