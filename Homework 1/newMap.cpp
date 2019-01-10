o//
//  Map.cpp
//  map
//
//  Created by Abhishek Naik on 1/22/18.
//  Copyright © 2018 AbhishekNaik. All rights reserved.
//

#include "newMap.h"


Map::Map(int num)// Create a map with num spaces
{
    m_listSize = num;
    m_pairs = new pair[m_listSize];
    m_nPairs = 0;
}

Map::Map()// Create an empty map (i.e., one with no key/value pairs)
{
    m_listSize = DEFAULT_MAX_ITEMS;
    m_pairs = new pair[DEFAULT_MAX_ITEMS];
    m_nPairs = 0;
}

Map::Map(const Map &old)
{
    m_listSize = old.m_listSize;
    m_nPairs = old.m_nPairs;
    m_pairs = new pair[m_listSize];
    for(int i = 0; i < m_nPairs; i++)
    {
        m_pairs[i] = old.m_pairs[i];
    }
}

Map::~Map()
{
    delete []m_pairs;
}

Map& Map::operator=(const Map &old)
{
    delete []m_pairs;
    m_listSize = old.m_listSize;
    m_pairs = new pair[m_listSize];
    m_nPairs = old.m_nPairs;
    
    for(int i = 0; i < m_nPairs; i++)
    {
        m_pairs[i] = old.m_pairs[i];
    }
    
    return (*this);
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
    return m_nPairs;
    
}

bool Map::insert(const KeyType& key, const ValueType& value){
    if(m_nPairs == m_listSize)
        return false;
    for(int i = 0; i < m_nPairs; i++){
        if(key == m_pairs[i].pairKey)
            return false;
    }
    m_pairs[m_nPairs].pairKey = key;
    m_pairs[m_nPairs].pairValue = value;
    m_nPairs++;
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
    for(int i = 0; i < m_nPairs; i++){
        if(key == m_pairs[i].pairKey){
            m_pairs[i].pairValue = value;
            return true;
        }
    }
    
    if(m_listSize == DEFAULT_MAX_ITEMS)
        return false;
    
    m_pairs[m_nPairs].pairKey = key;
    m_pairs[m_nPairs].pairValue = value;
    m_nPairs++;
    return true;
}

bool Map::erase(const KeyType& key)
{
    for(int i = 0; i < m_nPairs; i++)
    {
        if(key == m_pairs[i].pairKey)
        {
            m_pairs[i] = m_pairs[m_nPairs-1];
            m_nPairs--;
            return true;
        }
    }
    return false;
}

bool Map::contains(const KeyType& key) const
{
    for(int i = 0; i < m_nPairs; i++)
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
    for(int i = 0; i < m_nPairs; i++)
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
    if(i >= 0 && i < m_nPairs)
    {
        key = m_pairs[i].pairKey;
        value = m_pairs[i].pairValue;
        return true;
    }
    return false;
}

void Map::swap(Map& other)//fix this if needed
{
    Map temp;
    temp = other;
    other = *this;
    *this = temp;
    
    
    
    /*for(int i = 0; i < m_listSize; i++)
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
     */
    
}









