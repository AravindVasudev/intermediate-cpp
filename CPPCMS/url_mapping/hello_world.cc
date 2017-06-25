#include <cppcms/application.h>
#include <cppcms/applications_pool.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/url_mapper.h>
#include <cppcms/url_dispatcher.h>
#include <iostream>

class hello_world : public cppcms::application {
public:
    hello_world(cppcms::service &srv) : cppcms::application(srv) {
        dispatcher().assign("/number/(\\d+)", &hello_world::number, this, 1);
        mapper().assign("number", "/number/{1}");

        dispatcher().assign("/", &hello_world::index, this);
        mapper().assign("/");

        mapper().root("/");
    }

    void index() {
        response().out() << "Hey there!";
    }

    void number(std::string num) {
        response().out() << "The number is " << num;
    }
};

int main(int argc, char **argv) {
    try {
        cppcms::service srv(argc, argv);
        srv.applications_pool().mount(
            cppcms::applications_factory<hello_world>());
        srv.run();
    }
    catch(std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }
}
