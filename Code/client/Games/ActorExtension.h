#pragma once

#include <Structs/ActionEvent.h>

struct ActorExtension
{
    enum
    {
        kRemote = 1 << 0,
        kPlayer = 1 << 1,
    };

    bool IsRemote() const noexcept;
    bool IsLocal() const noexcept;
    bool IsPlayer() const noexcept;
    bool IsRemotePlayer() const noexcept;
    bool IsLocalPlayer() const noexcept;
    void SetRemote(bool aSet) noexcept;
    void SetPlayer(bool aSet) noexcept;
    void SetPlayerId(int32_t aId) noexcept;

    ActionEvent LatestAnimation{};
    size_t GraphDescriptorHash = 0;
    uint32_t PlayerId = -1;

private:

    uint32_t onlineFlags{ 0 };
};
