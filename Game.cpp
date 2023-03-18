#include "Game.h"
#include<string.h>
int Game:: Curr_Serial_Number = 1; // counter to give serial number to new robot enters the system
int Game:: rob_idx = 0; // index that counts how many robots in the system right now
/**
 * copy constructor
 */
Game::Game(const Game &source) {
     this->_robots = source._robots;
     this->_map1 = source._map1;
     this->_map2 = source._map2;

 }
/**
 * Allocates and adds a robot to the game at a specified location on a specified map.
 */
void Game::Add_Robot(int c_x, int c_y, int map) {
    if(c_x > 6 || c_x <0 ||c_y > 6 || c_y <0){
        std::cout<<"Invalid location \n";
        return ;
    }

    else{ // valid location
        if(map == 1){
            if(this->_map1->_map_array[c_x][c_y] == 1){
                std::cout<<"Invalid location \n";
                return ;}
        }
        else{
            if(this->_map2->_map_array[c_x][c_y] == 1){
                std::cout<<"Invalid location \n";
                return ;}

        }
}
        Robot** temp;
        temp = new Robot * [rob_idx + 1];

        for(int i =0 ; i<rob_idx ; i++){ // copy array elements
            temp[i] = _robots[i];
        }

        temp[rob_idx] =new Robot(Curr_Serial_Number,c_x,c_y,map); // creates new robot

        if (!temp[rob_idx]) // checks that the allocation succeed
        {
            delete[]temp;
            return ;
        }
        delete[]_robots;
        _robots =temp;
         Curr_Serial_Number ++;
         rob_idx++;

         std::cout<<"New Robot: "<<*_robots[rob_idx-1];

}

/**
 * search for the robot in the robots array, when found deletes him and remove him from
 */
void Game::Delete_Robot(int s_number, int print = 0) {
    // Find the index of the robot you want to delete

    int index = -1;
    for (int i = 0; i < rob_idx; i++) {
        if (_robots[i]->SerialNumber_ == s_number) {
            index = i;
            break;
        }
    }
    if(index == -1){
        return;
    }
    if(print == 0){
        std::cout<<"Robot deleted: "<<*_robots[index];}
    if (index != -1) {
        if(rob_idx == 1){
            delete _robots[0];
            rob_idx--;
            return;
        }
        Robot** temp;
        temp = new Robot * [rob_idx - 1];

        int j = 0;
        for (int i = 0; i < rob_idx; i++)
        {
            if (_robots[i]->SerialNumber_ != s_number)
            {
                temp[j] = _robots[i];
                j++;
            }
            else
                delete _robots[i]; // deletes the robot
        }
        delete[]_robots;
        _robots = temp;
        rob_idx--;
        return;
    }

     }

/**
 * first, looking for robot in the robots array, when found checks if hes coordinates are out of bounds, if yes we
 * return and if not we will preforme the needed action based on the given direction, at the end we will check if the robot
 * is not out of bounds, if yes we will change his coordinates to x = -1 y = -1
 */
void Game::Move_robot(int s_number, char direction) {
    int index = -1;
    for (int i = 0; i < rob_idx; i++) {
        if (_robots[i]->SerialNumber_ == s_number) {
            index = i;
            break;
        }
    }
    if( index == -1){
        return;
    }
    Robot* rob = _robots[index];
    const Map* m;
    if(rob->_map_number == 1){
        m = this->_map1;
    }
    else{
        m = this->_map2;
    }

    if(rob->_x == -1 && rob->_y == -1){
        return;
    }

    if(direction == 'U'){ // up
        if(rob->_y+1 >6){
            rob->_y = -1;
            rob->_x = -1;
            return;
        }
        if(m->_map_array[rob->_x][rob->_y+1] != 1){
            rob->_y += 1;}

    }
    else if(direction == 'D'){ // down
        if(rob->_y-1 <0){
            rob->_y = -1;
            rob->_x = -1;
            return;
        }
        if(m->_map_array[rob->_x][rob->_y-1] != 1){
            rob->_y-=1;}

    }
    else if(direction == 'R'){ // right
        if(rob->_x+1 >6){
            rob->_y = -1;
            rob->_x = -1;
            return;
        }
        if(m->_map_array[rob->_x+1][rob->_y] != 1){
            rob->_x +=1;}

    }
    else if(direction == 'L'){ // left
        if(rob->_x-1 <0){
            rob->_y = -1;
            rob->_x = -1;
            return;
        }
        if(m->_map_array[rob->_x-1][rob->_y] != 1){
            rob->_x-=1;}
    }
    if(rob->_y >= 7 || rob->_y < 0 || rob->_x >= 7 || rob->_x <0){
        rob->_y = -1;
        rob->_x = -1;
    }
    if(rob->_x != -1 && rob->_y != -1) {
        std::cout << "Robot: " << *rob;
    }
}


/**
* This function displays a menu to the user and allows them to perform various operations on robots in the game.
* The user is prompted to enter a choice from the menu, and the corresponding action is taken.
*/
void Game::RobotControlMenu() {
    int choice = 1;
    string t_choice;
    int map_number;// map number to get from the user
    int c_x;// x coordinate to get from the user
    int c_y; // y coordinate to get from the user
    int rob_num; // number of identification a robot
    char direction; // char represent the direction that the user  want to move the robot to
    int temp_idx;
    bool res;
    while (true) {
        std::cout << "Robot Control Menu \n";
        std::cout << "1. Add Robot \n";
        std::cout << "2. Delete Robot \n";
        std::cout << "3. Move Robot \n";
        std::cout << "4. Operator + \n";
        std::cout << "5. Operator += \n";
        std::cout << "6. Operator = \n";
        std::cout << "7. Operator == \n";
        std::cout << "8. Operator << \n";
        std::cout << "9. Quit \n";
        std::cout << "Input your option: \n";
        std::cin >> t_choice; // load the user's choice
        int c_checker = 0;// will check if there is letter in the input
        for(int i =0 ; i<t_choice.length();i++){
            if(!isdigit(t_choice[i])) {
                std::cout << "Invalid input\n";
                c_checker++;
                break;
            }
        }
        if(c_checker > 0){
            continue;
        }
        else{
            choice = stoi(t_choice);
        }
        if(choice <1 || choice >9){
            std::cout<<"Invalid input \n";
            continue;
        }
        switch (choice) {
            case 1: /// Add Robot
                std::cout << "Enter MAP number: \n";
                std::cin >> map_number;
                if(map_number>2 || map_number<1){
                    std::cout << "This is not valid Map number ! \n";
                }
                else{
                    std::cout << "Enter Coordinates (X,Y): \n";
                    std::cin >> c_x>>c_y;
                    Add_Robot(c_x,c_y,map_number);
                }
                continue;
            case 2: /// Delete Robot
                std::cout <<"Enter Robot number: \n";
                std::cin >> rob_num; // number to identify the wanted - to delete robot
                Delete_Robot(rob_num);
                continue;

            case 3: /// Move Robot
                std::cout <<"Enter Robot number: \n";
                std::cin >> rob_num; // number to identify the robot we want to move
                std::cout <<"Enter direction: \n";
                std::cin >> direction;// char represent the direction that the user  want to move the robot to
                Move_robot(rob_num,direction);
                continue;

            case 4: /// operator +
              std::cout << *_map1 + *_map2; // prints the new map
              for(int i = 0 ; i<rob_idx ; i++){

                  if((*_map1 + *_map2)._map_array[_robots[i]->_x][_robots[i]->_y] != 1){
                      if(_robots[i]->_x == -1 || _robots[i]->_y==-1){
                          continue;
                      }
                      std::cout<<"Robot: "<<_robots[i]->SerialNumber_<<"GPS: "<<_robots[i]->_x<<","<<_robots[i]->_y<<"\n";
                  }
              }
                continue;

            case 5: /// operator +=
                std::cout<<"Override MAP number: \n";
                std::cin >> map_number;
                if(map_number != 1 && map_number != 2){
                    std::cout<<"invalid MAP number \n";
                    continue;
                }
                if(map_number == 1){
                    *_map1+=*_map2; // will change map1
                }
                else{
                    *_map2+=*_map1;
                }
                temp_idx = 0;
                while(temp_idx<rob_idx){
                    if(_robots[temp_idx]->_x == -1 || _robots[temp_idx]->_y == -1){
                        temp_idx++;
                        continue;
                    }
                    if(_map1->_map_array[_robots[temp_idx]->_x][_robots[temp_idx]->_y] == 1){
                        Delete_Robot(_robots[temp_idx]->SerialNumber_,1);
                    }
                    else{
                        temp_idx++;
                    }
                }
                continue;
            case 6: /// operator =
                std::cout<<"Override MAP number: \n";
                std::cin >> map_number;
                if(map_number != 1 && map_number != 2) {
                    std::cout << "invalid MAP number \n";
                    continue;
                }
                if(map_number == 1) {
                    *_map1 = *_map2; // override map 1
                    temp_idx = 0;
                    while(temp_idx<rob_idx){
                        if(_robots[temp_idx]->_x == -1 || _robots[temp_idx]->_y == -1){
                            temp_idx++;
                            continue;
                        }
                        if(_map1->_map_array[_robots[temp_idx]->_x][_robots[temp_idx]->_y] == 1){
                            Delete_Robot(_robots[temp_idx]->SerialNumber_,1);
                        }
                        else{
                            temp_idx++;
                        }
                    }
                }
                else{
                    *_map2 = *_map1; // override map 2
                    temp_idx = 0;
                    while(temp_idx<rob_idx){
                        if(_robots[temp_idx]->_x == -1 || _robots[temp_idx]->_y == -1){
                            temp_idx++;
                            continue;
                        }
                        if(_map2->_map_array[_robots[temp_idx]->_x][_robots[temp_idx]->_y] == 1){
                            Delete_Robot(_robots[temp_idx]->SerialNumber_,1);
                        }
                        else{
                            temp_idx++;
                        }
                    }
                }

                continue;

            case 7: /// operator ==
                res = *_map1 == *_map2;
                std::cout<<std::boolalpha<<res<<"\n";
                continue;

            case 8: /// operator <<
                std::cout<<"Please enter MAP number: \n";
                std::cin>>map_number;
                if(map_number != 1 && map_number != 2) {
                    std::cout << "invalid MAP number \n";
                    continue;
                }
                if(map_number == 1){
                    std::cout<<*_map1;
                }
                if(map_number == 2){
                    std::cout<<*_map2;
                }
                std::cout<<"\n";
                for(int i = 0 ; i<rob_idx ; i++) {
                    if (_robots[i]->_map_number == map_number) {
                        if(_robots[i]->_x == -1 || _robots[i]->_y==-1){
                            continue;
                        }
                        std::cout <<"Robot: "<< *_robots[i];

                    }
                }
                continue;
            case 9: /// exit
                for(int i = 0; i<rob_idx; i++){ // iterate over the robots array and deletes the allocated memory
                    delete _robots[i];
                }
                delete[]_robots; // deletes the robots array
                delete _map1; // delete map1
                delete _map2; // delete map1
                exit(0); // exit from the program
        }

        }
}
/**
 * destructor
 */
Game::~Game() {
    int i;
    for (i = 0; i < rob_idx; i++)
        delete _robots[i];
    delete[]_robots;
}



