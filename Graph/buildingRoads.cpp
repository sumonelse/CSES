#include <bits/stdc++.h>
using namespace std;

const long long INF = 4e18;
const int MOD = 1e9 + 7;

using ll = long long;
using vi = vector<int>;

#define ln "\n"
#define REP(i, a, n) for (int i = a; i < n; i++)
#define RREP(i, a, n) for (int i = a; i >= n; i--)
#define PRINTARR(arr, a, n) for (int i = a; i < n; i++) cout << arr[i] << " "; cout << ln;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define PB push_back
#define RB pop_back


void setIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
}

void dfs(int city, vector<bool> &visited, unordered_map<int, vi> &graph){
    // BASE-CASE
    if(visited[city]) return;

    visited[city] = true;

    // Visiting Neighbour City
    for(auto &neighbour : graph[city]){
        dfs(neighbour, visited, graph);
    }
}

int main(){
    setIO();

    int t = 1;
    // cin >> t;

    while (t--){
        int n, m; cin >> n >> m;

        unordered_map<int, vi> graph;

        // Build the Graph
        REP(i, 0, m){
            int a, b; cin >> a >> b;
            graph[a].PB(b);
            graph[b].PB(a);
        }
        
        vector<bool> visited(n + 1, false); // Track Visited City when doing DFS

        int connectedCompCnt = 0; // Count of no. of Connected Components(City)
        vi representativeCities; // Stores a City from each Connected Components(City)

        REP(i, 1, n + 1){
            if(!visited[i]){
                representativeCities.PB(i);
                dfs(i, visited, graph);
                connectedCompCnt++;
            }
        }

        cout << connectedCompCnt - 1 << ln;
        REP(i, 0, representativeCities.size() - 1){
            cout << representativeCities[i] << " " << representativeCities[i + 1] << ln;
        }
    }
    return 0;
}