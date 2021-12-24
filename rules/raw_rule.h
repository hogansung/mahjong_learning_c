//
// Created by Hao-En Sung on 12/21/21.
//

#ifndef MAHJONG_LEARNING_C_RULES_RAW_RULE_H_
#define MAHJONG_LEARNING_C_RULES_RAW_RULE_H_

#include <unordered_set>

template <uint CommonTN, uint BonusTN, class CommonTC = TiletypeCounter<CommonTN>,
          class BonusTC = TiletypeCounter<BonusTN>>
class RawRule {
 public:
  RawRule(const std::string rule_name, const uint points,
          const std::function<bool(const State<CommonTN, BonusTN, CommonTC, BonusTC>&)>& func = nullptr)
      : rule_name_(rule_name), points_(points), func_(func) {}
  virtual ~RawRule() {}

  virtual std::unordered_set<CommonTC> compile(const Tileset& tileset, const uint tile_num) = 0;

  const std::string rule_name_;
  const uint points_;
  const std::function<uint(const State<CommonTN, BonusTN, CommonTC, BonusTC>&)> func_;
};

#endif  // MAHJONG_LEARNING_C_RULES_RAW_RULE_H_
