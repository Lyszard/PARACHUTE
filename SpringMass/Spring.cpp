#include "Spring.h"
#include <iostream>
using namespace std;
Spring::Spring(double pos, double len, int pointsNumber, double springConstant):
	position(pos),
	length(len),
	pointsNumber(pointsNumber),
	springConstant(springConstant),
	type(type),
	G(9.81)
{
	for (int i = 0; i <= pointsNumber; i++)
		points.push_back(new Point(ofVec3f(position + (length / pointsNumber)*i, 600, 0), 5));
	
	 
	
		for (int i = 0; i < points.size(); i++)
		{
			if (i == 0)
			{
				points[i]->connectPoints(points[i + 1]);
				points[i]->addSpring(points[i], points[i + 1]);
			}
			else if (i == points.size() - 1)
			{
				points[i]->connectPoints(points[i - 1]);
				points[i]->addSpring(points[i], points[i - 1]);
			}
			else
			{
				points[i]->connectPoints(points[i + 1]);
				points[i]->connectPoints(points[i - 1]);
				points[i]->addSpring(points[i], points[i + 1]);
				points[i]->addSpring(points[i], points[i - 1]);
			}
		}
	
}

Spring::~Spring()
{
}

vector<Point*> Spring::getPoints()
{
	return points;
}

void Spring::update( Attractor * att)
{
	
	ofVec2f SumForce;
	for (int i = points.size() - 2; i > 0; i--)
	{
		SumForce = ofVec2f(0, 0);
		for (int j = 0; j < points[i]->getConnectedSize(); j++)
		{
			SumForce += points[i]->calculateSpringForce(points[i]->getPosition(), points[i]->getConnected(j)->getPosition(), springConstant, points[i]->getSpring(j));

		}
		SumForce += att->CalculateAttraction(points[i]);
		//cout << "SumF " << SumForce[0] <<" "<<  SumForce[1] <<" "<< SumForce[2]<<endl;
		
		points[i]->setAcceleration(ofVec3f(SumForce[0] - points[i]->getDamping()[0], (SumForce[1] + points[i]->getMass() * G) - points[i]->getDamping()[1], 0));
		
	}

	for (int i = 0; i < points.size(); i++)
	{
		points[i]->update();
	}
}

void Spring::draw()
{
	ofSetColor(139, 69, 19);
	for (int i = 1; i < points.size(); i++)
	{
		ofLine(points[i]->getPosition()[0], points[i]->getPosition()[1], points[i - 1]->getPosition()[0], points[i - 1]->getPosition()[1]);
	}

	for (int i = 0; i < points.size(); i++)
	{
		points[i]->draw();
	}
}


