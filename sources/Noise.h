#pragma once

#include "Common.h"

#define CUBIC_NOISE_PERIOD_INFINITELY INT32_MAX

typedef struct
{
    uint32_t seed;
    int32_t octave;
    int32_t periodx, periody;
} NoiseConfig;

NoiseConfig noiseConfig1D(
    const uint32_t seed,
    const int32_t octave,
    const int32_t period);

NoiseConfig noiseConfig2D(
    const uint32_t seed,
    const int32_t octave,
    const int32_t periodx,
    const int32_t periody);

float noiseSample1D(
    const NoiseConfig config,
    const float x);

float noiseSample2D(
    const NoiseConfig config,
    const float x,
    const float y);
