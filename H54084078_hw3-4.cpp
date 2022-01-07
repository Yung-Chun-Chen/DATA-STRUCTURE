#include<iostream>
#include<stdlib.h>
#include <algorithm>
#include<string.h>
#include<fstream>
using namespace std;

#define max 2000000

ifstream fin;
ofstream fout;
struct node{
    long long from;       //from : from
    long long to;       //to : to     
    long long c;       //c : cost           
};

struct node array[max];
long long root[max], rankk[max];
long long ver, edge; //ver : vertices count, edge : the number of edges in this undirected graph

long long find(long long val){ //find the parent of node x
/* Make the parent of the nodes in the path
           from x--> parent[x] point to parent[x] */
    // if(root[x] == x){
    //     return x;
    // }
    // else{
    //     return (root[x] = find(root[x]));
    // }
    return root[val] == val ? val : (root[val] = find(root[val]));
}

void unionn(long long i, long long j){ // Union by rank
    i = find(i);
    j = find(j);
    if (rankk[i] < rankk[j]){
        root[i] = j;
    }
    else{
        root[j] = i;
        if(rankk[i]==rankk[j]){
            rankk[i]+=1;
        }
        
    }
}

int cmp(const void* a, const void* b){
    return ((struct node*)a)->c - ((struct node*)b)->c;
}

long long Kruskal(){
    long long cnt = 0; //count processed edge 
    long long ans = 0;
    qsort(array, edge, sizeof(struct node), cmp);
    for(long long i = 0; i < edge && cnt != edge - 1; i++){
        if(find(array[i].from) != find(array[i].to)){
            unionn(array[i].from, array[i].to);
            ans += array[i].c;
            cnt++;
        }
    }
    return ans;
}

int main(){
    string fileName;
    cout << "enter filename : ";
    while(cin >> fileName){
        int filelen = fileName.length();
        fin.open(fileName); //read file

        string out = fileName.substr(5,filelen);//determine output filename
        fout.open("output" + out);

        fin >> ver >> edge;
        for (long long i = 1; i <= ver; i++){
            root[i] = i, rankk[i] = 0;
        }

        for(long long i = 0; i < edge; i++){
            fin >> array[i].from >> array[i].to >> array[i].c;
        }
        long long ret = Kruskal();
        fout << ret << "\n";
        memset(root,0,sizeof(root));
        memset(rankk,0,sizeof(rankk));
        cout << "enter filename : ";
        fin.close();
        fout.close();
    }
    return 0;
}