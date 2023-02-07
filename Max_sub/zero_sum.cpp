/*
Given an array of positive and negative integers, develop a linear algorithm and write a C++ code to check if there exist a subarray whose sum is zero is present in it.
If such a subarray exist then print start and end index of first occurrence. Otherwise print -1 for both start and end index. 
For example, if the array contains seven elements 10, -3, 2,4, -3, 5, 7 then print start index as 2 and end index as 5

Hint: Use maps for keeping track of sums 

Note: If more than one zero sum subarray exist then print the one which has got maximum length

Input Format

First line contains the number of elements in the array, n

Next line contains the elements separated by a space

Output Format

Either print start index and end index of subarray whose sum becomes 0 or print -1 if no such subarray exist
*/


#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,tmp;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        a.push_back(tmp);
    }
    int sum,l=0,r=l+1,flag = 0;
    sum = a[l] + a[r];
    
    
    while(true){
        if(sum == 0){
            flag = 1;
            break;
        }
        r++;
        if(r < n)
            sum = sum + a[r];
        else{
            l++;
            r = l+1;
            sum = a[l] + a[r];
        }
        if(l>=n)
            break;
    }
    
    if(flag == 0)            //sum never became 0
        cout << "-1";
    else                     // if sum became 0,a[l.....r]
        cout << l+1 << " " << r+1;
        
    return 0;
}
