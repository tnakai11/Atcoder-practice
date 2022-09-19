#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define CINA(a,n) for(int i=0, i##_len=(n); i<i##_len; ++i) cin >> a[i];
#define ALL(a) (a).begin(),(a).end()
bool DEBUG = 0;
// https://atcoder.jp/contests/abc268/tasks/abc268_d
// 愚直にXを構成する場合 O(N! M) かかる
// N<= 8! = 40320 と M<=10^5 より愚直は間に合わない
// 挿入されるアンダーバーが1つ以上なのも面倒
// 検証をmapでやれば O(N! log M) に抑えられるのでは
int N,M; 
int usedMax;
map<string,int> mp;
vector<string> ans;
void func(vector<string> v, int index, string value, int used){
    if(index==N-1){
        value += v[index];
        if(value.size()<3) return;
        if(value.size()>16) return;
        if(mp[value]>0) return;
        ans.emplace_back(value);
        return;
    }
    for(int k=1;k<=(usedMax-used);++k){
        string next = value + v[index] + string(k,'_');
        if(next.size()>=16) break;
        func(v, index+1, next, used+k);
    }
}
void solve(){ 
    // input
    cin >> N >> M;
    vector<string> s(N);
    CINA(s,N);
    REP(bar, M){
        string t; cin >> t;
        ++mp[t];
    }
    // setup
    int count = 0;
    REP(i,N){
        count += s[i].size();
    }
    usedMax = 16 - count;
    // 総当たり
    sort(ALL(s));
    do {
        if(DEBUG) cout << s[0] << '\n';
        func(s,0,"",0);
        if(ans.size()>0) break;
    } while(next_permutation(ALL(s)));

    // 解答
    if(ans.size()){
        cout << ans[0] << '\n';
    }else{
        cout << -1 << '\n';
    }
}
int main(int argc, char *argv[]){
  if(argc>1 && argv[1][0]=='D'){DEBUG = 1;}
  solve();
  return 0;
}