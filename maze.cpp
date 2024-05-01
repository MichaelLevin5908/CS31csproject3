 #include "grid.h"
 #include <iostream>
 #include <string>
 #include <cassert>

 using namespace std;

//Maximum Rows and columns

 bool isValidDirection(char dir) {
    return (dir == 'N' || dir == 'n' || dir == 'E' || dir == 'e' || 
            dir == 'S' || dir == 's' || dir == 'W' || dir == 'w');
}

bool hasProperSyntax(string path) {
    // Check if the string is empty
    if (path.empty()) {return false;}

    int i = 0;
    while (i < path.length()) {
        // Check if current character is a valid direction
        if (!isValidDirection(path[i])){
            return false;}

        i++;
        //Count Digits after character
        int digitsCount = 0;
        while (i < path.length() && isdigit(path[i])) {
            digitsCount++;
            i++;
        }

        // Check if there are more than 2 digits after the direction
        if (digitsCount > 2){
            return false;}
    }

    // If all conditions are satisfied, return true
    return true;
}

//Next function travel segment
int travelSegment(int r, int c, char dir, int maxSteps)
    {
    //Get the max columns and rows
    int MAX_GRID_ROWS = getRows();
    int MAX_GRID_COLS = getCols();

    //Value to show max steps allowed
    int MaxStepsAllowed = 0;

    // Check if (r,c) is a valid empty grid position or maxsteps less than or equal to 0
    if (r < 0 || c < 0 || r >= MAX_GRID_ROWS || c >= MAX_GRID_COLS || maxSteps <= 0) return -1;

    // Check if dir is a valid direction letter
    if (!isValidDirection(dir)) return -1;
    //Show how many steps you have traveled
    int maxStepsAllowed;
    switch (dir) {
        case 'N':
        case 'n':
            for(int i = 0;i<r;i++)
            //check for wall on each step North
                if(isWall(i,c) == true){
                maxStepsAllowed = i;
                }

                else{
                maxStepsAllowed = r;}
                 // Maximum steps north
            break;
        case 'E':
        case 'e':
            maxStepsAllowed = MAX_GRID_COLS - 1 - c; // Maximum steps east
            break;
        case 'S':
        case 's':
            for(int i = MAX_GRID_ROWS-1; i>0;i--)
                //check for wall on each step south
            maxStepsAllowed = MAX_GRID_ROWS - 1 - r; // Maximum steps south
            break;
        case 'W':
        case 'w':
            for(int i = 0;i<r;i++)
            //check for wall on each step East
                if(isWall(r,i) == true){
                maxStepsAllowed = i;
                }

                else{
                maxStepsAllowed = c;}
            maxStepsAllowed = c; // Maximum steps west
            break;
        default:
            return -1; // Invalid direction
    }

    // Return the minimum of maxSteps and maxStepsAllowed
    return min(maxSteps, maxStepsAllowed);
}

int travelPath(int sr, int sc, int er, int ec, char dir, string path, int& nsteps)
        {   
        // Check if starting and ending positions are valid
        if (sr < 0 || sr >= getRows() || sc < 0 || sc >= getCols() ||
        er < 0 || er >= getRows() || ec < 0 || ec >= getCols()) {
        return 3; // Invalid positions
        }
        //check if has proper syntax
        if(!hasProperSyntax(path))
            return 3;
        for(int i = 0; i < path.size();i++){
            //Switch statement for movement of robot 
            switch (dir) {
            case 'N':
            case 'n':
                
                break;
            case 'E':
            case 'e':
                
                break;
            case 'S':
            case 's':
                
                break;
            case 'W':
            case 'w':
                
                break;
        }

        }

    
        
    }
    int main()
    {
        setSize(3,4);
        setWall(1,4);
        setWall(2,2);
        setWall(3,2);
        assert(hasProperSyntax("n2E1"));
        assert(!hasProperSyntax("w1x"));
        assert(travelSegment(3, 1, 'N', 2) == 2);
        cerr << "All tests succeeded" << endl;
    }