#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <time.h>



using namespace std;

struct Point
{
    int x;
    int y;

    /*Point()
      {
      x = 0;
      y = 0;
      }*/
};

bool operator==(Point p1, Point p2) {
    return ((p1.x == p2.x) && (p1.y == p2.y));
}

void printLocation(Point p) {
    printf("(x,y) = (%03i,%03i)\n",p.x,p.y);
}


void dumpLocation(Point p) {
    printf("%03i,%03i\n",p.x,p.y);
}

int move(Point *p) {


    int dir = rand()%4; // 0 to 3 inclusive


    switch(dir) {
        case 0: (*p).y++; break; // N
        case 1: (*p).x++; break; // E
        case 2: (*p).y--; break; // S
        case 3: (*p).x--; break; // W
        default: printf("ERROR! dir was %i\n", dir); break;
    } 
    return 0;
}

int avoidMove(Point *p, vector<Point> *history) {

    vector<int> possibleMoves;
    int x = (*p).x;
    int y = (*p).y;
    Point pN = {x+0,  y+1};
    if(std::find((*history).begin(), (*history).end(), pN) == (*history).end()) {
        possibleMoves.push_back(0);
    }
    Point pE = {x+1,  y+0};
    if(std::find((*history).begin(), (*history).end(), pE) == (*history).end()) {
        possibleMoves.push_back(1);
    }
    Point pS = {x+0, y-1};
    if(std::find((*history).begin(), (*history).end(), pS) == (*history).end()) {
        possibleMoves.push_back(2);
    }
    Point pW = {x-1, y+0};
    if(std::find((*history).begin(), (*history).end(), pW) == (*history).end()) {
        possibleMoves.push_back(3);
    }
    if(possibleMoves.size() == 0) {
        return -1;
    }
    int randDir = rand()%(possibleMoves.size()); // 0 to possible_moves-1 inclusive
    int moveCode = possibleMoves[randDir];
    //printf("x: %i; y: %i; randDir: %i; moveCode: %i; possibilities: %i\n",(*p).x,(*p).y,randDir,moveCode,possibleMoves.size());
    switch(moveCode) {
        case 0: (*p).y++; break; // N
        case 1: (*p).x++; break; // E
        case 2: (*p).y--; break; // S
        case 3: (*p).x--; break; // W
        default: printf("ERROR! dir was %i\n", moveCode); break;
    }
    return 0;
}

void SAW(int maxSteps, int *nSteps, int *maxX, int *maxY, int *maxRSq, int *endX, int *endY) {
    Point p = { }; // in C++, this sets all members to 0
    vector<Point> pointsHistory;
    int status;
    //printLocation(p);
    for(int i = 0; i < maxSteps; i++) {
        //move(&p);
        pointsHistory.push_back(p);

        status = avoidMove(&p, &pointsHistory);
        //status = move(&p);
        if(status == -1) break; // can't move anywhere

        if(abs(p.x) > abs(*maxX)) *maxX = p.x;
        if(abs(p.y) > abs(*maxY)) *maxY = p.y;
        if(p.x*p.x + p.y*p.y > *maxRSq) *maxRSq = p.x*p.x + p.y*p.y;
        //dumpLocation(p);
    }

    *endX = p.x;
    *endY = p.y;

    *nSteps = pointsHistory.size();


}

int main() {

    srand(time(NULL));


    for(int i = 0; i < 50000; i++) {
        int nSteps=0, maxX=0, maxY=0, maxRSq=0, endX=0, endY=0;

        SAW(i, &nSteps, &maxX, &maxY, &maxRSq, &endX, &endY);

        printf("%10i %10i %10i %10i %10i\n",nSteps,maxX,maxY,maxRSq,endX,endY);
        //cout << nSteps << " " << maxX << " " << maxY << " " << maxRSq << " " << endX << " " << endY << endl;
        //cout << nSteps << " " << maxX << " " << maxY << " " << maxRSq << " " << endX << " " << endY << endl;
    }
    /*Point p = { }; // in C++, this sets all members to 0
    vector<Point> pointsHistory;
    int status;
    int maxX=0, maxY=0, maxRSq=0;
    //printLocation(p);
    for(int i = 0; i < 20000; i++) {
        //move(&p);
        pointsHistory.push_back(p);

        status = avoidMove(&p, &pointsHistory);
        if(status == -1) break; // can't move anywhere

        if(p.x > maxX) maxX = p.x;
        if(p.y > maxY) maxY = p.y;
        if(p.x*p.x + p.y*p.y > maxRSq) maxRSq = p.x*p.x + p.y*p.y;
        dumpLocation(p);
    }

    cout << pointsHistory.size() << " " << maxX << " " << maxY << " " << maxRSq << endl;

*/
    return 0;
}
