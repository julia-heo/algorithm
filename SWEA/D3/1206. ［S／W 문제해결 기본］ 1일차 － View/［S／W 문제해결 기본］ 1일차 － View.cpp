#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int N, answer, i;
    vector<int> building;
    vector<int> subset(5);
	for( int num=1; num<=10;num++){
        cin>>N;
        building.clear();
        building.resize(N,0);
        for(i=0;i<N;i++){
            cin>>building[i];
        }
        if(N==4) answer=0;
        else{
            answer=0;

            for(i=4;i<N;i++){
                subset.clear();
                subset.resize(5,0);
                copy(building.begin()+i-4,building.begin()+i+1,subset.begin());

                sort(subset.begin(),subset.end(),greater<int>());
                if(subset[0]==building[i-2]){
                    answer+=subset[0]-subset[1];
                }
            }
        }



        cout<<"#"<<num<<" "<<answer<<endl;
    }
    return 0;
}