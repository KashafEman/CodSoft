//TIC TAC TOE GAME
#include<iostream>
using namespace std;
char box[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int column;
bool tye;
string player1,player2; 
char choice='X';
//FUNCTION FOR THE STRUCTURE OF GAME
void structure(){
	cout<<" |           |"<<endl;
	cout<<box[0][0]<<"| "<<box[0][1]<<"         | "<<box[0][2]<<endl;
	cout<<" |           |"<<endl;
	cout<<"_______________"<<endl;
	cout<<" |           |"<<endl;
	cout<<box[1][0]<<"| "<<box[1][1]<<"         | "<<box[1][2]<<endl;
	cout<<" |           |"<<endl;
	cout<<"_______________"<<endl;
	cout<<" |           |"<<endl;
	cout<<box[2][0]<<"| "<<box[2][1]<<"         | "<<box[2][2]<<endl;
	cout<<" |           |"<<endl;
}
//FUNCTION FOR THE GAME MOVES
void moves(){
	int digit;
	if(choice=='X'){
		cout<<player1<<" please enter the box you want to fill."<<endl;
		cin>>digit;
	}
	if(choice=='O'){
		cout<<player2<<" please enter the box you want to fill."<<endl;
		cin>>digit;
	}
	//ROWS AND COLUMNS ACCORDING TO DIGITS
	if(digit==1){
		row=0;
		column=0;
	}
		else if(digit==2){
		row=0;
		column=1;
	}
		else if(digit==3){
		row=0;
		column=2;
	}
		else if(digit==4){
		row=1;
		column=0;
	}
		else if(digit==5){
		row=1;
		column=1;
	}
		else if(digit==6){
		row=1;
	    column=2;
	}
		else if(digit==7){
		row=2;
		column=0;
	}
		else if(digit==8){
		row=2;
		column=1;
	}
		else if(digit==9){
		row=2;
		column=2;
	}
	else{
		cout<<" Invalid move."<<endl;
	}
	//CONDITIONS FOR ENTERING THE CHOICE IN SPACES  
	if (choice == 'X' && box[row][column] != 'X' && box[row][column] != 'O') {
    box[row][column] = 'X';  
    choice = 'O';
} else if (choice == 'O' && box[row][column] != 'X' && box[row][column] != 'O') {
    box[row][column] = 'O';  
    choice = 'X';
}

	//WHEN NO CHOICE IS AVAILABLE
	else{
		cout<<" There is no empty space."<<endl;
		moves();
	}
	structure();
}
//FUNCTION FOR THE CONDITIONS OF WIN LOSS OR DRAW
bool conditions(){
	for(int i=0;i<3;i++){
		//CONDITION FOR WIN 
		if(box[i][0]==box[i][1]&&box[i][0]==box[i][2]||box[0][i]==box[1][i]&&box[0][i]==box[2][i]){
			return true;
		}
	}
	//DIAGONAL WIN CONDITION
	if(box[0][0]==box[1][1]&&box[1][1]==box[2][2]||box[0][2]==box[1][1]&&box[1][1]==box[2][0]){
		return true;
	}
	//CONDITION FOR TYE
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(box[i][j]!='X'&&box[i][j]!='O'){
				return false;
			}
		}
	}
	tye=true;
	return false;
}

int main(){
	cout<<" TIC TAC TOE GAME"<<endl;
	cout<<" Enter the name of player 1: "<<endl;
	cin>>player1;
	cout<<" Enter the name of player 2: "<<endl;
	cin>>player2;
	cout<<player1<<" is the first player so they will play first."<<endl;
	//CALLING FUNCTION
	while(!conditions()){
		structure();
		moves();
		conditions();//functions here
	}
	if(choice=='X'&&tye==false){
		cout<<player2<<" Wins.\a"<<endl;
	}
	else if(choice=='O'&&tye==false){
		cout<<player1<<" Wins.\a"<<endl;
	}
	else{
		cout<<" Match results in a DRAW!!\a"<<endl;
	}
}