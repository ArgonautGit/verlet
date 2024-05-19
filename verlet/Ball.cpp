#include "imgui.h"
#include <GLFW/glfw3.h>

struct Ball {
    float mass = 1;
    float radius = 50;

    float dt;

    // Draws the ball at position
    ImGuiIO& io = ImGui::GetIO();
    // Defines window width and height
    float windowWidth = io.DisplaySize.x;
    float windowHeight = io.DisplaySize.y;
        
    // Defines the center point of the screen
    float origin_x = windowWidth/2;
    float origin_y = windowHeight/2;
    
    // Current motion. Replaced by new motion.
    struct acceleration { float x, y = 0; } acceleration;
    struct velocity     { float x, y = 0; } velocity;
    struct position     { float x, y = 0; } position;
    
    // Constructor
    Ball(float new_dt) {
        dt = new_dt;                                                        // Error Possibility 1
    }
    
    void update() {
        updateVelocity();
        updatePosition();

        draw();
        
        // Reset acceleration.
        acceleration.x, acceleration.y = 0;
    }

    void applyForce(int force_x, int force_y) {
        acceleration.x += force_x / mass;
        acceleration.y += force_y / mass;
    }

    void updateVelocity() {
        // Integrate velocity.
        velocity.x += acceleration.x * dt;
        velocity.y += acceleration.y * dt;
    }

    void updatePosition() {
        // Integrate position.
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