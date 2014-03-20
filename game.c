#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "conway.h"

void printusage(){
    printf("Usage: game <width> <height>\n");
}

void printboard(int **board, int width, int height){
    int i, j;
    
    for(i = 0; i < height; i++){
        for(j = 0; j < width; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    
}

int update(int **board, int width, int height){
    printf("entered update");
    int i = 0;
    int j = 0;
    int **temp_b = malloc(sizeof(int *) * height);
    for(i = 0; i < height; i++){
        temp_b[i] = malloc(sizeof(int) * width);
    }
    
    for(i = 0; i < height; i++){
        
        for(j = 0; j < width; j++){
            temp_b[i][j] = board[i][j];
        }
    }
    
   
    int n = 0; int jj =0; int ii = 0;
    for (i = 0; i< height; i++) {
        for(j = 0; j<width; j++){
            n=0;
            for(ii = i-1; ii<= i+1; ii++){
                for (jj = j-1; j<= j+1; jj++) {
                    if(board[(ii+height)%height][(jj+width)%width]){
                        n++;
                    }
                }
            }
            if(board[i][j]){
                n--;
            }
            temp_b[i][j] = (n==3 || (n==2 && board[i][j]));
        }
        
    }
     /*
    for(i=0;i<height; i++){
        for(j=0; j<width; j++){
            board[i][j] = temp_b[i][j];
        }
    }*/
    
    printf("Got out of for loops");
    return 0;
}


        
        
int main(int argc, char *argv[]){
    int width, height;
    int **board;
    int i;
    
    if(argc != 3){
        printusage();
        return 1;
    }
    if(sscanf(argv[1], "%d", &width) != 1){
        printusage();
        return 1;
    }
    
    if(sscanf(argv[2], "%d", &height) != 1){
        printusage();
        return 1;
    }
    
    /*allocate space for the board*/
    board = malloc(sizeof(int *) * height);
    for(i = 0; i < height; i++){
        board[i] = malloc(sizeof(int) * width);
    }
    
    /*initialize the board to be in a random state*/
    srand(time(NULL));
    
    for(i = 0; i < height; i++){
        int j;
        for(j = 0; j < width; j++){
            board[i][j] = rand() % 2;
        }
    }
    
    printboard(board, width, height);
    
    printf("Hello\n");

    /*call your update method*/
    
    printf("Heey");
    //update(board, width, height);
    
    printf("\n");
    
    printboard(board, width, height);
    
    //clean things up
    for(i = 0; i < height; i++){
        free(board[i]);
    }
    free(board);
    
}


