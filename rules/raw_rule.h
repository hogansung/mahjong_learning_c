//
// Created by Hao-En Sung on 12/21/21.
//

#ifndef MAHJONG_LEARNING_C_RULES_RAW_RULE_H_
#define MAHJONG_LEARNING_C_RULES_RAW_RULE_H_

#include <unordered_set>

class RawRule {
 public:
  RawRule(const std::string rule_name, const uint points, const std::function<bool(const State&)>& func = nullptr)
      : rule_name_(rule_name), points_(points), func_(func) {}
  virtual ~RawRule() {}

  TiletypeCounter _createTiletypeCounterFromTiles(const std::vector<Tiletype>& tiles, const Tileset& tileset) {
    std::vector<uint> tiletype_counter(tileset.common_tiletype_size, 0);
    for (auto tiletype : tiles) {
      tiletype_counter[tileset.tiletype_to_index.at(tiletype)] += 1;
    }
    return TiletypeCounter(tiletype_counter);
  }

  virtual std::unordered_set<TiletypeCounter> compile(const Tileset& tileset, const uint tile_num) = 0;

  const std::string rule_name_;
  const uint points_;
  const std::function<uint(const State&)> func_;
};

#endif  // MAHJONG_LEARNING_C_RULES_RAW_RULE_H_
