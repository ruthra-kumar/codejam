
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#include <iterator>

using namespace std;

int main(int argc,char *argv[]){
    int t,n,Case=1;
    cin>>t;

    while(t--){
        int cnt=0;
        cin>>n;
        int x,y;
        vector<pair<int,int>> wires;
        for(int i=0;i<n;++i){
            cin>>x>>y;
            wires.push_back(pair<int,int>(x,y));
        }
        sort(wires.begin(),wires.end());

        for(auto x=wires.begin();x != wires.end();++x){
            if(get<0>(*x) != get<1>(*x)){
                for(auto y=x+1;y!=wires.end();++y){
                    if( ( get<0>(*y) > get<0>(*x)) && (get<1>(*y)) < get<1>(*x) ) cnt++;
                }
            }
        }
        cout<<"Case #"<<Case++<<": "<<cnt<<'\n';
    }


    return 0;
}
