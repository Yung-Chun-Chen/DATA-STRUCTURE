#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    struct node *left, *right;
};

struct node *root = NULL;
vector<int> output;

// Insert a node
struct node *insert(struct node *root, int num) {
    if (root == NULL){ //empty tree
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->val = num;
            temp->left = temp->right = NULL;
            cout << "Number " << num << " is inserted.\n";
            return temp;
    }
    else{
        if (num < root->val){ //insert to left
            root->left = insert(root->left, num); 
        }
        else if(num > root->val){ //insert to right
            root->right = insert(root->right, num);
        }
        else{ //number already exists
            cout << "Error. Number " << num << " exists.\n";
        }
        return root;
    }
}

bool getPath(node* root, vector<int>& arr, int x)
{
    if (!root)
        return false;

    arr.push_back(root->val);

    if (root->val == x)
        return true;

    if (getPath(root->left, arr, x) || getPath(root->right, arr, x))
        return true;

    arr.pop_back();

    return false;
}

void printPathBetweenNodes(node* root, int n1, int n2)
{
    vector<int> path1;
    vector<int> path2;
 
    getPath(root, path1, n1);
    getPath(root, path2, n2);
 
    int intersection = -1;
 
    int i = 0, j = 0;

    while (i != path1.size() || j != path2.size()) {

        if (i == j && path1[i] == path2[j]) {
            i++;
            j++;
        }
        else {
            intersection = j - 1;
            break;
        }
    }
    

    for (int i = path1.size() - 1; i > intersection ; i--)
    {   
        //cout << path1[i] << " ";
        output.push_back(path1[i]);
    }
 
    for (int i = intersection ; i < path2.size(); i++)
    {   
        //cout << path2[i] << " ";
        output.push_back(path2[i]);
    }
}

int main()
{
    root = insert(root,8);
    root = insert(root,1);
    root = insert(root,10);
    root = insert(root,6);
    root = insert(root,5);
    root = insert(root,12);
    root = insert(root,9);
    root = insert(root,7);
    root = insert(root,18);
    root = insert(root,15);
    root = insert(root,2);
    root = insert(root,23);

    int node11 = 8;
    int node12 = 6;
    printPathBetweenNodes(root, node11, node12);

    int node21 = 6;
    int node22 = 23;
    printPathBetweenNodes(root, node21, node22);
    ////////////////////////////////
    int id = 0;
    while(id < output.size() - 1){
        if(output[id] != output[id + 1]){
            cout << output[id] << " ";
        }
        id++;
    }
    cout << output[id] << " ";
    /////////////////////////////////
    return 0;
}