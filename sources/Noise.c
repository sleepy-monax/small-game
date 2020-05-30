#include <math.h>

#include "Noise.h"

#define CUBIC_NOISE_RAND_A 134775813
#define CUBIC_NOISE_RAND_B 1103515245

static float noiseRandom(
    uint32_t seed,
    int32_t x,
    int32_t y)
{
    return (float)((((x ^ y) * CUBIC_NOISE_RAND_A) ^ (seed + x)) *
                   ((((CUBIC_NOISE_RAND_B * x) << 16) ^ (CUBIC_NOISE_RAND_B * y)) - CUBIC_NOISE_RAND_A)) /
           UINT32_MAX;
}

static int32_t noiseTile(
    const int32_t coordinate,
    const int32_t period)
{
    return coordinate % period;
}

static float noiseInterpolate(
    const float a,
    const float b,
    const float c,
    const float d,
    const float x)
{
    const float p = (d - c) - (a - b);

    return x * (x * (x * p + ((a - b) - p)) + (c - a)) + b;
}

NoiseConfig noiseConfig1D(
    const uint32_t seed,
    const int32_t octave,
    const int32_t period)
{
    NoiseConfig config;

    config.seed = seed;
    config.octave = octave;
    config.periodx = period / octave;

    return config;
}

NoiseConfig noiseConfig2D(
    const uint32_t seed,
    const int32_t octave,
    const int32_t periodx,
    const int32_t periody)
{
    NoiseConfig config;

    config.seed = seed;
    config.octave = octave;
    config.periodx = periodx / octave;
    config.periody = periody / octave;

    return config;
}

float noiseSample1D(
    const NoiseConfig config,
    const float x)
{
    const int32_t xi = (int32_t)floorf(x / config.octave);
    const float lerp = x / config.octave - xi;

    return noiseInterpolate(
               noiseRandom(config.seed, noiseTile(xi - 1, config.periodx), 0),
               noiseRandom(config.seed, noiseTile(xi, config.periodx), 0),
               noiseRandom(config.seed, noiseTile(xi + 1, config.periodx), 0),
               noiseRandom(config.seed, noiseTile(xi + 2, config.periodx), 0),
               lerp) *
               0.5f +
           0.25f;
}

float noiseSample2D(
    const NoiseConfig config,
    const float x,
    const float y)
{
    uint32_t i;
    const int32_t xi = (int32_t)floorf(x / config.octave);
    const float lerpx = x / config.octave - xi;
    const int32_t yi = (int32_t)floorf(y / config.octave);
    const float lerpy = y / config.octave - yi;

    float xSamples[4];

    for (i = 0; i < 4; ++i)
        xSamples[i] = noiseInterpolate(
            noiseRandom(config.seed,
                        noiseTile(xi - 1, config.periodx),
                        noiseTile(yi - 1 + i, config.periody)),
            noiseRandom(config.seed,
                        noiseTile(xi, config.periodx),
                        noiseTile(yi - 1 + i, config.periody)),
            noiseRandom(config.seed,
                        noiseTile(xi + 1, config.periodx),
                        noiseTile(yi - 1 + i, config.periody)),
            noiseRandom(config.seed,
                        noiseTile(xi + 2, config.periodx),
                        noiseTile(yi - 1 + i, config.periody)),
            lerpx);

    return noiseInterpolate(
               xSamples[0], xSamples[1], xSamples[2], xSamples[3], lerpy) *
               0.5f +
           0.25f;
}