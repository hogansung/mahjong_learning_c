//
// Created by Hao-En Sung on 12/21/21.
//

#ifndef MAHJONG_LEARNING_C_RULES_RULE_H_
#define MAHJONG_LEARNING_C_RULES_RULE_H_

class Rule {
 public:
  Rule(std::vector<std::vector<unsigned int>> tiletype_counters, unsigned int points) {
    tiletype_counters_ = tiletype_counters;
    points_ = points;
  }

  std::vector<std::vector<unsigned int>> tiletype_counters_;
  unsigned int points_;
};

#endif  // MAHJONG_LEARNING_C_RULES_RULE_H_
