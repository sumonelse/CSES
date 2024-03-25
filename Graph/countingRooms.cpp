#include<iostream>
#include<vector>
using namespace std;

bool inBnd(int x, int y, int n, int m){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y, int n, int m, vector<vector<char>> &map, vector<vector<bool>> &visited, int *dx, int *dy){
    visited[x][y] = true;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(inBnd(nx, ny, n, m) && map[nx][ny] == '.' && !visited[nx][ny]){
            dfs(nx, ny, n, m, map, visited, dx, dy);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
        }
    }

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int roomCnt = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(map[i][j] == '#' || visited[i][j]) continue;
            dfs(i, j, n, m, map, visited, dx, dy);
            roomCnt++;
        }
    }

    cout << roomCnt << endl;
}