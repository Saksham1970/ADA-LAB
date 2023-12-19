#include<bits/stdc++.h>
using namespace std;

int solvetab(string& text1 , string& text2 ){

    vector<vector<int>> dp(text1.size()+1 , vector<int>(text2.size()+1 , 0));

    for(int index1 = text1.size()-1 ; index1>=0; index1--)
        for(int index2 = text2.size()-1 ; index2>=0 ; index2--){
            int ans{};
            if(text1[index1] == text2[index2])
                ans = 1 + dp[index1+1][index2+1];
            else
                ans = max(dp[index1+1][index2], dp[index1][index2+1]);       
            dp[index1][index2] = ans;
        }
    return dp[0][0];
}

int main(){
    string text1{"abcde"},text2{"ace"}; 
    cout<<"Longest common subsequence of the strings "<<text1<< " & "<<text2<<" is "<<solvetab(text1 , text2);
}

