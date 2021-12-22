//
// Created by Hao-En Sung on 12/21/21.
//

#ifndef MAHJONG_LEARNING_C_TILESETS_TILESET_H_
#define MAHJONG_LEARNING_C_TILESETS_TILESET_H_

#include "enums/tiletype.h"

class Tileset {
 public:
  Tileset(std::vector<std::tuple<Tiletype, uint>> so_tile_metadata,
          std::vector<std::tuple<Tiletype, uint>> pin_tile_metadata,
          std::vector<std::tuple<Tiletype, uint>> man_tile_metadata,
          std::vector<std::tuple<Tiletype, uint>> wind_tile_metadata,
          std::vector<std::tuple<Tiletype, uint>> dragon_tile_metadata,
          std::vector<std::tuple<Tiletype, uint>> season_tile_metadata,
          std::vector<std::tuple<Tiletype, uint>> flower_tile_metadata)
      : so_tile_metadata_(so_tile_metadata),
        pin_tile_metadata_(pin_tile_metadata),
        man_tile_metadata_(man_tile_metadata),
        wind_tile_metadata_(wind_tile_metadata),
        dragon_tile_metadata_(dragon_tile_metadata),
        season_tile_metadata_(season_tile_metadata),
        flower_tile_metadata_(flower_tile_metadata) {
    assert(so_tile_metadata_.size() == 9);
    assert(pin_tile_metadata_.size() == 9);
    assert(man_tile_metadata_.size() == 9);
    assert(wind_tile_metadata_.size() == 4);
    assert(dragon_tile_metadata_.size() == 3);
    assert(season_tile_metadata_.size() == 4);
    assert(flower_tile_metadata_.size() == 4);

    tiletype_size = 0;

    // Suited Tiles
    for (auto suited_tile_metadata : std::vector<std::vector<std::tuple<Tiletype, uint>>>{
             so_tile_metadata_, pin_tile_metadata_, man_tile_metadata_}) {
      for (uint idx = 0; idx < suited_tile_metadata.size(); idx += 1) {
        if (idx + 2 < suited_tile_metadata.size()) {
          sequences_.emplace_back(std::get<0>(suited_tile_metadata[idx]), std::get<0>(suited_tile_metadata[idx + 1]),
                                  std::get<0>(suited_tile_metadata[idx + 2]));
        }
        tiletype_to_index[std::get<0>(suited_tile_metadata[idx])] = tiletype_size++;
        tiletype_limit.emplace_back(std::get<1>(suited_tile_metadata[idx]));
        tiletypes_.emplace_back(std::get<0>(suited_tile_metadata[idx]));
        pairs_.emplace_back(std::get<0>(suited_tile_metadata[idx]), std::get<0>(suited_tile_metadata[idx]));
        triplets_.emplace_back(std::get<0>(suited_tile_metadata[idx]), std::get<0>(suited_tile_metadata[idx]),
                               std::get<0>(suited_tile_metadata[idx]));
      }
    }

    // Honor Tiles
    for (auto suited_tile_metadata :
         std::vector<std::vector<std::tuple<Tiletype, uint>>>{wind_tile_metadata_, dragon_tile_metadata_}) {
      for (uint idx = 0; idx < suited_tile_metadata.size(); idx += 1) {
        tiletype_to_index[std::get<0>(suited_tile_metadata[idx])] = tiletype_size++;
        tiletype_limit.emplace_back(std::get<1>(suited_tile_metadata[idx]));
        tiletypes_.emplace_back(std::get<0>(suited_tile_metadata[idx]));
        pairs_.emplace_back(std::get<0>(suited_tile_metadata[idx]), std::get<0>(suited_tile_metadata[idx]));
        triplets_.emplace_back(std::get<0>(suited_tile_metadata[idx]), std::get<0>(suited_tile_metadata[idx]),
                               std::get<0>(suited_tile_metadata[idx]));
      }
    }

    // Bonus Tiles
    for (auto suited_tile_metadata :
         std::vector<std::vector<std::tuple<Tiletype, uint>>>{season_tile_metadata_, flower_tile_metadata_}) {
      for (uint idx = 0; idx < suited_tile_metadata.size(); idx += 1) {
        tiletype_to_index[std::get<0>(suited_tile_metadata[idx])] = tiletype_size++;
        tiletype_limit.emplace_back(std::get<1>(suited_tile_metadata[idx]));
        tiletypes_.emplace_back(std::get<0>(suited_tile_metadata[idx]));
      }
    }
  }

  const std::vector<std::tuple<Tiletype, uint>> so_tile_metadata_;
  const std::vector<std::tuple<Tiletype, uint>> pin_tile_metadata_;
  const std::vector<std::tuple<Tiletype, uint>> man_tile_metadata_;
  const std::vector<std::tuple<Tiletype, uint>> wind_tile_metadata_;
  const std::vector<std::tuple<Tiletype, uint>> dragon_tile_metadata_;
  const std::vector<std::tuple<Tiletype, uint>> season_tile_metadata_;
  const std::vector<std::tuple<Tiletype, uint>> flower_tile_metadata_;
  uint tiletype_size;
  std::unordered_map<Tiletype, uint> tiletype_to_index;
  std::vector<uint> tiletype_limit;
  std::vector<Tiletype> tiletypes_;
  std::vector<TwoSet> pairs_;
  std::vector<ThreeSet> sequences_;
  std::vector<ThreeSet> triplets_;
};

#endif  // MAHJONG_LEARNING_C_TILESETS_TILESET_H_
