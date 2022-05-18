//
// Created by hungr on 2022/05/18.
//

#ifndef HYPERWORLD_MARKUP_LANGUAGE_ENGINE_MAINWINDOW_H
#define HYPERWORLD_MARKUP_LANGUAGE_ENGINE_MAINWINDOW_H

#include <gtkmm.h>
#include <gdkmm.h>

namespace hwml_engine::ui {
    class MainWindow : public Gtk::Window {
    public:
        MainWindow() = default;
        ~MainWindow() override = default;

        void on_realize() override;

        void on_url_determined(const Glib::ustring& url);
        void on_glarea_realize();
        void on_glarea_unrealize();
        bool on_glarea_render(const Glib::RefPtr<Gdk::GLContext>& ctx);
    private:
        Gtk::Entry url_entry;
        Gtk::GLArea page_area;
        Gtk::VBox vbox;
    };
}

#endif //HYPERWORLD_MARKUP_LANGUAGE_ENGINE_MAINWINDOW_H
