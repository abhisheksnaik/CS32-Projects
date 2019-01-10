#include "newMap.h"
#include <iostream>
#include <cassert>
using namespace std;

// To test a Map from string to double, leave the following line commented out;
// to test a Map from int to string, remove the "//".

//#define INT_TO_STRING

#ifdef INT_TO_STRING

const KeyType DUMMY_KEY = 9876543;
const ValueType DUMMY_VALUE = "Ouch";
const KeyType NO_SUCH_KEY = 42;
const KeyType KEY1 = 123456789;
const ValueType VALUE1 = "Wow!";

#else // assume string to double

const KeyType DUMMY_KEY = "hello";
const ValueType DUMMY_VALUE = -1234.5;
const KeyType NO_SUCH_KEY = "abc";
const KeyType KEY1 = "xyz";
const ValueType VALUE1 = 9876.5;


const KeyType DUMMY_KEY2 = "hi";
const ValueType DUMMY_VALUE2 = -34.5;
const KeyType NO_SUCH_KEY2 = "poop";
const KeyType KEY2 = "abhi";
const ValueType VALUE2 = 5565.7;
const ValueType VALUE3 = 34.5;
const ValueType DUMMY_VALUE3 = 456766;

#endif

int main()
{
    Map m;
    assert(m.empty());
    ValueType v = DUMMY_VALUE;
    assert( !m.get(NO_SUCH_KEY, v)  &&  v == DUMMY_VALUE); // v unchanged by get failure
    m.insert(KEY1, VALUE1);
    assert(m.size() == 1);
    KeyType k = DUMMY_KEY;
    assert(m.get(0, k, v)  &&  k == KEY1  &&  v == VALUE1);
    
    ValueType v2 = DUMMY_VALUE2;
    assert( !m.get(NO_SUCH_KEY2, v2)  &&  v2 == DUMMY_VALUE2); // v2 unchanged by get failure
    m.insert(KEY2, VALUE2);
    assert(m.size() == 2);
    KeyType k2 = DUMMY_KEY2;
    assert(m.get(1, k2, v2)  &&  k2 == KEY2  &&  v2 == VALUE2);
    
    m.erase(KEY1);
    assert(m.size() == 1);
    
    m.update(KEY2, VALUE3);
    ValueType v3 = DUMMY_VALUE3;
    assert(m.get(KEY2, v3) && v3 == VALUE3);
    assert(!m.contains(KEY1));
    
    Map m2(5);
    
    m2.insert("daniel", 5.5);
    m2.insert("alex", 6.5);
    m2.insert("alexa", 3.4);
    m2.insert("bella", 9.6);
    m2.insert("laney", 5.7);
    assert(!m2.insert("izzy", 4.8));
    
    assert(m2.size() == 5);
    
    m.swap(m2);
    
    assert(m.contains("daniel"));
    assert(!m.contains(KEY2));
    assert(m2.contains(KEY2));
    
    
    cout << "Passed all tests" << endl;
}
