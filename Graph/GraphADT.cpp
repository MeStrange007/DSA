#include<bits/stdc++.h>
using namespace std;

class GraphADT{

    // TYPE {1. undirected+Matrix 2. undirected+List 3. directed+Matrix 4. directed+List}

    public:
        int V;
        int E;
        int **adjMat;
        vector<pair<int,int>> *adjLst;
        int type;
        GraphADT(int type){
            this->type=type;
            switch (type)
            {
            case 1:
                {
                    cout<<endl<<"Enter No of vertices : ";cin>>this->V;
                    cout<<endl<<"Enter No of Edges in graph : ";cin>>this->E;
                    this->adjMat = new int*[this->V];
                    for(int i = 0;i<this->V;i++){
                        this->adjMat[i] = new int[this->V];
                    }
                    for(int i=0;i<this->V;i++){
                        for(int j=0;j<this->V;j++){
                            if(i==j) this->adjMat[i][j]=0; else this->adjMat[i][j]=INT8_MAX;
                        }
                    }
                    cout<<endl<<"Enter Edges for undirected graph like : \nvert1 vert2 weight\n";
                    for(int i = 0;i<this->E;i++){
                        int vert1,vert2,weight;
                        cin>>vert1>>vert2>>weight;
                        this->adjMat[vert1-1][vert2-1]=weight;
                        this->adjMat[vert2-1][vert1-1]=weight;
                    }
                }
                break;
            case 2:
                {
                    cout<<endl<<"Enter No of vertices : ";cin>>this->V;
                    cout<<endl<<"Enter No of Edges in graph : ";cin>>this->E;
                    this->adjLst = new vector<pair<int,int>>[this->V];
                    cout<<endl<<"Enter Edges for undirected graph like : \nvert1 vert2 weight\n";
                    for(int i = 0;i<this->E;i++){
                        int vert1,vert2,weight;
                        cin>>vert1>>vert2>>weight;
                        this->adjLst[vert1].push_back({vert2,weight});
                        this->adjLst[vert2].push_back({vert1,weight});
                    }
                }
                break;
            case 3:
                {
                    cout<<endl<<"Enter No of vertices : ";cin>>this->V;
                    cout<<endl<<"Enter No of Edges in graph : ";cin>>this->E;
                    this->adjMat = new int*[this->V];
                    for(int i = 0;i<this->V;i++){
                        this->adjMat[i] = new int[this->V];
                    }
                    for(int i=0;i<this->V;i++){
                        for(int j=0;j<this->V;j++){
                            if(i==j) this->adjMat[i][j]=0; else this->adjMat[i][j]=INT8_MAX;
                        }
                    }
                    cout<<endl<<"Enter Edges for directed graph like : \nFrom TO weight\n";
                    for(int i = 0;i<this->E;i++){
                        int vert1,vert2,weight;
                        cin>>vert1>>vert2>>weight;
                        this->adjMat[vert1-1][vert2-1]=weight;
                    }
                }
                break;
            case 4:
                {
                    cout<<endl<<"Enter No of vertices : ";cin>>this->V;
                    cout<<endl<<"Enter No of Edges in graph : ";cin>>this->E;
                    this->adjLst = new vector<pair<int,int>>[this->V];
                    cout<<endl<<"Enter Edges for undirected graph like : \nFrom To weight\n";
                    for(int i = 0;i<this->E;i++){
                        int vert1,vert2,weight;
                        cin>>vert1>>vert2>>weight;
                        this->adjLst[vert1].push_back({vert2,weight});
                    }
                }
                break;
            default:
                cout<<endl<<"Wrong GRAPH type selected";
                break;
            }
        }

        void DFSUtil(int sourse,int vis[]){
            vis[sourse]=1;
            cout<<sourse;
            if(this->type == 1 ||this->type == 3){
                for(int i=0;i<this->V;i++){
                    if(!vis[i] && this->adjMat[sourse][i]<INT8_MAX && this->adjMat[sourse][i]>=0){
                        DFSUtil(i,vis);
                    }
                }
            }else{
                for(auto i : this->adjLst[sourse]){
                    if(!vis[i.first]){
                        DFSUtil(i.first,vis);
                    }
                }
            }
        }

        void DFSTravers(int sourse=NULL){
            int visited[this->V] = {0};
            if(sourse){
                DFSUtil(sourse-1,visited);
            }else{
                for(int i=0;i<this->V;i++){
                    if(!visited[i]){
                        DFSUtil(i,visited);
                    }
                }
            }
        }
};

int main(){
    
}