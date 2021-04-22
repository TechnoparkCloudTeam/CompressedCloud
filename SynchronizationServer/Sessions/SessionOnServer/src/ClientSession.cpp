#include "ClientSession.h"

void ClientSession::connect () {
    return;
}

void ClientSession::disconnect () {
    return;
}

std::string ClientSession::getRequestFromClient() {
    std::string json;
    return json;
}

void ClientSession::sendAnswerToClient (std::string json) {
    return;
}

int ClientSession::getClientId() const {
    return clientId;
}