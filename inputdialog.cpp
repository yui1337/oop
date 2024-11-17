#include "inputdialog.h"

const char* TITLE = "New Vector";
std::vector<const char*> fields = {"X:", "Y:", "Z:", "b:"};
int INP_LEN = 5;

TRect InputDialog::center(const TRect& parentBounds, const int messageSize) {
  const TPoint parentSize = {
    parentBounds.b.x - parentBounds.a.x,
    parentBounds.b.y - parentBounds.a.y
  };

  const TPoint size = { messageSize + 5 , 15 };

  return TRect(
    (parentBounds.b.x - size.x) / 2,
    (parentBounds.b.y - size.y) / 2,
    (parentBounds.b.x + size.x) / 2,
    (parentBounds.b.y + size.y) / 2
  );
}

InputDialog::InputDialog(const TRect& parentBounds, std::vector<TInputLine*>& itemInputLines) :
  _itemInputLines(itemInputLines),
  TDialog(center(parentBounds, static_cast<int>( strlen(TITLE) ) + INP_LEN + 10), TITLE),
  TWindowInit(TWindow::initFrame)
{
  for (size_t i = 0; i < fields.size(); ++i) {
    const auto inpI = new TStaticText(TRect( 2, 2 + 2 * i, 4, 3 * std::pow(2, i) ), fields[i]);
    _itemInputLines[i] = new TInputLine(TRect(5, 2 + 2 * i, size.x - 2, 3 + 2 * i), 8);

    insert(inpI);
    insert(_itemInputLines[i]);
  }

  const auto okButton = new TButton(TRect(1, 8, size.x / 3 - 1, 10), "Ok", cmCustomOk, bfNormal);
  const auto cancelButton = new TButton(TRect(size.x / 3 + 1, 8, size.x / 3 + 11, 10), "Cancel", cmCancel, bfNormal);

  insert(okButton);
  insert(cancelButton);

}

void InputDialog::handleEvent(TEvent &event) {
  TWindow::handleEvent(event);

  if (event.what == evCommand && event.message.command == cmCustomOk) {
    try {
      for (size_t i = 0; i < 4; ++i) {
        std::stod( std::string(_itemInputLines[i]->data) );
      }
      endModal(cmCancel);
    } catch (const std::exception&) {
      const auto errorText = new TStaticText(TRect(size.x / 3 + 1, 10, size.x / 3 + 11, 13), "Error! Check your fields.");
      insert(errorText);
      return;
    }
  } else if (event.what == evCommand && event.message.command == cmCancel) {
    for (size_t i = 0; i < 4; ++i) { _itemInputLines[i] = nullptr; }
    endModal(cmCancel);
  }
}
