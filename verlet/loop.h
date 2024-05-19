#include "imgui.h"

using namespace ImGui;

#define WINDOW_TITLE "verlet"
#define WINDOW_WIDTH  500
#define WINDOW_HEIGHT 500

inline void makeFullscreen() {
    SetNextWindowSize(ImVec2(50,100)); // Doesn't work for some reason.
    ImGui::SetNextWindowPos(ImGui::GetMainViewport()->WorkPos);
    ImGui::SetNextWindowSize(ImGui::GetMainViewport()->WorkSize);
}

void loop() {
    makeFullscreen();
    ImGuiIO &io = GetIO();
    io.FontGlobalScale = 1.5;
    ImGui::Begin("DrawTest", (bool*)true, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize);
    ImVec2 cursorPos = ImGui::GetCursorScreenPos();
    ImGui::Dummy(ImVec2(200, 200));

    ImDrawList* drawList = ImGui::GetWindowDrawList();

    drawList->AddCircleFilled(ImVec2(cursorPos.x + 50, cursorPos.y + 50), 30, IM_COL32(255, 0, 0, 255));
}
