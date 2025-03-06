#ifndef COORDINATOR_H_
#define COORDINATOR_H_

class Coordinator {
	Sender sender;
	Receiver receiver;
public:
	void run();
};

void Coordinator::run() {
	sender.setMessage(); // the sender set a message
    receiver.receiveMessage(sender.getDates()); // get message from the sender and pass it to the receiver
    receiver.printMessage();
}
#endif /* COORDINATOR_H_ */
