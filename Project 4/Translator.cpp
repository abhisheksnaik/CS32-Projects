//
//  Translator.h
//  test
//
//  Created by Abhishek Naik on 3/13/18.
//  Copyright © 2018 AbhishekNaik. All rights reserved.
//

#ifndef Translator_h
#define Translator_h

#include "provided.h"
#include <string>
#include <map>
#include <cctype>
#include <iostream>

using namespace std;

class TranslatorImpl
{
public:
    TranslatorImpl();
    bool pushMapping(string ciphertext, string plaintext);
    bool popMapping();
    string getTranslation(const string& ciphertext) const;
    /*void print()
    {
        printMap();
    }
     */
private:
    vector <map<char, char>> m_maps;
    int m_nMaps;
    int pushCounter;
    int popCounter;
    void printMap();
};

TranslatorImpl::TranslatorImpl()
{
    //m_maps.push_back(const_reference __x)
    map<char, char> temp;
    for(int i = 65; i < 91; i++)
    {
        
        temp[(char)i] = '?';
    }
    m_nMaps = 0;
    m_maps.push_back(temp);
    m_nMaps++;
    pushCounter = 0;
    popCounter = 0;
}

bool TranslatorImpl::pushMapping(string ciphertext, string plaintext)
{
    if(ciphertext.size() != plaintext.size())
        return false;
    
    for(int i = 0; i < plaintext.size(); i++)
    {
        if(!isalpha(ciphertext[i]) || !isalpha(plaintext[i]))
            return false;
        if(islower(plaintext[i]))
            toupper(plaintext[i]);
        if(islower(ciphertext[i]))
            toupper(ciphertext[i]);
    }
    
    //need to check for duplicate cipher and plain texts
    
    map<char, char> temp = m_maps[m_nMaps-1];
    
    
    for(int i = 0; i < plaintext.size(); i++)
    {
        if(temp[ciphertext[i]] == '?')
        {
            temp[ciphertext[i]] = plaintext[i];
        }
        else
            return false;
    }
    
    m_maps.push_back(temp);
    m_nMaps++;
    pushCounter++;
    return true;
}

bool TranslatorImpl::popMapping()
{
    if(pushCounter == popCounter)
        return false;  // This compiles, but may not be correct
    
    m_maps.pop_back();
    m_nMaps--;
    return true;
}

string TranslatorImpl::getTranslation(const string& ciphertext) const
{
    string translated = "";
    
    map<char,char>::const_iterator it;
    
    for(int i = 0; i < ciphertext.size(); i++)
    {
        if(!isalpha(ciphertext[i]))
        {
            translated += ciphertext[i];
            continue;
        }
        it = m_maps[m_nMaps-1].begin();
        while(it != m_maps[m_nMaps-1].end())
        {
            if(ciphertext[i] == (*it).first)
            {
                translated += (*it).second;
                break;
            }
            it++;
        }
        if(it == m_maps[m_nMaps-1].end())
        {
            translated += '?';
        }
    }
    return translated;
}

void TranslatorImpl::printMap()
{
    map<char, char>::const_iterator it;
    it = m_maps[m_nMaps-1].begin();
    while(it != m_maps[m_nMaps-1].end())
    {
        cout<<(*it).first<<"->"<<(*it).second<<endl;
        it++;
    }
}

//******************** Translator functions ************************************

// These functions simply delegate to TranslatorImpl's functions.
// You probably don't want to change any of this code.

Translator::Translator()
{
    m_impl = new TranslatorImpl;
}

Translator::~Translator()
{
    delete m_impl;
}

bool Translator::pushMapping(string ciphertext, string plaintext)
{
    return m_impl->pushMapping(ciphertext, plaintext);
}

bool Translator::popMapping()
{
    return m_impl->popMapping();
}

string Translator::getTranslation(const string& ciphertext) const
{
    return m_impl->getTranslation(ciphertext);
}
/*void Translator::print()
{
    m_impl->print();
}

*/

#endif /* Translator_h */
