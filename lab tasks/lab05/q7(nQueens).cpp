// Create a program that solves the N-Queens problem for any given N using backtracking. The program should print all possible solutions for placing N queens on an N x N chessboard so that no two queens threaten each other. This task requires you to use a recursive function to place queens row by row , and a validation function to check if a queen can be placed in a specific cell. If a placement leads to a conflict, the algorithm should backtrack to the previous row and try a different column.
#include <iostream>
using namespace std;

bool isSafe(int** board,int row, int col, int n){
    //horizontal
    for(int i=0; i< n; i++){
        if(board[row][i]==1) return false;
    }
    //vertical
    for(int i=0; i< n; i++){
        if(board[i][col]==1) return false;
    }
    //left diagonal
    for(int i=row, j=col;i>=0 && j>=0; i--,j--) {
        if(board[i][j]==1) return false;
    }

    //right diagonal
    for(int i=row, j=col;i>=0 && j<n; i--,j++) {
        if(board[i][j]==1) return false;
    }
    return true;
}

bool solve(int** board, int row,int n) {
    //base case: queen has been placed in all rows  
    if (row==n) return true;

    // find safe position in every row
    for(int i=0; i< n; i++) {
        if(isSafe(board, row, i,n)){
            board[row][i] = 1;
            if(solve(board, row+1,n) ==true){return true;}
            //backtrack if false is returned for some row because that means something in prev rows might have been placed wrong
            board[row][i] = 0;
        }
    }

    //if no safe position found
    return false;
}

int main(){
    cout<<"enter size of board: ";
    int n;
    cin>> n;

    int** board = new int*[n];
    for(int i=0; i<n; i++){
        board[i] = new int[n];
    }
    // 0 means no queen placed and 1 will mean there is a queen in that cell
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            board[i][j] = 0;
        }
    }
    
    bool ans = solve(board, 0,n);
    if(ans ==false){
        cout<<"no solution exists";
        return 0;
    }

    cout<< "solved board: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(board[i][j]==0) cout<<". ";
            else cout<<"Q ";
        }
        cout << endl;
    }
}