//
// Created by Hao-En Sung on 12/21/21.
//

#ifndef MAHJONG_LEARNING_C_RULESETS_GUANGDONG_RULESET_H_
#define MAHJONG_LEARNING_C_RULESETS_GUANGDONG_RULESET_H_

#include <vector>

#include "rules/condition.h"
#include "rules/rule.h"
#include "rulesets/ruleset.h"

class GuangdongRuleset : Ruleset {
  std::vector<Rule> ruleset;

  std::vector<Condition> ping_conditions;

};

#endif  // MAHJONG_LEARNING_C_RULESETS_GUANGDONG_RULESET_H_
