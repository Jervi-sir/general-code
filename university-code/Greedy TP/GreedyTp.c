/*--------------
 * Topic: GPSR,
 * Overall: finding the shortest path from A to sink
    Same idea with Dijkstra, but it takes to neighbor terminal who has the minimum distance between its self and the sink teminal
 * NOTE:: the input must be manually, and sink is always the last one

 * Author: Gacem Bekhira
 * Github: https://github.com/Jervi-sir
----------------*/
#include <stdio.h>
#include <math.h>

/*-- structure of a Terminal  --*/
struct Node
{
   int nodeId;
   int x;
   int y;
};
/*----
 * distance: to calculate geometric distance
 */ 
double distance(int x1, int y1, int x2, int y2) {
    //sqrt( x~2 + y~2)
    double x = x1 - x2;
    double y = y1 - y2;
    double result = sqrt(pow(x,2) + pow(y, 2));
    return result;
}

int main() 
{
    //Initialise nodes
    struct Node n[8];
    n[0].nodeId = 0;    n[0].x = 1;    n[0].y = 1;
    n[1].nodeId = 1;    n[1].x = 4;    n[1].y = 1;
    n[2].nodeId = 2;    n[2].x = 1;    n[2].y = 2;
    n[3].nodeId = 3;    n[3].x = 4;    n[3].y = 2;
    n[4].nodeId = 4;    n[4].x = 3;    n[4].y = 5;
    n[5].nodeId = 5;    n[5].x = 8;    n[5].y = 5;
    n[6].nodeId = 6;    n[6].x = 12;   n[6].y = 3;
    n[7].nodeId = 7;    n[7].x = 12;   n[7].y = 5;
  
    //initialise neighbors
    int neighbors[8][8] = {
     //  0, 1, 2, 3, 4, 5, 6, 7
        {0, 1, 1, 0, 0, 0, 0, 0}, //0
        {1, 0, 0, 1, 0, 0, 0, 0}, //1
        {1, 0, 0, 1, 1, 0, 0, 0}, //2
        {0, 1, 1, 0, 1, 1, 0, 0}, //3
        {0, 0, 1, 1, 0, 1, 0, 0}, //4
        {0, 0, 0, 1, 1, 0, 1, 1}, //5
        {0, 0, 0, 0, 0, 1, 0, 1}, //6
        {0, 0, 0, 0, 0, 1, 1, 0}, //7
    };


    //print node to start with 

    //Select line of neighbors
    int line = 0;
    printf("terminal: %d \t distance avec sink: %f \n", line, distance(n[line].x, n[line].y, n[7].x, n[7].y) );

    //select line in matrix
    while(line <= 6) {
        //loop through the selected line
        double minDist = 1000;  //minimum distance of the itterations
        int tempIndex;          //to store the best terminal id
        for(int index = 0; index < 8; index++) {
            //if selected terminal is a neighbor
            if(neighbors[line][index] == 1) {
                //calculate distance between current terminal and sink 
                double dist = distance(n[index].x, n[index].y, n[7].x, n[7].y);
                //if distance is the smallest of the itteration
                if(dist < minDist) {
                    minDist = dist;
                    tempIndex = index;
                }
            }
        }
        line = tempIndex;
        printf("terminal: %d \t distance: %f \n", line, minDist );
    }

}

