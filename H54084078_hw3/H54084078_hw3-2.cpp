#include<iostream>
#include<stdlib.h>
#include<string.h>
#include <fstream>
#include<climits>
using namespace std;

ifstream fin;
ofstream fout;
long arr[1000][1000]; //input arrar
long is_visited[99999]; //record the node is visited or not

long n; //how many datasets in the following input
long m; // the number of vertices in the given graph
long t; // a vertex index, it represents the entry point of the DFS traversal


void DFS(long t){
    //cout << t << " ";
    fout << t << " ";
    is_visited[t] = 1;
    for(long i = 0; i < m; i++){
        if(is_visited[i] == 0 && arr[t][i] != 0){
            DFS(i);
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
            DFS(t);
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