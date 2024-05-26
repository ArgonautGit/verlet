#include <vector>
#include "Ball.cpp"

#include "imgui.h"

struct Solver {
    int currentId = 0;
    std::vector<Ball*> ball_vector;

	void drawBounds() {
		ImDrawList* draw_list = ImGui::GetWindowDrawList();
		draw_list->AddRect(ImVec2(20, 20), ImVec2(400, 400), IM_COL32(200, 200, 200, 255), 0, 0, 5);
	}

    void addBall() {
        Ball* ball_p = new Ball(currentId++);
		ball_p->position.x = -200;
		ball_p->position.y = -200;
        ball_vector.emplace_back(ball_p);
    }

    void solve(float dt) {
        for (Ball* ball : ball_vector) {
            ball->update(dt);
        }

		solveAllBallCollisions();
		solveBoundaryCollisions();
    }

	void solveBoundaryCollisions() {
		for (Ball* ball : ball_vector) {
			float y_diff = ball->position.y - (-400) - ball->radius;
			if (y_diff < 0) {
				ball->position.y += (-y_diff);
				ball->velocity.x, ball->velocity.y = 0;
			}
		}
	}

	void solveAllBallCollisions() {
		for (Ball* ball_1 : ball_vector) {
			for (Ball* ball_2 : ball_vector) {
				if (ball_1 != ball_2)
				solveBallCollision(ball_1, ball_2);
			}
		}
	}

    void solveBallCollision(Ball* ball_1, Ball* ball_2) {
		float x_difference = ball_1->position.x - ball_2->position.x;
		float y_difference = ball_1->position.y - ball_2->position.y;
		float angle = tan(y_difference/x_difference);
		float min_distance = ball_1->radius + ball_2->radius;

		// Check for and solve x collisions.
		printf("x_diff: %f, y_diff: %f\n", x_difference, y_difference);
		if (abs(x_difference) < min_distance && abs(y_difference) < min_distance) {
			printf("collision detected: %d, %d, angle: %f\n", ball_1->id, ball_2->id, angle);
			// Move each ball away from the other.
			ball_1->position.x += ball_2->radius;
			ball_2->position.x -= ball_1->radius;

			ball_1->position.y += ball_2->radius;
			ball_2->position.y -= ball_1->radius;
		}
    }
};