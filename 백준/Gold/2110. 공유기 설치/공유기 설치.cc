#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    int N,K,mid,now,ans=0;
    cin>>N>>K;
    
    vector <int> vec(N+1);
    
    for(int i=1;i<=N;i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    
    int start=1;
    int end=vec[N]-vec[1];
    
    while (start <= end){
        int cnt=1;
        mid=(start+end)/2;
        now=vec[1];
        
        for(int i=2;i<=N;i++){
            if(vec[i]-now>=mid){
                now=vec[i];
                cnt++;
            }
        }
        if(cnt<K) end=mid-1;
        else {
            ans = max(ans, mid);
			start = mid + 1;
        }

    }
    cout << ans;
    return 0;
}