//
// Created by Hao-En Sung on 12/21/21.
//

#ifndef MAHJONG_LEARNING_C_TILESETS_TILESET_H_
#define MAHJONG_LEARNING_C_TILESETS_TILESET_H_

#include "enums/tiletype.h"

class Tileset {
 public:
  Tileset(std::vector<Tiletype> bamboo_tiletypes, std::vector<Tiletype> circle_tiletypes,
          std::vector<Tiletype> character_tiletypes, std::vector<Tiletype> wind_tiletypes,
          std::vector<Tiletype> dragon_tiletypes, std::vector<Tiletype> season_tiletypes,
          std::vector<Tiletype> flower_tiletypes)
      : bamboo_tiletypes_(bamboo_tiletypes),
        circle_tiletypes_(circle_tiletypes),
        character_tiletypes_(character_tiletypes),
        wind_tiletypes_(wind_tiletypes),
        dragon_tiletypes_(dragon_tiletypes),
        season_tiletypes_(season_tiletypes),
        flower_tiletypes_(flower_tiletypes) {
    assert(bamboo_tiletypes_.size() == 9);
    assert(circle_tiletypes_.size() == 9);
    assert(character_tiletypes_.size() == 9);
    assert(wind_tiletypes_.size() == 4);
    assert(dragon_tiletypes_.size() == 3);
    assert(season_tiletypes_.size() == 4);
    assert(flower_tiletypes_.size() == 4);

    // Suited Tiles
    for (auto suited_tiletypes : std::vector<std::vector<Tiletype>>{
             bamboo_tiletypes_, circle_tiletypes_, character_tiletypes_}) {
      for (unsigned int idx = 0; idx < suited_tiletypes.size(); idx += 1) {
        if (idx + 2 < suited_tiletypes.size()) {
          sequences_.emplace_back(suited_tiletypes[idx], suited_tiletypes[idx + 1],
                                  suited_tiletypes[idx + 2]);
        }
        tiletypes_.emplace_back(suited_tiletypes[idx]);
        pairs_.emplace_back(suited_tiletypes[idx], suited_tiletypes[idx]);
        triplets_.emplace_back(suited_tiletypes[idx], suited_tiletypes[idx], suited_tiletypes[idx]);
      }
    }

    // Honor Tiles
    for (auto suited_tiletypes :
         std::vector<std::vector<Tiletype>>{wind_tiletypes_, dragon_tiletypes_}) {
      for (unsigned int idx = 0; idx < suited_tiletypes.size(); idx += 1) {
        tiletypes_.emplace_back(suited_tiletypes[idx]);
        pairs_.emplace_back(suited_tiletypes[idx], suited_tiletypes[idx]);
        triplets_.emplace_back(suited_tiletypes[idx], suited_tiletypes[idx], suited_tiletypes[idx]);
      }
    }

    // Bonus Tiles
    for (auto suited_tiletypes :
         std::vector<std::vector<Tiletype>>{season_tiletypes_, flower_tiletypes_}) {
      for (unsigned int idx = 0; idx < suited_tiletypes.size(); idx += 1) {
        tiletypes_.emplace_back(suited_tiletypes[idx]);
      }
    }
  }

  const std::vector<Tiletype> bamboo_tiletypes_;
  const std::vector<Tiletype> circle_tiletypes_;
  const std::vector<Tiletype> character_tiletypes_;
  const std::vector<Tiletype> wind_tiletypes_;
  const std::vector<Tiletype> dragon_tiletypes_;
  const std::vector<Tiletype> season_tiletypes_;
  const std::vector<Tiletype> flower_tiletypes_;
  std::vector<Tiletype> tiletypes_;
  std::vector<TwoSet> pairs_;
  std::vector<ThreeSet> sequences_;
  std::vector<ThreeSet> triplets_;
};

#endif  // MAHJONG_LEARNING_C_TILESETS_TILESET_H_
