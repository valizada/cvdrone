//
//  sample.cpp
//  ARDrone 2
//
//  Created by Fizuli Valizada on 17/10/2015.
//  Copyright © 2015 valizada. All rights reserved.
//

#include <opencv2/opencv.hpp>
const int ESC = 27;

int main(){
    
    // create matrix to store image
    cv::Mat image;
    // initialize capture
    cv::VideoCapture cap;
    cap.open(0);
    
    // creta window to show image
    cv::namedWindow("opencv", 1);
    
    while (1) {
        
        int pressedKey = cvWaitKey(33);
        if (pressedKey == ESC) return 0;
        // copy webcam stream image
        cap>>image;
        
        // print image to screen
        imshow("opencv", image);
        
        // delat 33 ms
        cv::waitKey(33);
    }
}