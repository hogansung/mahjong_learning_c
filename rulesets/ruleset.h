//
// Created by Hao-En Sung on 12/21/21.
//

#ifndef MAHJONG_LEARNING_C_RULESETS_RULESET_H_
#define MAHJONG_LEARNING_C_RULESETS_RULESET_H_

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/bitset.hpp>
#include <filesystem>

#include "enums/tiletype.h"
#include "rules/raw_rule.h"

template <uint CommonTN, uint BonusTN, class CommonTC = TiletypeCounter<CommonTN>,
          class BonusTC = TiletypeCounter<BonusTN>>
class Ruleset {
 public:
  Ruleset() {}
  ~Ruleset() {
    for (auto rule_ptr : rule_ptr_vct_) {
      delete rule_ptr;
    }
  }

  void compileRawRules(std::vector<RawRule<CommonTN, BonusTN, CommonTC, BonusTC>*> raw_rule_ptr_vct) {
    std::string cached_folder_path = std::string("caches/") + getCachedTiletypeCountersByRulesPath();
    for (auto raw_rule_ptr : raw_rule_ptr_vct) {
      std::string cached_file_path = cached_folder_path + "/" + raw_rule_ptr->rule_name_ + ".bin";
      std::unordered_set<CommonTC> tiletype_counter_set;
      if (std::filesystem::exists(cached_file_path)) {
        std::ifstream ifs(cached_file_path.c_str(), std::ios::binary);
        if (ifs) {
          boost::archive::binary_iarchive ia(ifs);
          ia >> tiletype_counter_set;
          std::cout << "Loading tiletype counters for rule " + raw_rule_ptr->rule_name_ << " succeeds" << std::endl;
        } else {
          std::cerr << "Loading tiletype counters for rule " + raw_rule_ptr->rule_name_ << " fails" << std::endl;
        }
      } else {
        tiletype_counter_set = raw_rule_ptr->compile(getTileset(), getTileNum());
        std::ofstream ofs(cached_file_path.c_str(), std::ios::binary);
        if (ofs) {
          boost::archive::binary_oarchive oa(ofs);
          oa << tiletype_counter_set;
          std::cerr << "Saving tiletype counters for rule " + raw_rule_ptr->rule_name_ << " succeeds" << std::endl;
        } else {
          std::cerr << "Saving tiletype counters for rule " + raw_rule_ptr->rule_name_ << " fails" << std::endl;
        }
      }
      std::cout << raw_rule_ptr->rule_name_ << " has " << tiletype_counter_set.size() << " combinations" << std::endl;
      rule_ptr_vct_.emplace_back(new Rule<CommonTN, BonusTN, CommonTC, BonusTC>(
          raw_rule_ptr->rule_name_, raw_rule_ptr->points_, tiletype_counter_set, raw_rule_ptr->func_));
    }
  }

  virtual const Tileset& getTileset() = 0;
  virtual uint getTileNum() = 0;
  virtual const std::string& getCachedTiletypeCountersByRulesPath() = 0;

  std::unordered_set<CommonTC> tiletype_counter_set_for_four_sets_one_pair_;
  std::unordered_set<CommonTC> tiletype_counter_set_for_seven_pairs_;
  std::vector<Rule<CommonTN, BonusTN, CommonTC, BonusTC>*> rule_ptr_vct_;
};

#endif  // MAHJONG_LEARNING_C_RULESETS_RULESET_H_
