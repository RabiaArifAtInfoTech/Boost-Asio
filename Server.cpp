#include<iostream>
#include<boost/asio.hpp>
#include<boost/asio/write.hpp>
#include<boost/asio/read.hpp>

using namespace boost::asio;
using boost::asio::ip::tcp;
using std::string;
using std::cout;
using std::endl;

string readMsg(tcp::socket& socket)
{
	char data[1000];
	size_t len = socket.read_some(boost::asio::buffer(data, 1000));
	string data1 = std::string(data, len);
	return data1;
}

void writeMsg(tcp::socket& socket, const string& message)
{
	boost::asio::write(socket, boost::asio::buffer(message));
}

int main()
{
	boost::asio::io_service io_service;
	//listen for new connection
	tcp::acceptor acceptor_(io_service, tcp::endpoint(tcp::v4(), 3000));
	//socket creation 
	tcp::socket socket(io_service);
	//waiting for connection
	acceptor_.accept(socket);
	//read operation

	
	string msg = "0";

	do
	{
		string message = readMsg(socket);
		cout << "\nClient Msg: " << message << endl;

		cout << "\nServer: ";
		std::getline(std::cin, msg, '\n');

		writeMsg(socket, msg);

	} while (msg != "null");

	//socket.close();	
	cout << "Chat Finished";

	
	getchar();

	cout << "\n\n\n";
	return 0;
	
}
