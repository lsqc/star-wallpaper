#include "./raylib.h"

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

void generate(Vector2 *vec, int count, long width, long height)
{
    for (int i = 0; i < count; i++)
    {
        vec[i].x = rand() % width;
        vec[i].y = rand() % height;

    }
}

int main(int argc, char* argv[])
{
    int COUNT = 400;

    int HEIGHT = 1440;
    int WIDTH = 3440;

    char* e;

    if (argc >= 3)
    {
        long h = strtol(argv[1], &e, 10);
        if (*e != '\0')
        {
            printf("invalid height: %s\n", argv[1]);
            return 1;
        }

        long w = strtol(argv[2], &e, 10);
        if (*e != '\0')
        {
            printf("invalid width: %s\n", argv[1]);
            return 1;
        }

        if (argc >= 4)
        {

            long c = strtol(argv[3], &e, 10);
            if (*e != '\0')
            {
                printf("invalid count: %s\n", argv[3]);
                return 1;
            }
            COUNT = c;
        }

        HEIGHT = h;
        WIDTH = w;
    }

    InitWindow(WIDTH, HEIGHT, "window");

    Vector2 stars[COUNT]; 

    generate(stars, COUNT, WIDTH, HEIGHT);
//
    //for (int i = 0; i < COUNT; i++)
    //{
        //Vector2 pos;
        //pos.x = rand() % WIDTH;
        //pos.y = rand() % HEIGHT;
//
        //stars[i] = pos;
    //}
//
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        for (int i = 0; i < COUNT; i++)
        {
            DrawPixel((int) stars[i].x, (int)stars[i].y, PURPLE);
        }

        EndDrawing();

        if (IsKeyPressed(KEY_G)) generate(stars, COUNT, WIDTH, HEIGHT);

        if (IsKeyPressed(KEY_S))
        {
            time_t now = time(NULL);
            struct tm *t = localtime(&now);

            TakeScreenshot("img.png");
        }
    }

    CloseWindow();

    return 0;
}

