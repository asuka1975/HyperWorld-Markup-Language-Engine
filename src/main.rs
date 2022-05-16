extern crate gtk;

use gtk::prelude::*;
use gtk::{Application, ApplicationWindow};

fn main() {
    let app = Application::builder()
        .application_id("com.github.asuka1975.HyperWorld-Markup-Language-Engine")
        .build();

    app.connect_activate(|app| {
        let win = ApplicationWindow::builder()
            .application(app)
            .default_width(800)
            .default_height(500)
            .title("HyperWorld-Markup-Language-Engine")
            .build();
        win.show_all();
    });

    app.run();
}
