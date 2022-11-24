/**
Joe Francesconi
CPSC 2120
Stackbased_postfix_expression_calculator
**/

#include <string>
#include <stack>
#include <iostream>

using namespace std;

//Calculates a postfix expression with integer operands using a stack
//The expression is represented using an array of strings
//Each string is either an operand or operator symbol
//Operator symbols:
//"+" addition
//"-" subtraction
//"*" multiplication
//"/" divison
//"%" remainder
//Example expression: "8", "5", "-" evaluates to a result of 3:
//1: push 8, 2: push 5,
//3: "-"-> pop top two values, earlier value is the left-side operand: 8 - 5
//The result of the operation (8-5) is 3, push 3 onto stack
//After evaluation of the expression, the final result should be
//the only value on the stack, return 0 if the stack is
//non-empty after popping the result
//Return 0 if expression is zero-length or if there are insufficient operands
//for an operation
//The STL Stack class can be used
//To easily convert a numeric string to an int you may use the stoi() function
//which takes a string as a parameter and returns a string

//checks if value is a number
bool isNum(string);

//Calculates the postfix expression
int calculatePostfixExpression(string expression[], int length)
{
    stack<int> S;
    
    if (length == 1){
        if (isNum(expression[0])){
            return stoi(expression[0]);
        }
        return 0;
    }
    
    if (length < 3){
        return 0;
    }
    
    for (int i = 0; i < length; i++){
        if (isNum(expression[i])){
            S.push(stoi(expression[i]));
        }else{
            int sVal = S.top();
            S.pop();
            int iVal = S.top();
            S.pop();
            
            if(expression[i] == "+"){
                S.push(iVal + sVal);
            }
            else if(expression[i] == "-"){
                S.push(iVal - sVal);
            }
            else if(expression[i] == "*"){
                S.push(iVal * sVal);
            }
            else if(expression[i] == "/"){
                S.push(iVal / sVal);
            }
            else if(expression[i] == "%"){
                S.push(iVal % sVal);
            }
        }
    }
    
    int answer = S.top();
    S.pop();
    if (!S.empty()){
        return 0;
    }else{
        return answer;
    }
}

bool isNum(string s){
    if (s[0] >= '0' && s[0] <= '9'){
        return true;
    }else{
        return false;
    }
}
