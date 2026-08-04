#pragma once

#include <string>
#include <vector>

bool EnterToNextPage(const std::string& skip_target);

void EndingScroll(const std::vector<std::string>& lines);

void ShowAllAtOnce(const std::vector<std::string>& lines);

void DelayShowAllAtOnce(const std::vector<std::string>& lines);
