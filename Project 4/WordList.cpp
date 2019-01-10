#include "provided.h"
#include <string>
#include <vector>
#include "MyHash.h"
#include <functional>
#include <fstream>
#include <iostream>

using namespace std;

class WordListImpl
{
public:
    WordListImpl()
    {
    }
    
    ~WordListImpl()
    {
    }
    
    bool loadWordList(string filename);
    bool contains(string word) const;
    vector<string> findCandidates(string cipherWord, string currTranslation) const;
    
private:
    MyHash<string, vector<string>> m_hash;
    string getPattern(string word) const;
};

bool WordListImpl::loadWordList(string filename)
{
    string s = "";
    ifstream infile(filename);
    if(!infile)
        cerr << "Error: Cannot open data.txt!" << endl;
    
    while (getline(infile, s))
    {
        
        s = "cat";
        string wordPattern = getPattern(s);
        //if(wordPattern == "FALSE")
         //   return false;
        
        
        
        vector<string>* v;
        v = m_hash.find(s);
        if(v != nullptr)
        {
            v->push_back(s);
            m_hash.associate(wordPattern, *v);
        }
        else if(v == nullptr)
        {
            vector<string> newVector;
            newVector.push_back(s);
            m_hash.associate(wordPattern, newVector);
        }
    }

    return true;// This compiles, but may not be correct
}

bool WordListImpl::contains(string word) const
{
    string wordPattern = getPattern(word);
    const vector<string>* v = m_hash.find(wordPattern);
    
    if(v != nullptr)
    {
        vector<string>::const_iterator it;
        it = v->begin();
        while(it != v->end())
        {
            if((*it) == word)
                return true;
            it++;
        }
    }
    return false; // This compiles, but may not be correct
}

vector<string> WordListImpl::findCandidates(string cipherWord, string currTranslation) const
{

    vector<string> candidates;
    
    
    if(cipherWord.size()!=currTranslation.size())
        return vector<string>();
    
    for(int i = 0; i < cipherWord.size(); i++)
    {
        if(!isalpha(cipherWord[i]) && cipherWord[i] != '\'')
            return vector<string>();
        else if(isalpha(cipherWord[i]))
            if(islower(cipherWord[i]))
                toupper(cipherWord[i]);
    }
    for(int i = 0; i < currTranslation.size(); i++)
    {
        if(!isalpha(currTranslation[i]) && (currTranslation[i] != '\'' || currTranslation[i] != '?'))
            return vector<string>();
        else if(isalpha(currTranslation[i]))
            if(islower(currTranslation[i]))
                toupper(currTranslation[i]);
    }
    
    string wordPattern = getPattern(cipherWord);
    
    const vector<string>* v = m_hash.find(wordPattern);
    if(v == nullptr)
        return vector<string>();
    
    vector<string>:: const_iterator it;
    
    for(it = v->begin(); it != v->end(); it++)
    {
        bool isCandidate = true;
        string maybeCandidate = (*it);
        for(int j = 0; j < maybeCandidate.size(); j++)
        {
            if(isalpha(currTranslation[j]))
                if(maybeCandidate[j] != currTranslation[j])
                    isCandidate = false;
            if(currTranslation[j] == '?')
                if(!isalpha(maybeCandidate[j]))
                    isCandidate = false;
            if(currTranslation[j] == '\'')
                if(maybeCandidate[j] != '\'')
                    isCandidate = false;
        }
        if(isCandidate)
            candidates.push_back(maybeCandidate);
    }
    return candidates;  // This compiles, but may not be correct
}

//***** hash functions for string, int, and char *****

unsigned int hash(const std::string& s)
{
    return std::hash<std::string>()(s);
}

unsigned int hash(const int& i)
{
    return std::hash<int>()(i);
}

unsigned int hash(const char& c)
{
    return std::hash<char>()(c);
}

string WordListImpl::getPattern(string s) const
{
    string letterPattern = "";
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int numUnique = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(islower(s[i]))
            toupper(s[i]);
        if(!isalpha(s[i]) && s[i] != '\'')
            return "FALSE";
        
        for(int j = 0; j < i; j++)
        {
            if(s[j] == s[i])
            {
                letterPattern += letterPattern[j];
                break;
            }
        }
        if(letterPattern.size() == i)
        {
            letterPattern += alphabet[numUnique];
            numUnique++;
        }
    }
    return letterPattern;
}



//******************** WordList functions ************************************

// These functions simply delegate to WordListImpl's functions.
// You probably don't want to change any of this code.

WordList::WordList()
{
    m_impl = new WordListImpl;
}

WordList::~WordList()
{
    delete m_impl;
}

bool WordList::loadWordList(string filename)
{
    return m_impl->loadWordList(filename);
}

bool WordList::contains(string word) const
{
    return m_impl->contains(word);
}

vector<string> WordList::findCandidates(string cipherWord, string currTranslation) const
{
   return m_impl->findCandidates(cipherWord, currTranslation);
}
