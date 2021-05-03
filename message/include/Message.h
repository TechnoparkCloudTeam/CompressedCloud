#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
struct user
{
    std::string login;
    std::string password = "0"; //по идее не нужен если отправка на сервер с хранилищем
};

namespace msg
{
    template <typename T>
    struct MessageHeader
    {
        T id{}; //структуры с тегом запроса, будут разные для сервака облака и синхрониз
        user userID;
        uint32_t size = 0;
    };

    template <typename T>
    struct Message
    {
        MessageHeader<T> header{};
        std::vector<uint8_t> body;

        size_t getSize() const
        {
            return sizeof(MessageHeader<T>) + this->body.size();
        }

        friend std::ostream &operator<<(std::ostream &os, const Message<T> &msg)
        {
            os << "ID: " << int(msg.header.id) << " From User: " << msg.header.userID.login
               << " Size: " << msg.header.size;
            return os;
        }

        template <typename DataType>
        friend Message<T> &operator<<(Message<T> &msg, const DataType &data)
        {
            //можно ли добавить эти данные к сообщению
            static_assert(std::is_standard_layout<DataType>::value, "Data is not standart");
            //
            size_t i = msg.body.size();

            msg.body.resize(msg.body.size() + sizeof(DataType));

            std::memcpy(msg.body.data() + i, &data, sizeof(DataType));

            msg.header.size = msg.getSize();

            return msg;
        }

        template <typename DataType>
        friend Message<T> &operator>>(Message<T> &msg, const DataType &data);
        //достаем из сообщения
    };

}