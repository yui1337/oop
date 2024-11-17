cmake_minimum_required(VERSION 3.5)

project(lab5 CXX)

set(CMAKE_CXX_STANDARD 17)


include(FetchContent)

FetchContent_Declare(
  tvision
  GIT_REPOSITORY https://github.com/magiblot/tvision.git
)

FetchContent_MakeAvailable(tvision)

add_executable(
  lab5
  "main.cpp"
  "vector_3d.cpp"
  "messagedialog.cpp"
  "inputdialog.cpp"
  "listdialog.cpp"
  "app.cpp"
)

target_link_libraries(lab5 tvision)
