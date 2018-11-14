#include <iostream>
#include "Game/game.h"

/*int x_vault;

SDL_Rect ball;
struct { int x; int y; } speed;

SDL_Window* pWindow = nullptr;
SDL_Surface* win_surf = nullptr;
SDL_Surface* plancheSprites = nullptr;

SDL_Rect srcBg = { 0,128, 96,128 }; // x,y, w,h (0,0) en haut a gauche
SDL_Rect srcBall = { 0,64,24,24 };
SDL_Rect scrVaiss = { 128,0,128,32 };

void init()
{
    pWindow = SDL_CreateWindow("Arknoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_SHOWN);
    win_surf = SDL_GetWindowSurface(pWindow);

    plancheSprites = SDL_LoadBMP("./sprites.bmp");
    SDL_SetColorKey(plancheSprites, true, 0);  // 0: 00/00/00 noir -> transparent

    ball.x = win_surf->w / 2;;
    ball.y = win_surf->h / 2;
    speed.x =  5;
    speed.y = 7;
}


// fonction qui met à jour la surface de la fenetre "win_surf"
void draw()
{
    // remplit le fond
    SDL_Rect dest = { 0,0,0,0 };
    for (int j = 0; j < win_surf->h; j+=128)
        for (int i = 0; i < win_surf->w; i += 96)
        {
            dest.x = i;
            dest.y = j;
            SDL_BlitSurface(plancheSprites, &srcBg, win_surf, &dest);
        }


    // affiche balle
    SDL_BlitSurface(plancheSprites, &srcBall, win_surf, &ball);

    // dedplacement
    ball.x += speed.x;
    ball.y += speed.y;

    // collision bord
    if ((ball.x < 1) || (ball.x > (win_surf->w - 25)))
        speed.x *= -1;
    if ((ball.y < 1) || (ball.y > (win_surf->h - 25)))
        speed.y *= -1;

    // touche bas -> rouge
    if (ball.y >(win_surf->h - 25))
        srcBall.y = 64;

    // collision vaisseau
    if ((ball.x > x_vault) && (ball.x < x_vault+128) && (ball.y > win_surf->h - 32 -20))
    {
        speed.y *= -1;
        srcBall.y = 96; // -> vert
    }

    // vaisseau
    dest.x = x_vault;
    dest.y = win_surf->h - 32;
    SDL_BlitSurface(plancheSprites, &scrVaiss, win_surf, &dest);
}*/


int main(int argc, char** argv)
{
    Game game;
    game.run();
    return 0;
}
