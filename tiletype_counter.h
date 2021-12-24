//
// Created by Hao-En Sung on 12/23/21.
//

#ifndef MAHJONG_LEARNING_C__TILETYPE_COUNTER_H_
#define MAHJONG_LEARNING_C__TILETYPE_COUNTER_H_

#include <enums/tiletype.h>
#include <sys/types.h>
#include <tilesets/tileset.h>

#include <bitset>
#include <boost/dynamic_bitset.hpp>
#include <vector>

template <uint TileTypeNum>
class TiletypeCounter {
 public:
  const static uint counter_size_ = TileTypeNum * 3;

  static std::array<uint, TileTypeNum> convertTilesToNaiveCounter(std::vector<Tiletype>& tiles,
                                                                  const Tileset& tileset) {
    std::array<uint, TileTypeNum> naive_counter = std::array<uint, TileTypeNum>();
    for (auto tiletype : tiles) {
      naive_counter[tileset.tiletype_to_index.at(tiletype)] += 1;
    }
    return naive_counter;
  }

  static bool checkIfValidCommonTiles(std::vector<Tiletype>& tiles, const Tileset& tileset) {
    std::array<uint, TileTypeNum> naive_counter = convertTilesToNaiveCounter(tiles, tileset);
    for (uint idx = 0; idx < tileset.common_tiletype_size; idx += 1) {
      if (naive_counter[idx] > tileset.tiletype_limit[idx]) {
        return false;
      }
    }
    return true;
  }

  TiletypeCounter() {}
  TiletypeCounter(std::vector<Tiletype>& tiles, const Tileset& tileset) {
    std::array<uint, TileTypeNum> naive_counter = convertTilesToNaiveCounter(tiles, tileset);
    for (uint idx = 0; idx < TileTypeNum; idx += 1) {
      counter_[3 * idx] = naive_counter[idx] & 4;
      counter_[3 * idx + 1] = naive_counter[idx] & 2;
      counter_[3 * idx + 2] = naive_counter[idx] & 1;
    }
  }
  TiletypeCounter(std::bitset<counter_size_>& counter) : counter_(counter) {}

  template <class Archive>
  void serialize(Archive& ar, const unsigned int version) {
    ar& counter_;
  }

  virtual const Tileset& getTileset() = 0;

  std::bitset<counter_size_> counter_;
};

#endif  // MAHJONG_LEARNING_C__TILETYPE_COUNTER_H_
