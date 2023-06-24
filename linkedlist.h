#pragma once
#include <stdio.h>
#include <iostream>
#include "surveydata.h"
using namespace std;

class linkedlist
{

	surveydata *speedHead_SD = NULL;
	surveydata *sectorHead_SD = NULL;
	surveydata *exposureHead_SD = NULL;

public:

	~linkedlist()
	{
		surveydata* P, * Q;
		Q = sectorHead_SD;
		while(Q)
		{
			P = Q;
			Q = Q->getSectorNext();
			delete P;
		}
	}

	void insertSortedSectors(int, int, int);
	void insertSortedExposures(int, int, int);
	void insertSortedSpeed(int, int, int);
	void printDataSectorWise() const;
	void printDataExposureWise() const;
	void printDataSpeedWise() const;
	void averagePerSector() const;
	void histogramForExposure() const;
	void histogramForSpeed() const;
	bool sectorExist(int) const;
	void createList(int, int, int);
	void removeFromList(int) const;
	void printSectorList() const;
};

