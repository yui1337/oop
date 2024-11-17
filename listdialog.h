#pragma once
#include <sstream>
#include "headers.h"
#include "vector_3d.h"

class ListDialog : public TDialog {
private:
  std::vector<Vector> _items;

  TDeskTop* _desktop;
  TListBox* _listBox;
  TInputLine* _newItemInputLine;
  std::vector<TInputLine*> _itemInputLines { std::vector<TInputLine*>(4) };

  static TStringCollection* to_string_collection(const std::vector<Vector>& items);

  void addItem();
  void delItem();

public:
  static const ushort cmCustomAdd = 100;
  static const ushort cmCustomDel = 101;

  ListDialog(TDeskTop* desktop, const TRect& bounds, TStringView title);

  ListDialog(const ListDialog&) = delete;

  ListDialog& operator=(const ListDialog&) = delete;

  void handleEvent(TEvent &event) override;
};
