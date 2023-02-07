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
