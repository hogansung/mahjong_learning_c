//
// Created by Hao-En Sung on 12/23/21.
//

#ifndef MAHJONG_LEARNING_C_RULES_RAW_DECREMENTAL_RULE_H_
#define MAHJONG_LEARNING_C_RULES_RAW_DECREMENTAL_RULE_H_

#include "rules/raw_rule.h"
#include "tilesets/tileset.h"
#include "tiletype_counter.h"

template <uint CommonTN, uint BonusTN, class CommonTC = TiletypeCounter<CommonTN>,
          class BonusTC = TiletypeCounter<BonusTN>>
class RawDecrementalRule : public RawRule<CommonTN, BonusTN, CommonTC, BonusTC> {
 public:
  RawDecrementalRule(const std::string rule_name, const uint points,
                     const std::vector<std::vector<Tiletype>>& excluded_tiles_vct,
                     const std::unordered_set<CommonTC>& full_tiletype_counter_set,
                     const std::function<bool(const State<CommonTN, BonusTN, CommonTC, BonusTC>&)>& func = nullptr)
      : RawRule<CommonTN, BonusTN, CommonTC, BonusTC>(rule_name, points, func),
        excluded_tiles_vct_(excluded_tiles_vct),
        full_tiletype_counter_set_(full_tiletype_counter_set) {}

  bool checkIfTiletypeCounterShouldBeExcluded(CommonTC tiletype_counter, CommonTC excluded_tiletype_counter) {
    assert(tiletype_counter.counter_.size() == excluded_tiletype_counter.counter_.size());
    for (uint idx = 0; idx < tiletype_counter.counter_.size(); idx += 1) {
      if (std::min(tiletype_counter.counter_[idx], excluded_tiletype_counter.counter_[idx])) {
        return true;
      }
    }
    return false;
  }

  std::unordered_set<CommonTC> compile() {
    std::vector<CommonTC> excluded_tiletype_counters;
    for (auto excluded_tiles : excluded_tiles_vct_) {
      excluded_tiletype_counters.emplace_back(excluded_tiles);
    }

    std::unordered_set<CommonTC> tiletype_counter_set;
    for (auto tiletype_counter : full_tiletype_counter_set_) {
      bool should_be_excluded = false;
      for (auto excluded_tiletype_counter : excluded_tiletype_counters) {
        should_be_excluded |= checkIfTiletypeCounterShouldBeExcluded(tiletype_counter, excluded_tiletype_counter);
      }
      if (!should_be_excluded) {
        tiletype_counter_set.emplace(tiletype_counter);
      }
    }
    return tiletype_counter_set;
  }

  const std::vector<std::vector<Tiletype>> excluded_tiles_vct_;
  const std::unordered_set<CommonTC>& full_tiletype_counter_set_;
};

#endif  // MAHJONG_LEARNING_C_RULES_RAW_DECREMENTAL_RULE_H_
