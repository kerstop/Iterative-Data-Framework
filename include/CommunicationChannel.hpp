//
// Created by kerstop on 8/20/21.
//

#ifndef ITERATIVE_DATA_FRAMEWORK_COMMUNICATIONCHANNEL_HPP
#define ITERATIVE_DATA_FRAMEWORK_COMMUNICATIONCHANNEL_HPP

#include <queue>
#include <string>
#include <mutex>
#include <map>

struct Message{
    enum Type {
        EXIT, INFO, PAUSE,
    };
    Type type;
    std::string message;
};

class CommunicationChannel {
private:
    std::map<std::string, std::queue<Message>> bus;
    std::mutex mut;
public:
    void registerChannel(std::string channel);
    void sendMessage(std::string channel, Message message);
    Message getMessage(std::string channel);
    bool hasMessage(std::string channel);
    bool channelExists(std::string channel);

};


#endif //ITERATIVE_DATA_FRAMEWORK_COMMUNICATIONCHANNEL_HPP
