/*
Develop a top down dynamic programming algorithm to find minimum cost for matrix chain multiplication. Print the tables maintained by the algorithm. For example, when there are six matrices and the input given is 

7
30 35 15 5 10 20 25

M table should be printed as 

15750 7875 9375 11875 15125 
2625 4375 7125 10500 
750 2500 5375 
1000 3500 
5000 
S table should be printed as 
1 1 3 3 3 
2 3 3 3 
3 3 3 
4 5 
5 
Input Format

First line contains the number of matrices +1, n

Next line contains the dimensions of the matrices in the chain

Output Format

Print the mtable

Print the s table

Print the minimum cost
*/

#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

void matrix_chain(vector<int> p, vector<vector<int>>& m, vector<vector<int>>& s)
{   
    int q,j;
    int n = p.size()-1;
    for(int l = 2; l <= n;l++){
        for(int i = 1; i <= n-l+1;i++){
            j = i+l -1;
            m[i-1][j-1] = INT_MAX;
            for(int k = i ; k <= j-1 ; k++){
                q = m[i-1][k-1] + m[k][j-1] + p[i-1]*p[k]*p[j];
                if(q<m[i-1][j-1])
                {
                    m[i-1][j-1] = q;
                    s[i-1][j-1] = k;
                }
            }
        }
    }
}   

int main(){
    int n,x;
    cin >> n;
    vector<int> p;
    for(int i = 0; i < n;i++){
        cin >> x;
        p.push_back(x);
    }
    vector<vector<int> > m(n-1,vector<int>(n-1,0));
    vector<vector<int> > s(n-1,vector<int>(n-1,0));
    matrix_chain(p,m,s);
    
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
            cout<<m[i][j]<<" ";
        cout<<endl;
    }
    
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
            cout<<s[i][j]<<" ";
        cout<<endl;
    }
    cout << m[0][n-2];
    return 0;
}
