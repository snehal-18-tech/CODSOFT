/*To develope a simple caculator performing different arithmetic operations 
like addition ,multiplication ,substraction and division*/

#include<iostream>
using namespace std;
//function for addition of two numbers 
int addition(int a,int b)
{
    //will return addition
    return a+b;
}
//function for subtraction of two numbers
int substraction(int a,int b)
{
    //it will return substraction
    return a-b;
}
//function for multiplication of two numbers
int multiplication(int a,int b)
{
    //it will return multiplication
    return a*b;
}
//function for division of two numbers
int division(int a,int b)
{
    //try block to handle divide with zero exception
    try
    {
        if(b!=0)
        {
          return a/b;//return the division only when denominator!=0
        }
        else
        {
        throw(b); //throw statement
        }
         }
         catch(int b) //catch block
         {
            cout<<"Can't divide with zero"<<endl;
         }
}
int main()
{
   // calculator obj;
    int choice;
    int a,b;
    cout<<"Enter the first number"<<endl; //input for 1st number
    cin>>a;
    cout<<"Enter the second number"<<endl;//input for 2nd number
    cin>>b;
    do{
    cout<<" 1.Addition\n 2.Subtraction\n 3.Multiplication\n 4.Division\n 5.EXIT"<<endl;
    cout<<"Enter your choice :";
    cin>>choice;
    switch(choice)
    {
        case 1:
        cout<<"Addition:"<<addition(a,b)<<endl;//function call
        break;
        case 2:
        cout<<"Substraction:"<<substraction(a,b)<<endl;//function call
        break;
        case 3:
        cout<<"Multiplication:"<<multiplication(a,b)<<endl;//function call
        break;
        case 4:
        cout<<"Division:"<<division(a,b)<<endl;//function call
        break;
        case 5:
        exit;
        }
    }while(choice!=5);
    return 0;
}