//
// Created by Hao-En Sung on 12/21/21.
//

#ifndef MAHJONG_LEARNING_C_RULESETS_GUANGDONG_RULESET_H_
#define MAHJONG_LEARNING_C_RULESETS_GUANGDONG_RULESET_H_

#include <vector>

#include "rules/rule.h"
#include "rulesets/ruleset.h"
#include "tilesets/tileset.h"

class GuangdongRuleset : public Ruleset {
 public:
  GuangdongRuleset()
      : Ruleset(std::vector<Rule>{
            Rule(createTiletypeCounterFromListOfRequirement(
                     std::vector<std::vector<std::vector<Tiletype>>>{
                         generateConditionsWithExistingRequirementsAndMinMaxConstraints(
                             std::vector<Tiletype>(), std::tuple<unsigned int, unsigned int>(1, 1),
                             std::tuple<unsigned int, unsigned int>(4, 4),
                             std::tuple<unsigned int, unsigned int>(0, 0), 14)}),
                 0),  // 平
        }) {}
};

Tileset Ruleset::tileset = GuangdongTileset();

#endif  // MAHJONG_LEARNING_C_RULESETS_GUANGDONG_RULESET_H_
