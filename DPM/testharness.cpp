#include "testharness.h"

#include <iostream>
#include <stack>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

struct TimeStamp{
	string funcName;
	clock_t start;
	clock_t end;
};
stack<TimeStamp>* markPoint;
int indexLevel = -1;

string index(int level){
	string index = "";
	for (int i = 0; i < indexLevel; i++){
		index += "  ";
	}
	return index;
}

void MarkPoint(string funcName, string file, int line){
	if (markPoint == NULL){
		markPoint = new stack<TimeStamp>();
		markPoint->push(TimeStamp{ "XXXXXXXXXXX", clock() });
	}
	TimeStamp tmp = markPoint->top();
	if (tmp.funcName != funcName){  //ÐÂµÄº¯Êý
		indexLevel++;
		clock_t start = clock();
		markPoint->push(TimeStamp{ funcName, start });
//#define XXXX
#ifdef XXXX
		cout << index(indexLevel) << "Enter: " << funcName << "  " << (double)start / CLOCKS_PER_SEC << endl;
#endif 
	}
	else{
		markPoint->pop();
		clock_t end = clock();
		double total = (double)(end - tmp.start) / CLOCKS_PER_SEC;
#ifdef XXXX
		cout << index(indexLevel) << "Leave: " << funcName << "  " << (double)end / CLOCKS_PER_SEC << endl;
#endif
		char buff[100];
		sprintf_s(buff,sizeof(buff), "TimeSpend(%s):%0.3f", funcName.c_str(), total);
		cout << index(indexLevel) << buff << endl;

		indexLevel--;
	}
}