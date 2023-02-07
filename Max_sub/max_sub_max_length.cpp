/*
Given an array of positive and negative numbers, develop a linear algorithm and write a C++ code to print the start index, end index and 
sum of subarray which is having maximum sum and maximum length. Consider an array with 13 elements 4, -12, 3, 10, 4, 5, -100, 6, 7, 1, 3, 1, 4. 
There are two subarrays having sum as 22, that is starting at 2 and ending at 5 with elements 3, 10, 4, 5 and another subarray that starts at 8 and 
end at 13 with elements 6, 7, 1, 3, 1, 4

Input Format

First line contains the number of elements in array, n

Next line contains the elements in the array separated by a space

Output Format

Print the start index, end index and sum of array having maximum sum and having maximum number of elements
*/

#include<vector>
#include<iostream>
using namespace std;

int main()
{
    int n,tmp;
    vector <int> a;
    cin >> n;
    for(int i = 0;i<n;i++)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    int max = INT8_MIN;
    int l=0,r=0,j=1;     //l ,r= left & right index of sub arr
                         // j = temporary start index if sum becomes negative
    tmp = 0;             //temporary sum
    for(int i =0;i<n;i++){
        if(tmp < 0){
            tmp = 0;
            j = i+1;
        }
        tmp += a[i];
        
        if(tmp > max){
            max = tmp;
            l = j;
            r = i;
        }
        else if(tmp == max && i-j > r-l){        //checking which sub arr has bigger length
            l = j;
            r = i;
        }
    }
    cout << l << " " << r+1 << " " << max;
    return 0;
}
