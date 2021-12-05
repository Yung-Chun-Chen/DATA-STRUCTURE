#include<iostream>
#include<queue>
#include<string.h>
#include<string>
#include<fstream>
#include <bits/stdc++.h>

using namespace std;

struct node {
    int val;
    struct node *left, *right;
};
struct node *root = NULL;
struct node *r = NULL;

void preorder(struct node *root) { //prefix order
    if (root != NULL) {
        // Traverse root
        cout << root->val << " ";
        // Traverse left
        preorder(root->left);
        // Traverse right
        preorder(root->right);
    }
}

void inorder(struct node *root) { //infix order
  if (root != NULL) {
    // Traverse left
    inorder(root->left);
    // Traverse root
    cout << root->val << " ";
    // Traverse right
    inorder(root->right);
  }
}

void postorder(struct node *root) { //postfix order
    if (root != NULL) {
        // Traverse left
        postorder(root->left);
        // Traverse right
        postorder(root->right);
        // Traverse root
        cout << root->val << " ";
    }
}

void levelorder(struct node *root){ //level order
    queue<node *> q;
    q.push(root);               
    while (!q.empty()){  
        struct node *current = q.front();
        q.pop(); //pop front node 
        cout << current->val << " ";  // visiting
        if (current->left != NULL){   //if current node has left child, push it
            q.push(current->left);
        }
        if (current->right != NULL){   //if current node has right child, push it
            q.push(current->right);
        }
        //current = q.front();
    }
}

struct node *minValueNode(struct node *root) {
    struct node *current = root;

    // Find the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct node *find(int x) {
    struct node *current = root;
    while(current->val != x){
        if(current != NULL){
            if(current->val > x){
                current = current->left;
            }  //else go to right tree
            else {                
                current = current->right;
            }
            if(current == NULL){
                return NULL;
            }
        }
    }
    return current;      
}

// Delete a node
struct node *deleteNode(struct node *root, int num) {
    if (root == NULL){ //empty BST
        return root;
    }
    // Find the node to be deleted
    if (num < root->val){
        root->left = deleteNode(root->left, num);
    }
    else if (num > root->val){
        root->right = deleteNode(root->right, num);
    }

    else {
        // If the node is with only one child or no child
        if(!root->left || !root->right){
            struct node *tmp = root->left ? root->left : root->right;
            free(root);
            return tmp;
        }

        // If the node has two children
        
            struct node *temp = root->right;
            while(temp->left) temp=temp->left;
            // Place the inorder successor in position of the node to be deleted
            root->val = temp->val;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->val);
        
    }
    return root;
}

void delete_BST(){ //delete a number main function
    int num = 0;
    cout << "Enter numbers to be deleted : " ;
    while(true){
        cin >> num;
        if(num != -1){

            r = find(num); //check whether the node is exits.
            if(r == NULL){
                cout << "Number " << num << " is not exists.\n";
            }
            else{
                cout << "Number " << num << " is deleted.\n";
            }

            root = deleteNode(root, num);
        }
        else{
            break;
        }
    }
}

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

// Insert a node part2
struct node *insert_part2(struct node *root, int num) {
    if (root == NULL){ //empty tree
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->val = num;
            temp->left = temp->right = NULL;
            return temp;
    }
    else{
        if (num < root->val){ //insert to left
            root->left = insert_part2(root->left, num); 
        }
        else if(num > root->val){ //insert to right
            root->right = insert_part2(root->right, num);
        }
        else{ //number already exists
        }
        return root;
    }
}

void insert_BST(){ //Insert a number main function
    
    int num;
    cout << "Enter numbers: " ;
    while(true){
        cin >> num;
        if(num != -1){
            root = insert(root, num);
        }
        else{
            break;
        }
    }
}

void search_BST(){ //search a number main function
    int num = 0;
    cout << "Enter elements to searching : " ;
    while(true){
        cin >> num;
        if(num != -1){
            r = find(num); //check whether the node is exits.
            if(r == NULL){
                cout << "SORRY. " << num << " is not found.\n";
            }
            else{
                cout << "Bingo! " << num << " is found.\n";
            }
        }
        else{
            break;
        }
    }
}

void print_BST(){ //print 4 kinds of orders main function
    cout << "The tree in prefix order : ";
    preorder(root);
    cout << "\n";
    cout << "The tree in infix order : ";
    inorder(root);
    cout << "\n";
    cout << "The tree in post order : ";
    postorder(root);
    cout << "\n";
    cout << "The tree in level order : ";
    levelorder(root);
    cout << "\n";
}

void part_1(){ //BST operation
    while(1){
        char option;
        cout << "(I)nsert a number.\n" ;
        cout << "(D)elete a number.\n" ;
        cout << "(S)earch a number.\n" ;
        cout << "(P)rint 4 kinds of orders.\n" ;
        cout << "(R)eturn.\n" ;
        cin >> option;
        if(option=='r'){
            return;
        }
        else if(option == 'i'){
            insert_BST();
        }
        else if(option == 'd'){
            delete_BST();
        }
        else if(option == 's'){
            search_BST();
        }
        else if(option == 'p'){
            print_BST();
        }
    }
}

vector<int> output;
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

void part_2(){ //Finding Meaty
    struct node *root_part2 = NULL;
    string filename;
    int number;
    cout << "Please input the map file:";
    cin >> filename;

    if(!filename.empty()){
        ifstream input_file(filename);
        if (!input_file.is_open()) {
            cout << "Could not open the file '" << filename << "'" << endl;
            return ;
        }
        cout << "Load file success.\n";
        while (input_file >> number) {
            root_part2 = insert_part2(root_part2 , number);
        }
        cout << endl;
        input_file.close();
        cout << "Please input the sword location:"; //sword position
        int sword_pos;
        cin >> sword_pos;

        cout << "Please input the Meaty's location:"; //Meaty's position
        int Meaty_pos;
        cin >> Meaty_pos;

        cout << "Please input the broccoli trap's index (0~9):"; //trap's index
        int trap_index;
        cin >> trap_index;
        cout << endl;
        string node_trap;

        ifstream input(filename);
        while (input >> number) {
            node_trap = to_string(number);
            for(int i = 0; i < node_trap.length(); i++){
                if(node_trap[i] == trap_index+'0'){
                    cout << "Number " << number << " is deleted.\n";
                    root_part2 = deleteNode(root_part2 , number);
                    break;
                }
            }
        }
        cout << endl;
        input.close();

        cout << "Capoo successfully found his favorite meaty<3.\n\n";
        cout << "Shortest path to find the meaty : \n";
        int node11 = root_part2->val;
        int node12 = sword_pos;
        printPathBetweenNodes(root_part2, node11, node12);

        int node21 = sword_pos;
        int node22 = Meaty_pos;
        printPathBetweenNodes(root_part2, node21, node22);

        int id = 0;
        while(id < output.size() - 1){ //output shortest path
            if(output[id] != output[id + 1]){
                cout << output[id] << "->";
            }
            id++;
        }
        cout << output[id] << "\n";

        vector <int>().swap(output);    //clear up output
        int j = output.capacity();           
        int i = output.size();       
    }

    else{

    }
}

int main()
{
    while(1){
        int option;
        cout << "(1) Binary searching Tree.\n" ;
        cout << "(2) Finding Meaty.\n" ;
        cout << "(0) Escape and face to music next year.\n" ;
        cin >> option;
        if(option==0){
            return 0;
        }
        else if(option == 1){
            root = NULL;
            r = NULL;
            part_1();
        }
        else if(option == 2){
            part_2();
        }
    }
  return 0;
}