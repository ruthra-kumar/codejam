
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iterator>

using namespace std;

long long scalar(vector<int> &a,vector<int> &b){
    long long sum = 0;
    for(unsigned int i=0;i<a.size();++i){
        sum += (long long )(a[i])*b[i];
    }
    return sum;
}

int main(int argc,char *argv[]){
    int n,t,tmp,Case=1;
    vector<int> v1,v2;
    cin>>t;

    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>tmp;
            v1.push_back(tmp);
        }
        for(int i=0;i<n;i++){
            cin>>tmp;
            v2.push_back(tmp);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end(),greater<int>());
        cout<<"Case #"<<Case++<<": "<<scalar(v1,v2)<<'\n';

        v1.clear();
        v2.clear();
    }


    return 0;
}
