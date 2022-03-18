#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main()
{
    vector<string>add {"Hello","My","World"};
    vector<int> integerValuec {11,12,13,14,15};
    vector<string>reverse;
    vector<double>doubleValue {11.02,45.46,123.0212,89.12};
    auto i {5645};
    std::cout<<"Buff"<<endl;
    string newString {"Temppoof"};
    string copyString (newString,4);
    std::cout<<copyString<<endl;    

    for (const string &printForloop:add)
        std::cout<<printForloop.at(0)<<endl;

    for(auto temp = add.crbegin(); temp != add.crend(); temp++)
    {
        reverse.push_back(*temp);
        cout<<*temp<<endl;
    }
    for(vector<string>::iterator carry = reverse.begin(); carry != reverse.end();carry++)
        std::cout<<*carry<<endl;
    
    integerValuec.front() = 32;
    for(vector<int>::iterator integerCarry = integerValuec.begin(); integerCarry != integerValuec.end(); integerCarry++)
        std::cout<<*integerCarry<<endl;

    for(double check:doubleValue)
        std::cout<<check<<endl;

    
    std::cout<<"afterErase"<<endl;
    if(!doubleValue.empty())
        for(double check:doubleValue)
            std::cout<<check<<endl;
    
   for(vector<int>::iterator test = integerValuec.begin(); test != integerValuec.end();test++)
   {
        if(*test == 13)
        integerValuec.erase(test);
   }

   for(auto test:integerValuec)
    std::cout<<test<<endl;
    auto test = integerValuec.begin();
    for(auto i = 1; i<=integerValuec.size();++i,++test)
    {
        if(i == 3)
        integerValuec.erase(test);
    }
    for(auto test:integerValuec)
    std::cout<<test<<endl;
    return 0;
}