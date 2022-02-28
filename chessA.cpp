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
			Pieces * pic = new Pawn(picColor);
			board->settingBoard(pic, pos);
			board->insertColorPieces(pic, picColor);
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
			Pieces* pic = new Rook(picColor);

			board->settingBoard(pic, pos);
			board->insertColorPieces(pic, picColor);

			pos.x = j * 5 + 1;
			pic = new Knight(picColor);
			board->settingBoard(pic, pos);
			board->insertColorPieces(pic, picColor);

			pos.x = j * 3 + 2;
			pic = new Bishop(picColor);
			board->settingBoard(new Bishop(picColor), pos);
			board->insertColorPieces(pic, picColor);
		}
		
		sPosition pos;
		pos.y = i * 7,pos.x = 4;
		Pieces* pic = new Queen(picColor);
		board->settingBoard(new Queen(picColor), pos);
		board->insertColorPieces(pic, picColor);

		picColor = false;
	}

	sPosition pos;
	pos.y = 0, pos.x = 3;
	King* Bigking = new King(true);
	board->settingBoard(Bigking, pos);
	board->insertColorPieces(Bigking, true);

	pos.y = 7;
	King* smallKing = new King(false);
	board->settingBoard(smallKing, pos);
	board->insertColorPieces(smallKing, false);

	//board->printBoard(); 


	picColor = true;
	char  giboData[20]="\0";
	char  gibopre[20];
	Pieces* giboPic;
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

			printf("기보 입력해주세요 \n기마 이동거리Y X  현재 위치 Y X \n\n\n지금은 ");
			if (picColor)
				printf("대문자의 차례입니다.\n");
			else
				printf("소문자의 차례입니다.\n");

			giboData[0] = '\0';

			scanf_s("%[^\n]", giboData, 10);

			{
				while (getchar() != '\n');
			}
			strcpy_s(gibopre, giboData);

			char* passing = nullptr;
			char* token[5];
			token[0] = strtok_s(giboData, " ", &passing);
			token[1] = strtok_s(NULL, " ", &passing);
			token[2] = strtok_s(NULL, " ", &passing);
			token[3] = strtok_s(NULL, " ", &passing);
			//token[4] = strtok_s(NULL, " ", &passing);

			int currentPosition = atoi(token[3]);

			pos.y = (currentPosition / 10) - 1;
			pos.x = (currentPosition % 10) - 1;

			giboPic = board->searchPieces(*token[0], picColor,pos);


			rePos.y = atoi(token[1]);
			rePos.x = atoi(token[2]);
		} while (false == board->piecesMove(giboPic, rePos));



		printf("%s\n",picColor==true? smallKing->amIDanger()==true?"대문자가공격하고있습니다!!폐하":"적군을 공격하라!!!!" : Bigking->amIDanger() == true ? "소문자가공격하고있습니다!!폐하" : "적군을 공격하라!!!!");
		
		board->printBoard();
		//어떤 말을 움직일지 기보 작성
		//기보데이터 파싱하여 데이터 취득
		//취득 데이터통해서 board에게 기능수행

		picColor = !picColor;
	}



	return 0;
}

