#pragma once
#include "headers.h"

class MessageDialog : public TDialog {
private:
  static TRect center(const TRect& parentBounds, const int messageSize);

public:
  MessageDialog(const TRect& parentBounds, const std::string& title, const std::string& message);
};
