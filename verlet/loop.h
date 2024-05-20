#include "imgui.h"
#include "Ball.cpp"

using namespace ImGui;

// Window Settings
#define WINDOW_TITLE "verlet"
#define WINDOW_WIDTH  500
#define WINDOW_HEIGHT 500

int ballCount;

// Function to set the window as ImGui window to fullscreen
inline void makeFullscreen() {
    ImGui::SetNextWindowPos(ImGui::GetMainViewport()->WorkPos);
    ImGui::SetNextWindowSize(ImGui::GetMainViewport()->WorkSize);
}

// Creates Ball object
static char buf[32] = "";




// Main Loop
void loop(Ball& ball1) {
    makeFullscreen();                                       // Calls fullscreen function

    ImGuiIO &io = GetIO();                                   // Calls the GetIO function to retrieve the config settings
    // sprintf(buf, "dt: %.3f", ); ImGui::Text(buf[0] ? buf : "Null");
    ball1.windowWidth = WINDOW_WIDTH;
    ball1.windowHeight = WINDOW_HEIGHT;

    io.FontGlobalScale = 1.25;                              // Sets Global Font Scale

    // Starts ImGui Window
    ImGui::Begin("DrawTest", (bool*)true, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBackground);
    
    ImVec2 cursorPos = ImGui::GetCursorScreenPos();         // Sets the vector variable cursorPos to the cursor screen position


    float dt = ImGui::GetIO().DeltaTime;                    // Sets delta time variable which is equivalent to 1/60 of a second

    // ball1.applyForce(0, -9.8);                              // Applies a force of -9.8y to the ball via the applyForce function      
    ball1.update(dt);                                          // Updates the ball via running the update method

    // Debugging text for values
    sprintf(buf, "dt: %.3f", dt); ImGui::Text(buf[0] ? buf : "Null");
    sprintf(buf, "x_pos: %.2f", ball1.position.x); ImGui::Text(buf[0] ? buf : "Null"); SameLine(120);
    sprintf(buf, "y_pos: %.2f", ball1.position.y); ImGui::Text(buf[0] ? buf : "Null"); 
    sprintf(buf, "x_vel: %.2f", ball1.velocity.x); ImGui::Text(buf[0] ? buf : "Null"); SameLine(120); 
    sprintf(buf, "y_vel: %.2f", ball1.velocity.y); ImGui::Text(buf[0] ? buf : "Null"); 
    sprintf(buf, "x_acc: %.2f", ball1.acceleration.x); ImGui::Text(buf[0] ? buf : "Null"); SameLine(120);
    sprintf(buf, "y_acc: %.2f", ball1.acceleration.y); ImGui::Text(buf[0] ? buf : "Null"); 
    sprintf(buf, "origin_x: %.2f", ball1.origin_x); ImGui::Text(buf[0] ? buf : "Null"); SameLine(150);
    sprintf(buf, "origin_y: %.2f", ball1.origin_y); ImGui::Text(buf[0] ? buf : "Null"); 
}
