#include <tilesets/guangdong_tileset.h>

#include <iostream>

#include "rulesets/guangdong_ruleset.h"

int main() {
  GuangdongRuleset ruleset = GuangdongRuleset();
  GuangdongTileset tileset = GuangdongTileset();
  std::cout << tileset.tiletypes_.size() << std::endl;
  std::cout << tileset.pairs_.size() << std::endl;
  std::cout << tileset.sequences_.size() << std::endl;
  std::cout << tileset.triplets_.size() << std::endl;
  std::cout << ruleset.rules_.size() << std::endl;
  std::cout << ruleset.rules_[0].tiletype_counters_.size() << std::endl;
  return 0;
}
