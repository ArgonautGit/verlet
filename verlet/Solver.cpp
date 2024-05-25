#include <vector>
#include "Ball.cpp"

#include "imgui.h"

struct Solver {
    int currentId = 0;

    std::vector<Ball*> ball_vector;

    Solver() {
    }

    void addBall() {
        Ball* ball_p = new Ball(currentId++);
        ball_vector.emplace_back(ball_p);
    }

    void solve() {
        char buf[1000] = ""; sprintf(buf, "dt: %f", ImGui::GetIO().DeltaTime); ImGui::Text(buf);
        for (Ball* ball : ball_vector) {
            ball->update(ImGui::GetIO().DeltaTime);
        }
    }
};