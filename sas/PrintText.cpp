//
//  PrintText.cpp
//  glutapp
//
//  Created by Tlaloc Barajas on 5/8/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "PrintText.hpp"
#include "libs.h"
#include <string>     // std::string, std::to_string

PrintText::PrintText(int x, int y, std::string String){
    //(x,y) is from the bottom left of the window
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, WindowWidth, 0, WindowHeight, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glPushAttrib(GL_DEPTH_TEST);
    glDisable(GL_DEPTH_TEST);
    glRasterPos2i(x,y);
    for (int i=0; i<String.size(); i++){
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, String[i]);
    }
    glPopAttrib();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

void PrintText::display(int score, std::string hiScore){
    int endScore = score/8;
    glColor3f(0, 0, 0);
    PrintText(560, 580, std::to_string(endScore));
    PrintText(410, 580, hiScore);
}

void PrintText::displayFinal(int score){
    int endScore = score/8;
    glColor3f(0, 0, 0);
    std::string final = "Final Score ";
    PrintText(190, 100, final);
    PrintText(300, 100, std::to_string(endScore));
}


PrintText::~PrintText(){
    //    SOIL_free_image_data(filename); not sure which to free
    
}
