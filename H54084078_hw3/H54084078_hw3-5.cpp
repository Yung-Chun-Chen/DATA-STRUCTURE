#include<fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#define max 20000000
using namespace std;

ifstream fin;
ofstream fout;

struct edge { //edge
    int origin;
    int dst;
    int c;
};

struct edge Edge[max];
int m;
int t;
int cnt = 0;
int arr[max];
int is_visited[max];
int ans[max];

void dfs(int x){ //visited
    is_visited[x] = 1;
    for (int i = arr[x]; ~i; i = Edge[i].dst){
        if (is_visited[Edge[i].origin] == 0){
            ans[Edge[i].origin] += (Edge[i].c + ans[x]);
            dfs(Edge[i].origin);
        }
    }
    return;
}

void addedge(int origin, int dst, int c){ //add edge
    Edge[cnt].origin = dst;
    
    Edge[cnt].c = c;
    
    Edge[cnt].dst = arr[origin];
    arr[origin] = cnt++;
}

int main(){
    string fileName;
    cout << "enter filename : ";
    while(cin >> fileName){
        int filelen = fileName.length();
        fin.open(fileName); //read file

        string out = fileName.substr(5,filelen);//determine output filename
        fout.open("output" + out);
    
        fin >> m;
        cnt = 0;
        memset(arr, -1, sizeof(arr));
        memset(ans, 0, sizeof(ans));
        for (int i = 1, origin, dst, c; i <= m - 1; i++) {
            fin >> origin >> dst >> c;
            addedge(origin, dst, c);
            addedge(dst, origin, c);
        }
        fin >> t;
        ans[t] = 0;
        
        dfs(t); //visit
        for (int i = 1; i <= m; i++){
            fout << i << " " << ans[i] << "\n";
        }
           
        memset(is_visited,0,sizeof(is_visited));
        cnt = 0;
        fin.close();
        fout.close();
        cout << "enter filename : ";
    }
    return 0;
}