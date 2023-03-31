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
	//cout << "Servent sent Hello message to Client!" << endl;

}
//void writeMsg(tcp::socket& socket, const string& message) 
//{
//	const string msg = message + "\n";
//	boost::asio::write(socket, boost::asio::buffer(message));
//	cout << "Servent sent Hello message to Client!" << endl;
//
//}
//
//string readMsg(tcp::socket& socket)
//{
//	boost::asio::streambuf buf;
//	cout << "here";
//	boost::asio::read_until(socket, buf, "\n");
//	cout << "here";
//	string data = boost::asio::buffer_cast<const char*>(buf.data());
//	return data;
//}
//int main()
//{
//	boost::asio::io_service io_service;
//	//socket creation
//	tcp::socket socket(io_service);
//	//connection
//	socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 3000));
//	////Step 3: program initiates 'connect' operation
//	//acceptor_.accept(socket);
//	boost::system::error_code error;
//	//boost::asio::streambuf receive_buffer;
//	//boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
//	char data[1024];
//	size_t len = socket.read_some(buffer(data, 1024));
//	std::cout << "Response: " << std::string(data, len) << "\n";
//	getchar();
//	std::cout << "\n\n\n";
//	return 0;
//}

int main()
{
	////Step 1: IO execution context object
	//io_context io_context;

	//
	////Step 2: IO object (i.e. socket)
	//boost::asio::ip::tcp::socket socket(io_context);



	boost::asio::io_service io_service;
	//socket creation
	tcp::socket socket(io_service);
	//connection
	socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 3000));
	////Step 3: program initiates 'connect' operation
	//acceptor_.accept(socket);
	boost::system::error_code error;


	/*boost::asio::streambuf receive_buffer;
	boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
	const char* data = boost::asio::buffer_cast<const char*>(receive_buffer.data());
	cout << data << endl;*/
	//string message = readMsg(socket);
	//cout << "msg from client : " << message << endl;

	string msg = "test message from client side";

	writeMsg(socket, msg);
	getchar();
	string message = readMsg(socket);
	cout << "msg from server : " << message << endl;
	//cout << "clie sent Hello message to Client!" << endl;

	/*boost::system::error_code error;
	boost::asio::write(socket, boost::asio::buffer(msg), error);
	if (!error) {
		cout << "Client sent hello message!" << endl;
	}
	else {
		cout << "send failed: " << error.message() << endl;
	}*/

	//boost::asio::write(socket, boost::asio::buffer(msg));

	//socket.close();

	getchar();

	std::cout << "\n\n\n";
	return 0;
}