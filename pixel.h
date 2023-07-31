#pragma once
#include "iostream"
#include "SDL.h"
#include "vec.h"
#include "pixel.h"
#include "vector"

class Pixel {
public:

    Pixel(int pixelGridSize = 1, std::string mat = "sand") { 
        position = Vector2D();
        this->pixelGridSize = pixelGridSize;
        this->mat = mat;
    }
    Pixel(float _x, float _y, int pixelGridSize = 1, std::string mat = "sand") 
    {
        position.x = _x;
        position.y = _y;
        this->pixelGridSize = pixelGridSize;
        this->mat = mat;
    }
    Pixel(Vector2D position, int pixelGridSize = 1, std::string mat = "sand")
    {
         this->position = position;
         this->pixelGridSize = pixelGridSize;
         this->mat = mat;
    }

    void render(SDL_Renderer* renderer);
    void update(SDL_Renderer* renderer);

    void setPixelGridSize( int value ) { pixelGridSize = value; }
    float getPixelGridSize() { return pixelGridSize; }

    Vector2D position;

    friend bool operator!=(Pixel& p1, const Pixel& p2) {
        return ( p1.position != p2.position );
    }

    friend bool operator==(Pixel& p1, const Pixel& p2) {
        return ( p1.position == p2.position );
    }

private:
    std::string mat = "sand";
    SDL_Color mat_color;
    bool stc = false;
    int pixelGridSize = 1;
};