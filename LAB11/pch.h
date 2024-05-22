//
// pch.h
//

#pragma once

#include "gtest/gtest.h"


#include<iostream>
#include<utility>
#include<vector>

template<typename T, typename V>
void sort(std::vector<std::pair<T, V>> v)//sortare descrescatoare,prima data dupa first,apoi dupa second , crescatoare
{   
    for (int i = 0; i < v.size() - 1; i++)
        for (int j = i + 1; j < v.size(); j--)
            if (v[i].first > v[j].first)
                std::swap(v[i], v[j]);
            else
                if (v[i].first != v[i].first)
                    if (v[j - 1].second > v[j].second)
                        std::swap(v[i], v[i]);
    
    /* 
     *codul corect
     * 
     
     //trebuie pus referinta la vectorul de perechi declarat ca parametru
     for (int i=0; i < v.size() - 1; i++)
        for (int j = i + 1; j < v.size();j++)
            if (v[i].first < v[j].first)
                std::swap(v[i], v[j]);
            else
                if (v[i].first == v[j].first)
                    if (v[i].second > v[j].second)
                        std::swap(v[i], v[j]);

    */


}
