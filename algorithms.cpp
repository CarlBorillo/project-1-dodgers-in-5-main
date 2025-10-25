///////////////////////////////////////////////////////////////////////////////
// algorithms.cpp
//
// Definitions for three algorithms:
//
// find_dip
// longest_balanced_span
// telegraph_style
//
///////////////////////////////////////////////////////////////////////////////

#include "algorithms.hpp"
#include <unordered_map>
#include <optional>
#include <vector>
#include <string>

namespace algorithms {


std::vector<int>::const_iterator algorithms::find_dip(const std::vector<int>& values) {

  // TODO: Rewrite the body of this function so that it actually works. That
  // includes rewriting the return statement. After you do that, delete this
  // comment.
  return values.end();
}

std::optional<span> algorithms::longest_balanced_span(const std::vector<int>& V) {

    int n = static_cast<int>(V.size());
    std::optional<span> best = std::nullopt;

    for (int s = 0; s <= n; ++s) {
        for (int e = s + 1; e <= n; ++e) {

            int sum = 0;
            for (int i = s; i < e; ++i) {
                sum += V[i];
            }

            if (sum == 0) {
                if (!best.has_value() ||
                    (e - s) >= static_cast<int>(best->size())) {

                    best = span(V.begin() + s, V.begin() + e);
                }
            }
        }
    }

    return best;
}




std::string algorithms::telegraph_style(const std::string& s) {

  // TODO: Rewrite the body of this function so that it actually works. That
  // includes rewriting the return statement. After you do that, delete this
  // comment.
  return "";
}

} // namespace algorithms
