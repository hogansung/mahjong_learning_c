//
// Created by Hao-En Sung on 12/21/21.
//

#ifndef MAHJONG_LEARNING_C_RULESETS_RULESET_H_
#define MAHJONG_LEARNING_C_RULESETS_RULESET_H_

#include "enums/tiletype.h"
#include "rules/rule.h"

class Ruleset {
 public:
  Ruleset(Tileset tileset) : tileset_(tileset) {}

  void pushBackTwoSet(std::vector<uint>& tiletype_counter, TwoSet two_set) {
    tiletype_counter[tileset_.tiletype_to_index.at(std::get<0>(two_set))] += 1;
    tiletype_counter[tileset_.tiletype_to_index.at(std::get<1>(two_set))] += 1;
  }

  void popBackTwoSet(std::vector<uint>& tiletype_counter, TwoSet two_set) {
    tiletype_counter[tileset_.tiletype_to_index.at(std::get<0>(two_set))] -= 1;
    tiletype_counter[tileset_.tiletype_to_index.at(std::get<1>(two_set))] -= 1;
  }

  void pushBackThreeSet(std::vector<uint>& tiletype_counter, ThreeSet three_set) {
    tiletype_counter[tileset_.tiletype_to_index.at(std::get<0>(three_set))] += 1;
    tiletype_counter[tileset_.tiletype_to_index.at(std::get<1>(three_set))] += 1;
    tiletype_counter[tileset_.tiletype_to_index.at(std::get<2>(three_set))] += 1;
  }

  void popBackThreeSet(std::vector<uint>& tiletype_counter, ThreeSet three_set) {
    tiletype_counter[tileset_.tiletype_to_index.at(std::get<0>(three_set))] -= 1;
    tiletype_counter[tileset_.tiletype_to_index.at(std::get<1>(three_set))] -= 1;
    tiletype_counter[tileset_.tiletype_to_index.at(std::get<2>(three_set))] -= 1;
  }

  bool _checkIfTiletypeCounterIsWithinLimit(std::vector<uint> tiletype_counter) {
    for (uint idx = 0; idx < tileset_.tiletype_size; idx += 1) {
      if (tiletype_counter[idx] > tileset_.tiletype_limit[idx]) {
        return false;
      }
    }
    return true;
  }

  void _generateTiletypeCountersIncrementally(std::vector<uint>& tiletype_counter, uint pair_idx, uint pair_num,
                                              uint sequence_idx, uint sequence_num, uint triplet_idx, uint triplet_num,
                                              std::vector<std::vector<uint>>& tiletype_counters) {
    if (pair_num == 0 and sequence_num == 0 and triplet_num == 0) {
      if (_checkIfTiletypeCounterIsWithinLimit(tiletype_counter)) {
        tiletype_counters.emplace_back(tiletype_counter);
      }
    } else if (pair_num == 0 and sequence_num == 0) {
      for (unsigned triplet_c_idx = triplet_idx; triplet_c_idx < Ruleset::tileset_.triplets_.size();
           triplet_c_idx += 1) {
        pushBackThreeSet(tiletype_counter, Ruleset::tileset_.triplets_[triplet_c_idx]);
        _generateTiletypeCountersIncrementally(tiletype_counter, pair_idx, pair_num, sequence_idx, sequence_num,
                                               triplet_c_idx + 1, triplet_num - 1, tiletype_counters);
        popBackThreeSet(tiletype_counter, Ruleset::tileset_.triplets_[triplet_c_idx]);
      }
    } else if (pair_num == 0) {
      for (unsigned sequence_c_idx = sequence_idx; sequence_c_idx < Ruleset::tileset_.sequences_.size();
           sequence_c_idx += 1) {
        pushBackThreeSet(tiletype_counter, Ruleset::tileset_.sequences_[sequence_c_idx]);
        _generateTiletypeCountersIncrementally(tiletype_counter, pair_idx, pair_num, sequence_c_idx, sequence_num - 1,
                                               triplet_idx, triplet_num, tiletype_counters);
        popBackThreeSet(tiletype_counter, Ruleset::tileset_.sequences_[sequence_c_idx]);
      }
    } else {
      for (unsigned pair_c_idx = pair_idx; pair_c_idx < Ruleset::tileset_.pairs_.size(); pair_c_idx += 1) {
        pushBackTwoSet(tiletype_counter, Ruleset::tileset_.pairs_[pair_c_idx]);
        _generateTiletypeCountersIncrementally(tiletype_counter, pair_c_idx + 1, pair_num - 1, sequence_idx,
                                               sequence_num, triplet_idx, triplet_num, tiletype_counters);
        popBackTwoSet(tiletype_counter, Ruleset::tileset_.pairs_[pair_c_idx]);
      }
    }
  }

  std::vector<uint> _createTiletypeCounterFromTiles(std::vector<Tiletype> tiles) {
    std::vector<uint> tiletype_counter(tileset_.tiletype_size, 0);
    for (auto tiletype : tiles) {
      tiletype_counter[tileset_.tiletype_to_index.at(tiletype)] += 1;
    }
    return tiletype_counter;
  }

  std::vector<std::vector<uint>> generateTiletypeCountersIncrementally(
      const std::vector<std::vector<Tiletype>> included_tiles_vct, const std::tuple<uint, uint> pair_constraints,
      const std::tuple<uint, uint> sequence_constraints, const std::tuple<uint, uint> triplet_constraints,
      uint max_tile_num) {
    std::vector<std::vector<uint>> tiletype_counters;
    for (auto included_tiles : included_tiles_vct) {
      assert(included_tiles.size() + get<1>(pair_constraints) * 2 <= max_tile_num);
      assert(included_tiles.size() + get<1>(sequence_constraints) * 3 <= max_tile_num);
      assert(included_tiles.size() + get<1>(triplet_constraints) * 3 <= max_tile_num);

      std::vector<uint> tiletype_counter = _createTiletypeCounterFromTiles(included_tiles);
      for (uint pair_num = get<0>(pair_constraints); pair_num <= get<1>(pair_constraints); pair_num += 1) {
        for (uint sequence_num = get<0>(sequence_constraints); sequence_num <= get<1>(sequence_constraints);
             sequence_num += 1) {
          if (included_tiles.size() + pair_num * 2 + sequence_num * 3 > max_tile_num) {
            break;
          }
          for (uint triplet_num = get<0>(triplet_constraints); triplet_num <= get<1>(triplet_constraints);
               triplet_num += 1) {
            if (included_tiles.size() + pair_num * 2 + sequence_num * 3 + triplet_num * 3 != max_tile_num) {
              continue;
            }
            _generateTiletypeCountersIncrementally(tiletype_counter, 0, pair_num, 0, sequence_num, 0, triplet_num,
                                                   tiletype_counters);
          }
        }
      }
    }
    return tiletype_counters;
  }

  bool checkIfTiletypeCounterShouldBeExcluded(std::vector<uint> tiletype_counter,
                                              std::vector<uint> excluded_tiletype_counter) {
    for (uint idx = 0; idx < tileset_.tiletype_size; idx += 1) {
      if (std::min(tiletype_counter[idx], excluded_tiletype_counter[idx])) {
        return true;
      }
    }
    return false;
  }

  std::vector<std::vector<uint>> generateTiletypeCountersDecrementally(
      const std::vector<std::vector<Tiletype>> excluded_tiles_vct,
      std::vector<std::vector<uint>> prebuilt_tiletype_counters) {
    std::vector<std::vector<uint>> excluded_tiletype_counters;
    for (auto excluded_tiles : excluded_tiles_vct) {
      excluded_tiletype_counters.emplace_back(_createTiletypeCounterFromTiles(excluded_tiles));
    }

    std::vector<std::vector<uint>> tiletype_counters;
    for (auto prebuilt_tiletype_counter : prebuilt_tiletype_counters) {
      for (auto excluded_tiletype_counter : excluded_tiletype_counters) {
        if (!checkIfTiletypeCounterShouldBeExcluded(prebuilt_tiletype_counter, excluded_tiletype_counter)) {
          tiletype_counters.emplace_back(prebuilt_tiletype_counter);
        }
      }
    }
    return tiletype_counters;
  }

  Tileset tileset_;
  std::vector<std::vector<uint>> tiletype_counters_for_four_sets_one_pair_;
  std::vector<std::vector<uint>> tiletype_counters_for_seven_pairs_;
  std::vector<Rule> rules_;
};

#endif  // MAHJONG_LEARNING_C_RULESETS_RULESET_H_
