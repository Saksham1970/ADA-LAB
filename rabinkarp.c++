#include<bits/stdc++.h>
using namespace std;
#define mod 1'000'000'007

bool validate(string& text , string& pattern , const int& p , const int& t , const int& start){
    if(p!=t)
        return false;
    for(int i{} ; i<pattern.size() ;i++)
        if(text[i+start] != pattern[i])
            return false;
    return true;
}

vector<int>* Rabinkarp(string& text , string& pattern){

    vector<int>* ans = new vector<int>();
    long long p{} , t{} , inverse_multiplier{1};
    
    // calculating hashcode for deleting the front text character going out of window
    for(int i{} ; i<pattern.size()-1 ; i++)
        inverse_multiplier = (inverse_multiplier*10)%mod;

    // calculating hashcode for pattern : p & text : t
    for(int i{} ; i<pattern.size() ; i++)
        p = ((p*10)%mod + pattern[i]-'A')%mod,
        t = ((t*10)%mod + text[i]-'A')%mod;
    
    if(validate(text , pattern , p , t , 0))
        (*ans).push_back(0);
    
    for(int start{1},end=pattern.size() ; end<text.size() ; end++ , start++){

        // calculating new hashcode by deleting the text[star-1] character and adding text[end] character in it
        t = ( 10*(t - (text[start-1]-'A')*inverse_multiplier) + (text[end]-'A') )%mod;
        if(t<0)
            t += mod;
        if(validate(text , pattern , p , t , start))
            (*ans).push_back(start);

    }

    return ans;

}

int main(){
    // cout<<"------------------------------------------------------------------------------------------------\n";
    string text  = "AABAACAADAABAAABAA" , pattern = "AABA";
    // string text = "aabaacaadaabaaabaa" , pattern = "aaba";
    vector<int>* ans = Rabinkarp(text , pattern);
    cout<<"Pattern in a string start from positions : ";
    for(auto a : *ans)
        cout<<a<<",";

}