#include<stdio.h>
#include<stdlib.h>
#include<SDL2/SDL.h>   // This Library is for the functions for the graphics such as the window. 


int main()
{
	// Global variables and constants.
	const int width = 900;
	const int height = 600;


	printf("Hello World!\n");

	// CreateWindow creates as object(The window) and stores in memory. 
	// The pwindow variable of type sdl holds the address value.
	// The *pwindow accesses the object i.e. the window and its contents from that memory.
	// More like CreateWindow builds house at an address and pwindow is a paper on which the address is written. And when I do *pwindow Im accessing the house or using it with the pwindow address.
	// Params : ( Title , Position in X-Axis , Position in Y-Axis , Width , Height , Flags(0 or anyother based on docs) )
	SDL_Window *pwindow =  SDL_CreateWindow("Image Viewer",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,900,600,0);
	
	// Now we need to access the window's(Objects) drawing surface the canvas( The blank space) using the windows object address.
	// The GetWindow function returns address into psurface. [More over its the syntax.]
	SDL_Surface *psurface =  SDL_GetWindowSurface(pwindow);

	// Unsigned Integer (8 bit) -- as colours go from 0-255 and 2**8 is 256.
	Uint8 r,g,b;        // Ranges from 0-255 in decimal format , We shall use that instead of hexa-decimal.
	r = 255;
	g = b = 0;
	
	//Convert RBG values into the colour format used by SDL surface.
	Uint32 color = SDL_MapRGB(psurface->format,r,g,b);       // psurface->format  is short cut for (*psurface).format
								 // Here we have used the format of the surface but there are many predefine types like bitsperpixel,bytesperpixel etc.
	
	// Now let us try to fill the surface with each pixel represented by a rectangle.
	// Lets declare how a pixel looks like or is structured outside the loop to avoid decalaration in every loop.
	// Intitiated with 0 abnd then is updated inside the loop.
	SDL_Rect pixel = (SDL_Rect){0,0,1,1};	// Simple for :  SDL_Rect Pixel;
						// 		 Pixel.x = 0 , pixel.y = 0 , pixel.w = 1 , pixel.h = 1;
	
	for(int x=0 ; x<width ; x++)
	{
		for(int y=0; y<height ; y++)
		{
			pixel.x=x,pixel.y = y;                  // Update the position of each pixel as sixe is constant.
			SDL_FillRect(psurface,&pixel,color);	// Fills the pixel in the surface with the colour.
		}
	}

	// Takes the Surface(Canvas) and displays it on the window.
	SDL_UpdateWindowSurface(pwindow);

	

	SDL_Delay(3000);
}  
