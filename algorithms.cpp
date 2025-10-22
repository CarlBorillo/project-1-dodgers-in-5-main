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
#include <optional> // for std::optional
#include <unordered_map>
#include <span>

std::vector<int>::const_iterator algorithms::find_dip(const std::vector<int>& values) {

  // TODO: Rewrite the body of this function so that it actually works. That
  // includes rewriting the return statement. After you do that, delete this
  // comment.
  return values.end();
}

std::optional<algorithms::span> algorithms::longest_balanced_span(const std::vector<int>& values) {



    std::unordered_map<long long, int> first_seen;   // prefix sum → earliest position (+1)
    first_seen.reserve(values.size() * 2 + 1);
    first_seen[0] = 0;                               // zero sum occurs "before" index 0

    long long running_sum = 0;
    int left_best  = -1;
    int right_best = -1;
    int width_best = 0;

    const int n = static_cast<int>(values.size());
    for (int i = 0; i < n; ++i) {
        running_sum += static_cast<long long>(values[i]);

        auto iter = first_seen.find(running_sum);
        if (iter == first_seen.end()) {
            // First occurrence of this running sum
            first_seen.emplace(running_sum, i + 1);
        } else {
            // Repeated sum: range [iter->second, i+1) sums to zero
            const int start = iter->second;
            const int end   = i + 1;
            const int span_len = end - start;

            // Update if longer, or same length but starts later (prefer "last" span)
            if (span_len > width_best || (span_len == width_best && start > left_best)) {
                width_best  = span_len;
                left_best   = start;
                right_best  = end;
            }
        }
    }

    if (width_best == 0) {
        return std::nullopt;
    }
    return span(values.begin() + left_best, values.begin() + right_best);
}



std::string algorithms::telegraph_style(const std::string& s) {

  // TODO: Rewrite the body of this function so that it actually works. That
  // includes rewriting the return statement. After you do that, delete this
  // comment.
  return "";
}
