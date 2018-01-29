#include "Point.h"

Point::Point(ofVec3f pos, double r) :
	radius(r),
	mass(2),
	dt(0.1)
{
	position = pos;
	previousPosition = pos;
	velocity = ofVec3f(0, 0, 0);
}

Point::~Point()
{
}


ofVec2f Point::calculateSpringForce(ofVec3f pos1, ofVec3f pos2, double k, double springLength)
{
	double springForceX;
	double springForceY;
	if (pos1[0] > pos2[0])
	{
		springForceX = -k * (pos1[0] - pos2[0] - springLength);
		springForceY = -k * (pos1[1] - pos2[1] - springLength);
	}
	else
	{
		springForceX = k * (pos2[0] - pos1[0] - springLength);
		springForceY = k * (pos2[1] - pos1[1] - springLength);
	}
	ofVec2f springForce;
	springForce = ofVec2f(springForceX, springForceY);
	return springForce;
}

void Point::addSpring(Point* p1, Point* p2)
{
	double d = sqrt(pow(p1->getPosition()[0] - p2->getPosition()[0], 2) + pow(p1->getPosition()[1] - p2->getPosition()[1], 2));
	springLengths.push_back(d);
}

void Point::connectPoints(Point* point)
{
	connectedPoints.push_back(point);
}


double Point::getMass()
{
	return mass;
}

double Point::getRadius()
{
	return radius;
}

double Point::getSpring(int index)
{
	return springLengths[index];
}

int Point::getConnectedSize()
{
	return connectedPoints.size();
}

ofVec3f Point::getAcceleration()
{
	return acceleration;
}

ofVec3f Point::getDamping()
{
	ofVec3f damping;
	damping = ofVec3f(2*velocity[0], 2 * velocity[1], 2 * velocity[2]);
	return damping;
}

ofVec3f Point::getPosition()
{
	return position;
}

ofVec3f Point::getOldPosition()
{
	return previousPosition;
}

Point* Point::getConnected(int index)
{
	return connectedPoints[index];
}


void Point::setAcceleration(ofVec3f forces)
{
	acceleration = ofVec3f((forces[0] / getMass()), (forces[1] /getMass()), (forces[2] / getMass()));
}

void Point::setPosition(ofVec3f positionNew)
{
	position = positionNew;
}

void Point::setPreviousPosition(ofVec3f positionNew)
{
	previousPosition = positionNew;
}


void Point::update()
{
	ofVec3f temp;
	temp = position;

	position = ofVec3f(2 * position[0] - previousPosition[0] + (dt*dt) * acceleration[0] / mass,
		2 * position[1] - previousPosition[1] + (dt*dt) * acceleration[1] / mass,
		2 * position[2] - previousPosition[2] + (dt*dt) * acceleration[2] / mass);

	previousPosition = temp;
	velocity = ofVec3f(position[0] - previousPosition[0], position[1] - previousPosition[1], position[2] - previousPosition[2]);
}

void Point::draw()
{
	ofSetColor(0, 0, 0);
	ofCircle(position[0], position[1], position[2], radius);
}