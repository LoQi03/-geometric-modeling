#ifndef PERLIN_H
#define PERLIN_H

#include <cmath>

class PerlinNoise {
public:
    static double noise(double x, double y);

private:
    static double fade(double t);
    static double lerp(double a, double b, double t);
    static double grad(int hash, double x, double y);
    static const int permutation[512];
};

// Permutációs tábla (kétszer megismételve a pufferelkerülés miatt)
const int PerlinNoise::permutation[512] = {
    151,160,137,91,90,15,131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,142,
    151,160,137,91,90,15,131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,142
};

// Fade függvény a simább interpolációhoz
inline double PerlinNoise::fade(double t) {
    return t * t * t * (t * (t * 6 - 15) + 10);
}

// Lineáris interpoláció
inline double PerlinNoise::lerp(double a, double b, double t) {
    return a + t * (b - a);
}

// Gradient számítása (hash alapján)
inline double PerlinNoise::grad(int hash, double x, double y) {
    int h = hash & 3;
    double u = h < 2 ? x : y;
    double v = h < 2 ? y : x;
    return ((h & 1) ? -u : u) + ((h & 2) ? -2.0 * v : 2.0 * v);
}

// Perlin zaj generálása
inline double PerlinNoise::noise(double x, double y) {
    int X = (int)floor(x) & 255;
    int Y = (int)floor(y) & 255;
    x -= floor(x);
    y -= floor(y);

    double u = fade(x);
    double v = fade(y);

    int A = permutation[X] + Y;
    int B = permutation[X + 1] + Y;

    return lerp(lerp(grad(permutation[A], x, y), grad(permutation[B], x - 1, y), u),
        lerp(grad(permutation[A + 1], x, y - 1), grad(permutation[B + 1], x - 1, y - 1), u),
        v);
}

#endif // PERLIN_H
