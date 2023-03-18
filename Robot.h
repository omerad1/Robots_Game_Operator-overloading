#ifndef HW4_ROBOT_H
#define HW4_ROBOT_H
#include <iostream>
using namespace std;
/**
 *  Class robot represents a robot with a serial number, x and y coordinates, and a map number.
 */
class Robot{

private:
    int SerialNumber_; // serial number to identify robot
    // place
    int _x; // int represents x coordinate of the Robot location
    int _y; // int represents y coordinate of the Robot location
    int _map_number; // int represents map number the robot is currently in

public:

/**
 * constructor
 * @param SerialNumber : int represents serial number identify an Robot
 * @param x : int represents x coordinate of the Robot location
 * @param y : int represents y coordinate of the Robot location
 */
    Robot(int SerialNumber, int x , int y, int map_number); //constructor

/**
 * Robot class copy constructor
 * Initializes a new Robot object as a copy of an existing Robot object
 * @param Source : refernce to the robot we want to copy
 */
    Robot(const Robot& Source); // copy constructor

/**
 * operator = to robot assignment
 * @param Source : refernce to Robot
 * @return  : this
 */
    Robot& operator= (const Robot& Source);

    /**
     * destructor
     */
    ~Robot(); // destructor

    /**
     * set new location to the Robot
     * @param x : new x coordinate
     * @param y : new y coordinate
     * @param map_number : map we want to transfer the robot into, or to keep his location
     */
    void SetLocation(int x , int y , int map_number);

    friend class Map; // let Map class access robot fields

    friend class Game;// let Game class access robot fields
    /**
     * Robot class operator<< overload
     * Allows a Robot object to be printed to an out stream
     * "SERIAL_NUMBER MAP: MAP_NUMBER GPS: X,Y"
     * @param out: reference to the output stream.
     * @param rob: reference to the Robot object to be printed.
     * @return: reference to the output stream.
     */
    friend ostream& operator<< (ostream& out, const Robot& rob); // friend cut operator

};

#endif //HW4_ROBOT_H
