#include "Attractor.h"
#include <iostream>
using namespace std;
Attractor::Attractor(ofVec3f pos, double m):
	position(pos),
	mass(m),
	G(-9.81)
{}
	
	
ofVec3f Attractor::CalculateAttraction(Point* a)
{
	ofVec3f AttractionForce;
	double Fx = position[0] - a->getPosition()[0];
	double Fy = position[1] - a->getPosition()[1];
	double Fz = position[2] - a->getPosition()[2];

	double Flength = sqrt(pow(Fx,2)+pow(Fy,2));


	if (Flength > 20)
	{
		Fx = Fx / Flength;
		Fy = Fy / Flength;
		double Fstrength = (mass * a->getMass()*G) / pow(Flength,2);
		Fx = Fx * Fstrength;
		Fy = Fy * Fstrength;
		AttractionForce[0] = Fx;
		AttractionForce[1] = Fy;
		AttractionForce[2] = 0;
		//cout << "Fx " << AttractionForce[0] << endl;
		//cout << "Fy " << AttractionForce[1] << endl;
		
	}

	return AttractionForce;
}
	
void Attractor::draw()
{
	ofSetColor(0, 0, 255);
	ofCircle(position[0], position[1], position[2], 10);


}

void Attractor::setG()
{
	G*=-1;
}

ofVec3f Attractor::getPos()
{
	return position;

}

void Attractor::setMass(double m)
{
	mass = m ;
}