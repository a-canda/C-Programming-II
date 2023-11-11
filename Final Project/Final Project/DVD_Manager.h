#pragma once
#ifndef DVD_MANAGER_H
#define DVD_MANAGER_H
#include <iostream>
#include "DVD.h"

class DVD_Manager
{
public:
	void addDVD(DVD&);
	void deleteDVD(DVD&);
	void updateDVD(DVD&);
};

#endif


