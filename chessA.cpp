#include <stdio.h>
#include "Pieces.h"
#include "position.h"
#include "piecesH.h"
#include "Board.h"

int main()
{
    printf("Hello World!\n");

    //{
    //    //폰 체크
    //    {
    //        Pieces* pic = new Pawn();
    //        printf("Pawn 's move \n");
    //        pic->print();
    //        delete pic;
    //    }
    //    //비숍 체크
    //    {
    //        Pieces* pic = new Bishop();
    //        printf("bishop 's move \n");
    //        pic->print();
    //        delete pic;
    //    }
    //    //룩 체크
    //    {
    //        Pieces* pic = new Rook();
    //        printf("Rook 's move \n");
    //        pic->print();
    //        delete pic;
    //    }
    //    //킹 퀸 체크
    //    {
    //        Pieces* pic = new Queen();
    //        printf("queen 's move & king 's move\n");
    //        pic->print();
    //        delete pic;
    //        pic = new King();
    //        pic->print();
    //        delete pic;
    //    }
    //    //나이트 체크
    //    {
    //        Pieces* pic = new Knight();
    //        printf("knight's move \n");
    //        pic->print();
    //        delete pic;
    //    }
    //}

    
    Board* board = new Board();

    {
        Pieces* pic = new Pawn();
        sPosition pos;
        pos.y = 1; pos.x = 0;
        board->settingBoard(pic,pos);
        pos.x = 0; pos.y = 2;
        if (pic->isMoving(pos))
            printf("참이예여\n");
    }


    {
        board->printBoard();

        printf("다꺼져\n시발 좀 꺼져 \n");

        sPosition pos;
        pos.y = 1; pos.x = 0;

        sPosition movePos;
        movePos.y = 2; movePos.x = 0;
        board->piecesMove(pos, movePos);

        board->printBoard();
    }
    return 0;
}

