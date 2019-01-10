//
//  main.cpp
//  CS32HW3
//
//  Created by Abhishek Naik on 2/12/18.
//  Copyright © 2018 AbhishekNaik. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

//Your declarations and implementations would go here

class Investment
{
public:
    Investment(string name, int num)
    {
        m_name = name;
        m_price = num;
    }
    virtual string name() const
    {
        return m_name;
    }
    virtual bool fungible() const = 0;
    
    virtual string description() const = 0;
    
    virtual int purchasePrice() const
    {
        return m_price;
    }
    virtual ~Investment()
    {
    }
    
private:
    string m_name;
    int m_price;
    
};

class Stock: public Investment
{
public:
    Stock(string name, int num, string ticker)
    :Investment(name, num)
    {
        m_ticker = ticker;
    }
    
    virtual bool fungible() const
    {
        return true;
    }
    
    virtual string description() const
    {
        return ("stock trading as "+ m_ticker);
    }
    virtual ~Stock()
    {
        cout<<"Destroying "<<name()<<", a stock holding"<<endl;
    }
    
    
    
private:
    string m_ticker;
    
};

class House: public Investment
{
public:
    House(string name, int num)
    :Investment(name, num)
    {
    }
    
    virtual bool fungible() const
    {
        return false;
    }
    
    virtual string description() const
    {
        return ("house");
    }
    
    virtual ~House()
    {
        cout<<"Destroying "<<name()<<", a "<<description()<<endl;
    }

    
private:
    string m_ticker;
    
};


class Painting: public Investment
{
public:
    Painting(string name, int num)
    :Investment(name, num)
    {
    }
    
    virtual bool fungible() const
    {
        return false;
    }
    
    virtual string description() const
    {
        return ("painting");
    }
    virtual ~Painting()
    {
        cout<<"Destroying "<<name()<<", a "<<description()<<endl;
    }

    
    
private:
    string m_ticker;
    
};
