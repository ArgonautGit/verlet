#include "imgui.h"
#include "Solver.cpp"

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

void setup() {

}

static int count = 0;
// Main Loop
void loop(Solver* solver) {
    makeFullscreen();                                       // Calls fullscreen function

    ImGuiIO &io = GetIO();                                   // Calls the GetIO function to retrieve the config settings
    io.FontGlobalScale = 1.25;                              // Sets Global Font Scale

    // Starts ImGui Window
    ImGui::Begin("DrawTest", (bool*)true, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoBackground);
    
    ImVec2 cursorPos = ImGui::GetCursorScreenPos();         // Sets the vector variable cursorPos to the cursor screen position


    float dt = ImGui::GetIO().DeltaTime;                    // Sets delta time variable which is equivalent to 1/60 of a second


    if (count++ < 2) {
        solver->addBall();
    }

    solver->drawBounds();
    solver->solve(dt);

    // // Debugging text for values
    // sprintf(buf, "dt: %.3f", dt); ImGui::Text(buf[0] ? buf : "Null");
    // sprintf(buf, "x_pos: %.2f", ball1.position.x); ImGui::Text(buf[0] ? buf : "Null"); SameLine(120);
    // sprintf(buf, "y_pos: %.2f", ball1.position.y); ImGui::Text(buf[0] ? buf : "Null"); 
    // sprintf(buf, "x_vel: %.2f", ball1.velocity.x); ImGui::Text(buf[0] ? buf : "Null"); SameLine(120); 
    // sprintf(buf, "y_vel: %.2f", ball1.velocity.y); ImGui::Text(buf[0] ? buf : "Null"); 
    // sprintf(buf, "x_acc: %.2f", ball1.acceleration.x); ImGui::Text(buf[0] ? buf : "Null"); SameLine(120);
    // sprintf(buf, "y_acc: %.2f", ball1.acceleration.y); ImGui::Text(buf[0] ? buf : "Null"); 
    // sprintf(buf, "origin_x: %.2f", ball1.origin_x); ImGui::Text(buf[0] ? buf : "Null"); SameLine(150);
    // sprintf(buf, "origin_y: %.2f", ball1.origin_y); ImGui::Text(buf[0] ? buf : "Null"); 
}
