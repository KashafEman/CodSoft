//number guessing game
#include<iostream>
//including the standard library to generate random number
#include<cstdlib>
//include the ctime library to add time function
#include<ctime>
using namespace std;
//main body of the 
int main(){
	int guess;
	int count=0;
	int num;
	srand(time(0));//for the generation of random number
	num = rand() % 100 + 1; //number between 1 and 100
	cout<<" NUMBER GUESSING GAME \a"<<endl;
	cout<<" You have limited tries. Best of Luck "<<endl;
	do{
	cout<<" Guess the number between 1 and 100"<<endl;
	cin>>guess;
	count++;
	if(num>guess){
		cout<<" Lower than the number."<<endl;
	}
	else if(num<guess){
		cout<<" Higher than the number."<<endl;
	}
	else{
		cout<<" Your guess is right \a"<<endl;
	}
}
while(guess!=num);
{
	return 0;
}
}
