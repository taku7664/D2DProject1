#include "LoadAnimationData.h"

namespace LoadAnimation
{

    SwordManIdle::SwordManIdle()
    {
        _key = L"A_SwordManIdle";
        _spriteKey = L"S_SwordManSheet1";
        _data = {
            {4, 0.15f, Vector2(0,0)},
            {5, 0.15f, Vector2(0,0)},
            {6, 0.15f, Vector2(0,0)},
            {7, 0.15f, Vector2(0,0)},
            {8, 0.15f, Vector2(0,0)},
            {9, 0.15f, Vector2(0,0)}
        };
    }

    SwordManWalk::SwordManWalk()
    {
        _key = L"A_SwordManWalk";
        _spriteKey = L"S_SwordManSheet1";
        _data = {
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

    SwordManRun::SwordManRun()
    {
        _key = L"A_SwordManRun";
        _spriteKey = L"S_SwordManSheet1";
        _data = {
            {18, 0.1f},
            {19, 0.1f},
            {20, 0.1f},
            {21, 0.1f},
            {22, 0.1f},
            {23, 0.1f},
            {24, 0.1f},
            {25, 0.1f}
        };
    }

    SwordManJump::SwordManJump()
    {
        _key = L"A_SwordManJump";
        _spriteKey = L"S_SwordManSheet1";
        _data = {
            {26, 0.1f},
            {27, 0.1f},
            {28, 0.1f},
            {29, 0.15f},
            {30, 0.15f},
            {31, 0.15f},
            {32, 0.15f}
        };
    }

    SwordManHit::SwordManHit()
    {
        _key = L"A_SwordManHit";
        _spriteKey = L"S_SwordManSheet1";
        _data = {
            {34, 0.1f},
            {35, 0.1f},
            {36, 0.1f},
            {37, 0.1f},
            {38, 0.1f},
            {39, 0.1f},
        };
    }

    SwordManBasicAttack1::SwordManBasicAttack1()
    {
        _key = L"A_SwordManBasicAttack1";
        _spriteKey = L"S_SwordManSheet2";
        _data = {
            {2, 0.1f},
            {3, 0.1f},
            {4, 0.1f},
            {5, 0.1f},
            {6, 0.1f},
            {7, 0.1f},
            {8, 0.3f}
        };
    }

    SwordManBasicAttack2::SwordManBasicAttack2()
    {
        _key = L"A_SwordManBasicAttack2";
        _spriteKey = L"S_SwordManSheet2";
        _data = {
            {9, 0.1f},
            {10, 0.1f},
            {11, 0.1f},
            {12, 0.1f},
            {13, 0.05f},
            {14, 0.05f},
            {15, 0.3f}
        };
    }

    SwordManBasicAttack3::SwordManBasicAttack3()
    {
        _key = L"A_SwordManBasicAttack3";
        _spriteKey = L"S_SwordManSheet2";
        _data = {
            {16, 0.1f},
            {17, 0.1f},
            {18, 0.1f},
            {20, 0.1f},
            {21, 0.1f},
            {22, 0.2f}
        };
    }

    SwordManJumpAttack::SwordManJumpAttack()
    {
        _key = L"A_SwordManJumpAttack";
        _spriteKey = L"S_SwordManSheet2";
        _data = {
            {23, 0.1f},
            {24, 0.1f},
            {25, 0.1f},
            {26, 0.1f},
            {27, 0.1f},
            {28, 0.1f},
        };
    }

    SwordManDashAttack::SwordManDashAttack()
    {
        _key = L"A_SwordManDashAttack";
        _spriteKey = L"S_SwordManSheet2";
        _data = {
            {39, 0.15f},
            {40, 0.1f},
            {41, 0.1f},
            {42, 0.1f},
            {43, 0.1f},
            {44, 0.1f},
            {45, 0.2f}
        };
    }

    // 귀참 모션
    SwordManAttack1::SwordManAttack1()
    {
        _key = L"A_SwordManAttack1";
        _spriteKey = L"S_SwordManSheet2";
        _data = {
            {46, 0.1f},
            {47, 0.1f},
            {48, 0.1f},
            {49, 0.1f},
            {50, 0.1f},
            {51, 0.1f},
            {52, 0.1f},
            {53, 0.2f}
        };
    }
    // 열파참1 모션
    SwordManAttack2::SwordManAttack2()
    {
        _key = L"A_SwordManAttack2";
        _spriteKey = L"S_SwordManSheet2";
        _data = {
            //{75, 0.1f, Vector2(20,0)},
            {76, 0.1f, Vector2(20,0)},
            {77, 0.1f, Vector2(20,0)},
            {78, 0.1f, Vector2(20,0)},
            {79, 0.1f, Vector2(20,0)},
            {80, 0.1f, Vector2(20,0)}
        };
    }
    // 열파참2 모션
    SwordManAttack3::SwordManAttack3()
    {
        _key = L"A_SwordManAttack3";
        _spriteKey = L"S_SwordManSheet2";
        _data = {
            {81, 0.2f, Vector2(20,0)},
            {82, 0.2f, Vector2(20,0)},
            {83, 0.1f, Vector2(20,0)},
            {84, 0.1f, Vector2(20,0)},
            {85, 0.1f, Vector2(20,0)},
            {86, 0.1f, Vector2(20,0)}
        };
    }
}
