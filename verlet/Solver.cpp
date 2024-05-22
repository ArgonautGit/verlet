#include <vector>
#include "Ball.cpp"

#include "imgui.h"

struct Solver {
    std::vector<Ball*> ball_vector;

    Solver() {
    }

    void addBall() {
        Ball ball();
        ball_vector.emplace_back(&ball);
    }

    void solve() {
        char buf[32] = ""; sprintf(buf, "dt: %f", ImGui::GetIO().DeltaTime); ImGui::Text(buf);
        for (Ball* ball : ball_vector) {
            ball->update(ImGui::GetIO().DeltaTime);
        }
    }
};