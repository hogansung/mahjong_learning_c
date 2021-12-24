//
// Created by Hao-En Sung on 12/23/21.
//

#ifndef MAHJONG_LEARNING_C_RULES_RAW_INCREMENTAL_RULE_H_
#define MAHJONG_LEARNING_C_RULES_RAW_INCREMENTAL_RULE_H_

#include "rules/raw_rule.h"
#include "tiletype_counter.h"

template <uint CommonTN, uint BonusTN, class CommonTC = TiletypeCounter<CommonTN>,
          class BonusTC = TiletypeCounter<BonusTN>>
class RawIncrementalRule : public RawRule<CommonTN, BonusTN, CommonTC, BonusTC> {
 public:
  RawIncrementalRule(const std::string rule_name, const uint points,
                     const std::vector<std::vector<Tiletype>>& included_tiles_vct,
                     const std::vector<std::tuple<uint, uint, uint>>& nums_vct,
                     const std::function<bool(const State<CommonTN, BonusTN, CommonTC, BonusTC>&)>& func = nullptr)
      : RawRule<CommonTN, BonusTN, CommonTC, BonusTC>(rule_name, points, func),
        included_tiles_vct_(included_tiles_vct),
        nums_vct_(nums_vct) {}

  void pushBack(std::vector<Tiletype>& tiles, const TwoSet& two_set) {
    tiles.emplace_back(std::get<0>(two_set));
    tiles.emplace_back(std::get<1>(two_set));
  }

  void popBack(std::vector<Tiletype>& tiles, const TwoSet& two_set) {
    tiles.pop_back();
    tiles.pop_back();
  }

  void pushBack(std::vector<Tiletype>& tiles, const ThreeSet& three_set) {
    tiles.emplace_back(std::get<0>(three_set));
    tiles.emplace_back(std::get<1>(three_set));
    tiles.emplace_back(std::get<2>(three_set));
  }

  void popBack(std::vector<Tiletype>& tiles, const ThreeSet& three_set) {
    tiles.pop_back();
    tiles.pop_back();
    tiles.pop_back();
  }

  bool _checkIfTiletypeCounterIsWithinLimit(CommonTC tiletype_counter, const Tileset& tileset) {
    for (uint idx = 0; idx < tileset.common_tiletype_size; idx += 1) {
      if (tiletype_counter.counter_[idx] > tileset.tiletype_limit[idx]) {
        return false;
      }
    }
    return true;
  }

  void _generateTiletypeCountersIncrementally(std::vector<Tiletype>& tiles, uint pair_idx, uint pair_num,
                                              uint sequence_idx, uint sequence_num, uint triplet_idx, uint triplet_num,
                                              std::unordered_set<CommonTC>& tiletype_counter_set,
                                              const Tileset& tileset) {
    if (pair_num == 0 and sequence_num == 0 and triplet_num == 0) {
      if (CommonTC::checkIfValidCommonTiles(tiles, tileset)) {
        tiletype_counter_set.emplace(tiles);
      }
    } else if (pair_num == 0 and sequence_num == 0) {
      for (unsigned triplet_c_idx = triplet_idx; triplet_c_idx < tileset.triplets_.size(); triplet_c_idx += 1) {
        pushBack(tiles, tileset.triplets_[triplet_c_idx]);
        _generateTiletypeCountersIncrementally(tiles, pair_idx, pair_num, sequence_idx, sequence_num, triplet_c_idx + 1,
                                               triplet_num - 1, tiletype_counter_set, tileset);
        popBack(tiles, tileset.triplets_[triplet_c_idx]);
      }
    } else if (pair_num == 0) {
      for (unsigned sequence_c_idx = sequence_idx; sequence_c_idx < tileset.sequences_.size(); sequence_c_idx += 1) {
        pushBack(tiles, tileset.sequences_[sequence_c_idx]);
        _generateTiletypeCountersIncrementally(tiles, pair_idx, pair_num, sequence_c_idx, sequence_num - 1, triplet_idx,
                                               triplet_num, tiletype_counter_set, tileset);
        popBack(tiles, tileset.sequences_[sequence_c_idx]);
      }
    } else {
      for (unsigned pair_c_idx = pair_idx; pair_c_idx < tileset.pairs_.size(); pair_c_idx += 1) {
        pushBack(tiles, tileset.pairs_[pair_c_idx]);
        _generateTiletypeCountersIncrementally(tiles, pair_c_idx + 1, pair_num - 1, sequence_idx, sequence_num,
                                               triplet_idx, triplet_num, tiletype_counter_set, tileset);
        popBack(tiles, tileset.pairs_[pair_c_idx]);
      }
    }
  }

  std::unordered_set<CommonTC> compile(const Tileset& tileset, const uint tile_num) {
    assert(included_tiles_vct_.size() > 0 and nums_vct_.size() > 0);
    std::unordered_set<CommonTC> tiletype_counter_set;
    for (auto included_tiles : included_tiles_vct_) {
      for (auto nums : nums_vct_) {
        uint pair_num = std::get<0>(nums);
        uint sequence_num = std::get<1>(nums);
        uint triplet_num = std::get<2>(nums);
        assert(included_tiles.size() + pair_num * 2 + sequence_num * 3 + triplet_num * 3 == tile_num);
        _generateTiletypeCountersIncrementally(included_tiles, 0, pair_num, 0, sequence_num, 0, triplet_num,
                                               tiletype_counter_set, tileset);
      }
    }
    return tiletype_counter_set;
  }

  const std::vector<std::vector<Tiletype>> included_tiles_vct_;
  const std::vector<std::tuple<uint, uint, uint>> nums_vct_;
};

#endif  // MAHJONG_LEARNING_C_RULES_RAW_INCREMENTAL_RULE_H_
