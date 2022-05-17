extern crate gtk;

use gtk::prelude::*;
use gtk::{Application, ApplicationWindow};

fn build_ui(app: &gtk::Application) {
    let url_entry = gtk::Entry::new();

    let _hbox = gtk::Box::builder()
        .orientation(gtk::Orientation::Horizontal)
        .build();
    let render_area = gtk::GLArea::builder()
        .width_request(800)
        .build();
    _hbox.pack_start(&render_area, false, true, 0);

    let _vbox = gtk::Box::builder()
        .orientation(gtk::Orientation::Vertical)
        .build();
    _vbox.pack_start(&url_entry, false, true, 0);
    _vbox.pack_start(&_hbox, true, true, 0);

    let win = ApplicationWindow::builder()
        .application(app)
        .default_width(800)
        .default_height(500)
        .title("HyperWorld-Markup-Language-Engine")
        .child(&_vbox)
        .build();   
    
    win.show_all();
}

fn main() {
    let app = Application::builder()
        .application_id("com.github.asuka1975.HyperWorld-Markup-Language-Engine")
        .build();

    app.connect_activate(build_ui);

    app.run();
}
