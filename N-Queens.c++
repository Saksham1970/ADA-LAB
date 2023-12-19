#include <bits/stdc++.h> 
using namespace std;

bool check(int row, int col , int n , const vector<vector<int>>& board , const vector<bool>& flag_row , unordered_map<int,int>& right_down_diagonal , unordered_map<int,int>& left_down_diagonal){
    if(flag_row[row])
        return false;
    if(right_down_diagonal[row-col])
        return false;
    if(left_down_diagonal[row+col])
        return false;
    return true;    
}   
void solve(int n , vector<vector<int>>& board , vector<bool>& flag_row , int col , vector<vector<int>>* ans , unordered_map<int,int>& right_down_diagonal , unordered_map<int,int>& left_down_diagonal){
    if(col >= n){
        (*ans).push_back(vector<int>());
        for(auto board_row : board)
            for(auto element : board_row)
                (*ans).back().push_back(element);
        return;
    }
    for(int row{} ; row<n ; row++)        
        if(check(row , col , n , board , flag_row , right_down_diagonal , left_down_diagonal)){
            board[row][col] = 1;
            flag_row[row] = true;
            left_down_diagonal[row+col]++;
            right_down_diagonal[row-col]++;
            solve(n,board,flag_row,col+1,ans , right_down_diagonal , left_down_diagonal);
            board[row][col] = 0;
            flag_row[row] = false;
            left_down_diagonal[row+col]--;
            right_down_diagonal[row-col]--;

        }
}
vector<vector<int>>* nQueens(int n){	
    vector<vector<int>> board(n,vector<int>(n,0));
    vector<bool> flag_row(n,false);
    vector<vector<int>>* ans = new vector<vector<int>>();
    unordered_map<int,int> right_down_diagonal;
    unordered_map<int,int> left_down_diagonal;
    solve(n , board , flag_row , 0 , ans ,right_down_diagonal , left_down_diagonal) ;
    return ans;
}

int main(){

    cout<<"Enter size of the chessboard : 4\n";
    vector<vector<int>>* ans = nQueens(4);
    cout<<"There are a total of "<<ans->size()<<" ways to place nQueen on 4x4 chessboard\n";
    cout<<"All possible ways to place nQueens are listed below \n";
    for(auto eachway : *ans){
        for(int i{} ; i<eachway.size() ; i++){
            cout<<eachway[i];
            if(i%4 == 3)
                cout<<endl;
            else
                cout<<",";
        }
        cout<<"=================================================================\n";
    }
    
}