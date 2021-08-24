#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
bool DEBUG = 0;
template<class T> void dprint(T s){
  if(DEBUG){ cout << s << "\n"; }
}
// https://atcoder.jp/contests/abc215/tasks/abc215_c
// |S|<=8 より全列挙しても高々 8!  = 40320 パターン
// 重複に注意
// AC
// そもそも next_permutation は重複を除いて辞書順に出力してくれるらしい
string s;
int K;
map<string,int> mp;
vector<string> v;
void solve(){ 
    cin >> s >> K;
    sort(ALL(s));
    do {
        ++mp[s];
        if(mp[s]>1) continue;
        v.emplace_back(s);
    } while (next_permutation(ALL(s)));
    sort(ALL(v));
    cout << v[K-1] << '\n';
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){ DEBUG = 1;}
  solve();
  return 0;
}