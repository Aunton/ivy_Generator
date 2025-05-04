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


#include "Camera.h"




Camera::Camera()
{
	pos = Vector3d(0.0f, 0.4f, 0.0f);

	head = PI * 0.25f;

	pitch = PI * 0.1f;

	bank = 0.0f;
	
	pivot = Vector3d(0.0f, 0.0f, 0.0f);

	clipNear = 0.001f;

	clipFar = 10.0f;

	fovy = 45.0f;

	aspectRatio = 1.0f;
}


Camera::~Camera()
{
}


void Camera::computeVectorBasis(Vector3d &dir, Vector3d &right, Vector3d &up)
{
	
}


void Camera::setupPerspectiveMatrix()
{
}


void Camera::setupViewMatrix()
{
	
}


void Camera::placeNicely(const BasicMesh& mesh)
{
	pos = mesh.boundingSpherePos + Vector3d(-mesh.boundingSphereRadius, mesh.boundingSphereRadius * 0.5f, -mesh.boundingSphereRadius);

	head = PI * 0.25f;

	pitch = PI * 0.1f;
}