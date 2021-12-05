#include <cstring>
#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#define M 17
#define N 17 //17*17 matrix

struct offsets {
    int row_offset;
    int col_offset;
 }; //position offset
offsets Move[4]={ {0,1} , {1,0} , {-1,0} , {0,-1} }; //0:right 1:down 2:up 3:left

struct item {
    int x;
    int y;
    int dir;
}; //keep pass history : (x , y , dir)

void path(int m, int p ,char maze[][17] ,int start_x, int start_y, int exit_x, int exit_y){
    int cnt = 0; //count the path
    if(maze[start_x][start_y] == '1'){ //start position is barrier
        cout<<"Failed to escape. Start position is barrier!"<<endl;
        return ;
    }
    int mark[m][p] = {0}; //record each position is visited or not
    mark[start_x][start_y] = 1; //because is visited, set 1
    std::stack<item> stack; 
    item temp;
    temp.x = start_x; temp.y = start_y; temp.dir = 0;
    stack.push(temp); //record pass history using stack
    while(!stack.empty()){ //there still have moves
        temp = stack.top();
        stack.pop(); //pop out one pass history
        int i = temp.x; 
        int j = temp.y; 
        int d = temp.dir;
        cout << cnt++ << ":" << i << "," << j << endl;
        while(d < 4){ //there still have directions
            int current_x = Move[d].row_offset + i;
            int current_y = Move[d].col_offset + j;
            if((current_x == exit_x) && (current_y == exit_y) && maze[exit_x][exit_y] =='0'){ //reach exit
                cout<< cnt++ << ":" << current_x << "," << current_y <<endl;
                cout << "successfully escaped!!"<<endl;
                return;
            }
            else if((current_x == exit_x) && (current_y == exit_y) && maze[exit_x][exit_y] =='1'){ //reach exit but exit is barrier
                cout << "Failed to escape. Exit is barrier!"<<endl;
                return;
            }
            if(maze[current_x][current_y]=='0' && (!mark[current_x][current_y])){ //open path and unvisited
                mark[current_x][current_y] = 1; //set mark[visited_position_x][visited_position_y] to 1 because is visited.
                temp.x = i; temp.y = j; temp.dir = d+1; //because direction d is used, so if this stack is pop out in the future, 
                                                        //we use direction d+1 to move
                stack.push(temp); //record pass history using stack
                i = current_x; //update i
                j = current_y; //update j
                d = 0; //direction is set to right
                cout<< cnt++ << ":" << current_x << "," << current_y <<endl;
            }
            else{
                d++; //use another direction
            }
        }
    }
    cout<<"Failed to escape."<<endl;
}

int main(){
    std::string fileName;
    char maze[M][N]; //17*17 maze
    cout<<"enter filename : ";
    cin>> fileName;

    ifstream fin;
    fin.open(fileName); //read file
    for(int i = 0 ; i < M ; i++){
        for(int j = 0 ; j < N ; j++){
            fin >> maze[i][j];
        }
    }
    fin.close();

    for(int i = 0 ; i < M ; i++){ //output the maze
        for(int j = 0 ; j < N ; j++){
            cout<<maze[i][j];
        }
        cout<<endl;
    }

    int start_x , start_y , exit_x , exit_y;
    
    while(true){
        cout<<"enter start position : ";
        cin>> start_x >> start_y;
        if(start_x == -1 && start_y == -1){
            cout<<"end the code.";
            return 0;
        }
        cout<<"enter exit position : ";
        cin>> exit_x >> exit_y;
        
        

        path(M, N, maze ,start_x, start_y, exit_x, exit_y); //call function path
    }
    
    return 0;
}
