#pragma once

#include <list>

#include "../Types.h"

#include "../BW/UnitType.h"
#include "../BW/Offsets.h"

#include "Race.h"

namespace BW { struct Unit; };

namespace BWAPI
{
  class Unit;
  /** 
  * Represents one player in game, note that there is always player 12 who owns resources.
  */
  class Player
  {
  public :
    Player(u8 id);
    ~Player();
    char* getName() const;
    void  setName(const char* const name);
    s32   getMinerals() const;
    s32   getMineralsLocal() const;
    s32   getGas() const;
    s32   getGasLocal() const;
    u8    getID() const;
    void  spendLocal(s32 minerals, s32 gas);

    s32   getSuppliesAvailableProtoss();
    s32   getSuppliesAvailableProtossLocal();
    s32   getSuppliesUsedProtoss();
    s32   getSuppliesUsedProtossLocal();
    void  useSuppliesProtossLocal(u8 supplies);
    s32   freeSuppliesProtossLocal();
    
    s32   getSuppliesAvailableTerran();
    s32   getSuppliesAvailableTerranLocal();
    s32   getSuppliesUsedTerran();
    s32   getSuppliesUsedTerranLocal();
    void  useSuppliesTerranLocal(u8 supplies);
    s32   freeSuppliesTerranLocal();

    s32   getSuppliesAvailableZerg();
    s32   getSuppliesAvailableZergLocal();
    s32   getSuppliesUsedZerg();
    s32   getSuppliesUsedZergLocal();
    void  useSuppliesZergLocal(u8 supplies);
    s32   freeSuppliesZergLocal();
    
    s32 freeSuppliesLocal(BWAPI::Race::Enum race);
    s32 usedSuppliesLocal(BWAPI::Race::Enum race);

    /** 
    * List of units owned by the current player, this structure owns (so the player needs 
    * to be deleted upon removal.
    */
    std::list<Unit*> units; 
    BW::Unit** selectedUnit();
    void update();
    bool canBuild(BW::UnitType unit);
    u16 unitTypeCount[BW::unitTypeCount];
  private :
    u8 id;  /**< Order of the player, is used to load player's information from the memory */
    s32 mineralsLocal, gasLocal;

    s32 suppliesAvailableProtossLocal;
    s32 suppliesUsedProtossLocal;

    s32 suppliesAvailableTerranLocal;
    s32 suppliesUsedTerranLocal;
    
    s32 suppliesAvailableZergLocal;
    s32 suppliesUsedZergLocal;
  };
};