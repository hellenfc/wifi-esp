void clientDemo() {
  // To use the ESP8266 as a TCP client, use the 
  // ESP8266Client class. First, create an object:
  ESP8266Client client;

  // ESP8266Client connect([server], [port]) is used to 
  // connect to a server (const char * or IPAddress) on
  // a specified port.
  // Returns: 1 on success, 2 on already connected,
  // negative on fail (-1=TIMEOUT, -3=FAIL).
  int retVal = client.connect(destServer, 5000);
  if (retVal == -1) {
    Serial.println(F("Time out"));
    return;
  } else if(retVal == -3) {
    Serial.println(F("Fail connection"));
    return;
  } else if(retVal == 1) {
    Serial.println("Connected with server!");
  }

  // print and write can be used to send data to a connected
  // client connection.
  client.print(httpPost);

  // available() will return the number of characters
  // currently in the receive buffer.
  while (client.available())
    Serial.write(client.read()); // read() gets the FIFO char

  // connected() is a boolean return value - 1 if the 
  // connection is active, 0 if it's closed.
  if (client.connected())
    client.stop(); // stop() closes a TCP connection.
}
