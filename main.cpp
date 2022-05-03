#include "main.h" 
#include<iostream>

/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, math, and strings
// #include <SDL2/SDL.h>


    const int windowHeight = 1000;
    const int windowWidth = 1000;


int main() {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> randHeight(0,windowHeight);
	std::uniform_int_distribution<std::mt19937::result_type> randWidth(0,windowWidth); 

	std::vector<star<double>> stars;

	for (int i = 0; i < 100; i++){
		Vec3<double> position(randWidth(rng),randHeight(rng),0);
		Vec3<double> Velocity(0,0,0);
		star<double> temp(1,position,Velocity);
		stars.push_back(temp);
	}

    stars[(int) stars.size()/2].mass = 100;
    stars[(int) stars.size()/2].setRGB(0xFF,1,1);


    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        return 1;
        std::cout << "Initialization failed" << std::endl;
    }

    SDL_Window *window = SDL_CreateWindow("Practice making sdl Window",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth,
            windowHeight, SDL_WINDOW_SHOWN);

    if (window == NULL) {
        SDL_Quit();
        return 2;
    }

    // We create a renderer with hardware acceleration, we also present according with the vertical sync refresh.
    SDL_Renderer *s = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC) ;

    const int pointLocationx = windowWidth/2;
    const int pointLocationy = windowHeight/2;

    bool quit = false;
    SDL_Event event;

    while (!quit) {
        //drawing particles
        //setting up objects
        //repeated over and over again

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }

            switch (event.type) {
                case SDLK_d:
                for (auto&& i:stars){
                    i.pos.setx(i.pos.getx() + 10);
                }
                break;
                case SDLK_s:
                for (auto&& i:stars){
                    i.pos.sety(i.pos.gety() - 5);
                }
                break;

            }
        }





        // We clear what we draw before
        SDL_RenderClear(s);

	for (int n = 0; n < stars.size(); n++){
        star<double> *i = &stars[n];
        
		SDL_SetRenderDrawColor(s, i->R, i->G, i->B, 0xFF);
		SDL_RenderDrawPoint(s,i->pos.getx(),i->pos.gety());
		SDL_SetRenderDrawColor(s, 0x00, 0x00, 0x00, 0xFF);	
		// std::cout << i.pos.getx() << "\n";
        i->update(stars,n);
	}
        // Set our color for the draw functions
        SDL_SetRenderDrawColor(s, 0xFF, 0xFF, 0xFF, 0xFF);
        // Now we can draw our point
        SDL_RenderDrawPoint(s, pointLocationx, pointLocationy);
        // Set the color to what was before
        SDL_SetRenderDrawColor(s, 0x00, 0x00, 0x00, 0xFF);
        // .. you could do some other drawing here
        // And now we present everything we draw after the clear

        SDL_RenderPresent(s);
        SDL_Delay(120);
    }

    SDL_DestroyWindow(window);
    // We have to destroy the renderer, same as with the window.
    SDL_DestroyRenderer(s);
    SDL_Quit();

}