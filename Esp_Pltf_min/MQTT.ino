void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '1') {
    // DigOut(13, HIGH);
    //  digitalWrite(BUILTIN_LED, LOW);   // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is acive low on the ESP-01)
  } else {
    //  digitalWrite(BUILTIN_LED, HIGH);  // Turn the LED off by making the voltage HIGH
    //    DigOut(13, LOW);
  }

}

void reconnect() {
  // Loop until we're reconnected
  //  while (!client.connected()) {
  Serial.print("Attempting MQTT connection...");
  // Attempt to connect
  if (client.connect(MqttClName.c_str())) {
    Serial.println("connected");
    // Once connected, publish an announcement...
    //   client.publish("outTopic", "hello world");
    // ... and resubscribe
    String inTopic = MQTT_TOPIC + MqttClName ;
    inTopic += "/ch1";
    client.subscribe(inTopic.c_str());
    inTopic = MQTT_TOPIC + MqttClName ;
    inTopic += "/ch2";
    client.subscribe(inTopic.c_str());
    inTopic = MQTT_TOPIC + MqttClName ;
    inTopic += "/ch3";
    client.subscribe(inTopic.c_str());
    inTopic = MQTT_TOPIC + MqttClName ;
    inTopic += "/ch4";
    client.subscribe(inTopic.c_str());

  } else {
    Serial.print("failed, rc=");
    Serial.print(client.state());
    Serial.println(" try again in 5 seconds");
    // Wait 5 seconds before retrying
    //  delay(5000);
  }
  // }
}
