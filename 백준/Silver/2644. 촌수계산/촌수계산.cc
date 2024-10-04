#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, A, B, K,answer=-2;
vector <vector <int>> vec;
vector <int> visited;

void func(int front,int flong){
    for (int i=1;i<=N;i++){
        if(vec[front][i]==1&&visited[i]==0){
            if(i==B)answer=flong;
            visited[i] = 1;
            func(i,flong+1);
        }
    }
    
}

int main()
{

    cin>>N;
    cin>>A>>B;
    cin>>K;
    int a,b;
    
    vec.resize(N+1, vector<int>(N+1, 0));
    visited.resize(N+1, 0);
    
    for (int i=1;i<=K;i++){
        cin>>a>>b;
        vec[a][b]=1;
        vec[b][a]=1;
    }

    
    queue <int> q;
    q.push(A);
    visited[A]=1;
    
    
    func(A,0);
    
    
    cout<<answer+1;
    
    return 0;
}