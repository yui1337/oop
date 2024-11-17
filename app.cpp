#include "app.h"

void App::handleEvent(TEvent &event) {
  TApplication::handleEvent(event);

  if (event.what == evCommand && event.message.command == cmNew) {
    newWindow();
  }
}

void App::newWindow() {
  const auto window = new ListDialog(deskTop, TRect(0, 0, deskTop->size.x, deskTop->size.y), "LIST");
  deskTop->insert(window);
}


TStatusLine* App::initStatusLine(TRect r) {
  const auto defs = new TStatusDef(
    std::numeric_limits<ushort>::min(),
    std::numeric_limits<ushort>::max()
  );

  *defs
    + *new TStatusItem("~CTRL+X~ Close Program", kbCtrlX, cmQuit)
    + *new TStatusItem("~CTRL+N~ New", kbCtrlN, cmNew);

  r.a.y = r.b.y - 1;

  return new TStatusLine(r, *defs);
}

TDeskTop* App::initDeskTop(TRect r) {
  --r.b.y;
  return new TDeskTop(r);
}
