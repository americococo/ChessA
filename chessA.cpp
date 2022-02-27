#include <stdio.h>
#include <string.h>
#include "Pieces.h"
#include "position.h"
#include "piecesH.h"
#include "Board.h"

#define ENEYCREATE 2

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
	for (int j = 0; j < ENEYCREATE; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			sPosition pos;
			pos.y = 1 + (j * 5), pos.x = i;
			board->settingBoard(new Pawn(picColor), pos);
		}
		picColor = false;
	}

	picColor = true;

	//보드판 세팅 중입니다!!!!
	for (int i = 0; i < ENEYCREATE; i++)
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
		pos.y = i * 7, pos.x = 3;
		board->settingBoard(new King(picColor), pos);
		pos.x = 4;
		board->settingBoard(new Queen(picColor), pos);

		picColor = false;
	}

	//board->printBoard(); 


	picColor = true;
	char  giboData[10]="\0";
	char  gibopre[10];
	strcpy_s(gibopre, giboData);
	//프로모션 테스트용 코드

	//{
	//	sPosition pos;
	//	pos.y = 5, pos.x = 1;
	//	board->settingBoard(new Pawn(picColor), pos);
	//}

	board->printBoard();

	while (true)
	{
		sPosition pos;
		sPosition rePos;
		do
		{
			board->insertLastgiboData(gibopre);

			printf("기보 입력해주세요 지금은 ");
			if (picColor)
				printf("대문자의 차례입니다.\n");
			else
				printf("소문자의 차례입니다.\n");

			scanf_s("%[^\n]", giboData, 10);

			{
				while (getchar() != '\n');
			}
			strcpy_s(gibopre, giboData);

			char* passing = nullptr;
			char* token[4];
			token[0] = strtok_s(giboData, " ", &passing);
			token[1] = strtok_s(NULL, " ", &passing);
			token[2] = strtok_s(NULL, " ", &passing);

			Pieces* pic = board->searchPieces(*token[0], picColor);

			int CHyx = atoi(token[1]);
			int Reyx = atoi(token[2]);

			pos.y = (CHyx / 10) - 1;
			pos.x = (CHyx % 10) - 1;

			rePos.y = (Reyx / 10) - 1;
			rePos.x = (Reyx % 10) - 1;
		} while (false == board->piecesMove(pos, rePos));


		
		board->printBoard();
		//어떤 말을 움직일지 기보 작성
		//기보데이터 파싱하여 데이터 취득
		//취득 데이터통해서 board에게 기능수행

		picColor = !picColor;
	}



	return 0;
}

