#include<bits/stdc++.h>
using namespace std;

string longestPalin(string str){
    vector<int> vec;
    vector<pair<int,int>> pos;
    for(int i=0;i<str.length();i++){
        int firstPtr = i;
        int lstPtr = str.length()-1;
        int initial=i;
        int lst;
        bool first_time=true;
        while(abs(firstPtr-lstPtr)!=0){
            if(abs(firstPtr-lstPtr)==1){
                if(str[firstPtr]==str[lstPtr]){
                    if(first_time){
                        lst=lstPtr;
                        first_time=false;
                    }
                }else{
                    first_time=true;
                }
                break;
            }else{
                if(str[firstPtr]==str[lstPtr]){
                    firstPtr++;
                    lstPtr--;
                    if(first_time){
                        lst=lstPtr+1;
                        first_time=false;
                    }
                }else{
                    if(firstPtr==i) lstPtr--;
                    firstPtr=i;
                    first_time=true;
                }   
            }
        }
        if(first_time){lst=initial;}
        vec.push_back(lst-initial);
        pos.push_back({initial,lst});
    }
    int max_index = distance(vec.begin(),max_element(vec.begin(),vec.end()));
    return str.substr(pos[max_index].first,pos[max_index].second-pos[max_index].first+1);
}

int main(){
    string str;
    cout<<"Enter string : ";cin>>str;
    cout<<longestPalin(str);
}