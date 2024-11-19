#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

int score1,score2,wicket=1;
char ball,bat;


void Chase(int count){
	int n=1;
	do{
		if(count==0){
			if(score2<score1){
				printf("\t!!! PLAYER 1 WINS BY %d RUNS !!!\n",score1-score2);
				return;
			}
			else if(score2==score1){
				SuperOver();
			}
			else{
				return;
			}
		}
		printf("Deliver ball: ");
		ball = getch();
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
				printf("\t!!! PLAYER 1 WINS BY %d RUNS !!!\n",score1-score2);
				break;
			}
			else if(score2==score1){
				printf("\t!!! MATCH DRAWN !!!\n");
				printf("==========================================\n\n");
				SuperOver();
			    break;
			}
		}
		printf("Batsman scored %c runs\n\n",bat);
		switch(bat){
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
			default:
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
			printf("\t!!! PLAYER 2 WINS !!!\n\n");
			break;
		}
		n++;
		count--;
	}while(ball!=bat);
}


void Target(int count){
	int n=1;
	do{
		if(count==0){
			printf("\tRUNS REQUIRED TO WIN: %d\n",score1+1);
			printf("==========================================\n\n");
			printf("\tSECOND INNINGS START\n\n");
			Chase(6);
			return;
		}
		printf("Deliver ball: ");
		ball= getch();
		printf("*\n");
		printf("Play the shot: ");
		bat = getch();
		printf("*\n\n");
		if(ball>'6'){
			printf("Invalid input from bowler!\nPENALTY: Batsman gets 6 runs\n");
			score1+=6;
		}
		if(ball==bat){
			wicket--;
			printf("\t OUT !!!\n\n");
			printf("==========================================\n\n");
			break;
		}
		printf("Batsman scored %c runs\n\n",bat);
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
			default:
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
	Chase(count);
}


int Toss(){
	srand(time(NULL));
	int upper=1,lower=0,value;
	char HT,BB;
	printf("Enter your choice (H for Head/T for Tail): ");
	scanf("%c",&HT);
	value = rand()%(upper-lower+1)+lower;
	if(value == 1 && (HT=='H'|| HT=='T')){
		printf("** PLAYER 1 WON THE TOSS ** \n");
		printf("Bat or Bowl ? (X for Bat/O for Ball): ");
		scanf(" %c",&BB);
		if(BB=='X'){
			printf("\n** PLAYER 1 BATS FIRST **\n");
			printf("==========================================\n\n");
		}
		else if(BB=='O'){
			printf("\n** PLAYER 1 BALLS FIRST **\n");
			printf("==========================================\n\n");
		}
		printf("\n");
		printf("\tFIRST INNINGS START\n\n");
		Target(-1);
	}
	else if(value == 0 && (HT=='H'|| HT=='T')){
		printf("** PLAYER 2 WON THE TOSS ** \n");
		printf("Bat or Bowl ? (X for Bat/O for Ball): ");		
		scanf(" %c",&BB);
		if(BB=='X'){
			printf("\n** PLAYER 2 BATS FIRST **\n");
			printf("==========================================\n");
		}
		else if(BB=='O'){
			printf("\n** PLAYER 2 BALLS FIRST **\n");
			printf("==========================================\n");
		}
		printf("\tFIRST INNINGS START\n\n");
		Target(-1);
	}
	else{
		printf("Invalid input\nPENALTY: Player 2 won the toss \n");
		printf("Bat or Bowl ? (X for Bat/O for Ball): ");
		scanf(" %c",&BB);
		if(BB=='X'){
			printf("\n** PLAYER 2 BATS FIRST **\n");
			printf("==========================================\n");
		}
		else if(BB=='O'){
			printf("\n** PLAYER 2 BALLS FIRST **\n");
			printf("==========================================\n");
		}
		printf("\tFIRST INNINGS START\n\n");
		Target(-1);
	}	
}

void SuperOver(){
	wicket=1,score1=0,score2=0;
	printf("\n\t!!! SUPER OVER !!!\n\n");
	printf("\n** PLAYER 1 WILL BAT FIRST **\n\n");
	Target(6);
}

int main(){
	
	printf("\t\t CRICKET SIMULATION\n");
	printf("RULES:\n1)KEEP THE CAPSLOCK ON WHILE PLAYING THE GAME!!\n");
	printf("2)If bowler enters an invalid input, batsman will get 6 runs.\n");
	printf("3)If batsman enters an invalid input, 6 runs will be deducted from the score\n");
	printf("4)Same inputs is Out.\n5)Different inputs, game continues.\n\n");
	
	Toss();
	
	return 0;
}


