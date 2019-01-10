//
//  main.cpp
//  evaluate
//
//  Created by Abhishek Naik on 2/6/18.
//  Copyright © 2018 AbhishekNaik. All rights reserved.
//

#include <iostream>
#include "Map.h"
#include <string>
#include <stack>
#include <cctype>
#include <cassert>
using namespace std;


bool hasCorrectSyntax(string infix);
bool inToPost(string, string&);
bool precedence(char a, char b);
void removeSpace(string& infix);


int evaluate(string infix, const Map& values, string& postfix, int& result)
{
    removeSpace(infix);
    
    if(!inToPost(infix, postfix))
        return 1;
    
    stack<int> opstack;
    
    
    for(int i = 0; i < postfix.length(); i++)
    {
        if(islower(postfix[i]))
        {
            char val1 = postfix[i];
            int val2 = 0;
            if(!(values.get(val1, val2)))
                return 2;
            opstack.push(val2);
        }
        else
        {
            int operand2 = opstack.top();
            opstack.pop();
            if(opstack.top() == 0)
                return 1;
            int operand1 = opstack.top();
            opstack.pop();
            if(postfix[i] == '+')
                opstack.push(operand2 + operand1);
            if(postfix[i] == '-')
                opstack.push(operand1 - operand2);
            if(postfix[i] == '*')
                opstack.push(operand1*operand2);
            if(postfix[i] == '/')
            {
                if(operand2 == 0)
                    return 3;
                else
                    opstack.push(operand1/operand2);
            }
        }
    }
    result = opstack.top();
    
    return 0;
}


// Evaluates an integer arithmetic expression
//   If infix is a syntactically valid infix integer expression whose
//   only operands are single lower case letters (whether or not they
//   appear in the values map),

//   then postfix is set to the postfix
//   form of the expression;

//   otherwise postfix may or may not be
//   changed, result is unchanged, and the function returns 1.
//
//   if infix is syntactically valid but contains at least one lower
//   case letter operand that does not appear in the values map, then
//   result is unchanged and the function returns 2.

//   If infix is
//   syntactically valid and all its lower case operand letters
//   appear in the values map, then if evaluating the expression
//   (using for each letter in the expression the value in the map
//   that corresponds to it) attempts to divide by zero, then result
//   is unchanged and the function returns 3;

//   otherwise, result is
//   set to the value of the expression and the function returns 0.



bool inToPost(string infix, string& postfix)
{
    int counter = 0;
    if(infix == "")
        return false;
    postfix = "";
    stack <char> opstack;
    
    for(int i = 0; i < infix.length(); i++)
    {
        switch(infix[i])
        {
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'h':
            case 'i':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'o':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'u':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
            {
                if(i!=0 && (infix[i-1] == ')' || islower(infix[i-1])))
                    return false;
                    
                postfix +=infix[i];
                break;
            }
                
                
            case '(':
            {
                if(i!=0 && (infix[i-1] == ')' || islower(infix[i-1])))
                    return false;
                if(i == infix.length()-1)
                    return false;
                opstack.push(infix[i]);
                counter++;
                break;
            }
                
                
            case ')':
            {
                if(i==0 || infix[i-1] == '(' || infix[i-1] == '-' || infix[i-1] == '+' || infix[i-1] == '*' || infix[i-1] == '/')
                    return false;
                
                while(opstack.top()!= '(')
                {
                    postfix += opstack.top();
                    opstack.pop();
                }
                opstack.pop();
                counter--;
                break;
            }
                
                
            
            case '/':
            case '*':
            case '+':
            case '-':
            {
                if(i==0 || infix[i-1] == '(' || infix[i-1] == '-' || infix[i-1] == '+' || infix[i-1] == '*' || infix[i-1] == '/')
                    return false;
                if(i == infix.length()-1)
                    return false;
                
                while(!(opstack.empty()) && (opstack.top() != '(') && precedence(infix[i], opstack.top()))
                {
                    postfix += opstack.top();
                    opstack.pop();
                }
                opstack.push(infix[i]);
                break;
            }
                
            
            default:
                return false;
        }
    }
    while(!opstack.empty())
    {
        postfix += opstack.top();
        opstack.pop();
    }
    if(counter != 0)
        return false;
    
    
    return true;
}

bool precedence(char a, char b)
{
    if(a == '*' || a == '/')
       {
           if(b == '*' || b == '/')
               return true;
            else
                return false;
       }
    else
        return true;
        
}

void removeSpace(string& infix)
{
    string newInfix = "";
    for(int i = 0; i < infix.length(); i++)
    {
        if(!isspace(infix[i]))
            newInfix += infix[i];
    }
    infix = newInfix;
}

/*
int main()
{
    char vars[] = { 'a', 'e', 'i', 'o', 'u', 'y', '#' };
    int  vals[] = {  3,  -9,   6,   2,   4,   1  };
    Map m;
    for (int k = 0; vars[k] != '#'; k++)
        m.insert(vars[k], vals[k]);
    string pf;
    int answer;
    assert(evaluate("a+ e", m, pf, answer) == 0  &&
           pf == "ae+"  &&  answer == -6);
    answer = 999;
    assert(evaluate("", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("a+", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("a i", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("ai", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("()", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("y(o+u)", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("a+E", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("(a+(i-o)", m, pf, answer) == 1  &&  answer == 999);
    // unary operators not allowed:
    assert(evaluate("-a", m, pf, answer) == 1  &&  answer == 999);
    assert(evaluate("a*b", m, pf, answer) == 2  &&
           pf == "ab*"  &&  answer == 999);
    assert(evaluate("y +o *(   a-u)  ", m, pf, answer) == 0  &&
           pf == "yoau-*+"  &&  answer == -1);
    answer = 999;
    assert(evaluate("o/(y-y)", m, pf, answer) == 3  &&
           pf == "oyy-/"  &&  answer == 999);
    assert(evaluate(" a  ", m, pf, answer) == 0  &&
           pf == "a"  &&  answer == 3);
    assert(evaluate("((a))", m, pf, answer) == 0  &&
           pf == "a"  &&  answer == 3);
    cout << "Passed all tests" << endl;
}
 */
