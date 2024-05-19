#include "imgui.h"
#include "Ball.cpp"

using namespace ImGui;

#define WINDOW_TITLE "verlet"
#define WINDOW_WIDTH  500
#define WINDOW_HEIGHT 500

inline void makeFullscreen() {
    SetNextWindowSize(ImVec2(50,100)); // Doesn't work for some reason.
    ImGui::SetNextWindowPos(ImGui::GetMainViewport()->WorkPos);
    ImGui::SetNextWindowSize(ImGui::GetMainViewport()->WorkSize);
}

static char buf[32] = "";
void loop() {
    makeFullscreen();
    ImGuiIO &io = GetIO();
    io.FontGlobalScale = 1.25;
    ImGui::Begin("DrawTest", (bool*)true, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);
    ImVec2 cursorPos = ImGui::GetCursorScreenPos();

    ImDrawList* drawList = ImGui::GetWindowDrawList();

    //drawList->AddCircleFilled(ImVec2(cursorPos.x + 50, cursorPos.y + 50), 30, IM_COL32(255, 0, 0, 255));

    float dt = ImGui::GetIO().DeltaTime;
    Ball ball1(dt);
    sprintf(buf, "dt: %f", dt);
    ImGui::Text(buf[0] ? buf : "Null");
    ball1.applyForce(0, -9.8f);
    ball1.update();
    
}
