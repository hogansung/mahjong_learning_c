//
// Created by Hao-En Sung on 12/21/21.
//

#ifndef MAHJONG_LEARNING_C_TILESETS_TILESET_H_
#define MAHJONG_LEARNING_C_TILESETS_TILESET_H_

#include "enums/tiletype.h"

class Tileset {
 public:
  Tileset(std::vector<std::tuple<Tiletype, unsigned int>> bamboo_tile_metadata,
          std::vector<std::tuple<Tiletype, unsigned int>> circle_tile_metadata,
          std::vector<std::tuple<Tiletype, unsigned int>> character_tile_metadata,
          std::vector<std::tuple<Tiletype, unsigned int>> wind_tile_metadata,
          std::vector<std::tuple<Tiletype, unsigned int>> dragon_tile_metadata,
          std::vector<std::tuple<Tiletype, unsigned int>> season_tile_metadata,
          std::vector<std::tuple<Tiletype, unsigned int>> flower_tile_metadata)
      : bamboo_tile_metadata_(bamboo_tile_metadata),
        circle_tile_metadata_(circle_tile_metadata),
        character_tile_metadata_(character_tile_metadata),
        wind_tile_metadata_(wind_tile_metadata),
        dragon_tile_metadata_(dragon_tile_metadata),
        season_tile_metadata_(season_tile_metadata),
        flower_tile_metadata_(flower_tile_metadata) {
    assert(bamboo_tile_metadata_.size() == 9);
    assert(circle_tile_metadata_.size() == 9);
    assert(character_tile_metadata_.size() == 9);
    assert(wind_tile_metadata_.size() == 4);
    assert(dragon_tile_metadata_.size() == 3);
    assert(season_tile_metadata_.size() == 4);
    assert(flower_tile_metadata_.size() == 4);

    tiletype_index = 0;

    // Suited Tiles
    for (auto suited_tile_metadata : std::vector<std::vector<std::tuple<Tiletype, unsigned int>>>{
             bamboo_tile_metadata_, circle_tile_metadata_, character_tile_metadata_}) {
      for (unsigned int idx = 0; idx < suited_tile_metadata.size(); idx += 1) {
        if (idx + 2 < suited_tile_metadata.size()) {
          sequences_.emplace_back(std::get<0>(suited_tile_metadata[idx]),
                                  std::get<0>(suited_tile_metadata[idx + 1]),
                                  std::get<0>(suited_tile_metadata[idx + 2]));
        }
        tiletype_to_index[std::get<0>(suited_tile_metadata[idx])] = tiletype_index++;
        tiletype_limit.emplace_back(std::get<1>(suited_tile_metadata[idx]));
        tiletypes_.emplace_back(std::get<0>(suited_tile_metadata[idx]));
        pairs_.emplace_back(std::get<0>(suited_tile_metadata[idx]),
                            std::get<0>(suited_tile_metadata[idx]));
        triplets_.emplace_back(std::get<0>(suited_tile_metadata[idx]),
                               std::get<0>(suited_tile_metadata[idx]),
                               std::get<0>(suited_tile_metadata[idx]));
      }
    }

    // Honor Tiles
    for (auto suited_tile_metadata : std::vector<std::vector<std::tuple<Tiletype, unsigned int>>>{
             wind_tile_metadata_, dragon_tile_metadata_}) {
      for (unsigned int idx = 0; idx < suited_tile_metadata.size(); idx += 1) {
        tiletype_to_index[std::get<0>(suited_tile_metadata[idx])] = tiletype_index++;
        tiletype_limit.emplace_back(std::get<1>(suited_tile_metadata[idx]));
        tiletypes_.emplace_back(std::get<0>(suited_tile_metadata[idx]));
        pairs_.emplace_back(std::get<0>(suited_tile_metadata[idx]),
                            std::get<0>(suited_tile_metadata[idx]));
        triplets_.emplace_back(std::get<0>(suited_tile_metadata[idx]),
                               std::get<0>(suited_tile_metadata[idx]),
                               std::get<0>(suited_tile_metadata[idx]));
      }
    }

    // Bonus Tiles
    for (auto suited_tile_metadata : std::vector<std::vector<std::tuple<Tiletype, unsigned int>>>{
             season_tile_metadata_, flower_tile_metadata_}) {
      for (unsigned int idx = 0; idx < suited_tile_metadata.size(); idx += 1) {
        tiletype_to_index[std::get<0>(suited_tile_metadata[idx])] = tiletype_index++;
        tiletype_limit.emplace_back(std::get<1>(suited_tile_metadata[idx]));
        tiletypes_.emplace_back(std::get<0>(suited_tile_metadata[idx]));
      }
    }
  }

  const std::vector<std::tuple<Tiletype, unsigned int>> bamboo_tile_metadata_;
  const std::vector<std::tuple<Tiletype, unsigned int>> circle_tile_metadata_;
  const std::vector<std::tuple<Tiletype, unsigned int>> character_tile_metadata_;
  const std::vector<std::tuple<Tiletype, unsigned int>> wind_tile_metadata_;
  const std::vector<std::tuple<Tiletype, unsigned int>> dragon_tile_metadata_;
  const std::vector<std::tuple<Tiletype, unsigned int>> season_tile_metadata_;
  const std::vector<std::tuple<Tiletype, unsigned int>> flower_tile_metadata_;
  unsigned int tiletype_index;
  std::unordered_map<Tiletype, unsigned int> tiletype_to_index;
  std::vector<unsigned int> tiletype_limit;
  std::vector<Tiletype> tiletypes_;
  std::vector<TwoSet> pairs_;
  std::vector<ThreeSet> sequences_;
  std::vector<ThreeSet> triplets_;
};

#endif  // MAHJONG_LEARNING_C_TILESETS_TILESET_H_
