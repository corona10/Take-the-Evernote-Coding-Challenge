#include <iostream>
#include <vector>
#include<deque>
#include <string>
#include <sstream>

using namespace std;

// PROBLEM FROM https://evernote.com/careers/challenge.php
int main()
{
    int buffer_size = 0;
    
    cin >> buffer_size;
    
    
    std::deque<string> buffer;
   while(true){
       
       string commend;
       getline(cin, commend);
        vector<string> results;
        stringstream s(commend);
        while(!s.eof()) {
      string tmp;
      s >> tmp;
      results.push_back(tmp);
      }
         
     string commend_category = results[0];
     
      if(commend_category == "Q")
      {
         return 0;
      }else if(commend_category == "L")
      {
         for(auto iter = buffer.begin(); iter != buffer.end(); iter++)
         {
             cout<<*iter<<endl;
         }
         
      }else if(commend_category == "A")
      {
         int count = std::stoi(results[1]);
         
         for (int j =0; j <count; j++)
         {
             if(buffer.size() ==  buffer_size)
                  buffer.pop_front();
                  
             string part_of_buffer;
             cin>>part_of_buffer;
             buffer.push_back(part_of_buffer);
         }
      }else if(commend_category == "R")
      {
         int count = std::stoi(results[1]);
         
         for(int j = 0; j < count; j++)
             buffer.pop_front();
      }
   }

 
    
    return 0;
}