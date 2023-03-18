
#ifndef HW4_MAP_H
#define HW4_MAP_H
#include "Robot.h"
#include <iostream>
using namespace std;
/**
 * class seems to represent a map in a game.
 * The class has a 7 by 7 integer array that stores the map,
 * and an integer member to store the map identifier
 */

class Map{

private:
    int _map_array [7][7]{}; // the array represents the map
    int _map_number{}; // map identifier
public:

    /**
     * default constructor
     */
    Map();

    /**
     * constructor
     * @param map_array : receives array matrix represents map
     * @param map_number : map identifier
     */
    Map(int map_array[7][7], int map_number);


    /**
     * copy constructor
     * @param source Map we want to copy
     */
    Map(const Map& source);

    /**
     * default destructor
     */
    ~Map();

    /**
     * This function assigns the elements of the m Map to this Map
     * It checks for self-assignment before making any changes
     * @param m : reference to other Map we want to assign to this Map
     * @return a reference to this Map after the assignment
     */
    Map& operator=(const Map& m);

    /**
    * operator ==
    * Compares two Map objects for equality
    * @param m: Map object to compare with this Map object
    * @return true if all elements in both Map objects are equal, false otherwise
    */
    bool operator==(const Map& m)const;

    /**
     * operator +
     * @param m : other map we want to create new map with
     * @return : new map that is the result of an OR operation on the elements of this map and the m map
     */
    Map operator+(const Map& m) const;

    /**
     * This function performs an OR operation on the elements of this Map and the m Map,
     * and assigns the result to this Map.
     * @param m : reference to other Map we want to perform the operation on
     * @return a reference to this Map
     */
    Map operator+=(const Map& m);

    /**
     * This function overloads the << operator to allow a Map object to be printed to an output stream.
     * @param out : reference to the stream class out
     * @param map : map we want to print to output stream
     * @return a reference to the output stream.
     */
    friend ostream& operator<< (ostream& out, const Map& map);

    /**
     * make Game able to get into Map fields
     */
    friend class Game;
};

























#endif //HW4_MAP_H
