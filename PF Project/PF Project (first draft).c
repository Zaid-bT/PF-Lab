#include<stdio.h>
#include<string.h>
#include<conio.h>     // for getch() (line 103,106,183,186)
#include<stdlib.h>    // for rand() function (line 245)
#include<time.h>      // generate new random value everytime (line 239)

void Chase(int count,int p2_status);
void Target(int count,int p2_status);
int Toss();
void SuperOver();
void menu();
void clearscreen();


int score1,score2,wicket=1;
char player1[50];
char player2[50];


int main(){
	
	while(1)
	{
		int choice;
		clearscreen();
	    menu();                         // MENU
	    printf("Enter your choice: ");
	    scanf("%d", &choice);
	    
	    switch(choice)
	    {
	    	case 1:{
	    		clearscreen();
	    		printf("====================R U L E S=======================\n");
                printf("\n1)KEEP THE CAPSLOCK ON WHILE PLAYING THE GAME!!\n");
               	printf("\n2)If bowler enters an invalid input, batsman will get 6 runs.\n");
              	printf("\n3)If batsman enters an invalid input, 6 runs will be deducted from the score\n");
              	printf("\n4)Same inputs is Out.\n\n5)Different inputs, game continues.\n\n");
              	printf("Player 1 name: ");
				scanf("%s", player1);      
				printf("Player 2 name: ");
				scanf("%s", player2);  
				score1=0,score2=0;
              	Toss();
				break;
			}
			case 2:{
				clearscreen();
				printf("====================R U L E S=======================\n");
                printf("\n1)KEEP THE CAPSLOCK ON WHILE PLAYING THE GAME!!\n");
               	printf("\n2)If bowler enters an invalid input, batsman will get 6 runs.\n");
              	printf("\n3)If batsman enters an invalid input, 6 runs will be deducted from the score\n");
              	printf("\n4)Same inputs is Out.\n\n5)Different inputs, game continues.\n\n");
				break;
			}
			case 3:{
				clearscreen();
				printf("==========C R E D I T S==========\n");
				printf("This game was designed by:\n");
				printf("\n- Zaid Bin Tariq (24k-0789)\n\n- Muhammad Subhan (24k-0784)\n\n- Asad Ullah Bin Tufail (24k-0801)\n\n");
				break;
			}
			case 4:{
				printf("Exiting....\n");
				exit(0);
				break;
			}
			default:{
				printf("Invalid Input\n");
				break;
			}
		}
		printf("Press enter to to return to menu........");
		getchar();   // used to get chars: 1 for buffer
		getchar();   // 2 to detect newline character and return to menu
	}
	
	
	return 0;
}


void Chase(int count,int p2_status){
	char ball,bat;
	int n=1;  // BALL COUNT
	do{
		if(count==0){
			if(score2<score1){
				if(p2_status==1){
					printf("\t!!! %s WINS BY %d RUNS !!!\n", player2, score1-score2);
					return;
				}
				else{
					printf("\t!!! %s WINS BY %d RUNS !!!\n", player1, score1-score2);
					return;
				}
			}
			else if(score2==score1){
				SuperOver();
			}
			else{
				return;
			}
		}
		printf("Deliver ball: ");
		ball = getch();           // HIDES INPUT
		printf("*\n");
		printf("Play the shot: ");
		bat = getch();
		printf("*\n\n");
		if(ball>'6'){
			printf("Invalid input from bowler!\nPENALTY: Batsman gets 6 runs\n");
			score2+=6;	
		}
		if(ball==bat){
			wicket--;
			printf("\tOUT !!!\n\n");
			printf("==========================================\n\n");
			if(score2<score1){
				if(p2_status==1){
					printf("\t!!! %s WINS BY %d RUNS !!!\n", player2, score1-score2);
					break;
				}
				else{
					printf("\t!!! %s WINS BY %d RUNS !!!\n", player1, score1-score2);
					break;
				}
			}
			else if(score2==score1){
				printf("\t!!! MATCH DRAWN !!!\n");
				printf("==========================================\n\n");
				SuperOver();
			    break;
			}
		}
		printf("%c runs scored\n\n",bat);
		switch(bat){       // SCORE CALCULATION
			case '1':
				score2+=1;
				break;
			case '2':
				score2+=2;
				break;
			case '3':
				score2+=3;
				break;
			case '4':
				score2+=4;
				break;
			case '5':
				score2+=5;
				break;
			case '6':
				score2+=6;
				break;
			default:  // VALIDATION
			    printf("\nInvalid input from batsman!\nPENALTY: 6 runs deducted from the score\n");
				score2-=6;
			    break;
		}
		printf("Score: %d\n",score2);
		if(score1+1-score2 >= 0){
		printf("Runs left to win: %d\n",score1+1-score2);
		printf("Ball number: %d\n",n);
		printf("==========================================\n\n");
		}
		else{
			printf("Runs left to win: 0\n");
			printf("Ball number: %d\n",n);
			printf("==========================================\n\n");
		}
		if(score2>score1){
			printf("\t!!! %s WINS !!!\n\n", player2);
			break;
		}
		n++;
		count--;
	}while(ball!=bat);
}


void Target(int count,int p2_status){
	char ball,bat;
	int n=1;
	do{
		if(count==0){
			printf("\tRUNS REQUIRED TO WIN: %d\n",score1+1);
			printf("==========================================\n\n");
			printf("\tSECOND INNINGS START\n\n");
			Chase(6,p2_status);
			return;
		}
		printf("Deliver ball: ");
		ball= getch();
		printf("*\n");
		printf("Play the shot: ");
		bat = getch();
		printf("*\n\n");
		if(ball>'6'){   // VALIDATION
			printf("Invalid input from bowler!\nPENALTY: Batsman gets 6 runs\n");
			score1+=6;
		}
		if(ball==bat){
			wicket--;
			printf("Tried to score %c runs.\n",bat);
			printf("\t OUT !!!\n\n");
			printf("==========================================\n\n");
			break;
		}
		printf(" %c runs scored\n\n",bat);
		switch(bat){
			case '1':
				score1+=1;
				break;
			case '2':
				score1+=2;
				break;
			case '3':
				score1+=3;
				break;
			case '4':
				score1+=4;
				break;
			case '5':
				score1+=5;
				break;
			case '6':
				score1+=6;
				break;
			default: // VALIDATION
				printf("\nInvalid input from batsman!\nPENALTY: 6 runs deducted from the score\n");
				score1-=6;
				break;
		}
		printf("Score: %d\n",score1);
		printf("Ball number: %d\n",n);
		printf("==========================================\n");
		n++;
		count--;
	}while(ball!=bat);
	printf("\tRUNS REQUIRED TO WIN: %d\n",score1+1);
	printf("==========================================\n\n");
	printf("\tSECOND INNINGS START\n\n");
	Chase(count,p2_status);
}


int Toss(){
	int p2_bat=0;
	int flag = 0;
	srand(time(NULL));  // GIVES DIFF RANDOM VALUE EVERYTIME
	int upper=1,lower=0,value;
	char HT,BB;
	printf("\n%s will choose the toss! \n",player1);
	printf("Enter your choice (H for Head/T for Tail): ");
	scanf(" %c",&HT);
	getchar();
	value = rand()%(upper-lower+1)+lower;  // CALCULATES RANDOM VALUE
	if(value == 1 && (HT=='H'|| HT=='T')){
		printf("** %s WON THE TOSS ** \n", player1);
		do
		{
			printf("Bat or Bowl ? (X for Bat/O for Ball): ");
		    scanf(" %c",&BB);
		if(BB=='X'){
			flag = 1;
			printf("\n** %s BATS FIRST **\n", player1);
			printf("==========================================\n\n");
		}
		else if(BB=='O'){
			flag = 1;
			p2_bat=1;
			printf("\n** %s BALLS FIRST **\n", player1);
			printf("==========================================\n\n");
		}
		else{         // FOR INCORRECT INPUT
			printf("Invalid Input\n");
			flag= 0;
		}
		}while(flag == 0);
		printf("\n");
		printf("\tFIRST INNINGS START\n\n");
		Target(-1,p2_bat);
	}
	else if(value == 0 && (HT=='H'|| HT=='T')){
		printf("** %s WON THE TOSS ** \n", player2);
		do{
			printf("Bat or Bowl ? (X for Bat/O for Ball): ");		
			scanf(" %c",&BB);
		if(BB=='X'){
			flag = 1;
			p2_bat=1;
			printf("\n** %s BATS FIRST **\n", player2);
			printf("==========================================\n");
		}
		else if(BB=='O'){
			flag = 1;
			printf("\n** %s BALLS FIRST **\n", player2);
			printf("==========================================\n");
		}
		else{         // FOR INCORRECT INPUT
			printf("Invalid Input\n");
			flag= 0;
		}
		}while(flag == 0);
		printf("\n");
		printf("\tFIRST INNINGS START\n\n");
		Target(-1,p2_bat);
	}
	else{              // INVALID INPUT FOR TOSS DECISION
		printf("Invalid input\nPENALTY: %s won the toss \n", player2);
		do{
			printf("Bat or Bowl ? (X for Bat/O for Ball): ");
			scanf(" %c",&BB);
		if(BB=='X'){
			flag = 1;
			p2_bat=1;
			printf("\n** %s BATS FIRST **\n", player2);
			printf("==========================================\n");
		}
		else if(BB=='O'){
			flag = 1;
			printf("\n** %s BALLS FIRST **\n", player2);
			printf("==========================================\n");
		}
		else{  // FOR INCORRECT INPUT
			printf("Invalid Input\n");
			flag= 0;
		}
		}while(flag == 0);
		printf("\n");
		printf("\tFIRST INNINGS START\n\n");
		Target(-1,p2_bat);
	}	
}

void SuperOver(){
	wicket=1,score1=0,score2=0;
	printf("\n\t!!! SUPER OVER !!!\n\n");
	printf("\n** %s WILL BAT FIRST **\n\n", player1);
	Target(6,0);
}

void menu()
{
	printf("=========================================\n");
	printf("     C R I C K E T  S I M U L A T I O N  \n");
	printf("=========================================\n");
    printf("=========================================\n");
    printf("               MAIN MENU                 \n"); 
    printf("=========================================\n");
    printf("1. CLASSIC GAME\n2. RULES\n3. CREDITS\n4. EXIT\n");
    printf("_________________________________________\n");
}

void clearscreen()
{
	system("cls");
}



