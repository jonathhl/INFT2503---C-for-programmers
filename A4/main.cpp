#include <gtkmm.h>

class Window : public Gtk::Window {
public:
  Gtk::VBox vbox;
  Gtk::Label fNameLabel;
  Gtk::Label lNameLabel;
  Gtk::Entry fName;
  Gtk::Entry lName;
  Gtk::Button button;
  Gtk::Label label;

  Window() {
      set_title("Øving 4 - oppg 2");
      set_size_request(400);
    button.set_label("Click here");
    fNameLabel.set_label("First name");
    lNameLabel.set_label("Last name");
    button.set_sensitive(false);

    vbox.pack_start(fNameLabel);
    vbox.pack_start(fName);
    vbox.pack_start(lNameLabel);
    vbox.pack_start(lName);
    vbox.pack_start(button);
    vbox.pack_start(label);

    add(vbox);  //Add vbox to window
    show_all(); //Show all widgets

    fName.signal_activate().connect([this]() {
        if(fName.get_text().length() == 0) button.set_sensitive(false);
        if(fName.get_text().length() > 0 && lName.get_text().length() > 0) button.set_sensitive(true);
    });

    lName.signal_activate().connect([this]() {
        if(lName.get_text().length() == 0) button.set_sensitive(false);
        if(fName.get_text().length() > 0 && lName.get_text().length() > 0) button.set_sensitive(true);
    });

    button.signal_clicked().connect([this]() {
      label.set_text(fName.get_text() + " " + lName.get_text());
    });
  }
};

int main() {
  Gtk::Main gtk_main;
  Window window;
  gtk_main.run(window);
}
