/*
Matrix Chain Multiplication (MCM) Problem is one in which given a chain of matrices < A1,A2, ...,An > of n matrices, task is to fully parenthesize the product A1 ∗A2∗, ... ∗ An in such a way that the number of scalar multiplications ( the number of multiplications between the entries of the given matrices) performed in computing the product A1 ∗ A2∗, ... ∗ An is minimum. Here is a special kind of problem in which we do MCM in a chain of matrices in which the first and last matrices are square matrices of some dimension 'm' and has some 'k' number of paired column and row matrices of dimension 'm'. A column matrix of dimension 'm' is one in which number of columns is 1 and number of rows is 'm'.  A row matrix of dimension 'm' is one in which number of rows is 1 and number of columns is 'm'.

Given the number of paired column and row matrices, k and dimension 'm', develop an algorithm and C++ code to find the mimimum number of multiplications to be done to get the resultant matrix. For example, if the input is 1, 2 then there is a chain of 4 matrices of the dimensions 2x2, 2x1, 1x2, 2x2. If the input is 3, 2 then there is a chain of 8 matrices 2x2, 1x2, 2x1, 1x2, 2x1, 1x2, 2x1, 2x2

Input Format

First line contains the value of k

Next line contains the dimension 'm'

Output Format

Print minimum number of multiplications to be done
*/
#include<iostream>
#include<vector>
using namespace std;

int min(int a,int b){
    if(a<b)
        return a;
    return b;
}

int matrix_chain_mul(int a,int b,vector<int> A)
{
    if(a==b)
        return 0;
    int q = INT16_MAX;
    for(int i = a;i < b; i++){
        q = min(q,matrix_chain_mul(a,i,A)+matrix_chain_mul(i+1,b,A)+A[a-1]*A[i]*A[b]);
    }
    return q;
}

int main()
{
    int k,ele,m;
    vector<int> p;
    cin>>k;
    cin >> m;
    p.push_back(m);
    for(int i=0;i<2*k+1;i++)
    {
        if(i%2==0)
            ele = m;
        else 
            ele = 1;
        p.push_back(ele);
    }
    p.push_back(m);
    cout<<matrix_chain_mul(1,2*k+2,p);
    return 0;
}
