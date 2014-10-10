#include<iostream>
#include<string>
#include <map>
#include <functional>
#include <vector>
#include <algorithm>

// PROBLEM FROM https://evernote.com/careers/challenge.php
using namespace std;

class cmp { 
    
public:
  bool operator() (const string& left, const string& right) const 
  {
      return left<right;
      
  }  
};

template<template <typename> class P = std::less >
struct compare_pair_second {
    template<class T1, class T2> bool operator()(const std::pair<T1,T2>&left, const std::pair<T1,T2>&right) {
        return P<T2>()(left.second, right.second);
    }
};

int main()
{
    
    
    int testcase;
    map<string, int,  cmp> word_map;
    
    
    cin >> testcase;
    
    for (int i =0; i < testcase; i++)
    {
        string word;
        cin >> word;
        
        
        
        auto iter = word_map.find(word);
        if(iter == word_map.end())
        {
           int count = 1;
            word_map.insert( map<string, int>::value_type(word, count));
        }else{
           iter->second += 1;
           
        }
       
    }
    
    std::vector<std::pair<string, int> > vec(word_map.begin(), word_map.end());
    stable_sort(vec.begin(), vec.end(), compare_pair_second<std::greater>());
    int topN;
    cin >> topN;
    
    
    auto top_iter = vec.begin();
    for(int j =0; j < topN; j++)
    {
        
        cout<<top_iter->first<<endl;
        
        top_iter++;
    }
    
    
    
    return 0;
}