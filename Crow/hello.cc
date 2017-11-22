#include "crow_all.h"
#include <sstream>

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "Hello world";
    });

    CROW_ROUTE(app, "/json")
    ([](){
        crow::json::wvalue x;

        x["Name"] = "Itachi";
        x["Clan"] = "Uchiha";

        return x;
    });

    CROW_ROUTE(app, "/saymyname")
    .methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body);
        if (!x) {
            return crow::response(400);
        }

        std::cout << x["firstName"];

        std::stringstream os;
        os << "Hello, " << x["firstName"] << " " << x["lastName"];

        return crow::response(os.str());
    });    

    CROW_ROUTE(app, "/id/<int>")
    ([](int id){
        std::stringstream out;

        out << "Your ID is " << id;

        return crow::response(out.str());
    });


    app.port(3000).multithreaded().run();
}
