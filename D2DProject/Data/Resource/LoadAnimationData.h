#pragma once
#include "DemoApp.h"

namespace LoadAnimation
{
    struct LoadAnimationData abstract
    {
        std::wstring _key = L"";
        std::wstring _spriteKey;
        std::vector<AnimationData> _data;
        Resource::Animation2D* Load()
        {
            return ResourceManager::AddAnimation2D(_key,
                ResourceManager::GetSprite2D(_spriteKey),
                _data);
        }
        void Release()
        {
            ResourceManager::ReleaseAnimation2D(_key);
        }
        Resource::Animation2D* Get()
        {
            return ResourceManager::GetAnimation2D(_key);
        }
    };

    // Player
    // SwordMan - NoneAttack
    struct SwordManIdle : public LoadAnimationData
    {
        SwordManIdle();
    };

    struct SwordManWalk : public LoadAnimationData
    {
        SwordManWalk();
    };

    struct SwordManRun : public LoadAnimationData
    {
        SwordManRun();
    };

    struct SwordManJump : public LoadAnimationData
    {
        SwordManJump();
    };

    struct SwordManHit : public LoadAnimationData
    {
        SwordManHit();
    };

    struct SwordManWin : public LoadAnimationData
    {
        SwordManWin();
    };

    // SwordMan - Attack
    struct SwordManBasicAttack1 : public LoadAnimationData
    {
        SwordManBasicAttack1();
    };

    struct SwordManBasicAttack2 : public LoadAnimationData
    {
        SwordManBasicAttack2();
    };

    struct SwordManBasicAttack3 : public LoadAnimationData
    {
        SwordManBasicAttack3();
    };

    struct SwordManJumpAttack : public LoadAnimationData
    {
        SwordManJumpAttack();
    };

    struct SwordManDashAttack : public LoadAnimationData
    {
        SwordManDashAttack();
    };
    struct SwordManAttack1 : public LoadAnimationData
    {
        // 찌르기 (귀참)
        SwordManAttack1();
    };
    struct SwordManAttack2 : public LoadAnimationData
    {
        // 올려치기 (열파참1)
        SwordManAttack2();
    };

    struct SwordManAttack3 : public LoadAnimationData
    {
        // 내려치기 (열파참2)
        SwordManAttack3();
    };

    // Gunner - NoneAttack
    struct GunnerIdle : public LoadAnimationData
    {
        GunnerIdle();
    };

    struct GunnerWalk : public LoadAnimationData
    {
        GunnerWalk();
    };

    struct GunnerRun : public LoadAnimationData
    {
        GunnerRun();
    };

    struct GunnerJump : public LoadAnimationData
    {
        GunnerJump();
    };

    struct GunnerHit : public LoadAnimationData
    {
        GunnerHit();
    };

    // ======================Skill======================
    struct HardAttack : public LoadAnimationData
    {
        HardAttack();
    };
    struct UpperSlash : public LoadAnimationData
    {
        UpperSlash();
    };
    struct VaneSlashWave : public LoadAnimationData
    {
        VaneSlashWave();
    };
    struct VaneSlash : public LoadAnimationData
    {
        VaneSlash();
    };
}
