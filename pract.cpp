/*Given a string s containing just the characters 
'(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
*/

#include<iostream>
#include <bits/stdc++.h>

using namespace std;

// Is valid. ({[]}) or (){}[]
bool IsValid(char * string){
    //In order to open brackets at the top of stack and compare 
    //with the occring characters.
    stack<char> s;
     
    int len = 0;
    char* tmp = string;
     while(*tmp != '\0'){
         tmp++;
         len++;
     }
    
    //If the character count is odd,
    //that means the string does not complete its pair.
    if(len%2) return false;

    for(int i = 0; i < len; i++){
        //placing the open brackets in stack.
        if(string[i] == '(' || string[i] == '{' || string[i] == '['){
            s.push(string[i]);
        }
        // checking with the top of stack and current character.
        else if(!s.empty() && string[i] == '}' && s.top() == '{'){
            s.pop();
        }
       else if(!s.empty() && string[i] == ']' && s.top() == '['){
            s.pop();
        }
       else if(!s.empty() && string[i] == ')' && s.top() == '('){
            s.pop();
        }
        else{
            return false;
        }
    }
    return s.empty();
}


//driver code.
int main()
{   
    char str[] = "(){}[]{}";
    if(IsValid((str)))
    cout << "string is valid" << endl;

    else
    cout << "string is not valid "<< endl;

    return 0;
}
