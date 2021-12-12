#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

void post_to_pre(int* in, int* post, int len){ //postfix to prefix
    if (len > 0) {
        for (int i = len; i >= 0; i--) {
            if (*(in + i) == *(post + len - 1)) {
                printf("%d ", *(post + len - 1));
                post_to_pre(in, post, i);
                post_to_pre(in + i + 1, post + i, len - i - 1);
                return;
            }
        }
    }
}

void pre_to_post(int* in, int* pre, int len){ //prefix to postfix
    if (len > 0) {
        for (int i = 0; i < len; i++) {
            if (*(in + i) == *pre) {
                pre_to_post(in, pre + 1, i);
                pre_to_post(in + i + 1, pre + i + 1, len - i - 1);
                printf("%d ", *pre);
                return;
            }
        }
    }
}

int main(){
    int m, num; //m : how many test dataset in the following input
                //num : number of the sequence
    int pre[4096], post[4096], in[4096];
    cin >> m;
    string str; //preorder-inorder or postorder-inorder
    for(int i = 0; i < m ;i++){
        cin >> str >> num;
        for(int j = 0; j < num; j++){
            if(str == "preorder-inorder"){
                cin >> pre[j];
            }
            else if(str == "postorder-inorder"){
                cin >> post[j];
            }
        }
        for(int j = 0; j < num; j++){
            cin >> in[j];
        }
        if(str == "preorder-inorder"){ //prefix to postfix
            pre_to_post(in, pre, num);
        }
        else if(str == "postorder-inorder"){ //postfix to prefix
            post_to_pre(in, post, num);
        }
        cout << "\n";
    }     
    return 0;
}