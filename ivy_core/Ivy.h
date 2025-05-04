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


#ifndef IVY_H
#define IVY_H

#include "Vector3d.h"
#include "BasicMesh.h"
#include <vector>



/** an ivy node */
struct  IvyNode2
{
public:

	//IvyNode2() : climb(false), length(0.0f), floatingLength(0.0f) {};

	/** node position */
	Vector3d2 pos;

	/** primary grow direction, a weighted sum of the previous directions */
	Vector3d2 primaryDir;

	/** adhesion vector as a result from other scene objects */
	Vector3d2 adhesionVector;

	/** a smoothed adhesion vector computed and used during the birth phase,
	   since the ivy leaves are align by the adhesion vector, this smoothed vector
	   allows for smooth transitions of leaf alignment */
	Vector3d2 smoothAdhesionVector;

	/** length of the associated ivy branch at this node */
	float length;

	/** length at the last node that was climbing */
	float floatingLength;

	/** climbing state */
	bool climb;
};





/** an ivy node */
class IvyNode
{
public:

	IvyNode() : climb(false), length(0.0f), floatingLength(0.0f) {};

	/** node position */
	Vector3d pos;			

	/** primary grow direction, a weighted sum of the previous directions */
	Vector3d primaryDir;

	/** adhesion vector as a result from other scene objects */
	Vector3d adhesionVector;

	/** a smoothed adhesion vector computed and used during the birth phase,
	   since the ivy leaves are align by the adhesion vector, this smoothed vector
	   allows for smooth transitions of leaf alignment */
	Vector3d smoothAdhesionVector;

	/** length of the associated ivy branch at this node */
	float length;

	/** length at the last node that was climbing */
	float floatingLength;

	/** climbing state */
	bool climb;
};



 struct IvyRoot2
{

public:

	/** a number of nodes */
	//std::vector<IvyNode2> nodes;
	IvyNode2 nodes[3000]; 
	//IvyNode2* n2;
	/** alive state */
	bool alive;

	/** number of parents, represents the level in the root hierarchy */
	int parents;
};






/** an ivy root point */
class IvyRoot
{
public:

	/** a number of nodes */
	std::vector<IvyNode> nodes;

	/** alive state */
	bool alive;

	/** number of parents, represents the level in the root hierarchy */
	int parents;
};


/** the ivy itself, derived from basic mesh that allows to handle the final ivy mesh as a drawable object */
class Ivy : public BasicMesh
{
public:

	Ivy();

	void resetSettings();

	/** initialize a new ivy root */
	void seed(const Vector3d &seedPos);

	/** one single grow iteration */
	void grow();
	void setSet(float aa, float bb, float cc, float dd, float ee, float ff, float gg, float hh, float ii, float jj, float kk);
	void multiple_seed(Vector3d seedPos);

	/** compute the adhesion of scene objects at a point pos*/
	Vector3d computeAdhesion(const Vector3d &pos);

	/** computes the collision detection for an ivy segment oldPos->newPos, newPos will be modified if necessary */
	bool computeCollision(const Vector3d &oldPos, Vector3d &newPos, bool &climbingState);

	/** creates the ivy triangle mesh */
	void birth();
	
	/** the ivy roots */
	std::vector<IvyRoot> roots;	

public:

	/** the ivy size factor, influences the grow behaviour [0..0,1] */
	float ivySize;

	/** leaf size factor [0..0,1] */
	float ivyLeafSize;

	/** branch size factor [0..0,1] */
	float ivyBranchSize;

    /** maximum length of an ivy branch segment that is freely floating [0..1] */
	float maxFloatLength;

	/** maximum distance for adhesion of scene object [0..1] */
	float maxAdhesionDistance;

	/** weight for the primary grow vector [0..1] */
	float primaryWeight;

	/** weight for the random influence vector [0..1] */
	float randomWeight;

	/** weight for the gravity vector [0..1] */
	float gravityWeight;

	/** weight for the adhesion vector [0..1] */
	float adhesionWeight;

	/** the probability of producing a new ivy root per iteration [0..1]*/
	float branchingProbability;

	/** the probability of creating a new ivy leaf [0..1] */
	float leafProbability;
};


#endif