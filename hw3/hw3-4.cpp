#include<iostream>
#include<stdlib.h>
#include <algorithm>
using namespace std;
#define LL long long //save time(for very big input)

struct node{
    LL u, v, c; //Each line contains three numbers u, v, and c
                //u : from
                //v : to
                //c : cost
};

node arr[999999];
LL root[999999], rankk[999999];
LL ver, edge; //ver : vertices count, edge : the number of edges in this undirected graph

int cmp(const void* a, const void* b){
    return ((node*)a)->c - ((node*)b)->c;
}

LL find(LL x){ //find the parent of node x
/* Make the parent of the nodes in the path
           from x--> parent[x] point to parent[x] */
    if(root[x] == x){
        return x;
    }
    else{
        return (root[x] = find(root[x]));
    }
}

void unionn(LL x, LL y){ // Union by rank
    x = find(x);
    y = find(y);
    if (rankk[x] < rankk[y]){
        root[x] = y;
    }
    else{
        root[y] = x;
        if(rankk[x] == rankk[y]){
            rankk[x] += 1;
        }
    }
}

LL Kruskal(){
    LL cnt = 0; //count processed edge 
    LL ans = 0;
    qsort(arr, edge, sizeof(node), cmp);
    for(LL i = 0; i < edge && cnt != edge - 1; i++){
        if(find(arr[i].u) != find(arr[i].v)){
            unionn(arr[i].u, arr[i].v);
            ans += arr[i].c;
            cnt++;
        }
    }
    return ans;
}

int main(){
    cin >> ver >> edge;
    for (LL i = 1; i <= ver; i++){
        root[i] = i, rankk[i] = 0;
    }

    for(LL i = 0; i < edge; i++){
        cin >> arr[i].u >> arr[i].v >> arr[i].c;
    }
    cout << Kruskal() << "\n";
    return 0;
}