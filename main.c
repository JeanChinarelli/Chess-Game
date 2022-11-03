#include <stdio.h> 
#include <stdlib.h>

char chess[8][8] = {
    {'T', 'H', 'B', 'Q', 'K', 'B', 'H', 'T'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'t', 'h', 'b', 'q', 'k', 'b', 'h', 't'}
};

int printScreen(){
    int lin, col, count;

    system("CLS");

    for(lin=0; lin<8; lin++){
        for(count=0;count<3;count++){
            for(col=0; col<8; col++){

                char piece = chess[lin][col];
                char letter = ((lin + col) % 2==0) ? '\xB2' : ' ';
                letter = (count == 1 && piece!=' ') ? piece : letter;

                if((lin + col) % 2==0){
                    printf("\xB2\xB2%c\xB2\xB2", letter);
                }
                else{
                    printf("  %c  ", letter);
                }

            }
            printf("\n");
        }
    }
}

int movePiece(int lineOrigin, int columnOrigin, int lineDestination, int columnDestination){
    if((lineOrigin>=0 && lineOrigin<8 && columnOrigin>=0 && columnOrigin<8) &&
        (lineDestination>=0 && lineDestination<8 && columnDestination>=0 && columnDestination<8)){
            chess[lineDestination][columnDestination] = chess[lineOrigin][columnOrigin];
            chess[lineOrigin][columnOrigin] =  ' ';
            return 1;
    }
    else{
        return 0;
    }   
}

int main(){
    int lineOrigin, columnOrigin, lineDestination, columnDestination;

    while(1){
        printScreen();

        printf("\nChoose the position of the piece you want to move: ");
        scanf("%d %d", &lineOrigin, &columnOrigin);
        printf("\n\nChoose the position where you want to move: ");
        scanf("%d %d", &lineDestination, &columnDestination);

        if(movePiece(lineOrigin, columnOrigin, lineDestination, columnDestination)!=1){
            printf("\nERROR!!! Invalid coordinates!!!");
        }
    }
    system("pause");
    return 0;
}