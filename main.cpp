#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WBreak.h>

class HelloApplication : public Wt::WApplication {
    public:
        HelloApplication(const Wt::WEnvironment& env);

    private:
        Wt::WLineEdit *nameEdit_;
        Wt::WText     *greeting_;

        void greet();
};

HelloApplication::HelloApplication(const Wt::WEnvironment& env) : WApplication(env) {
    setTitle("Application title");

    root()->addWidget(std::make_unique<Wt::WText>("Lorem ipsum dolor sit amet"));

    nameEdit_ = root()->addWidget(std::make_unique<Wt::WLineEdit>());
    nameEdit_->setMargin(5, Wt::Side::Left);
    nameEdit_->setFocus();

    // Make the greeting interactive
    root()->addWidget(std::make_unique<Wt::WBreak>());
    greeting_ = root()->addWidget(std::make_unique<Wt::WText>());

    nameEdit_->keyWentUp().connect(this, &HelloApplication::greet);
}

void HelloApplication::greet() {
    greeting_->setText("Hello there, " + nameEdit_->text());
}

int main(int argc, char **argv) {
    return Wt::WRun(argc, argv, [](const Wt::WEnvironment &env) {
        return std::make_unique<HelloApplication>(env);
    });
}
