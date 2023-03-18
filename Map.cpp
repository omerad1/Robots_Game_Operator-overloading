#include "Map.h"
#include <iostream>

/**
 * constructor
 */
Map::Map(int map_array[7][7], int map_number =0) {

    for(int j = 6; j > -1; j--){
        for(int i = 0; i < 7; i++){
            _map_array[i][j] = map_array[i][j];
        }
    }
    this->_map_number = map_number;
}

/**
 * copy constructor
 */
Map::Map(const Map& source) {
    for(int j = 6; j > -1; j--){
        for(int i = 0; i < 7; i++){
            this->_map_array[i][j] = source._map_array[i][j];
        }
    }
    this->_map_number = source._map_number;
}

/**
 * default destructor
 */
Map::~Map() = default;


/**
 * operator +
 */
Map Map::operator+(const Map &m) const {
    int temp [7][7];
    for(int j = 6; j > -1; j--){
        for(int i = 0; i < 7; i++){
            if(this->_map_array[i][j] == 1 || m._map_array[i][j] == 1){
                temp[i][j] =1;
            }
            else{
                temp[i][j] = 0;
            }
        }
    }
    Map res(temp,3);
    return res;
}

/**
 * This function assigns the elements of the m Map to this Map
 * It checks for self-assignment before making any changes
 */
Map &Map::operator=(const Map &m) {
    if(this == &m)// The if statement in the assignment operator checks for self-assignment
        return *this;

    for(int j = 6; j > -1; j--){
        for(int i = 0; i < 7; i++){
            _map_array[i][j] = m._map_array[i][j];
        }
    }
    return *this;
}


/**
 * This function performs an OR operation on the elements of this Map and the m Map,
 * and assigns the result to this Map.
 */
Map Map::operator+=(const Map &m)  {
    for(int j = 6; j > -1; j--){
        for(int i = 0; i < 7; i++){
            if (m._map_array[i][j] == 1){
                this->_map_array[i][j] = 1;
            }
        }
    }
    return *this;
}

/**
 * This function overloads the << operator to allow a Map object to be printed to an output stream.
 */
ostream &operator<<(ostream &out, const Map &map) {
    for(int j = 6; j > -1; j--){
        out<<"[";
        for(int i = 0; i < 7; i++){
            if(i==6){
                out<<map._map_array[i][j];
            }
            else {
                out << map._map_array[i][j] << " ";
            }
        }
        out<<"]\n";
    }
    return out;
}

/**
* operator ==
* Compares two Map objects for equality
*/
 bool Map::operator==(const Map &m) const {
     for(int j = 6; j > -1; j--){
         for(int i = 0; i < 6; i++){
            if(this->_map_array[i][j] != m._map_array[i][j]){
                return false;
            }
        }
    }
    return true;
}

Map::Map()= default;


