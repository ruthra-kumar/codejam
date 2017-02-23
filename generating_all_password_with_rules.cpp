#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool num_set[10];

void unset()
{
    for(int i=0;i<10;i++)
    {
        num_set[i]  =   0;
    }
}

bool Odd(int n)
{
    return n%2;
}

long long Fact(int n)
{
    long long a =   1;
    for(int i=1;i<=n;i++)
    {
        a   *=  i;
    }
    
    return  a;
}

bool Prime(int Sum)
{
    //since min is (0+1+2+3+4+5) = 15
    //and max is (9+8+7+6+5+4)  =   39
    //check for primes between 15 and 39
    
    static const int primes[]   =   {17, 19, 23, 27, 29, 31, 37, 39};
    
    for(auto &X: primes)
    {
        if(X    ==  Sum)
            return  true;
    }
    return  false;
}

int main()
{
    int a   =   123456;
    int tmp;
    vector<int> num;
    
    for(;   a   <= 987654; a++)
    {
        unset();
        tmp =   a;
        num.clear();
        
        int digit   =   0;
        int sum =   0;
        //all are unique numbers
        while(tmp)
        {
            digit   =   tmp%10;
            if(num_set[digit])
            {
                continue;
            }
            sum +=  digit;
            num.push_back(digit);
            tmp /=  10;
        }
        
        //get it back to straight order
        reverse(num.begin(),num.end());
        
        if(Prime(sum))
        {
            int first   =   num[0];
            int smallest =   *(min_element(num.begin(),num.end()));
            
            if( Odd(    Fact(first)/Fact(first-smallest)    )    )
            {
                cout    <<  a   <<  '\n';
            }
        }
        
    }
    return 0;
}
