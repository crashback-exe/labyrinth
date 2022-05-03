#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
using namespace std;
// color your text in Windows console mode
// colors are 0=black 1=blue 2=green and so on to 15=white  
// colorattribute = foreground + background * 16
// to get red text on yellow use 4 + 14*16 = 228
// light red on yellow would be 12 + 14*16 = 236


const int LEN=21;

void cColor(int fg_color=15, int bg_color=0){
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, fg_color + bg_color*16);
}

void printBoard(short int board[LEN][LEN], int endPos[2], int py=-1, int px=-1, bool win=false){
	if (!win)cColor(0, 8);
	else cColor(0, 2);
	cout << "                                              " << endl;
	for (int i=0; i<LEN; i++){
		if (!win)cColor(0, 8);
		else cColor(0, 2);
		cout << "  ";
		cColor();
		for (int j=0; j<LEN; j++){
			if(i==endPos[1]&&j==endPos[0]){
				cColor(0, 3);
				cout << "  ";
			}else if(i==px && j==py){
				cColor(0, 4);
				cout << "  ";
			}else if (board[i][j]==1){
				cColor(0, 0);
				cout << "  ";
			}else{
				cColor(0, 15);
				cout << "  ";
			}
		}
		if (!win)cColor(0, 8);
		else cColor(0, 2);
		cout << "  ";
		cColor();
		cout << "\n";
	}
	if (!win)cColor(0, 8);
	else cColor(0, 2);
	cout << "                                              ";
	cColor(15, 0);
	cout << endl;
}

int main(){
	short int board[LEN][LEN]={
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
		{1,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0,0,0,1},
		{1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1},
		{1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1},
		{1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1,0,1},
		{1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,1},
		{1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1},
		{1,0,0,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1},
		{1,1,1,1,1,1,1,0,1,1,1,0,1,0,1,0,1,1,1,0,1},
		{1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1},
		{1,0,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1},
		{1,0,0,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1},
		{1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1,1,1},
		{1,0,1,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,1},
		{1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1,1,1,0,1},
		{1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1},
		{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	
//	W = 119, 89
//	A = 97, 65
//	S = 115, 83
//	D = 100, 68
	
	int pos[2] = {1, 1}; 		// x, y
	int endPos[2] = {20, 19}; 	// x, y
	int mov[2] = {0, 0}; 		// x, y
	bool end=false;
	
	printBoard(board, endPos, pos[0], pos[1]);
	
	while (!end){
		int input = getch();
		switch (input){
			case 119:
				mov[1] = -1;
				break;
			case 97:
				mov[0] = -1;
				break;
			case 115:
				mov[1] = 1;
				break;
			case 100:
				mov[0] = 1;
				break;
			default:
				continue;
		}
		
		if(board[pos[1]+mov[1]][pos[0]+mov[0]]!=1){	
			system("cls");
			pos[0] += mov[0];
			pos[1] += mov[1]; 
			printBoard(board, endPos, pos[0], pos[1]);
		}
		mov[0] = 0;
		mov[1] = 0;
		if (pos[0]==endPos[0]&&pos[1]==endPos[1]){
			system("cls");
			printBoard(board, endPos, pos[0], pos[1], true);
			cColor(2, 0);
			cout << endl << "You won!" << endl;
			end=true;
		}
	}
	cColor(0, 15);
	cout << "Press any key to exit";
	cColor();
	cout<<endl;
	getch();
}
