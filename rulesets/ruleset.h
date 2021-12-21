//
// Created by Hao-En Sung on 12/21/21.
//

#ifndef MAHJONG_LEARNING_C_RULESETS_RULESET_H_
#define MAHJONG_LEARNING_C_RULESETS_RULESET_H_

#include "enums/tiletype.h"
#include "rules/rule.h"

class Ruleset {
 public:
  Ruleset(std::vector<Rule> rules) : rules_(rules) {}

  static void retrieveConditionsWithExistingRequirementsAndConstraints(
      std::vector<Tiletype>& requirements, unsigned int pair_idx, unsigned int pair_num,
      unsigned int sequence_idx, unsigned int sequence_num, unsigned int triplet_idx,
      unsigned int triplet_num, std::vector<std::vector<Tiletype>>& retrieved_conditions) {
    if (pair_num == 0 and sequence_num == 0 and triplet_num == 0) {
      retrieved_conditions.emplace_back(requirements);
    } else if (pair_num == 0 and sequence_num == 0) {
      for (unsigned triplet_c_idx = triplet_idx; triplet_c_idx < Ruleset::tileset.triplets_.size();
           triplet_c_idx += 1) {
        pushBackThreeSet(requirements, Ruleset::tileset.triplets_[triplet_c_idx]);
        retrieveConditionsWithExistingRequirementsAndConstraints(
            requirements, pair_idx, pair_num, sequence_idx, sequence_num, triplet_c_idx + 1,
            triplet_num - 1, retrieved_conditions);
        popBackThreeSet(requirements);
      }
    } else if (pair_num == 0) {
      for (unsigned sequence_c_idx = sequence_idx;
           sequence_c_idx < Ruleset::tileset.sequences_.size(); sequence_c_idx += 1) {
        pushBackThreeSet(requirements, Ruleset::tileset.sequences_[sequence_c_idx]);
        retrieveConditionsWithExistingRequirementsAndConstraints(
            requirements, pair_idx, pair_num, sequence_c_idx, sequence_num - 1, triplet_idx,
            triplet_num, retrieved_conditions);
        popBackThreeSet(requirements);
      }
    } else {
      for (unsigned pair_c_idx = pair_idx; pair_c_idx < Ruleset::tileset.pairs_.size();
           pair_c_idx += 1) {
        pushBackTwoSet(requirements, Ruleset::tileset.pairs_[pair_c_idx]);
        retrieveConditionsWithExistingRequirementsAndConstraints(
            requirements, pair_c_idx + 1, pair_num - 1, sequence_idx, sequence_num, triplet_idx,
            triplet_num, retrieved_conditions);
        popBackTwoSet(requirements);
      }
    }
  }

  static std::vector<std::vector<Tiletype>>
  generateConditionsWithExistingRequirementsAndMinMaxConstraints(
      std::vector<Tiletype> existing_requirements,
      std::tuple<unsigned int, unsigned int> pair_num_constraint,
      std::tuple<unsigned int, unsigned int> sequence_num_constraint,
      std::tuple<unsigned int, unsigned int> triplet_num_constraint, unsigned int max_tile_num) {
    std::vector<std::vector<Tiletype>> list_of_requirements;
    for (unsigned int pair_num = get<0>(pair_num_constraint);
         pair_num <= get<1>(pair_num_constraint); pair_num += 1) {
      for (unsigned int sequence_num = get<0>(sequence_num_constraint);
           sequence_num <= get<0>(sequence_num_constraint); sequence_num += 1) {
        if (pair_num * 2 + sequence_num * 3 > max_tile_num) {
          break;
        }
        for (unsigned int triplet_num = get<0>(triplet_num_constraint);
             triplet_num <= get<0>(triplet_num_constraint); triplet_num += 1) {
          if (pair_num * 2 + sequence_num * 3 + triplet_num * 3 != max_tile_num) {
            continue;
          }
          retrieveConditionsWithExistingRequirementsAndConstraints(
              existing_requirements, 0, pair_num, 0, sequence_num, 0, triplet_num,
              list_of_requirements);
        }
      }
    }
    return list_of_requirements;
  }

  static bool checkIfTiletypeCounterIsValid(std::vector<unsigned int> tiletype_counter) {
    for (unsigned int idx = 0; idx < tileset.tiletype_index; idx += 1) {
      if (tiletype_counter[idx] > tileset.tiletype_limit[idx]) {
        return false;
      }
    }
    return true;
  }

  static std::vector<std::vector<unsigned int>> createTiletypeCounterFromListOfRequirement(
      std::vector<std::vector<std::vector<Tiletype>>> list_of_list_of_requirements) {
    std::cout << "zz " << list_of_list_of_requirements[0].size() << std::endl;
    std::vector<std::vector<unsigned int>> tiletype_counters;
    for (auto list_of_requirements : list_of_list_of_requirements) {
      for (auto requirements : list_of_requirements) {
        std::vector<unsigned int> tiletype_counter(tileset.tiletype_index, 0);
        for (auto tiletype : requirements) {
          tiletype_counter[tileset.tiletype_to_index.at(tiletype)] += 1;
        }
        if (checkIfTiletypeCounterIsValid(tiletype_counter)) {
          tiletype_counters.emplace_back(tiletype_counter);
        }
      }
    }
    return tiletype_counters;
  }

  static Tileset tileset;

  std::vector<Rule> rules_;
};

#endif  // MAHJONG_LEARNING_C_RULESETS_RULESET_H_
