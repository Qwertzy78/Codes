/*
Develop an algorithm and implement it to solve maximum sum subarray problem in linear time to print the starting index, end index and sum of the subarray whose sum is 
maximum. Compare the performance of this algorithm with naive algorithm and divide and conquer algorithm for size of inputs 
100, 1000, 10000, 50000, 100000, 500000, 1000000. 
For example, consider an array with 16 elements, 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7. Maximum subarray starts at index 8 and 
ends at index 11 (human indices) and sum is 43

Input Format

First line contains the number of elements, n

Next line contains 'n' elements separated by a space

Output Format

Print the start index, end index and sum of subarray that has got maximum sum
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
    int l=0,r=0,j=1;     
    tmp = 0;
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
    }
    cout << l << " " << r+1 << " " << max;
    return 0;
}
