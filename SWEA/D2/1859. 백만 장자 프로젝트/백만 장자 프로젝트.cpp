#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T, N, max;
	long long answer;
    vector <int> future;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
	    answer=0;max=-1;
		cin>>N;
        future.resize(N,0);
        for(int i=0;i<N;i++){
            cin>>future[i];
        }
        
        
        for(int i=N-1;i>=0;i--){
            if(future[i]>max){
                max=future[i];
            }
            else{
                answer+=max-future[i];
            }
        }
        
    
        cout<<"#"<<test_case<<" "<<answer<<endl;


	}
	return 0;
}