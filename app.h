#pragma once
#include "headers.h"
#include "listdialog.h"

class App : public TApplication {
public:
  App() :
    TProgInit(
      &App::initStatusLine,
      nullptr,
      &App::initDeskTop
    )
  { }

  App(const App&) = delete;

  App& operator=(const App&) = delete;

  void handleEvent(TEvent &event) override;

private:
  void newWindow();

  static TStatusLine* initStatusLine(TRect r);

  static TDeskTop* initDeskTop(TRect r);
};
