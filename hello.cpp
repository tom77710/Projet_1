#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

void connectToDatabase() {
    try {
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *conn;

        driver = sql::mysql::get_mysql_driver_instance();

        // Connexion au serveur MySQL XAMPP
        conn = driver->connect("tcp://127.0.0.1:3306", "root", "");
        conn->setSchema("GestionContacts");

        std::cout << "Connexion réussie à la base de données !" << std::endl;

        delete conn;
    } catch (sql::SQLException &e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }
}

int main() {
    connectToDatabase();
    return 0;
}
