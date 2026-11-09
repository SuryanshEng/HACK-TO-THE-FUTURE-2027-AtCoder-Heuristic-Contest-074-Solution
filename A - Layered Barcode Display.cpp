#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K, P, R;
    cin >> N >> K >> P >> R;
    vector<string> A(P);
    for(auto &s : A) cin >> s;

    for(int k = 0; k < K; k++){
        string s(N, '.');
        if(k < N) s[k] = '1';
        else if(k < 2 * N) s[k - N] = '0';
        cout << s << "\n";
    }
    cout << flush;

    vector<int> cur(N, 1);
    for(int r = 0; r < R; r++){
        int a;
        if(!(cin >> a) || a < 0) return 0;
        vector<pair<int,int>> ops;
        for(int j = 0; j < N; j++){
            int want = A[a][j] - '0';
            if(cur[j] != want){
                int sheet = cur[j] ? j : N + j;
                ops.push_back({sheet, K - 1});
                cur[j] = want;
            }
        }
        cout << ops.size() << "\n";
        for(auto &o : ops) cout << o.first << " " << o.second << "\n";
        cout << flush;
    }
}