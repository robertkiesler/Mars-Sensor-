#pragma once
#include "linkedlist.h"


class datalogger 
{
	linkedlist normalDataLL;
	linkedlist badDataLL;

public:


	void addData(int, int, int);

	void removeSector(int);

	void containsSector(int);

	void printReport();

	void printSectorList();

};
