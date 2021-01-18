#include <Wt/WApplication.h>

class HelloApplication : public Wt::WApplication {
    public:
        HelloApplication(const Wt::WEnvironment& env);
};

HelloApplication::HelloApplication(const Wt::WEnvironment& env) : WApplication(env) {
    setTitle("Application title");
}

int main(int argc, char **argv) {
    return Wt::WRun(argc, argv, [](const Wt::WEnvironment &env) {
        return std::make_unique<HelloApplication>(env);
    });
}
