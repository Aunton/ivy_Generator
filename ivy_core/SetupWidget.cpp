/**************************************************************************************
**
**  Copyright (C) 2006 Thomas Luft, University of Konstanz. All rights reserved.
**
**  This file is part of the Ivy Generator Tool.
**
**  This program is free software; you can redistribute it and/or modify it
**  under the terms of the GNU General Public License as published by the
**  Free Software Foundation; either version 2 of the License, or (at your
**  option) any later version.
**  This program is distributed in the hope that it will be useful, but
**  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
**  or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
**  for more details.
**  You should have received a copy of the GNU General Public License along
**  with this program; if not, write to the Free Software Foundation,
**  Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110, USA 
**
***************************************************************************************/


#include "SetupWidget.h"
#include "Common.h"
#include "OBJLoader.h"
#include "OBJWriter.h"
#include <iostream>
using namespace std;





void SetupWidget::setIvySize(int value)
{
	Common::ivy.ivySize = (float)value / 20000.0f;
}


void SetupWidget::setIvyLeafSize(int value)
{
	Common::ivy.ivyLeafSize = (float)value / 500.0f;


}


void SetupWidget::setIvyBranchSize(int value)
{
	Common::ivy.ivyBranchSize = (float)value / 2000.0f;

	
}


void SetupWidget::setBranchingProbability(int value)
{
	Common::ivy.branchingProbability = (float)value / 1000.0f;

	
}


void SetupWidget::setLeafProbability(int value)
{
	Common::ivy.leafProbability = (float)value / 1000.0f;

	
}


void SetupWidget::setMaxFloatLength(int value)
{
	Common::ivy.maxFloatLength = (float)value / 1000.0f;


}


void SetupWidget::setMaxAdhesionDistance(int value)
{
	Common::ivy.maxAdhesionDistance = (float)value / 1000.0f;

	
}


void SetupWidget::setPrimaryWeight(int value)
{
	Common::ivy.primaryWeight = (float)value / 1000.0f;

	
}


void SetupWidget::setRandomWeight(int value)
{
	Common::ivy.randomWeight = (float)value / 1000.0f;

	
}


void SetupWidget::setGravityWeight(int value)
{
	Common::ivy.gravityWeight = (float)value / 1000.0f;


}


void SetupWidget::setAdhesionWeight(int value)
{
	Common::ivy.adhesionWeight = (float)value / 1000.0f;

	
}	


void SetupWidget::onImportObj(char* va)
{
	//OBJLoader::loadOBJ("C:\\Users\\28362\\Downloads\\Compressed\\", "3.obj", Common::mesh);
	OBJLoader::loadOBJ(va, "", Common::mesh);
	
}


void SetupWidget::onExportObj(char* va)
{
	string path = "D:\\3.obj";
	OBJWriter::writeOBJ(va,".obj", Common::ivy);

}


void SetupWidget::onGrow()
{
	Common::ivy.grow();

	//compute alive roots
	unsigned int aliveCount = 0;

	for (std::vector<IvyRoot>::iterator root = Common::ivy.roots.begin(); root != Common::ivy.roots.end();  ++root)
	{
		if (root->alive) ++aliveCount;
	}



	if (aliveCount == 0)
	{
		
	}



	//test
	//Common::ivy.birth();
	//Common::renderWidget->writeScreen();

	
}


void SetupWidget::onToggleGrow(bool checked)
{
	if (checked)
	{
		Common::ivy.reset();

		
	}
	else
	{
	
	}
}


void SetupWidget::onBirth()
{


	Common::ivy.birth();


}

void SetupWidget::onFlipNormals()
{
	Common::mesh.flipNormals();

	Common::mesh.createDisplayList();

	
}
	

	


