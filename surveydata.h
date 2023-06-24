#pragma once
#include <cstddef>

class surveydata
{

	int sector;
	int exposure;
	int speed;
	surveydata* sectorNext;
	surveydata* speedNext;
	surveydata* exposureNext;
public:
	surveydata()
	{
		sector = exposure = speed = 0;
	}

	void setSectorNext(surveydata*);
	void setExposureNext(surveydata*);
	void setSpeedNext(surveydata*);
	surveydata* getSectorNext()const;
	surveydata* getExposureNext()const;
	surveydata* getSpeedNext()const;

	void setSectorValue(int);
	void setExposureValue(int);
	void setSpeedValue(int);
	int getSectorValue()const;
	int getExposurevalue()const;
	int getSpeedValue() const;
};
