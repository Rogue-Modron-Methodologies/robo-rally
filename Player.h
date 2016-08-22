// Player Header
// Has a collection of cards which are used to register it's robot
// Has a robot that actually moves about the board

#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "Robot.h"
#include "Card.h"



class Player : public Object  {
	//std::string name;
	//std::vector<Card> hand;
	//std::vector<Card> program;
	Robot *robot;
	//Card *currentAction;

public:
	Player(std::string robotName) 
		: Object(ROBOT_BOARD, { 2000, 700 }, { 0, 0 }, { 300, 300 }) {
		robot = new Robot(robotName, { 0,0 });
	};
	~Player() { delete robot; }
	Robot *getRobot() { return robot; }
	void drawPlayer(sf::RenderWindow &window) {
		this->draw(window);
		robot->draw(window);
	};

	int queueOrder(int actionNum) {
		// 
		// return the 
	}
	sf::Vector2f getRobotPosition() { return robot->getPosition(); }
	void setRobotPosition(sf::Vector2f pos, int orientation) {
		robot->setPosition(pos);
		robot->setRotation(orientation);
	}
	void initializeRobot(sf::Vector2f pos, int orientation) {  
		robot->setResPoint(pos); 
		robot->returntoResPoint();
		robot->setRotation(orientation); 
	}
	void resetRobot() {
		robot->returntoResPoint();
	}
	void moveRobot(int direction) {
		switch (direction)
		{
		case up:
			robot->moveForward();
			break;
		case right:
			robot->turnRight();
			break;
		case down:
			robot->moveBackward();
			break;
		case left:
			robot->turnLeft();
			break;
		}
	}
	void programRobot() {};
};

#endif // PLAYER_H