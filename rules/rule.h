//
// Created by Hao-En Sung on 12/22/21.
//

#ifndef MAHJONG_LEARNING_C_RULES_RULE_H_
#define MAHJONG_LEARNING_C_RULES_RULE_H_

#include <tiletype_counter.h>

#include <string>
#include <unordered_set>

#include "state.h"

template <uint CommonTN, uint BonusTN, class CommonTC = TiletypeCounter<CommonTN>,
          class BonusTC = TiletypeCounter<BonusTN>>
class Rule {
 public:
  Rule(std::string rule_name, uint points,
       std::unordered_set<CommonTC> tiletype_counter_set = std::unordered_set<CommonTC>(),
       const std::function<bool(const State<CommonTN, BonusTN, CommonTC, BonusTC>&)>& func = nullptr)
      : rule_name_(rule_name), points_(points), tiletype_counter_set_(tiletype_counter_set), func_(func) {
    rule_size_ += 1;
  }

  uint checkIfTriggered(const State<CommonTN, BonusTN, CommonTC, BonusTC>& state) {
    bool is_successful = true;
    is_successful &= (tiletype_counter_set_.size() == 0 or
                      tiletype_counter_set_.find(state.common_tiletype_counter_) != tiletype_counter_set_.end());
    is_successful &= (func_ == nullptr or func_(state));
    return is_successful ? points_ : 0;
  }

  const std::string rule_name_;
  const uint points_;
  const std::unordered_set<CommonTC> tiletype_counter_set_;
  const std::function<bool(const State<CommonTN, BonusTN, CommonTC, BonusTC>&)> func_;

  inline static uint rule_size_ = 0;
};

#endif  // MAHJONG_LEARNING_C_RULES_RULE_H_
