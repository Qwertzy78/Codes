/*
Given two strings of length n and m respectively, design an algorithm using dynamic programming technique  and implement using C++  to compute the 

(i) Length of the Longest Common Subsequence of X and Y

(ii) Identify the position of the rightmost character in Y that has to be changed in order to make the length of the LCS(X, Y) increase by 1.

For example, If X=ABBCD, Y=BBEDF, then the LCS is BBD and the length of the LCS is 3.  If we change  'E'  in Y  to letter 'C', then LCS (X,Y) is BBCD and length of the LCS is increased by 1. 

Your code should return the the index of the character 'E' that has to be changed (i.e.) 3.  For some sequences like : X=ABBCD, Y=BBDEF, LCS is BBD. Here, we cannot increase the length of the LCS by changing any character of Y.  In that case, your code should return -1.

Input format:

First line contains the string X

Next line contains the string Y

Output format:

Length of the LCS of X and Y

Position of Rightmost character of Y that has to be changed to increase the length of the LCS by 1:
*/

#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

int lcs(string text1 , string text2){
    int n = text1.length();
    int m = text2.length();

    vector <vector<int>> dp(n+1,vector <int>(m+1,0) );
    for(int i =1; i<=n; i++){
        for(int j =1; j<=m; j++){
            if(text1[i-1]==text2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                int op1 = dp[i][j-1];
                int op2 = dp[i-1][j];

                dp[i][j] = max(op1,op2);
            }
        }
    }
    return dp[n][m];
}

int returnIdx(string text1, string text2){
    int n = text1.length();
    int m = text2.length();

    int len = lcs(text1, text2);

    if(len==0){
        return m;
    }
    map <int, int,greater<int>> mp;
    int ptr = 0;
    for(int i = 0; i<m; i++ ){
        for(int j = ptr; j<n; j++ ){
            if(text2[i]==text1[j]){
                ptr= j+1;
                mp[i] = j;
                break;
            }
        }
    }
    int a = len;
    pair <int,int> prev = {0,0};
    map <int,int> :: iterator itr;
    for( itr = mp.begin(); itr!=mp.end(); itr++){
        int fst = itr->first;
        int nd = itr->second;

        if(a==len){
            if(fst<m-1 && nd<n-1){
                return m;
            }
            if(a==1 ){
                if(fst==m-1 && nd> 0){
                    return fst;
                }
            }
        }

        else{

            int k = prev.first- fst;
            int b = prev.second - nd;

            if(k>1 && b>1){
                return prev.first ;
            }

            else{
                if(a==1 ){
                    if(fst==0 || nd ==0){
                        return -1;
                    }
                    else{
                        return fst;
                        
                    }
                    
                }
            
             }
        }
        prev = {fst,nd};
         a--;
    }
    return -1;
}

int main(){
    string s1, s2;
    cin>>s1>>s2;
    int ans = lcs(s1,s2);
    cout<<ans<<endl;
    int ptr = returnIdx(s1, s2);
    cout<<ptr;
    return 0;
}
