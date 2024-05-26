#include "imgui.h"

#include "math.h"
#include <stdio.h>

struct Ball {
    double mass = 1.0;     // Creates the mass variable of the ball
    double radius = 20;  // Creates the radius variable of the ball
    int count = 0;
    int id;

    double dt;           // Creates the delta time variable 

    // Retrieves the ImGui config data from the GetIO function
    ImGuiIO &io = ImGui::GetIO();
    double windowWidth = 0;       // Defines window width 
    double windowHeight = 0;      // Defines window height

    double origin_x = windowWidth/2;     // Defines the center of the x axis
    double origin_y = windowHeight/2;    // Defines the center of the y axis

    // Current motion.
    struct acceleration { double x, y = -100; } acceleration;       // Creates the acceleration struct
    struct velocity     { double x, y; } velocity;           // Creates the velocity struct
    struct position     { double x, y; } position;           // Creates the position struct
    
    // Constructor for Ball
    Ball(int id_c) {
        id = id_c;
        printf("ball %d constructed\n", id);
    }
    
    void update(double dt) {      
        updateVelocity(dt);     // Updates velocity as a function of delta time
        updatePosition(dt);     // Updates position as a function of delta time


        draw();                 // Calls the draw function to draw the circle
    }

    void applyForce(double force_x, double force_y) {
        acceleration.x = force_x / mass;
        acceleration.y = force_y / mass;
    }

    // Integrate acceleration.
    void updateVelocity(double dt) {
        velocity.x += acceleration.x * dt;
        velocity.y += acceleration.y * dt;
    }

    // Integrate velocity.
    void updatePosition(double dt) {
        position.x += velocity.x * dt;
        position.y += velocity.y * dt;

    }

    void draw(){
        // Calls the draw_list object
        ImDrawList* draw_list = ImGui::GetWindowDrawList();
        char buf[1000] = ""; sprintf(buf, "position: %f, %f", position.x, position.y); ImGui::Text(buf[0] ? buf : "Null");
        // printf("drawn\n");
        draw_list->AddCircleFilled(ImVec2(origin_x + (-position.x), origin_y + (-position.y)), radius, IM_COL32(255, 255, 0, 255));
    }
};