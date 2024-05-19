// Programmer Name: Nicholas Sara
// Program Date: 5/15/2024
// Program Name: imgui-test
// Program description: Uses a basic immediate-mode GUI framework
// called DearImGui to display a few buttons and inputs, and plot
// a sine wave and sawtooth wave.

#include <stdio.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <unistd.h>

#define WINDOW_TITLE "verlet"
#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500

// User source files.
#include "Ball.cpp"

using namespace ImGui;

int main() {
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, nullptr, nullptr);
    glfwMakeContextCurrent(window);
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init((char*)"#version 130");
    glClearColor(0.3, 0.3, 0.3, 0);
    
    static Ball ball1;
    float initialTime = glfwGetTime();
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::SetNextWindowPos(ImGui::GetMainViewport()->WorkPos);
        ImGui::SetNextWindowSize(ImGui::GetMainViewport()->WorkSize);

        static char buf[32] = "";

        float finalTime = glfwGetTime();
        float deltaTime = finalTime - initialTime;
        initialTime = finalTime;

        ImGui::Begin("Verlet");

        ImVec2 cursorPos = ImGui::GetCursorScreenPos();

        ball1.refresh(deltaTime,WINDOW_WIDTH);
        ball1.tc += deltaTime;

        // Debugging text values
        sprintf(buf, "time: %.3f s", ball1.tc); ImGui::Text(buf[0] ? buf : "Null");
        sprintf(buf, "position y: %.3f m", ball1.position_y); ImGui::Text(buf[0] ? buf : "Null");
        sprintf(buf, "acceleration: %.3f m/s^2", ball1.accelleration); ImGui::Text(buf[0] ? buf : "Null");
        sprintf(buf, "velocity: %.3f m/s", ball1.velocity); ImGui::Text(buf[0] ? buf : "Null");

        ImGui::End();
        ImGui::Render();
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
