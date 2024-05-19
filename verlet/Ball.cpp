#include "imgui.h"

struct Ball {
    float mass = 1.0;     // Creates the mass variable of the ball
    float radius = 50;  // Creates the radius variable of the ball

    float dt;           // Creates the delta time variable 

    // Retrieves the ImGui config data from the GetIO function
    ImGuiIO &io = ImGui::GetIO();
    float windowWidth;       // Defines window width 
    float windowHeight;      // Defines window height

    float origin_x = windowWidth/2;     // Defines the center of the x axis
    float origin_y = windowHeight/2;    // Defines the center of the y axis

    // Current motion. Replaced by new motion.
    struct acceleration { float x, y = 0; } acceleration;       // Creates the acceleration struct
    struct velocity     { float x, y = 0; } velocity;           // Creates the velocity struct
    struct position     { float x, y = 0; } position;           // Creates the position struct
    
    // Constructor for Ball
    Ball() {
                                                           
    }
    
    void update(float dt) {      
        updateVelocity(dt);     // Updates velocity as a function of delta time
        updatePosition(dt);     // Updates position as a function of delta time


        draw();                 // Calls the draw function to draw the circle
    }

    void applyForce(float force_x, float force_y) {
        acceleration.x = force_x / mass;
        acceleration.y = force_y / mass;
    }

    // Integrate velocity.
    void updateVelocity(float dt) {
        velocity.x += acceleration.x * dt;
        velocity.y += acceleration.y * dt;
    }

    // Integrate position.
    void updatePosition(float dt) {
        position.x += velocity.x * dt;
        position.y += velocity.y * dt;
    }

    void draw(){
        // Calls the draw_list object
        ImDrawList* draw_list = ImGui::GetWindowDrawList();

        // Error possibility 2
        draw_list->AddCircleFilled(ImVec2(origin_x + position.x, origin_y + position.y), radius, IM_COL32(255, 255, 0, 255));
    }
};