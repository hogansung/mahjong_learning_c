//
// Created by Hao-En Sung on 12/21/21.
//

#ifndef MAHJONG_LEARNING_C_RULES_RULE_H_
#define MAHJONG_LEARNING_C_RULES_RULE_H_

class Rule {
 public:
  Rule(std::string rule_name, std::vector<std::vector<uint>> tiletype_counters, uint points) {
    rule_name_ = rule_name;
    tiletype_counters_ = tiletype_counters;
    points_ = points;
  }

  std::string rule_name_;
  std::vector<std::vector<uint>> tiletype_counters_;
  uint points_;
};

#endif  // MAHJONG_LEARNING_C_RULES_RULE_H_
