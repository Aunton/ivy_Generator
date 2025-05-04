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


#include "RenderWidget.h"
#include "Common.h"



RenderWidget::RenderWidget() 
{
	



	imageNr = 0;
}




void RenderWidget::paintGL()
{



	//camera, initialize projection, view, and model matrix
	setupCamera();

	//light, e.g. ambient and three diffuse lights
	setupLight();

	//mesh, e.g. basic mesh, ivy mesh
	renderScene();

	//auxiliary objects, e.g. grid, ivy skeleton
	renderAuxiliary();
}


void RenderWidget::resizeGL(int width, int height)
{
	
}



void RenderWidget::setupCamera()
{
	
}


void RenderWidget::setupLight()
{
	
}


void RenderWidget::renderScene()
{
}



void RenderWidget::renderAuxiliary()
{
}



void RenderWidget::writeScreen()
{
}