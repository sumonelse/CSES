#include <bits/stdc++.h>
using namespace std;

/*
  Permutations generator that produces unique permutations in lexicographic order.
  Approach:
    - Build a frequency map (std::map<char,int>) of the characters in the input string.
      std::map iterates keys in ascending order, so choosing characters in map order
      yields permutations in lexicographic order.
    - Use recursive backtracking: at each step choose a character with remaining count,
      append it to the current string `cur`, decrement its count, recurse, then backtrack.
    - Collect permutations into a vector<string> (beware: O(n * n!) memory for large n).
*/

const long long INF = 4e18;
const int MOD = 1e9 + 7;

using ll = long long;
using vi = vector<int>;

#define ln "\n"
#define REP(i, a, n) for (int i = a; i < n; i++)
#define RREP(i, a, n) for (int i = a; i >= n; i--)
#define PRINTARR(arr, a, n)     \
    for (int i = a; i < n; i++) \
        cout << arr[i] << " ";  \
    cout << ln;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define PB push_back
#define RB pop_back

void setIO(string name = ""){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (!name.empty())
    {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}


/*
  findPermutations:
    - cur: the current partial permutation being built
    - freq: map<char,int> giving how many of each character remain to use
            (std::map is ordered → ensures lexicographic output order)
    - n: target length (original input length)
    - s: original string (not used in generation; can be removed from signature)
    - permutations: output vector collecting completed permutations

  Method:
    - If cur.size() == n: cur is a complete permutation → store it.
    - Otherwise iterate keys in freq; for each with count > 0:
        * decrement count, append character to cur
        * recurse to fill the next position
        * pop last character and restore count (backtrack)
*/
void findPermutations(string &cur, map<char,int> &freq, int n, vector<string> &permutations){
    // Base case: if current string has length n, we have a complete permutation
    if(cur.size() == n) {
        permutations.PB(cur);
        return;
    }
    
    // Try each character that still has frequency > 0
    for(auto &c : freq){
        char ch = c.first;
        int cnt = c.second;
        if(cnt == 0) continue;

        // Decrement frequency, add character
        freq[ch]--;
        cur.PB(ch);

        // Recurse to fill the next position.
        findPermutations(cur, freq, n, permutations);

        // Backtrack: remove last char and restore count.
        cur.RB();
        freq[ch]++;
    }
}

int main(){
    setIO("");

    int t = 1;
    // cin >> t;

    while (t--){
        string s; 
        cin >> s;

        int n = s.size();
        string cur = "";
        vector<string> permutations;

        // Count frequency of each character
        map<char,int> freq;
        for(char c : s) freq[c]++;

        // Generate all unique permutations
        findPermutations(cur, freq, n, permutations);

        // Output count and all permutations
        cout << permutations.size() << ln;
        for(string &permutation : permutations){
            cout << permutation << ln;
        }
    }
    return 0;
}
