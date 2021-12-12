#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<queue>
using namespace std;

int is_visited[4096];
int arr[4096][4096];
int n, m, t; //n:how many datasets are in the following input
             //m: the number of vertices in the given graph.
             //t:a vertex index, it represents the entry point of the BFS traversal.

void BFS(int t){
    queue<int> q;
    q.push(t);
    is_visited[t] = 1;
    while(!q.empty()){
        t = q.front(); //t will change so bfs doesn't need recursive
        cout << t << " ";
        q.pop();
        for (int i = 0; i < m; i++) {
            if (arr[t][i] && !is_visited[i]){ 
                q.push(i);
                is_visited[i] = 1;
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> m >> t;
        memset(is_visited, 0, sizeof(is_visited));
        for(int j = 0; j < m; j++){
            for(int k = 0; k < m; k++){
                cin >> arr[j][k];
            }
        }
        BFS(t);
        cout << "\n";
    }
    return 0;
}