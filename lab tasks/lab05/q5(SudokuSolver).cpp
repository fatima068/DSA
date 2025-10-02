// Implement a Sudoku solver using the backtracking technique. The program should take a partially filled 9x9 Sudoku grid and fill the empty cells (represented by 0) to solve the arr. Your algorithm should:
// 1. Find an empty cell.
// 2. Try placing a number from 1 to 9 in the empty cell.
// 3. Check if the number is valid in the current row, column, and 3x3 subgrid.
// 4. If valid, recursively call the function to solve the rest of the arr.
// 5. If the recursive call doesn't lead to a solution, backtrack by resetting the cell to 0 and trying the next number.
#include <iostream>
using namespace std;

bool isSafe(int** board, int row, int col, int digit){
    //ceck horizontally
    for (int i =0; i<9; i++) {
        if(board[row][i]==digit){
            return false;
        }
    }
    //check vertically 
    for (int i =0; i<9; i++) {
        if(board[i][col]==digit){
            return false;
        }
    }
    // check in 3x3 grid
    int gridrow = (row/3)*3;
    int gridcol = (col/3)* 3;
    for(int i = gridrow; i <= gridrow+2; i++){
        for(int j =gridcol; j <= gridcol+2; j++){
            if(board[i][j]==digit){
                return false;
            }
        }
    }
    
    return true;
}

bool solve(int** board, int row=0,int col = 0){
    //base case
    if(row ==9) return true;

    // calculating next row and col to be worked upon
    int nextRow = row;
    int nextCol=col+ 1;
    if(nextCol == 9){
        nextCol = 0;
        nextRow = row+1;
    }

    if (board[row][col] != 0){ // 0 basically means empty cell, so if not empty then leave it as it is and solve for next cell 
        return solve(board, nextRow, nextCol);
    }
    //if zero, find correct digit between 1 and 9 to place
    for (int digit=1; digit < 10; digit++ ){
        if(isSafe(board, row, col, digit)) {
            board[row][col] = digit;
            if(solve(board, nextRow, nextCol)){
                return true;
            }
            //backtrack if some thing ever returns false and place 0 in the cell, then try with new digit
            board[row][col] = 0;
        }
    }

    return false; // because we have checked everything and no digit between 1 and 9 can fit in a particular cell
}

int main() {
    int** board = new int*[9];
    for(int i=0; i<9; i++){
        board[i] = new int[9];
    }

    //hardcode sudoku grid because taking 9x9 input too time consuming
    int arr[9][9] = {
        {5,3,0, 0,7,0, 0,0,0},
        {6,0,0, 1,9,5, 0,0,0},
        {0,9,8, 0,0,0, 0,6,0},

        {8,0,0, 0,6,0, 0,0,3},
        {4,0,0, 8,0,3, 0,0,1},
        {7,0,0, 0,2,0, 0,0,6},

        {0,6,0, 0,0,0, 2,8,0},
        {0,0,0, 4,1,9, 0,0,5},
        {0,0,0, 0,8,0, 0,7,9}
    };
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board[i][j] = arr[i][j];
        }
    }

    cout<<"unsolved ans:"<<endl;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }

    if(solve(board)){
        cout<<endl<<"solved ans:"<<endl;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    } else {
        cout<<"sudoku grid cannot be solved "<<endl;
    }

    for(int i=0; i<9; i++){
        delete[] board[i];
    }
    delete[] board;

}