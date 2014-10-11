#include <iostream>
#include <vector>
// PROBLEM FROM https://evernote.com/careers/challenge.php
using namespace std;
int main()
{
    int input_number;
    
    cin >> input_number;
    
    vector<int64_t> input;
    vector<int64_t> answer;
    int numberofzeros = 0;
    
    int64_t multiply = 1;
    
    for(int i = 0; i < input_number; i++)
    {
        int64_t number;
        cin >> number;
        if(number == 0 )
        {
           numberofzeros++;
           input.push_back(number);
           multiply *= 1;
        }else{
         input.push_back(number);
         multiply *= number;
        }
    }
    
    for(int j =0; j < input_number; j++)
    {
        if(numberofzeros == 0)
        {
           int64_t answer_number = multiply / input[j];
           answer.push_back(answer_number);
        }else if(numberofzeros == 1)
        {
            if(input[j] != 0)
            {
              answer.push_back(0);
            }else{
              answer.push_back(multiply);
            }
        }else{
           answer.push_back(0);
        }
    }
    
    for(auto iter = answer.begin(); iter != answer.end(); iter++)
    {
        cout<<*iter<<endl;   
    }
        
    return 0;
}
