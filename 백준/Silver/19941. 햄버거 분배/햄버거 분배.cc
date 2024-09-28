#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N,K,answer=0;
    cin>>N>>K;
    vector<char> line(N);
    for(int i=0;i<N;i++){
        cin>>line[i];
    }
    for(int i=0;i<N;i++){
        if(line[i]=='P'){
            for(int j=i-K;j<=i+K;j++){
                if(j>=0&&j<N&&line[j]=='H'){
                    answer++;
                    line[j]='N';
                    break;
                }
            }
        }
    }
    
    cout<<answer;
    return 0;
}

