#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(int argc, char** argv)
{
	int test_case;
	int T, N, i, j, start, end, num;
	cin>>T;
    
    vector <vector <int>> snail;

	for(test_case = 1; test_case <= T; ++test_case)
	{
            cin>>N;
			snail.clear();
            snail.resize(N,vector<int>(N,0));
            start=0;
            end=N-1;
            num=1;
        
            while(start<end){
                for( i=start; i<=end; i++ ){
                    snail[start][i]=num++;
                }   
                for( i=start+1;i<=end;i++){
                    snail[i][end]=num++;
                }
                for( i=end-1;i>=start;i--){
                    snail[end][i]=num++;
                }
                for( i=end-1;i>start;i--){
                    snail[i][start]=num++;
                }
                start++;
                end--;

            }
            if(start==end) snail[start][start]=num++;
        
        	cout<<"#"<<test_case<<"\n";
            for( i=0;i<N;i++){
                for( j=0;j<N;j++){
                    cout<<snail[i][j]<<" ";
                }
                cout<<"\n";
            }   

	}
	return 0;
}