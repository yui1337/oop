#include "messagedialog.h"

TRect MessageDialog::center(const TRect& parentBounds, const int messageSize) {
  const TPoint parentSize = {
    parentBounds.b.x - parentBounds.a.x,
    parentBounds.b.y - parentBounds.a.y
  };

  const TPoint size = { messageSize + 5 , 8 };

  return TRect(
    (parentBounds.b.x - size.x) / 2,
    (parentBounds.b.y - size.y) / 2,
    (parentBounds.b.x + size.x) / 2,
    (parentBounds.b.y + size.y) / 2
  );
}

MessageDialog::MessageDialog(const TRect& parentBounds, const std::string& title, const std::string& message) :
  TDialog(center(parentBounds, static_cast<int>(message.size())), title.c_str()),
  TWindowInit(TWindow::initFrame)
{
  const auto staticText = new TStaticText(TRect(2, 2, size.x - 1, 3), message.c_str());
  insert(staticText);

  const auto button = new TButton(TRect(size.x - 8, 4, size.x - 2, 6), "Ok", cmOK, bfNormal);
  insert(button);
}
