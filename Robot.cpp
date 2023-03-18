
#include "Robot.h"

/**
 * constructor
 * @param SerialNumber : int represents serial number identify an Robot
 * @param x : int represents x coordinate of the Robot location
 * @param y : int represents y coordinate of the Robot location
 * @param map_number: number represents the current map the robot is in at the moment
 */

Robot::Robot(int SerialNumber, int x, int y , int map_number): SerialNumber_(SerialNumber) , _x(x) , _y(y)
,_map_number(map_number) {}


/**
 * copy constructor
 * @param Source : reference to robot we want to copy into this
 */
Robot::Robot(const Robot &Source): SerialNumber_(Source.SerialNumber_), _x(Source._x), _y(Source._y)
, _map_number(Source._map_number){}


/**
 * operator = to robot assignment
 * @param Source : refernce to Robot
 * @return  : this
 */
Robot &Robot::operator=(const Robot &Source) {
    if(this == &Source){ // The if statement in the assignment operator checks for self-assignment
        return *this;
    }
    this->SerialNumber_ = Source.SerialNumber_;
    this->_x = Source._x;
    this->_y = Source._y;
    return *this;
}


/**
 * location setter
 * @param x : new x coordinate
 * @param y : new y coordinate
 */
void Robot::SetLocation(int x , int y ,  int map_number) {
    this->_x = x;
    this->_y = y;
    this->_map_number = map_number;

}

/**
 * Robot class operator<< overload
   Allows a Robot object to be printed to an out stream
   */

ostream &operator<<(ostream &out, const Robot &rob) {
    out<<rob.SerialNumber_<<" MAP: "<<rob._map_number<<" GPS: "<<rob._x<<","<<rob._y<<"\n";
    return out;
}
/**
 * default constructor
 */
Robot::~Robot() = default;



