
#ifndef HW4_GAME_H
#define HW4_GAME_H
#include "Map.h"
#include "Robot.h"
#include <iostream>


using namespace std;
/**
 * Game is a class that represents a game of robots moving on maps.
 * The Game class has a static member Curr_Serial_Number which is used to assign serial numbers to robots.
 * The Game class has a constructor which creates a copy of the source object and 3 member functions:
 * Add_Robot, Delete_Robot, Move_robot
 */
class Game{

private:
    int a1 [7][7] = {{1,1,1,0,0,1,1},{0,0,0,0,1,1,0}
            ,{0,1,1,0,0,0,0},{0,0,1,1,1,0,1}
            ,{0,0,0,1,1,0,1},{0,1,1,1,1,0,0},
                            {0,0,0,0,0,1,1}};

    int a2 [7][7] = {{1,1,0,0,1,1,1},{0,1,0, 1,1,1,1}
            ,{1,0,0,1,0,0,0},{0,1,0,1,0,1,0},
                            {0,1,0,0,0,1,0},{0,1,1,1,1,1,1},{0,0,1,1,1,1,1}};

    Map* _map1 = new Map(a1,1);
    Map* _map2 = new Map(a2,2);
    Robot** _robots = new Robot * [0];
    static int rob_idx; // keep track the robots number

public:
    Game()= default;; // default constructor

    friend class Map; // map is friend class

    static int Curr_Serial_Number ;// counter to keep track about the number of robots in the system and in order to
    // allocate serial number to new robot

    Game(const Game& source); // copy constructor

    /**
    * This function displays a menu to the user and allows them to perform various operations on robots in the game.
    * The user is prompted to enter a choice from the menu, and the corresponding action is taken. The available choices are:
    1.Add a robot to the game at a specified location on a specified map.
    2.Delete a robot from the game based on its serial number.
    3.Move a robot on its current map based on its serial number and a specified direction.
    4.Print the result of adding two maps element-wise using the + operator.
    5.Add two maps element-wise using the += operator and assign the result to one of the maps.
    6.Assign one map to another using the = operator.
    7.Compare two maps for equality using the == operator.
    8.Print a map using the << operator.
    9.Quit the menu.
    The function continues to display the menu and accept user input until the user selects the option to quit.
    */
    void RobotControlMenu();

    /**
     * default destructor
     */
    ~Game();

    /**
     * Allocates and adds a robot to the game at a specified location on a specified map.
     * resize the dynamic array to fit the new size
     * @param c_x The x-coordinate of the desired location for the robot.
     * @param c_y The y-coordinate of the desired location for the robot.
     * @param map The map on which the robot should be placed.
     */
    void Add_Robot(int c_x , int c_y , int map);

    /**
     * search for the robot in the robots array, when found deletes him and remove him from the array.
     * then shrink the array to fit the new size
     * @param s_number:  the serial number represents the robot we want to delete
     * @param print: if print = 1 do not print output
     */
    void Delete_Robot(int s_number, int print);

    /**
     * Finds the robot with serial number s_number, and moves it to the new location (c_x, c_y).
     * @param s_number: The serial number of the robot to be moved.
     * @param c_x: The new x-coordinate of the robot.
     * @param c_y: The new y-coordinate of the robot.
     */
    void Move_robot(int Rob_Num, char direction);

};
#endif //HW4_GAME_H
