//
//  sample.cpp
//  ARDrone 2
//
//  Created by Fizuli Valizada on 13/10/2015.
//  Copyright © 2015 valizada. All rights reserved.
//


#include "ardrone/ardrone.h"

int main(int argc, char *argv[])
{
    // AR.Drone class
    ARDrone ardrone;
    // Initialize
    if (!ardrone.open()) {
        std::cout << "Failed to initialize." << std::endl;
        return -1;
    }
    // Battery
    std::cout << "Battery = " << ardrone.getBatteryPercentage() << "[%]" << std::endl;
    
//    ardrone.takeoff();
    double vx = 3;
    double vy = 4;
    double vz = 2;
    double vr = 5;
    
//    sleep(1000);
//    ardrone.move(vx, vy, vr);
    int previousCamera = 0;
    while (1) {
        // Battery
        std::cout << "Altitude = " << ardrone.getAltitude() << "[%]" << std::endl;
        
        // Key input
        int key = cv::waitKey(33);
        if (key == 0x1b) break;
        
        cv::Mat image = ardrone.getImage();
        cv::imshow("camera", image);
        
        if (key == 'c') {
            if (previousCamera == 0) {
                ardrone.setCamera(1);
            }
            else
                ardrone.setCamera(0);
        }
        
    }
//    ardrone.move3D(vx, vy, vz, vr);
//    ardrone.move(vx, vy, vr);
//    sleep(1000);
    
//    ardrone.landing();
    // See you
    ardrone.close();
    
    return 0;
}