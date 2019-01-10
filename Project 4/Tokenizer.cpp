#include "provided.h"
#include <string>
#include <vector>
using namespace std;

class TokenizerImpl
{
public:
    TokenizerImpl(string separators);
    vector<string> tokenize(const string& s) const;
private:
    vector<char> sep;
};

TokenizerImpl::TokenizerImpl(string separators)
{
    for(int i = 0; i < separators.size(); i++)
    {
        sep.push_back(separators[i]);
    }
}

vector<string> TokenizerImpl::tokenize(const string& s) const
{
    vector<string> sep_words;
    string temp = "";
    
    for(int i = 0; s.size(); i++)
    {
        for(int j = 0; j< sep.size(); j++)
        {
            if(s[i] == sep[j])
            {
                sep_words.push_back(temp);
                temp = "";
                continue;
            }
        }
        temp += s[i];
    }
    
    return sep_words;  // This compiles, but may not be correct
}

//******************** Tokenizer functions ************************************

// These functions simply delegate to TokenizerImpl's functions.
// You probably don't want to change any of this code.

Tokenizer::Tokenizer(string separators)
{
    m_impl = new TokenizerImpl(separators);
}

Tokenizer::~Tokenizer()
{
    delete m_impl;
}

vector<string> Tokenizer::tokenize(const string& s) const
{
    return m_impl->tokenize(s);
}
