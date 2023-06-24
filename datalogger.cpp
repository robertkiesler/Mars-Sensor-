#include "datalogger.h"


void datalogger::addData(int sector, int exposure, int speed)
{
	if(exposure < 0 || speed < 0)
	{
		if(!badDataLL.sectorExist(sector)
			badDataLL.createList(sector, exposure, speed);
	}
	else
		normalDataLL.createList(sector, exposure, speed);
}

void datalogger::removeSector(int sector)
{
	normalDataLL.removeFromList(sector);
}

bool datalogger::containsSector(int sector)
{
	return normalDataLL.sectorExist(sector);
}


void datalogger::printReport()
{
	cout << "----------------------------------------------------------------------" << endl
	    << "Data values" << endl << "----------------------------------------------------------------------" << endl;

	normalDataLL.printDataSectorWise();
	normalDataLL.printDataExposureWise();
	normalDataLL.printDataSpeedWise();
	cout << "---------------------------------------------------------------------- " << endl
	    << "Averages Per Sector" << endl << "----------------------------------------------------------------------" << endl;
	normalDataLL.averagesPerSector();
	cout << "---------------------------------------------------------------------- " << endl
	   << "Histogram data for exposure" << endl << "----------------------------------------------------------------------" endl;
	normalDataLL.histogramForExposure();
	cout << "---------------------------------------------------------------------- " << endl
	    << "Histogram data for speed" << endl << "----------------------------------------------------------------------" << endl;
	normalDataLL.histogramForSpeed();
}

void datalogger::printSectorList()
{
	badDataLL.printSectorList();
}
