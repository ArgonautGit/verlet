#include "imgui.h"

struct Ball {
    // Ball Variables
    float mass = 1.0f;
    float radius = 50.0f;
    float force = -9.8f;
    float tc = 0.0f;

    // Motion Variables
    float accelleration = force / mass;
    float velocity = 0.0f;
    float position_y = 0.0f;

    void refresh(float deltaTime, float windowWidth){
        velocity += accelleration * deltaTime;
        position_y += velocity * deltaTime;

        ImDrawList* draw_list = ImGui::GetWindowDrawList();
        draw_list->AddCircleFilled(ImVec2(windowWidth/2.0f, position_y - 2 * position_y), radius, IM_COL32(255,255,0,255));
    }
};