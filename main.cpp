#include "raylib.h"

int main()
{
    int windowWidth{800};
    int windowHeight{600};
    InitWindow(windowWidth, windowHeight, "Axe Game");

    int circleX{400};
    int circleY{400};
    int circleRadius{25};

    int leftEdgeCircleX{circleX - circleRadius};
    int rightEdgeCircleX{circleX + circleRadius};
    int topEdgeCircleY{circleY - circleRadius};
    int bottomEdgeCircleY{circleY + circleRadius};

    int axeX{500};
    int axeY{0};
    int axeLength{50};
    int axeDirection{5};

    int leftEdgeAxeX{axeX};
    int rightEdgeAxeX{axeX + axeLength};
    int topEdgeAxeY{axeY};
    int bottomEdgeAxeY{axeY + axeLength};

    bool collisionWithAxe = 
                        (bottomEdgeAxeY >= topEdgeCircleY) && 
                        (topEdgeAxeY <= bottomEdgeCircleY) &&
                        (rightEdgeAxeX >= leftEdgeCircleX) && 
                        (leftEdgeAxeX <= rightEdgeCircleX);

    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(BLACK);

        if (collisionWithAxe)
        {
            DrawText("Game Over!", 350, 300, 20, RED);
        }
        else
        {
            // Update edges
            leftEdgeCircleX = circleX - circleRadius;
            rightEdgeCircleX = circleX + circleRadius;
            topEdgeCircleY = circleY - circleRadius;
            bottomEdgeCircleY = circleY + circleRadius;
            leftEdgeAxeX = axeX;
            rightEdgeAxeX = axeX + axeLength;
            topEdgeAxeY = axeY;
            bottomEdgeAxeY = axeY + axeLength;

            // Update collision with axe
            collisionWithAxe = 
                        (bottomEdgeAxeY >= topEdgeCircleY) && 
                        (topEdgeAxeY <= bottomEdgeCircleY) &&
                        (rightEdgeAxeX >= leftEdgeCircleX) && 
                        (leftEdgeAxeX <= rightEdgeCircleX);

            DrawCircle(circleX, circleY, circleRadius, GREEN);
            DrawRectangle(axeX, axeY, axeLength, axeLength, WHITE);

            axeY += axeDirection;

            if(axeY > windowHeight || axeY < 0)
            {
                axeDirection = -axeDirection;
            }

            if(IsKeyDown(KEY_D) && circleX < windowWidth - circleRadius)
            {
                circleX += 5;
            }

            if(IsKeyDown(KEY_A) && circleX > 0 + circleRadius)
            {
                circleX -= 5;
            }

            // if(IsKeyDown(KEY_W) && circleY > 0 + circleRadius)
            // {
            //     circleY -= 2;
            // }

            // if(IsKeyDown(KEY_S) && circleY < windowHeight - circleRadius)
            // {
            //     circleY += 2;
            // }
        }

        EndDrawing();
    }
}