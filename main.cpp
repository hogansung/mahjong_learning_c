#include <rules/rule.h>
#include <tilesets/guangdong_tileset.h>

#include <boost/serialization/unordered_set.hpp>
#include <boost/serialization/vector.hpp>
#include <fstream>
#include <iostream>

#include "guangdong_common_tiletype_counter.h"
#include "rulesets/guangdong_ruleset.h"
#include "tiletype_counter.h"

int main() {
  GuangdongRuleset ruleset = GuangdongRuleset();
  //  GuangdongTileset tileset = GuangdongTileset();
  //  //  std::cout << tileset.tiletypes_.size() << std::endl;
  //  //  std::cout << tileset.pairs_.size() << std::endl;
  //  //  std::cout << tileset.sequences_.size() << std::endl;
  //  //  std::cout << tileset.triplets_.size() << std::endl;
  //  std::cout << ruleset.rules_.size() << std::endl;
  //  for (auto rule : ruleset.rules_) {
  //    std::cout << "Rule " << rule.rule_name_ << " has " << rule.tiletype_counters_.size() << " matches." <<
  //    std::endl;
  //  }
  //
  //  std::cout << ruleset.tiletype_counters_for_four_sets_one_pair_.size() << std::endl;
  //  std::cout << ruleset.tiletype_counters_for_seven_pairs_.size() << std::endl;

  //  GuangdongCommonTiletypeCounter tiletype_counter;
  //  std::cout << tiletype_counter.counter_.size() << std::endl;

  return 0;
}
