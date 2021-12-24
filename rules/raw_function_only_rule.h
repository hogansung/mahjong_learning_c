//
// Created by Hao-En Sung on 12/24/21.
//

#ifndef MAHJONG_LEARNING_C_RULES_RAW_FUNCTION_ONLY_RULE_H_
#define MAHJONG_LEARNING_C_RULES_RAW_FUNCTION_ONLY_RULE_H_

template <uint CommonTN, uint BonusTN, class CommonTC = TiletypeCounter<CommonTN>,
          class BonusTC = TiletypeCounter<BonusTN>>
class RawFunctionOnlyRule : public RawRule<CommonTN, BonusTN, CommonTC, BonusTC> {
 public:
  RawFunctionOnlyRule(const std::string rule_name, const uint points,
                      const std::function<bool(const State<CommonTN, BonusTN, CommonTC, BonusTC>&)>& func = nullptr)
      : RawRule<CommonTN, BonusTN, CommonTC, BonusTC>(rule_name, points, func) {}

  std::unordered_set<CommonTC> compile(const Tileset& tileset, const uint tile_num) {
    return std::unordered_set<CommonTC>();
  };
};

#endif  // MAHJONG_LEARNING_C_RULES_RAW_FUNCTION_ONLY_RULE_H_
