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

	bool picColor = true;
	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			sPosition pos;
			pos.y = 1 + (j*5), pos.x = i;
			board->settingBoard(new Pawn(picColor), pos);
		}
		picColor = false;
	}

	picColor = true;

	//보드판 세팅 중입니다!!!!
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			sPosition pos;
			pos.y = (i * 7), pos.x = j * 7;
			board->settingBoard(new Rook(picColor), pos);
			
			pos.x = j * 5 + 1;
			board->settingBoard(new Knight(picColor), pos);
			
			pos.x = j * 3 + 2;
			board->settingBoard(new Bishop(picColor), pos);
		}

		sPosition pos;
		pos.y = i * 7,pos.x=3;
		board->settingBoard(new King(picColor), pos);
		pos.x = 4;
		board->settingBoard(new Queen(picColor), pos);

		picColor = false;
	}


	while (true)
	{
		char  giboData[10];
		scanf("%s",giboData,10);

		//어떤 말을 움직일지 기보 작성
		//기보데이터 파싱하여 데이터 취득
		//취득 데이터통해서 board에게 기능수행


	}


	board->printBoard(); 

	return 0;
}

