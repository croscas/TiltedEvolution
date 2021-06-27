#include <stdafx.h>

#include "Player.h"
#include <GameServer.h>

static uint32_t GenerateId()
{
    static std::atomic<uint32_t> s_counter;
    return s_counter.fetch_add(1);
}

Player::Player(ConnectionId_t aConnectionId)
    : m_id(GenerateId())
    , m_connectionId(aConnectionId)
{
    
}

CellIdComponent& Player::GetCellComponent() noexcept
{
    return m_cell;
}

const CellIdComponent& Player::GetCellComponent() const noexcept
{
    return m_cell;
}

QuestLogComponent& Player::GetQuestLogComponent() noexcept
{
    return m_questLog;
}

const QuestLogComponent& Player::GetQuestLogComponent() const noexcept
{
    return m_questLog;
}

void Player::SetDiscordId(uint64_t aDiscordId) noexcept
{
    m_discordId = aDiscordId;
}

void Player::SetEndpoint(String aEndpoint) noexcept
{
    m_endpoint = std::move(aEndpoint);
}

void Player::SetUsername(String aUsername) noexcept
{
    m_username = std::move(aUsername);
}

void Player::SetMods(Vector<String> aMods) noexcept
{
    m_mods = std::move(aMods);
}

void Player::SetModIds(Vector<uint16_t> aModIds) noexcept
{
    m_modIds = std::move(aModIds);
}

void Player::SetCharacter(entt::entity aCharacter) noexcept
{
    m_character = aCharacter;
}

void Player::SetCellComponent(const CellIdComponent& aCellComponent) noexcept
{
    m_cell = aCellComponent;
}

void Player::Send(const ServerMessage& acServerMessage) const
{
    GameServer::Get()->Send(GetConnectionId(), acServerMessage);
}
