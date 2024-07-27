#include "LoadAnimationData.h"

namespace LoadAnimation
{
    GunnerIdle::GunnerIdle()
    {
        _key = L"A_GunnerIdle";
        _spriteKey = L"S_GunnerSheet1";
        _data = {
            {0, 0.25f},
            {1, 0.25f},
            {2, 0.25f},
            {3, 0.25f},
        };
    }

    GunnerWalk::GunnerWalk()
    {
        _key = L"A_GunnerWalk";
        _spriteKey = L"S_GunnerSheet1";
        _data = {
            {22, 0.1f},
            {23, 0.1f},
            {24, 0.1f},
            {25, 0.1f},
            {26, 0.1f},
            {27, 0.1f},
            {28, 0.1f},
            {29, 0.1f}
        };
    }

    GunnerRun::GunnerRun()
    {
        _key = L"A_GunnerRun";
        _spriteKey = L"S_GunnerSheet1";
        _data = {
            {30, 0.1f},
            {31, 0.1f},
            {32, 0.1f},
            {33, 0.1f},
            {34, 0.1f},
            {35, 0.1f},
            {36, 0.1f},
            {37, 0.1f}
        };
    }

    GunnerJump::GunnerJump()
    {
        _key = L"A_GunnerJump";
        _spriteKey = L"S_GunnerSheet1";
        _data = {
            {38, 0.15f},
            {39, 0.15f},
            {40, 0.15f},
            {41, 0.15f},
            {42, 0.15f},
        };
    }

    GunnerHit::GunnerHit()
    {
        _key = L"A_GunnerHit";
        _spriteKey = L"S_GunnerSheet1";
        _data = {
           // {45, 0.1f},
            {46, 0.1f},
            {47, 0.1f},
            {48, 0.1f},
            {49, 0.1f},
            {50, 0.1f},
            {51, 0.1f},
        };
    }
}