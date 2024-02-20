#ifndef FOOD_WASTAGE_REPORT_H_
#define FOOD_WASTAGE_REPORT_H_
#include <iostream>
#include <map>
#include <string>
#include <unordered_set>
#include <vector>

#include "food_wastage_record.h"

// Please fill in below.
// Daniel Lee
// CPSC 121L=13
// 12/1/2023
// arcjak@csu.fullerton.edu
// arcjak

class FoodWastageReport {
  // ======================= YOUR CODE HERE =======================
  // Write the FoodWastageReport class here. Refer to your class design for the
  // member variables, constructors, and member functions needed.
  //
  // Note: mark functions that do not modify the member variables
  // as const, by writing `const` after the parameter list.
  // Pass objects by const reference when appropriate.
  // Remember that std::string is an object!
  // ===============================================================

 public:
  FoodWastageReport(
      const std::vector<FoodWastageRecord> &food_wastage_records) {
    food_wastage_records_ = food_wastage_records;
  }

  std::vector<std::string> MostCommonlyWastedFoods() {
    std::map<std::string, int> most_;

    for (std::vector<FoodWastageRecord>::iterator it =
             food_wastage_records_.begin();
         it != food_wastage_records_.end(); it++) {
      most_[it->FoodName()]++;
    }
    int max_wasted = 0;
    for (auto [key, value] : most_) {
      if (value == max_wasted) {
        most_commonly_wasted_foods_.push_back(key);
      } else if (value > max_wasted) {
        most_commonly_wasted_foods_.clear();
        most_commonly_wasted_foods_.push_back(key);
        max_wasted = value;
      } else {
        continue;
      }
    }
    return most_commonly_wasted_foods_;
  }

  std::vector<std::string> MostCostlyWasteProducingMeals() {
    std::map<std::string, double> most_costly;

    for (std::vector<FoodWastageRecord>::iterator it =
             food_wastage_records_.begin();
         it != food_wastage_records_.end(); it++) {
      most_costly[it->Meal()] += it->Cost();
    }
    double cost_wasted = 0;
    for (auto [key, value] : most_costly) {
      if (most_costly_waste_producing_meals_.size() == 0) {
        most_costly_waste_producing_meals_.push_back(key);
        cost_wasted = value;
      } else if (value > cost_wasted) {
        most_costly_waste_producing_meals_.clear();
        most_costly_waste_producing_meals_.push_back(key);
        cost_wasted = value;

      } else if (value == cost_wasted) {
        most_costly_waste_producing_meals_.push_back(key);
      }
      std::cout << key << "  " << value << "  " << cost_wasted << std::endl;
    }
    for (int i = 0; i < most_costly_waste_producing_meals_.size(); i++) {
      std::cout << most_costly_waste_producing_meals_[i] << std::endl;
    }
    return most_costly_waste_producing_meals_;
  }

  double TotalCostOfFodWasted() {
    for (std::vector<FoodWastageRecord>::iterator it =
             food_wastage_records_.begin();
         it != food_wastage_records_.end(); it++) {
      total_cost_of_food_wasted_ += it->Cost();
    }
    return total_cost_of_food_wasted_;
  }

  std::vector<std::string> MostCommonWastageReasons() {
    std::map<std::string, int> most_reason;

    for (std::vector<FoodWastageRecord>::iterator it =
             food_wastage_records_.begin();
         it != food_wastage_records_.end(); it++) {
      most_reason[it->WastageReason()]++;
    }
    int max_reason = 0;
    for (auto [key, value] : most_reason) {
      if (value == max_reason) {
        most_common_wastage_reasons_.push_back(key);
      } else if (value > max_reason) {
        most_common_wastage_reasons_.clear();
        most_common_wastage_reasons_.push_back(key);
        max_reason = value;
      } else {
        continue;
      }
    }
    return most_common_wastage_reasons_;
  }

  std::vector<std::string> MostCommonDisposalMechanisms() {
    std::map<std::string, int> most_mechanism;

    for (std::vector<FoodWastageRecord>::iterator it =
             food_wastage_records_.begin();
         it != food_wastage_records_.end(); it++) {
      most_mechanism[it->DisposalMechanism()]++;
    }
    int max_mechanism = 0;
    for (auto [key, value] : most_mechanism) {
      if (value == max_mechanism) {
        most_common_disposal_mechanisms_.push_back(key);
      } else if (value > max_mechanism) {
        most_common_disposal_mechanisms_.clear();
        most_common_disposal_mechanisms_.push_back(key);
        max_mechanism = value;
      }
    }
    return most_common_disposal_mechanisms_;
  }

  std::vector<std::string> SuggestWasteReductionStrategies() {
    std::unordered_set<std::string> reasons;

    for (int i = 0; i < most_common_wastage_reasons_.size(); i++) {
      if (most_common_wastage_reasons_[i] == "Expired") {
        reasons.insert("Donate before expiration");

      }

      else if (most_common_wastage_reasons_[i] == "Tastes bad") {
        reasons.insert("Buy less food");
        reasons.insert("Recycle left overs");

      }

      else if (most_common_wastage_reasons_[i] == "Too much left overs") {
        reasons.insert("Buy less food");
        reasons.insert("Cook small servings");
        reasons.insert("Recycle left overs");
      }
    }

    if (most_common_wastage_reasons_.size() == 3) {
      reasons.erase("Recycle left overs");
    }
    std::vector<std::string> suggested_strategies_to_reduce_waste_(
        reasons.size());
    copy(reasons.begin(), reasons.end(),
         suggested_strategies_to_reduce_waste_.begin());

    return suggested_strategies_to_reduce_waste_;
  }

 private:
  std::vector<FoodWastageRecord> food_wastage_records_;
  std::vector<std::string> most_commonly_wasted_foods_;
  std::vector<std::string> most_costly_waste_producing_meals_;
  double total_cost_of_food_wasted_ = 0;
  std::vector<std::string> most_common_wastage_reasons_;
  std::vector<std::string> most_common_disposal_mechanisms_;
  std::vector<std::string> suggested_strategies_to_reduce_waste_;
};

#endif