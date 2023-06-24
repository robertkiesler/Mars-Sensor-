#include "linkedlist.h"
#include "surveydata.h"
#include <math>

void linkedlist::createList(int sector, int exposure, int speed)
{

	if(sectorHead_SD == NULL)
	{
		surveydata* newRecord = new surveydata();
		newRecord->setExposureValue(exposure);
		newRecord->setSpeedValue(speed);
		newRecord->setSectorValue(sector);
		sectorHead_SD = exposureHead_SD = speedHead_SD = newRecord;
	}
	else
	{
		insertSortedExposures(sector, exposure, speed);
		insertSortedSpeed(sector, exposure, speed);
		insertSortedSectors(sector, exposure, speed);
	}

}

void linkedlist::insertSortedSectors(int sector, int exposure, int speed)
{

	surveydata* newRecord = new surveydata();
	newRecord->setExposureValue(exposure);
	newRecord->setSpeedValue(speed);
	newRecord->setSectorValue(sector);
	surveydata* sorted = sectorHead_SD;

	if(sorted == NULL || sorted->getSectorValue() >= newRecord->getSectorValue())
	{
		newRecord->setSectorNext(sorted);
		sectorHead_SD = newRecord;
	}
	else
	{
		surveydata* current = sorted;
		while(current->getSectorNext() != NULL && current->getSectorNext()->getSectorValue() < newRecord->getSectorValue())
		{
			current = current->getSectorNext();
		}
		newRecord->setSectorNext(current->getSectorNext());
		current->setSectorNext(newRecord);
	}
}

void linkedlist::insertSortedSpeed(int sector, int exposure, int speed)
{
	surveydata* newRecord = new surveydata();
	newRecord->setExposureValue(exposure);
	newRecord->setSpeedValue(speed);
	newRecord->setSectorValue(sector);
	surveydata* sorted = speedHead_SD;
	if(sorted == NULL || sorted->getSpeedValue() >= newRecord->getSpeedValue())
	{
		newRecord->setSpeedNext(sorted);
		speedHead_SD = newRecord;
	}
	else
	{
		surveydata* current = sorted;
		while(current->getSpeedNext() != NULL && current->getSpeedNext()->getSpeedValue() < newRecord->getSpeedValue())
		{
			current = current->getSpeedNext();
		}
		newRecord->setSpeedNext(current->getSpeedNext());
		current->setSpeedNext(newRecord);
	}
}

void linkedlist::insertSortedExposure(int sector, int exposure, int speed)
{
	surveydata* newRecord = new surveydata();
	newRecord->setExposureValue(exposure);
	newRecord->setSpeedValue(speed);
	newRecord->setSectorValue(sector);
	surveydata* sorted = exposureHead_SD;
	if(sorted == NULL || sorted->getExposureValue() >= newRecord->getExposureValue())
	{
		newRecord->setExposureNext(sorted);
		exposureHead_SD = newRecord;
	}
	else
	{
		surveydata* current = sorted;
		while(current->getExposureNext() != NULL && current->getExposureNext()->getExposureValue() < newRecord->getExposureValue())
		{
			current = current->getExposureNext();
		}
		newRecord->setExposureNext(current->getExposureNext());
		current->setExposureNext(newRecord);
	}
}

void linkedlist::printDataSectorWise() const
{
	cout << "Data by Sector" << endl;
	const surveydata* tempPtr = sectorHead_SD;
	while(tempPtr)
	{
		cout << "Sector: #" << tempPtr->getSectorValue() << " " << tempPtr->getExposureValue() << "% exposure, " << tempPtr->getSpeedValue() << " km/hr windspeed" << endl;
		tempPtr = tempPtr->getSectorNext();
	}
}

void linkedlist::printDataExposureWise() const
{
	cout << "Data by Exposure" << endl;
	const surveydata* tempPtr = exposureHead_SD;
	while(tempPtr)
	{
		cout << "Sector: #" << tempPtr->getSectorValue() << " " << tempPtr->getExposureValue() << "% exposure, " << tempPtr->getSpeedValue() <<  " km/hr windspeed" << endl;
		tempPtr = tempPtr->getExposureNext();
	}
}

void linkedlist::printDataSpeedWise() const
{
	cout << "Data by Speed" << endl;
	const surveydata* tempPtr = speedHead_SD;
	while(tempPtr)
	{
		cout << "Sector: #" << tempPtr->getSectorValue() << " " << tempPtr->getExposureValue() << "% exposure, " << tempPtr->getSpeedValue() << " km/hr windspeed" << endl;
		tempPtr = tempPtr->getSpeedNext();
	}
}

void linkedlist::averagePerSector() const
{
	const surveydata* tempPtr = sectorHead_SD;
	for(int i = 0; i <= 500 && tempPtr; i++)
	{
		int sectorNum = tempPtr->getSectorValue();
		if(sectorNum == i + 1)
		{
			int expVals = 0;
			int speedVals = 0;
			int totalSectorCount = 0;
			while(tempPtr && tempPtr->getSectorValue() == sectorNum)
			{
				expVals += tempPtr->getExposureValue();
				speedVals += tempPtr->getSpeedValue();
				tempPtr = tempPtr->getSectorNext();
				totalSectorCount++;
			}
			if(totalSectorCount < 1)
				cout << "Sector: #" << sectorNum << " " << expVals << "% exposure, " << speedVals << " km/hr windspeed" << endl;
			else
				cout << "Sector: #" << sectorNum << " " << round(expVals / totalSectorCount) << "% exposure" << round(speedVals / totalSectorCount) << " km /hr windspeed" << endl;
		}
		else
			cout << "Sector: #" << i + 1 << " -- no data -- " << endl;
	}
}

void linkedlist::histogramForExposure() const
{
	const surveydata* tempPtr = exposureHead_SD;
	while(tempPtr)
	{
		int exposureValue = tempPtr->getExposureValue();
		int exposureCount = 0;
		while(tempPtr && tempPtr->getExposureValue() == exposureValue)
		{
			exposureCount++;
		}
		cout << exposureValue << ", " << exposureCount << endl;
	}
}

void linkedlist::histogramForSpeed() const
{
	const surveydata* tempPtr = speedHead_SD;
	for(int i = 0; i <= 70 && tempPtr; i++)
	{
		int speedValue = tempPtr->getSpeedValue();
		if(speedValue == i + 1)
		{
			while(tempPtr && tempPtr->getSpeedValue() == i + 1)
			{
				speedValue = tempPtr->getSpeedValue();
				int speedCount = 0;
				while(tempPtr && tempPtr->getSpeedValue() == speedValue)
				{
					speedCount++;
					tempPtr = tempPtr->getSpeedNext();
				}
				cout << i + 1 << ", " << speedCount << endl;
			}
		}
		else
			cout << i + 1 << ", " << 0 << endl;
	}
}

bool linkedlist::sectorExist(int sectorToCheck) const
{
	const surveydata* tempPtr = sectorHead_SD;

	while(tempPtr)
	{
		if(tempPtr->getSectorValue() == sectorToCheck)
			return true;
		tempPtr = tempPtr->getSectorNext();
	}
	return false;
}

void linkedlist::removeFromList(int sector) const
{
	surveydata* tempPtr = sectorHead_SD, * prev = NULL;
	while(tempPtr && tempPtr->getSectorValue() == sector)
		tempPtr = tempPtr->getSectorNext();
	surveydata* currentPtr = tempPtr;

	while(currentPtr)
	{
		if(currentPtr->getSectorValue() == sector)
			prev->setSectorNext(currentPtr->getSectorNext());
		else
			prev = currentPtr;
		currentPtr = currentPtr->getSectorNext();
	}
}

void linkedlist::printSectorList() const
{

	const surveydata* tempPtr = sectorHead_SD;
	while(tempPtr)
	{
		cout << tempPtr->getSectorValue();
		tempPtr = tempPtr->getSectorNext();
		if(tempPtr)
			cout << ", ";
	}
}
