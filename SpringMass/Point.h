#pragma once
#include "ofMain.h"
#include <vector>

class Point
{
public:
	Point(ofVec3f pos, double r);
	~Point();

	//Opearting functions
	ofVec2f calculateSpringForce(ofVec3f pos1, ofVec3f pos2, double k, double springLength);
	void addSpring(Point* one, Point* two);
	void connectPoints(Point* point);
	
	
	double getMass();
	double getRadius();
	double getSpring(int index);
	int getConnectedSize();
	ofVec3f getAcceleration();
	ofVec3f getDamping();
	ofVec3f getPosition();
	ofVec3f getOldPosition();
	Point* getConnected(int index);
	
	void setAcceleration(ofVec3f acc);
	void setPosition(ofVec3f pos);
	void setPreviousPosition(ofVec3f pos);
	
	void update();
	void draw();
	
private:
	double radius;
	double mass;
	double dt;
	ofVec3f acceleration;
	ofVec3f position;
	ofVec3f previousPosition;	
	ofVec3f velocity;
	vector<double> springLengths;
	vector<Point*> connectedPoints;
};

