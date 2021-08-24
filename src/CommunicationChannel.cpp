//
// Created by kerstop on 8/20/21.
//

#include "CommunicationChannel.hpp"

void CommunicationChannel::registerChannel(std::string channel) {
    mut.lock();
    bus.insert(std::pair<std::string, std::queue<Message>>
        (channel, std::queue<Message>())
    );
    mut.unlock();
}

void CommunicationChannel::sendMessage(std::string channel, Message message) {
    mut.lock();
    bus[channel].push(message);
    mut.unlock();
}

Message CommunicationChannel::getMessage(std::string channel) {
    Message ret;
    mut.lock();
    ret = bus[channel].front();
    bus[channel].pop();
    mut.unlock();
    return ret;
}

bool CommunicationChannel::hasMessage(std::string channel) {
    bool ret;
    mut.lock();
    ret = !bus[channel].empty();
    mut.unlock();
    return ret;
}

bool CommunicationChannel::channelExists(std::string channel) {
    bool ret;
    mut.lock();
    ret = bus.count("Console") > 0;
    mut.unlock();
    return ret;
}


