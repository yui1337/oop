#pragma once
#include <cmath>
#include "headers.h"

class InputDialog : public TDialog {
private:
  static TRect center(const TRect& parentBounds, const int messageSize);
  std::vector<TInputLine*>& _itemInputLines;

public:
  static const ushort cmCustomOk = 102;

  InputDialog(const TRect& parentBounds, std::vector<TInputLine*>& itemInputLines);

  void handleEvent(TEvent &event) override;
};
