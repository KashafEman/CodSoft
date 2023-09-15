//code for the calculator in C++
//Using the standard and the Maths library
#include<iostream>
#include<cmath>
using namespace std;
//main Body
int main(){
	//the main driver code
	//initializing the variables
	int a,b,sum,diff,div,product;
	char opt;
	//Prompting the user for the input
	cout<<"Enter the number you want."<<endl;
	cin>>a;
	cout<<"Enter the other number."<<endl;
	cin>>b;
	cout<<"Enter the arithmetic operation you want to perform."<<endl;
	cout<<"Enter \"+\" for SUM, \"-\" for SUBTRACTION, \"/\"for DIVISION and \"*\" for MULTIPLICATION"<<endl;
	cin>>opt;
	//using the switch system to execute the code
	switch(opt){
		//Case for the addition of the numbers
		case '+':
			sum=a+b;
			cout<<" The sum of the given number is: "<<sum;
			break;
			//Case for Subtracting the numbers
			case '-':
				diff=a-b;
			cout<<" The difference of the given number is: "<<diff;
			break;
			//Case for Division
			case '/':
				div=a/b;
			cout<<" The division of the given number is: "<<div;
			break;
			//Product of the numbers
			case '*':
				product=a*b;
			cout<<" The product of the given number is: "<<product;
			break;
			//Error handling in the calculator
			default:
				cout<<" Enter the correct information"<<endl;
				break;
			
				}
	}