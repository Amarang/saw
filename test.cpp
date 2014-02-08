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

};

bool operator==(Point p1, Point p2) {
    return ((p1.x == p2.x) && (p1.y == p2.y));
}

int move(Point *p, vector<Point> *history) {

    int randDir = rand()%4;

    switch(randDir) {
        case 0: (*p).y++; break; // N
        case 1: (*p).x++; break; // E
        case 2: (*p).y--; break; // S
        case 3: (*p).x--; break; // W
    }

    //cout << (*p).x << " " << (*p).y << endl;
    if(std::find((*history).begin(), (*history).end(), *p) != (*history).end()) {
        //cout << "failed" << endl;
        return -1; 
    }
    return 0;
}


int main() {

    srand(time(NULL));

    int nSteps = 26;
    int nWalks = 100;

    int badWalks = 0;
    int walks = 0;


    while(walks < nWalks) {
        Point p = { };
        vector<Point> history;
        bool isBadWalk = false;

        int status;

        for(int i = 0; i < nSteps; i++) {
            status = move(&p, &history);
            if(status == -1) {
                isBadWalk = true;
                //cout << badWalks << " " << walks << endl;
                break;
            }
            history.push_back(p);
        }


        if(isBadWalk) {
            badWalks++;
            continue;
        }
        walks++;
        if(walks%10==0) cout << walks << endl;
    }

    cout << "nSteps " << nSteps << endl;
    cout << "badWalks " << badWalks << " walks " << walks << endl;
    cout << "success rate: " << 1.0*walks/(badWalks+walks) << endl;
    return 0;
}
