#include<bits/stdc++.h>
#include<graphics.h>
#include<time.h>
char score[15],x[15];


int main()
{
    int gd = DETECT,gm,key_dir,foodX,foodY,snakeX[200],snakeY[200];   // DETECT = 0; gm = graph mode ; gd =graph diver
    initgraph(&gd,&gm,(char*)" ");

    //initialization

    int  delayTime = 200;
    int food = 0;        // snake food
    int p_dir = 1;     //p_dir = previous direction;
    int length = 1;   // snake game;
    int game = 3;  // declaration a variable for the life

    foodX = 200, foodY = 200; // starting position of food
    // snake array
        init:
        snakeX[200] = {0};
        snakeY[200] = {0};

    // initialization for display snake ;

    snakeX[0] = 200,snakeY[0] = 200; // starting position of the snake
    key_dir = rand()%2;


    // drawing game panel

    while(game)
    {
        setfillstyle(SOLID_FILL,BLACK); // initialization back ground color
        bar(0,0,630,470);  //  initializing background size or wide (lower width 630 and right length 470)

        sprintf(score, "SCORE: %d", (food-1)*10);   // convert int value into string
        sprintf(x, "LIFE: %d", game);   // convert int value into string
        outtextxy(0, 0, score); // display live score in top left
        outtextxy(580, 0, x); // display life remaining in top right

        setfillstyle(SOLID_FILL,GREEN);  // initializing boarder color

        bar(80,0,575,10); // upper boarder width,length

        bar(0,20,10,470); // right boarder width,length

        bar(0,470,630,460); // lower boarder width,length

        bar(620,20,630,470); // lower boarder width,length

        bar(290,100,300,350); // creating obstacle

        setfillstyle(SOLID_FILL,	YELLOW); // initialization food color

        if(snakeX[0] == foodX && snakeY[0] == foodY) // checking snake and food is in the same position or not
        {
            length = length + 1;
            food = food +1 ;
            delayTime = delayTime - 2;  // food consumed by snake then the delay time reduced and snake spread increase

            bar(foodX,foodY,foodX + 10 , foodY + 10 ); // food poosition

            do{
                foodX = (10 + rand() % 600);
                foodY = (10 + rand() % 450);
            }while(getpixel(foodX,foodY) != 0 && foodX > 10 && foodY>10); //condition for food visualization

            // condition for not overlaping food or snake

            foodX = foodX / 10;
            foodX = foodX * 10;
            foodY = foodY / 10;
            foodY = foodY * 10;

            // condition for food coordinate can't be 10, if so then the food will situated beside the boarder line every time

            if(foodX == 10){
                foodX = rand() % 10 + 5;
                foodX = food * 10;
            }
            else if(foodY == 10)
            {
                foodY = rand() % 10 + 5;
                foodY = foodY * 10;
            }

        }

        bar(foodX,foodY,foodX + 10, foodY + 10); // final  food position for display

        setfillstyle(SOLID_FILL,   RED); // initialize snake color

        // condition for key direction

        if((GetAsyncKeyState(VK_RIGHT)||GetAsyncKeyState('D'))&&p_dir!=2){
            key_dir = 1;
        }
        else if((GetAsyncKeyState(VK_LEFT)||GetAsyncKeyState('A'))&&p_dir!=1){
            key_dir = 2;
        }
        else if((GetAsyncKeyState(VK_UP)||GetAsyncKeyState('W'))&&p_dir!=4){
            key_dir = 3;
        }
        else if((GetAsyncKeyState(VK_DOWN)||GetAsyncKeyState('S'))&&p_dir!=3){
            key_dir = 4;
        }
        else {
                key_dir = 0;
        }

        // condition for moving snake according to key direction

        switch(key_dir)
        {
        case 0:
            if(p_dir == 1){
                snakeX[0] = snakeX[0] + 10;
            }
            else if(p_dir == 2){
                snakeX[0] = snakeX[0] - 10;
            }
            else if(p_dir == 3){
                snakeY[0] = snakeY[0] - 10;
            }
            else if(p_dir == 4){
                snakeY[0] = snakeY[0] + 10;
            }
            else{
                key_dir = 0;
            }
            break;

        case 1:
            snakeX[0] = snakeX[0] + 10;
            p_dir = 1;
            break;
        case 2:
            snakeX[0] = snakeX[0] - 10;
            p_dir = 2;
            break;
        case 3:
            snakeY[0] = snakeY[0] - 10;
            p_dir = 3;
            break;
        case 4:
            snakeY[0] = snakeY[0] + 10;
            p_dir = 4;
            break;

        }

       // displaying snake

       for(int i =0; i < length; i++)
       {
           bar(snakeX[i], snakeY[i], snakeX[i] + 10, snakeY[i] + 10);
       }

       // body of snake

       for(int i = 199; i > 0; i--)
       {
           snakeX[i] = snakeX[i - 1];
           snakeY[i] = snakeY[i - 1];
       }

    // checking bumping into body

    for(int i = 2; i < length; i++)
    {
        if(snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i])
        {
            std::cout<<"Snake bumped into itself !!!\n\n";
            game--;
            goto init;
            break;
        }
    }

    delay(delayTime);

    // checking bumping in to boundary or obstacle;

    if(snakeX[0] >= 615 || snakeX[0] <=5 || (snakeX[0] == 290 && snakeY[0]>= 100 && snakeY[0]<= 350) || snakeY[0] <= 5|| snakeY[0] >= 455){
        game--;
        goto init;
    }

    }

    // game result

    std::cout<<"Your score is : " <<(food-1)*10<<"\n\n";
    std::cout<<"Game Over !!!\n\nModified by Nixon Deb Antu\nReg.No.:2020831023\n\n";
    getch();
    return 0;
}
