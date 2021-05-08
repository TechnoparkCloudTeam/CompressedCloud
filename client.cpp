#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include "message.pb.h"

int main()
{
    messageFS::Request req;

    req.set_name("M.U.Lermontov");
    req.set_id(2);
    boost::asio::io_service io_service_;
    boost::asio::ip::tcp::resolver resolver(io_service_);
    boost::asio::ip::tcp::resolver::results_type endpoints =
        resolver.resolve({"127.0.0.1", "8888"});

    boost::asio::ip::tcp::socket socket_(io_service_);
    boost::asio::connect(socket_, endpoints);

    boost::asio::streambuf streamBuffer_;
    std::ostream output_stream(&streamBuffer_);
    google::protobuf::io::ZeroCopyOutputStream *raw_output =
        new google::protobuf::io::OstreamOutputStream(&output_stream);
    google::protobuf::io::CodedOutputStream *coded_output =
        new google::protobuf::io::CodedOutputStream(raw_output);
    coded_output->WriteVarint32(req.ByteSizeLong());
    req.SerializeToCodedStream(coded_output);

    delete coded_output;
    delete raw_output;


    boost::system::error_code error;

    boost::array<char, 128> bufIn;
    while(1){
    sleep(5);
    socket_.write_some(streamBuffer_.data(), error);
    }
    socket_.read_some(boost::asio::buffer(bufIn), error);
    
    for (int i = 0; i < 100; i++)
        std::cout << bufIn[i];
}