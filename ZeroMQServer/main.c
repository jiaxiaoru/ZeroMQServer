//
//  main.c
//  ZeroMQServer
//
//  Created by Judith on 2019/11/13.
//  Copyright © 2019 Judith. All rights reserved.
//

#include <stdio.h>
#include "zmq.h"

int main(int argc, const char * argv[]) {
    void *context = zmq_ctx_new();
    void *responder = zmq_socket(context, ZMQ_REP);
    zmq_bind(responder, "tcp://*:5555");
    while (1) {
        printf("server start receive\n");
        char buffer[20];
        zmq_recv(responder, buffer, 20, 0);
        printf("server received message %s\n",buffer);
        zmq_send(responder, "get it", 7, 0);
    }
    return 0;
}
