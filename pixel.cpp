#include "pixel.h"

SDL_Color sand = {255,255,0};
SDL_Color rock = {128,128,128};

void Pixel::render(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, mat_color.r, mat_color.g, mat_color.b, mat_color.a);
    SDL_Rect r;
    r.h = pixelGridSize;
    r.w = pixelGridSize;
    r.x = position.x * pixelGridSize;
    r.y = position.y * pixelGridSize;
    SDL_RenderFillRect(renderer, &r);
}

void Pixel::update(SDL_Renderer* renderer)
{
    if(mat == "sand") {
        mat_color = sand;
        if(this->position.y < (600 - pixelGridSize)/pixelGridSize && this->position.x > 0 && this->position.x < (800 - pixelGridSize)/pixelGridSize && !stc) {
            SDL_Surface* pixelSurface = SDL_CreateRGBSurface(0, 800, 600, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	        SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_ARGB8888, pixelSurface->pixels, pixelSurface->pitch);

            //Uint8 *pPixel = (Uint8*)pixelSurface->pixels + pixel_Y * pixelSurface->pitch + pixel_X * 4;

            //Uint32 pixelData = *(Uint32*)pPixel;

            Uint8 *pPixelBottom = (Uint8*)pixelSurface->pixels + (int)(this->position.y * pixelGridSize + pixelGridSize) * pixelSurface->pitch + (int)(this->position.x * pixelGridSize) * 4;
            Uint32 pixelDataBottom = *(Uint32*)pPixelBottom;
            Uint8 *pPixelLeft = (Uint8*)pixelSurface->pixels + (int)(this->position.y * pixelGridSize + pixelGridSize) * pixelSurface->pitch + (int)(this->position.x * pixelGridSize + pixelGridSize) * 4;
            Uint32 pixelDataLeft = *(Uint32*)pPixelLeft;
            Uint8 *pPixelRight = (Uint8*)pixelSurface->pixels + (int)(this->position.y * pixelGridSize + pixelGridSize) * pixelSurface->pitch + (int)(this->position.x * pixelGridSize - pixelGridSize) * 4;
            Uint32 pixelDataRight = *(Uint32*)pPixelRight;

            SDL_Color bottom_color;
            SDL_Color left_color;
            SDL_Color right_color;

            //SDL_GetRGBA(pixelData, pixelSurface->format, &pixelColor.r, &pixelColor.g, &pixelColor.b, &pixelColor.a);

            SDL_GetRGBA(pixelDataBottom, pixelSurface->format, &bottom_color.r, &bottom_color.g, &bottom_color.b, &bottom_color.a);
            SDL_GetRGBA(pixelDataLeft, pixelSurface->format, &left_color.r, &left_color.g, &left_color.b, &left_color.a);
            SDL_GetRGBA(pixelDataRight, pixelSurface->format, &right_color.r, &right_color.g, &right_color.b, &right_color.a);

            SDL_FreeSurface(pixelSurface);

            //SDL_Color bottom_color = getPixelColor(renderer, &pixelSurface, this->position.x * pixelGridSize, this->position.y * pixelGridSize + pixelGridSize);
            //SDL_Color left_color = getPixelColor(renderer, &pixelSurface, this->position.x * pixelGridSize + pixelGridSize, this->position.y * pixelGridSize + pixelGridSize);
            //SDL_Color right_color = getPixelColor(renderer, &pixelSurface, this->position.x * pixelGridSize - pixelGridSize, this->position.y * pixelGridSize + pixelGridSize);

            if( 
                bottom_color.r == 0 &&
                bottom_color.g == 0 &&
                bottom_color.b == 0   ) 
            {
                this->position.y += 1;
            }
            else if(  
                right_color.r == 0 && 
                right_color.g == 0 &&
                right_color.b == 0    )
            {
                this->position.x -= 1;
                this->position.y += 1;
            }
            else if(  
                left_color.r == 0 && 
                left_color.g == 0 &&
                left_color.b == 0   )
            {
                this->position.x += 1;
                this->position.y += 1;
            }
            else {
                this->stc = true;
            }
        }
        else {
            this->stc = true;
        }
    }
    else {
        mat_color = rock;
    }
}