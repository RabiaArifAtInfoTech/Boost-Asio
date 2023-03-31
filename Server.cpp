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
	char data[100];
	size_t len = socket.read_some(boost::asio::buffer(data, 100));

	string data1 = std::string(data, len);

	return data1;
	//std::cout << "Response from client : " << std::string(data, len) << "\n";

	

	/*char data[2056];
	size_t len = socket.read_some(buffer(data, 2056));
	return data;*/

	
	/*string data1 = string(data, len);
	return data1;*/
	/*boost::asio::streambuf buf;
	cout << "here";
	boost::asio::read_until(socket, buf, "\n");
	cout << "here";
	string data = boost::asio::buffer_cast<const char*>(buf.data());
	return data;*/
}

void writeMsg(tcp::socket& socket, const string& message)
{
	const string msg = message + "\n";
	boost::asio::write(socket, boost::asio::buffer(message));
//	cout << "Servent sent Hello message to Client!" << endl;

}

//void write_(tcp::socket& socket, const string& message) {
//	const string msg = message + "\n";
//	boost::asio::write(socket, boost::asio::buffer(message));
//}
//

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

	//string msg = "test message from client side";

	//boost::asio::write(socket, boost::asio::buffer(msg, msg.length()));
	////writeMsg(socket, msg);
	//cout << "Servent sent Hello message to Client!" << endl;

	string message = readMsg(socket);
	cout << "msg from client : " << message << endl;

	string msg = "test message from server side";

	getchar();
	writeMsg(socket, msg);
	//cout << "Servent sent Hello message to Client!" << endl;


	/*std::string msg = "test message from client side";

	boost::asio::write(socket, boost::asio::buffer(msg));

	socket.close();*/

	getchar();
	std::cout << "\n\n\n";
	return 0;
}