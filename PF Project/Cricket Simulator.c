#include<stdio.h>
#include<string.h>
#include<conio.h>          // for getch() 
#include<stdlib.h>         // for rand() function 
#include<time.h>           // generate new random value everytime (line 239)

struct Player{
	char name[50];
	int score;

};

void Chase(struct Player *player1, struct Player *player2, int count, int batfirst);//int batfirst tells if Player 2 is batting first or not
void Target(struct Player *player1, struct Player *player2, int count, int batfirst);
int Toss(struct Player *player1, struct Player *player2, int batfirst);
void SuperOver(struct Player *player1, struct Player *player2);
void menu();
void clearscreen();
void scorecard(struct Player *player1, struct Player *player2, int batfirst);




int wicket = 1;


int main(){
	struct Player p1, p2;
	int batfirst = 0;
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
	    		printf("==================R U L E S=====================\n");
                printf("\n1)KEEP THE CAPSLOCK ON WHILE PLAYING THE GAME!!\n");
               	printf("\n2)If bowler enters an invalid input, batsman will get 6 runs.\n");
              	printf("\n3)If batsman enters an invalid input, 6 runs will be deducted from the score\n");
              	printf("\n4)Same inputs is Out.\n\n5)Different inputs, game continues.\n\n");
              	printf("Player 1 name: ");
				scanf("%s", p1.name);      
				printf("Player 2 name: ");
				scanf("%s", p2.name);  
				p1.score=0, p2.score=0;
              	Toss(&p1, &p2, batfirst);
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
		getchar(); // used two get chars: 1 for buffer
		getchar();// 2 to detect newline character and return to menu
	}
	
	return 0;
}


void Chase(struct Player *player1, struct Player *player2, int count, int batfirst){
	char ball,bat;
	int n=1;  // BALL COUNT
	do{
		if(count==0){
			if(player2->score < player1->score){
				printf("\t!!! %s WINS BY %d RUNS !!!\n", player1->name, player1->score - player2->score);
				scorecard(player1, player2, batfirst);
				return;
			}
			else if(player2->score==player1->score){
				SuperOver(player1, player2);
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
			player2->score+=6;	
		}
		if(ball==bat){
			wicket--;
			printf("\tOUT !!!\n\n");
			printf("==========================================\n\n");
			if(player2->score<player1->score){
				if(batfirst==1){
					printf("\t!!! %s WINS BY %d RUNS !!!\n", player1->name, player1->score-player2->score);
					scorecard(player1, player2, batfirst);
					break;
				}
				else{
					printf("\t!!! %s WINS BY %d RUNS !!!\n", player2->name, player1->score-player2->score);
					scorecard(player2, player1, batfirst);
					break;
				}
			}
			else if(player2->score==player1->score){
				printf("\t!!! MATCH DRAWN !!!\n");
				printf("==========================================\n\n");
				SuperOver(player1, player2);
			    break;
			}
		}
		printf("%c runs scored\n\n",bat);
		switch(bat){       // SCORE CALCULATION
			case '1':
				player2->score+=1;
				break;
			case '2':
				player2->score+=2;
				break;
			case '3':
				player2->score+=3;
				break;
			case '4':
				player2->score+=4;
				break;
			case '5':
				player2->score+=5;
				break;
			case '6':
				player2->score+=6;
				break;
			default:  // VALIDATION
			    printf("\nInvalid input from batsman!\nPENALTY: 6 runs deducted from the score\n");
				player2->score-=6;
			    break;
		}
		printf("Score: %d\n",player2->score);
		if(player1->score+1-player2->score >= 0){
		printf("Runs left to win: %d\n",player1->score+1-player2->score);
		printf("Ball number: %d\n",n);
		printf("==========================================\n\n");
		}
		else{
			printf("Runs left to win: 0\n");
			printf("Ball number: %d\n",n);
			printf("==========================================\n\n");
		}
		if(player2->score>player1->score){
			printf("\t!!! %s WINS !!!\n\n", player2->name);
			scorecard(player1, player2, batfirst);
			break;
		}
		n++;
		count--;
	}while(ball!=bat);
	
	
}


void Target(struct Player *player1, struct Player *player2, int count, int batfirst){
	char ball,bat;
	int n=1;
	do{
		if(count==0){
			printf("\tRUNS REQUIRED TO WIN: %d\n",player1->score+1);
			printf("==========================================\n\n");
			printf("\tSECOND INNINGS START\n\n");
			Chase(player1, player2, 6, batfirst);
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
			player1->score+=6;
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
				player1->score+=1;
				break;
			case '2':
				player1->score+=2;
				break;
			case '3':
				player1->score+=3;
				break;
			case '4':
				player1->score+=4;
				break;
			case '5':
				player1->score+=5;
				break;
			case '6':
				player1->score+=6;
				break;
			default: // VALIDATION
				printf("\nInvalid input from batsman!\nPENALTY: 6 runs deducted from the score\n");
				player1->score-=6;
				break;
		}
		printf("Score: %d\n",player1->score);
		printf("Ball number: %d\n",n);
		printf("==========================================\n");
		n++;
		count--;
	}while(ball!=bat);
    printf("\tRUNS REQUIRED TO WIN: %d\n",player1->score+1);
	printf("==========================================\n\n");
	printf("\tSECOND INNINGS START\n\n");
	Chase(player1, player2, count, batfirst);
}


int Toss(struct Player *player1, struct Player *player2, int batfirst){
	int flag = 0;       
	srand(time(NULL));  // GIVES DIFF RANDOM VALUE EVERYTIME
	int upper=1,lower=0,value;
	char HT,BB;
	printf("%s will choose the toss\n",player1->name);
	printf("Enter your choice (H for Head/T for Tail): ");
	scanf(" %c",&HT);
	getchar();
	value = rand()%(upper-lower+1)+lower;  // CALCULATES RANDOM VALUE
	if(value == 1 && (HT=='H'|| HT=='T')){
		printf("** %s WON THE TOSS ** \n", player1->name);
		do
		{
			printf("Bat or Bowl ? (X for Bat/O for Ball): ");
		    scanf(" %c",&BB);
		if(BB=='X'){
			flag = 1;
			printf("\n** %s BATS FIRST **\n", player1->name);
			printf("==========================================\n\n");
			batfirst = 1;
		}
		else if(BB=='O'){
			flag = 1;
			printf("\n** %s BALLS FIRST **\n", player1->name);
			printf("==========================================\n\n");
			batfirst = 0;
		}
		else{  // FOR INCORRECT INPUT
			printf("Invalid Input\n");
			flag= 0;
		}
		}while(flag == 0);
		printf("\n");
		printf("\tFIRST INNINGS START\n\n");
		Target(player1, player2, -1, batfirst);
	}
	else if(value == 0 && (HT=='H'|| HT=='T')){
		printf("** %s WON THE TOSS ** \n", player2->name);
		do{
			printf("Bat or Bowl ? (X for Bat/O for Ball): ");		
			scanf(" %c",&BB);
		if(BB=='X'){
			flag = 1;
			printf("\n** %s BATS FIRST **\n", player2->name);
			printf("==========================================\n");
			batfirst = 0;
		}
		else if(BB=='O'){
			flag = 1;
			printf("\n** %s BALLS FIRST **\n", player2->name);
			printf("==========================================\n");
			batfirst = 1;
		}
		else{  // FOR INCORRECT INPUT
			printf("Invalid Input\n");
			flag= 0;
		}
		}while(flag == 0);
		printf("\n");
		printf("\tFIRST INNINGS START\n\n");
		Target(player1, player2, -1, batfirst);
	}
	else{  // INVALID INPUT FOR TOSS DECISION
		printf("Invalid input\nPENALTY: %s won the toss \n", player2->name);
		do{
			printf("Bat or Bowl ? (X for Bat/O for Ball): ");
			scanf(" %c",&BB);
		if(BB=='X'){
			flag = 1;
			printf("\n** %s BATS FIRST **\n", player2->name);
			printf("==========================================\n");
			batfirst = 0;
		}
		else if(BB=='O'){
			flag = 1;
			printf("\n** %s BALLS FIRST **\n", player2->name);
			printf("==========================================\n");
			batfirst = 1;
		}
		else{  // FOR INCORRECT INPUT
			printf("Invalid Input\n");
			flag= 0;
		}
		}while(flag == 0);
		printf("\n");
		printf("\tFIRST INNINGS START\n\n");
		Target(player1, player2, -1, batfirst);
	}	
}

void SuperOver(struct Player *player1, struct Player *player2){
	wicket=1,player1->score=0,player2->score=0;
	printf("\n\t!!! SUPER OVER !!!\n\n");
	printf("\n** %s WILL BAT FIRST **\n\n", player1);
	Target(player1, player2, 6, 0);
}

void menu()
{
	printf("=========================================\n");
	printf("     C R I C K E T  S I M U L A T I O N  \n");
	printf("=========================================\n");
    printf("==========================================\n");
    printf("                MAIN MENU                 \n"); 
    printf("==========================================\n");
    printf("1. CLASSIC GAME\n2. RULES\n3. CREDITS\n4. EXIT\n");
    printf("___________________________________________\n");
}

void clearscreen()
{
	system("cls");
}

void scorecard(struct Player *player1, struct Player *player2, int batfirst)
{
	if(batfirst == 1)
	{
		printf("\n==========================================\n");
        printf("                SCORECARD                 \n");
        printf("==========================================\n");

        printf("**********First Innings**********\n");
        printf("Player: %s\n", player1->name);
        printf("Total Score: %d\n", player1->score);

        printf("\n**********Second Innings**********\n");
        printf("Player: %s\n", player2->name);
        printf("Total Score: %d\n", player2->score);
       printf("\n==========================================\n");
	}
	else
	{
		printf("\n==========================================\n");
        printf("               SCORECARD                  \n");
        printf("==========================================\n");

        printf("**********First Innings**********\n");
        printf("Player Name: %s\n", player2->name);
        printf("Total Score: %d\n", player2->score);

       printf("\n**********Second Innings**********\n");
       printf("Player Name: %s\n", player1->name);
       printf("Total Score: %d\n", player1->score);

       printf("\n==========================================\n");
	}
    
}

