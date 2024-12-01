#include <stdio.h>
#include <string.h>

struct Player {
    int ballScores[12];
    char playerName[100];
    int totalScore;
};

void playGame(struct Player* player){
	int i,score;
    printf("Enter the name of the player: ");
    fgets(player->playerName, sizeof(player->playerName), stdin);
    player->playerName[strcspn(player->playerName, "\n")] = '\0'; 
    player->totalScore = 0;
    for(i=0;i<12;i++){
        printf("Enter score for ball %d (0-6): ", i+1);
        scanf("%d", &score);
        if(validateScore(score)){
            player->ballScores[i] = score;
            player->totalScore += score;
        }else{
            printf("Invalid score, ball will be marked but score disregarded.\n");
            player->ballScores[i] = 0;  
        }
    }
}

int validateScore(int score){
    return (score>=0 && score<=6);
}

void findWinner(struct Player player1, struct Player player2){
    if (player1.totalScore > player2.totalScore){
        printf("\nWinner: %s\n", player1.playerName);
    }else if (player2.totalScore > player1.totalScore){
        printf("\nWinner: %s\n", player2.playerName);
    }else{
        printf("\nIt's a tie! Both players scored the same.\n");
    }
}

void displayMatchScoreboard(struct Player player1, struct Player player2){
	int i;
    printf("\nMatch Scoreboard:\n");
    printf("\nPlayer 1: %s\n", player1.playerName);
    for(i=0;i<12;i++){
        printf("Ball %d: %d\n", i+1, player1.ballScores[i]);
    }
    printf("Total Score: %d\n", player1.totalScore);
    printf("Average Score: %.2f\n", player1.totalScore / 12.0);
    printf("\nPlayer 2: %s\n", player2.playerName);
    for(i=0;i<12;i++){
        printf("Ball %d: %d\n", i+1, player2.ballScores[i]);
    }
    printf("Total Score: %d\n", player2.totalScore);
    printf("Average Score: %.2f\n", player2.totalScore/12.0);
}

int main(){
    struct Player player1, player2;
    printf("Cricket Showdown: Player 1's turn\n");
    playGame(&player1);
    printf("\nCricket Showdown: Player 2's turn\n");
    playGame(&player2);
    
    displayMatchScoreboard(player1, player2);
    findWinner(player1, player2);

    return 0;
}

