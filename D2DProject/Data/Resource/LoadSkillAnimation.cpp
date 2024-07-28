#include "LoadAnimationData.h"
#include "DemoApp.h"

namespace LoadAnimation
{
	HardAttack::HardAttack()
	{
        _key = L"A_HardAttack";
        _spriteKey = L"S_HardAttack";
        _data = {
            {0, 0.1f},
            {1, 0.1f},
            {2, 0.1f},
            {3, 0.1f},
            {4, 0.1f},
            {5, 0.1f}
        };
	}
    UpperSlash::UpperSlash()
    {
        _key = L"A_UpperSlash";
        _spriteKey = L"S_UpperSlash";
        _data = {
            {0, 0.1f},
            {1, 0.1f},
            {2, 0.1f},
            {3, 0.1f}
        };
    }
    VaneSlash::VaneSlash()
    {
        _key = L"A_VaneSlash";
        _spriteKey = L"S_VaneSlashSheet2";
        _data = {
            {0, 0.1f, Vector2(70,40)},
            {1, 0.1f, Vector2(70,40)},
            {2, 0.1f, Vector2(70,40)},
            {3, 0.1f, Vector2(70,40)},
            {4, 0.1f},
            {5, 0.1f},
            {6, 0.1f},
            {7, 0.1f},
            {8, 0.1f}
        };
    }
    VaneSlashWave::VaneSlashWave()
    {
        _key = L"A_VaneSlashWave";
        _spriteKey = L"S_VaneSlashSheet1";
        _data = {
            {0, 0.1f},
            {1, 0.1f},
            {2, 0.1f},
            {3, 0.1f},
            {4, 0.1f},
            {5, 0.1f},
            {6, 0.1f},
            {7, 0.1f},
            {8, 0.1f},
            {9, 0.1f},
            {10, 0.1f},
            {11, 0.1f},
            {12, 0.1f},
            {13, 0.1f},
            {14, 0.1f},
            {15, 0.1f},
            {16, 0.1f},
            {17, 0.1f}
        };
    }
};