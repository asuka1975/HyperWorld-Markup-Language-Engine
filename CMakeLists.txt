cmake_minimum_required(VERSION 3.16)

project(HyperWorld_Markup_Language_Engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0 -pg")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG -march=native")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtkmm-3.0)
pkg_check_modules(LIBXML REQUIRED libxml++-2.6)

add_executable(HyperWorld_Markup_Language_Engine src/main.cpp include/ui/MainWindow.h src/ui/MainWindow.cpp include/dom/RenderingTree.h include/dom/DocumentObjectModel.h include/dom/CascadingStyleSheetsObjectModel.h src/dom/RenderingTree.cpp)
target_include_directories(HyperWorld_Markup_Language_Engine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include ${GTK3_INCLUDE_DIRS} ${LIBXML_INCLUDE_DIRS})
target_link_directories(HyperWorld_Markup_Language_Engine PRIVATE ${GTK3_LIBRARY_DIRS} ${LIBXML_LIBRARY_DIRS})
target_link_libraries(HyperWorld_Markup_Language_Engine PRIVATE ${GTK3_LIBRARIES} ${LIBXML_LIBRARIES})
add_definitions(${GTK3_CFLAGS_OTHER})