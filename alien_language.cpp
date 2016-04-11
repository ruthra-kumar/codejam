
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iterator>

using namespace std;

bool if_word_possible(string &word,string &tok){
    vector<string> possibilites;
    for(unsigned int i=0;i<tok.size();){
        if(tok.at(i) == '('){
            string t;
            while(tok.at(++i) != ')'){
                t += tok.at(i);
            }
            i++;
            possibilites.push_back(t);
        }
        else{
            possibilites.push_back({tok.at(i)});
            i++;
        }
    }

    for(unsigned int i=0;i<word.size();){
        string s = possibilites.at(i);
        if(find(s.begin(),s.end(),word.at(i)) != end(s)) i++;
        else return false;
    }

    return true;

}

int main(int argc,char *argv[]){
    int Case=1,cnt;
    long int l,d,n;
    string token;
    vector<string> dict;
    cin>>l>>d>>n;

    for(long int i=0;i<d;++i){
        cin>>token;
        dict.push_back(token);
    }

    while(n--){
        cnt=0;
        cin>>token;
        for(auto x:dict){
            if(if_word_possible(x,token)) cnt++;
        }
        cout<<"Case #"<<Case++<<": "<<cnt<<'\n';
    }


    return 0;
}
