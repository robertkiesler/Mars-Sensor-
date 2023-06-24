#include "surveydata.h"

void surveydata::setSectorValue(int sector)
{
	this->sector = sector;
}

void surveydata::setExposureValue(int exposure)
{
	this->exposure = exposure;
}

void surveydata::setSpeedValue(int speed)
{
	this->speed = speed;
}

int surveydata::getSectorValue()const
{
	return this->sector;
}

int surveydata::getExposureValue()const
{
	return this->exposure;
}

int surveydata::getSpeedValue()const
{
	return this->speed;
}

void surveydata::setSectorNext(surveydata* sectorNext)
{
	this->sectorNext = sectorNext;
}

void surveydata::setExposureNext(surveydata* exposureNext)
{
	this->exposureNext = exposureNext;
}

void surveydata::setSpeedNext(surveydata* speedNext)
{
	this->speedNext = speedNext;
}

surveydata* surveydata::getSectorNext()const
{
	return this->sectorNext;
}

surveydata* surveydata::getExposureNext()const
{
	return this->exposureNext;
}

surveydata* surveydata::getSpeedNext()const
{
	return this->speedNext;
}
