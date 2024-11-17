#include "listdialog.h"
#include "messagedialog.h"
#include "inputdialog.h"
#include "vector_3d.h"


TStringCollection* ListDialog::to_string_collection(const std::vector<Vector>& items) {
  const auto stringCollection = new TStringCollection(static_cast<short>(items.size()), 0);

  for (size_t i = 0; i < items.size(); ++i) {
    std::ostringstream oss;
    oss << items[i];

    char* rawString = new char[oss.str().size() + 1];
    strcpy(rawString, oss.str().c_str());
    stringCollection->atInsert(static_cast<ccIndex>(i), rawString);
  }
  return stringCollection;
}


void ListDialog::addItem() {
  const auto dialog = new InputDialog( this->getBounds(), _itemInputLines );
  _desktop->execView(dialog);

  if ( !(_itemInputLines[0] && _itemInputLines[1] && _itemInputLines[2]) ) { return; }

  double x = std::stod( std::string(_itemInputLines[0]->data) );
  double y = std::stod( std::string(_itemInputLines[1]->data) );
  double z = std::stod( std::string(_itemInputLines[2]->data) );
  double b = std::stod( std::string(_itemInputLines[2]->data) );
  _items.push_back( Vector(x,y,z) ) ;
  _listBox->newList(to_string_collection(_items));
}


void ListDialog::delItem() {
  int idx = 0;

  try {
    idx = std::stoi( std::string(_itemInputLines[3]->data) );
  } catch (const std::exception&) {
    const auto dialog = new MessageDialog(this->getBounds(), "Error!", "Incorrect values!");
    _desktop->execView(dialog);
    TObject::destroy(dialog);
    return;
  }

  if ( idx < 0 || idx >= _items.size() ) {
    const auto dialog = new MessageDialog(this->getBounds(), "Error!", "Incorrect idx!");
    _desktop->execView(dialog);
    TObject::destroy(dialog);
    return;
  }

  _items.erase(_items.begin() + idx);
  _listBox->newList(to_string_collection(_items));
  _itemInputLines[3]->setData(const_cast<void*>(static_cast<const void*>("")));
}


ListDialog::ListDialog(TDeskTop* desktop, const TRect& bounds, TStringView title) :
  TDialog(bounds, title),
  TWindowInit(&TWindow::initFrame),
  _desktop(desktop)
{
  // _listBox
  {
    const auto listBoxText = new TStaticText(TRect(2, 2, size.x - 2, 3), "List of vectors:");
    insert(listBoxText);

    _listBox = new TListBox(TRect(2, 3, size.x - 2, size.y - 4), 1, nullptr);
    insert(_listBox);
  }

  // _newItemInputLine + addButton
  {
    const auto delButton = new TButton(TRect(2, size.y - 3, 30, size.y - 1), "Delete vector from list", cmCustomDel, bfNormal);
    insert(delButton);

    _itemInputLines[3] = new TInputLine(TRect(32, size.y - 3, (size.x / 4) + 12, size.y - 2), 17);
    insert(_itemInputLines[3]);

    const auto addButton = new TButton(TRect(size.x - 24, size.y - 3, size.x - 2, size.y - 1), "Add vector to list", cmCustomAdd, bfNormal);
    insert(addButton);
  }
}


void ListDialog::handleEvent(TEvent &event) {
  TWindow::handleEvent(event);

  if (event.what == evCommand && event.message.command == cmCustomAdd) {
    addItem();
  } else if (event.what == evCommand && event.message.command == cmCustomDel) {
    delItem();
  }
}
