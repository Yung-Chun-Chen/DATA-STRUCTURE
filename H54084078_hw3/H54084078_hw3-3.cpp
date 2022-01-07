#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<fstream>
using namespace std;

ifstream fin;
ofstream fout;

long is_visited[99999];
long arr[1000][1000];
long n, m, t; //n:how many datasets are in the following input
             //m: the number of vertices in the given graph.
             //t:a vertex index, it represents the entry point of the BFS traversal.

void BFS(long t){
    queue<long> q;
    q.push(t);
    is_visited[t] = 1;
    while(!q.empty()){
        t = q.front(); //t will change so bfs doesn't need recursive
        fout << t << " ";
        q.pop();
        for (long i = 0; i < m; i++) {
            if (arr[t][i] && !is_visited[i]){ 
                q.push(i);
                is_visited[i] = 1;
            }
        }
    }
}

int main(){
    string fileName;
    cout << "enter filename : ";
    while(cin >> fileName){
        int filelen = fileName.length();
        fin.open(fileName); //read file

        string out = fileName.substr(5,filelen);//determine output filename
        fout.open("output" + out);
        fin >> n;
        for(long i = 0; i < n; i++){
            fin >> m >> t;
            memset(is_visited, 0, sizeof(is_visited));
            for(long j = 0; j < m; j++){
                for(long k = 0; k < m; k++){
                    fin >> arr[j][k];
                }
            }
            BFS(t);
            fout << "\n";
        }
        memset(arr,0,sizeof(arr));
        memset(is_visited,0,sizeof(is_visited));
        cout << "enter filename : ";
        fin.close();
        fout.close();
    }
    return 0;
}