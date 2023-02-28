#include<iostream>
using namespace std;

int max(int a, int b){
    if(a>b)
        return a;
    return b;
}

/* top-down
int cut_rod(int A[],int length)
{
    int q = INT_MIN;
    if(length == 0)
        return 0;
    for(int i = 1; i <= length; i ++)
    {
        q = max(q,A[i-1] + cut_rod(A,length-i));
    }
    return q;
}
*/

/* top-down memoised
int memo_cut(int A[], int length,int *memo)
{
    int q = INT_MIN;
    if(length == 0)
        return 0;
    if(memo[length] >= 0){
        return memo[length];
    }
    for(int i = 1; i <= length; i ++)
    {
        q = max(q,A[i-1] + memo_cut(A,length-i,memo));
    }
    memo[length] = q;
    return q;
}
*/

//bottom-up
int cut_rod(int A[],int length){
    int mem[length];
    int q;
    // for(int i = 0; i < length;i++)
    //     mem[i] = INT16_MIN;
    mem[0] = 0;
    for(int i = 1;i <= length ;i++){
        q = INT_MIN;
        for(int j = 1;j<= i ;j++)
        {
            q = max(q,A[j-1]+mem[i-j]);
        }
        mem[i] = q;
    }
    return q;
}

int main(){
    int arr[] =  { 1, 5, 8, 9, 10, 17, 17, 20 };
    cout <<  cut_rod(arr,8)<<endl;
    return 0;
}
