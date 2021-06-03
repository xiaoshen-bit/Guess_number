#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<time.h>

#define ROW 3
#define COL 3

void Init_chess(char chess[ROW][COL], int row, int col);
void Background(char chess[ROW][COL], int row, int col);
void Play_chess(char chess[ROW][COL], int row, int col);
char Is_win(char chess[ROW][COL], int row, int col);
char Com_chess(char chess[ROW][COL], int row, int col);