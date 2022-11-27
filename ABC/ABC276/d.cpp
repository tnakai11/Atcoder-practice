#include <bits/stdc++.h>
using namespace std;
bool DEBUG = 0;
typedef long long ll;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
template<class T> void chmin(T& a, T b){ if(a>b){a=b;} }
// https://atcoder.jp/contests/abc276/tasks/abc276_d
// それぞれの値を素因数分解して、均すのに必要な操作数を数える
// 2,3以外の素因数の数が一致しなければアウト
// 素因数を控えるのが面倒なので均してみてから判定する O(N log A)
int findMin(vector<int> v){
    int res = v[0];
    for(auto x:v){
        chmin(res,x);
    }
    return res;
}

void solve(){ 
    int N; cin >> N;
    vector<ll> a(N); REP(i,N) cin >> a[i];
    vector<int> two(N,0);
    vector<int> three(N,0);
    map<ll,int> other;
    REP(i,N){
        ll x = a[i];
        while(x%2==0){
            x /= 2;
            ++two[i];
        }
        while(x%3==0){
            x /= 3;
            ++three[i];
        }
    }
    int twoMin = findMin(two);
    int threeMin = findMin(three);

    int ans = 0;
    REP(i,N){
        int twoDiff = two[i]-twoMin;
        int threeDiff = three[i]-threeMin;

        ans += twoDiff + threeDiff;

        REP(count,twoDiff){
            a[i] /= 2;
        }
        REP(count,threeDiff){
            a[i] /= 3;
        }
    }
    REP(i,N){
        if(a[i]!=a[0]){
            cout << -1 << '\n';
            return;
        }
    }
    cout << ans << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}