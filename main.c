#include <stdio.h>
#include <raylib.h>

#define WIDTH 1080
#define HEIGHT 720
#define ballradius 30

float verticalvelocity = 1.2;
float decreasingforce = .9;
float gravity = 0.5;
int ballposy  = HEIGHT/4;
int ballYDirection = 1;
int buttonDown;


bool toggleGravity = true;
bool start = false;

void applyGravity();
void switchDirection();


int main(){

    //settig up the window
    InitWindow(WIDTH, HEIGHT, "mario's window");
    SetTargetFPS(60);

    //checking if the window show close
    while(!WindowShouldClose()){
        BeginDrawing();

        ClearBackground(BLACK);
        DrawCircle(WIDTH/2, ballposy, ballradius, WHITE);                  


        //input handling
        if(IsKeyPressed(KEY_SPACE)){
            printf("space pressed\n");
            buttonDown = KEY_SPACE;
        }

        //applying gravity to the velocity
        if(toggleGravity){
            applyGravity();
        }
        

        //applies the velocity to the position
        if(buttonDown == KEY_SPACE){
            printf("switching\n");
            start = !start;
        }

        //
        if(start == true){
            ballposy = ballposy + (verticalvelocity * ballYDirection);
            printf("the velocity: %.2f\n", verticalvelocity);
            printf("the ballposy: %d\n", ballposy);
            printf("direction: %d\n", ballYDirection);
            printf("vect * balldirection: %.2f\n", verticalvelocity * ballYDirection);
            printf("---------------\n");
        }

        //detecting if the ball hits the ground
        if(ballposy >= (HEIGHT - ballradius)){
            toggleGravity = true;
            buttonDown = 0;

            switchDirection();
            printf("---------------\n");
            printf("---------------\n");
            printf("---------------\n");
            printf("ball is going up\n");
            printf("---------------\n");
            printf("---------------\n");
            printf("---------------\n");

        }
        EndDrawing();
    }


    CloseWindow();  


    printf("Success\n");
    return 0;
}




void applyGravity(){
    if(ballYDirection != -1){
        //happens when its 1
        verticalvelocity = (verticalvelocity + gravity);
    }else{

        //happens when its -1
        if(verticalvelocity <= -0.00){
            printf("---------------\n");
            printf("---------------\n");
            printf("---------------\n");
            printf("ball going down\n");
            printf("---------------\n");
            printf("---------------\n");
            printf("---------------\n");
            verticalvelocity = 0.00;
            verticalvelocity = (verticalvelocity + gravity);
            ballYDirection = 1;
        }else{
            verticalvelocity = (verticalvelocity - decreasingforce);
        }
        
    }
    
};

void switchDirection(){
    if(ballYDirection == -1){
        ballYDirection = 1;
    }else{
        ballYDirection = -1;
    }
}



