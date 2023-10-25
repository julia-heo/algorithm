/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
// def binary_search(target, data):
//     data.sort()
//     start = 0 		
//     end = len(data) - 1 

//     while start <= end:
//         mid = (start + end) 

//         if data[mid] == target:
//             return mid 	

//         elif data[mid] > target: 
//             end = mid - 1
//         else:                  
//             start = mid + 1
//     return


#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N,K;
    cin>>N>>K;
    int ran[N+1];
    for(int i=0;i<N;i++){
        cin>>ran[i];
    }
    sort(ran,ran+N);
    long long start=1;
    long long end=ran[N-1];
    long long result=0;
    while(start<=end){
        long long  mid=(start+end)/2;
        int cnt=0;
        for(int i=0;i<N;i++){
            cnt+=ran[i]/mid;
        }
        // cout<<cnt<<" "<<mid<<" ";
        if(cnt>=K){
            start=mid+1;
            if (result < mid) result=mid;
        }
        else{
            end=mid-1;
        }
    }
    cout<<result;
    

    return 0;
}
