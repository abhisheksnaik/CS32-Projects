//
//  Map.cpp
//  map
//
//  Created by Abhishek Naik on 1/22/18.
//  Copyright © 2018 AbhishekNaik. All rights reserved.
//

#include "Map.h"


Map::Map()// Create an empty map (i.e., one with no key/value pairs)
{
    m_listSize = 0;
}

bool Map::empty() const // Return true if the map is empty, otherwise false.
{
    if(size() == 0)
        return true;
    else
        return false;
}

int Map::size() const  // Return the number of key/value pairs in the map.
{
    return m_listSize;
}

bool Map::insert(const KeyType& key, const ValueType& value){
    if(size() == DEFAULT_MAX_ITEMS)
        return false;
    for(int i = 0; i < m_listSize; i++){
        if(key == m_pairs[i].pairKey)
            return false;
    }
    m_pairs[m_listSize].pairKey = key;
    m_pairs[m_listSize].pairValue = value;
    m_listSize++;
    return true;
}

bool Map::update(const KeyType& key, const ValueType& value)
{
    for(int i = 0; i < m_listSize; i++){
        if(key == m_pairs[i].pairKey){
            m_pairs[i].pairValue = value;
            return true;
        }
    }
    return false;
}

bool Map::insertOrUpdate(const KeyType& key, const ValueType& value)
{
    for(int i = 0; i < m_listSize; i++){
        if(key == m_pairs[i].pairKey){
            m_pairs[i].pairValue = value;
            return true;
        }
    }

    if(m_listSize == DEFAULT_MAX_ITEMS)
        return false;
    
    m_pairs[m_listSize].pairKey = key;
    m_pairs[m_listSize].pairValue = value;
    m_listSize++;
    return true;
}

bool Map::erase(const KeyType& key)
{
    for(int i = 0; i < m_listSize; i++)
    {
        if(key == m_pairs[i].pairKey)
        {
            m_pairs[i] = m_pairs[m_listSize-1];
            m_listSize--;
            return true;
        }
    }
    return false;
}

bool Map::contains(const KeyType& key) const
{
    for(int i = 0; i < m_listSize; i++)
    {
        if(key == m_pairs[i].pairKey)
        {
            return true;
        }
    }
    return false;
}

bool Map::get(const KeyType& key, ValueType& value) const
{
    for(int i = 0; i < m_listSize; i++)
    {
        if(key == m_pairs[i].pairKey)
        {
            value = m_pairs[i].pairValue;
            return true;
        }
    }
    return false;
}

bool Map::get(int i, KeyType& key, ValueType& value) const
{
    if(i >= 0 && i < m_listSize)
    {
        key = m_pairs[i].pairKey;
        value = m_pairs[i].pairValue;
        return true;
    }
    return false;
}

void Map::swap(Map& other)
{
    Map temp;
    temp = other;
    other.m_listSize = m_listSize;
    
    for(int i = 0; i < m_listSize; i++)
    {
        other.m_pairs[i].pairKey = m_pairs[i].pairKey;
        other.m_pairs[i].pairValue = m_pairs[i].pairValue;
    }
   
    m_listSize = temp.m_listSize;
    for(int i = 0; i < m_listSize; i++)
    {
        m_pairs[i].pairKey = temp.m_pairs[i].pairKey;
        m_pairs[i].pairValue = temp.m_pairs[i].pairValue;
    }
    
}










