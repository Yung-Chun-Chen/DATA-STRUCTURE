#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int arr[4096][4096]; //input arrar
int is_visited[4096]; //record the node is visited or not

int n; //how many datasets in the following input
int m; // the number of vertices in the given graph
int t; // a vertex index, it represents the entry point of the DFS traversal

void DFS(int t){
    cout << t << " ";
    is_visited[t] = 1;
    for(int i = 0; i < m; i++){
        if(is_visited[i] == 0 && arr[t][i] != 0){
            DFS(i);
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
        DFS(t);
        cout << "\n";
    }
    return 0;
}