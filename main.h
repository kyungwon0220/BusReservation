//#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // system("cls");
#include <conio.h> // _getch()
#include <string.h> // strcmp()

int login(); // login.c
void ViewBusList(int HowManyBus, char** Bus_to, char** Bus_price); // ViewBus.c
void ViewBusSeats(int Cho_BusNum, char** Bus_to, int Seats, int* check); // ViewBus.c
void SeatFileOpenReadMode(char* Bus_fileName, int Seats, char* p); // SeatFileOpenReadMode.c
void SeatFileWriteAddMode(char* Bus_fileName, int Seats, int* check); // SeatFileWriteAddMode.c
