#pragma once
#ifndef __COMMON_H__
#define __COMMON_H__
#include<iostream>
#include<Windows.h>
using namespace std;
class Common
{
public:
	static void fixConsoleWindow();
	static void gotoXY(int, int);
	static void resizeConsole(int, int);
};
#endif