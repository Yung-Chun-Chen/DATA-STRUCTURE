#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string.h>
#include <fstream>
#include<climits>
using namespace std;

ifstream fin;
ofstream fout;


void post_to_pre(long* in,  long* post,  long len){ //postfix to prefix
    if (len > 0) {
        for (long long i = len; i >= 0; i--) {
            if (in[i] == post[len-1]){
                fout << post[len-1] << " ";
                
                post_to_pre(in, post, i);
                post_to_pre(in + i + 1, post + i, len - i - 1);
                return;
            }
        }
    }
}

void pre_to_post(long* in, long* pre, long len){ //prefix to postfix
    if (len > 0) {
        for (long long i = 0; i < len; i++) {
            if (in[i] == *pre) {
                pre_to_post(in, pre + 1, i);
                pre_to_post(in + i + 1, pre + i + 1, len - i - 1);
                
                fout << *pre << " ";
                return;
            }
        }
    }
}

int main(){
    long pre[99999], post[99999], in[99999];
    string fileName;
    cout << "enter filename : ";
    while(cin >> fileName){
        // cin >> fileName;
        int filelen = fileName.length();
        fin.open(fileName); //read file

        string out = fileName.substr(5,filelen);//determine output filename
        fout.open("output" + out);

        long long m, num; //m : how many test dataset in the following input
                    //num : number of the sequence
        // long long pre[99999999], post[99999999], in[99999999];
        fin >> m;
        string str; //preorder-inorder or postorder-inorder
        for(long long i = 0; i < m ;i++){
            fin >> str >> num;
            for(long long j = 0; j < num; j++){
                if(str == "preorder-inorder"){
                    fin >> pre[j];
                }
                else if(str == "postorder-inorder"){
                    fin >> post[j];
                }
            }
            for(long long j = 0; j < num; j++){
                fin >> in[j];
            }
            if(str == "preorder-inorder"){ //prefix to postfix
                pre_to_post(in, pre, num);
            }
            else if(str == "postorder-inorder"){ //postfix to prefix
                post_to_pre(in, post, num);
            }
            fout << "\n";
        }     
        fout.close();
        fin.close();
        cout << "enter filename : ";
        memset(pre,0,sizeof(pre));
        memset(in,0,sizeof(in));
        memset(post,0,sizeof(post));
    }
    return 0;
}