//
// Created by hungr on 2022/05/18.
//

#include <ui/MainWindow.h>
#include <iostream>

void hwml_engine::ui::MainWindow::on_realize() {
    Widget::on_realize();

    set_title("HyperWorld-Markup-Language-Engine");
    set_default_size(800, 500);

    vbox.pack_start(url_entry, false, true, 0);
    vbox.pack_start(page_area, true, true, 0);

    add(vbox);

    show_all();

    url_entry.signal_key_press_event().connect([this] (GdkEventKey* e) -> bool {
        if(e != nullptr && e->keyval == GDK_KEY_Return) {
            auto url = url_entry.get_buffer()->get_text();
            on_url_determined(url);
        }
        return false;
    }, false);

    page_area.set_required_version(4, 6);
    page_area.signal_realize().connect(sigc::mem_fun(*this, &MainWindow::on_glarea_realize));
    page_area.signal_unrealize().connect(sigc::mem_fun(*this, &MainWindow::on_glarea_unrealize), false);
    page_area.signal_render().connect(sigc::mem_fun(*this, &MainWindow::on_glarea_render), false);
}

void hwml_engine::ui::MainWindow::on_url_determined(const Glib::ustring &url) {
    page_area.queue_draw();
}

void hwml_engine::ui::MainWindow::on_glarea_realize() {
    page_area.make_current();
    try {
        page_area.set_has_depth_buffer();
        page_area.throw_if_error();
    } catch (const Gdk::GLError& gle) {
        std::cerr << "Failed to initialize OpenGL";
    }
}

void hwml_engine::ui::MainWindow::on_glarea_unrealize() {
    page_area.make_current();
    try {
        page_area.throw_if_error();
    } catch (const Gdk::GLError& gle) {
        std::cerr << "Failed to finalize OpenGL";
    }
}

bool hwml_engine::ui::MainWindow::on_glarea_render(const Glib::RefPtr<Gdk::GLContext>& ctx) {
    try {
        page_area.throw_if_error();

        return true;
    } catch(const Gdk::GLError& gle) {
        std::cerr << "Failed to render" << std::endl;
        return false;
    }
}

