#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc216/tasks/abc216_c
// 概ね2進数
// 2^60 > 1e18 なのでたぶん工夫は要らない
void solve(){ 
    ll N; cin >> N;
    vector<string> v;
    while(N>0){
        if(N%2==1){
            N -= 1;
            v.emplace_back("A");
        }else{
            N /= 2;
            v.emplace_back("B");
        }
    }
    for_each(v.rbegin(),v.rend(),[](auto&& s){
        cout << s;
    });
    cout << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}