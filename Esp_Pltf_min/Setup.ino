
void setup(void) {
  DBG_OUTPUT_PORT.begin(115200);
  DBG_OUTPUT_PORT.print("\n");
  DBG_OUTPUT_PORT.setDebugOutput(true);
  DBG_OUTPUT_PORT.print("macAddress -  ");
  DBG_OUTPUT_PORT.println(WiFi.macAddress());

  // кнопка сброса настроек
  pinMode(reset_buton, INPUT);
  reset_debouncer.attach(reset_buton);
  reset_debouncer.interval(5);


  //светодид на плате
  pinMode(LED_BOARD, OUTPUT);
  digitalWrite(LED_BOARD, LOW );
  

  SPIFFS.begin();
  {
    Dir dir = SPIFFS.openDir("/");
    while (dir.next()) {
      String fileName = dir.fileName();
      size_t fileSize = dir.fileSize();
      DBG_OUTPUT_PORT.printf("FS File: %s, size: %s\n", fileName.c_str(), formatBytes(fileSize).c_str());
    }
    DBG_OUTPUT_PORT.printf("\n");
  }
  if (loadConfig1()) {
    //  DBG_OUTPUT_PORT.println("Load Config 1 - OK");
  } else {
    //  DBG_OUTPUT_PORT.println("Load Config 1 - BAD!!!!");
  }
  if (loadConfig2()) {
    //  DBG_OUTPUT_PORT.println("Load Config 2 - OK");
  } else {
    // DBG_OUTPUT_PORT.println("Load Config 2 - BAD!!!!");
  }
  if (loadConfig3()) {
    // DBG_OUTPUT_PORT.println("Load Config 3 - OK");
  } else {
    //  DBG_OUTPUT_PORT.println("Load Config 3 - BAD!!!!");
  }
  if (loadConfig4()) {
     DBG_OUTPUT_PORT.println("Load Config 4 - OK");
  } else {
  //  DBG_OUTPUT_PORT.println("Load Config 4 - BAD!!!!");
  }

  loadConfigMqttIO("io5");
  loadConfigMqttIO("io4");
  loadConfigMqttIO("io0");
  loadConfigMqttIO("io2");
  loadConfigMqttIO("io15");
  loadConfigMqttIO("io9");
  loadConfigMqttIO("io10");
  loadConfigMqttIO("io13");
  loadConfigMqttIO("io12");
  loadConfigMqttIO("io14");
  loadConfigMqttIO("io16");
  loadConfigMqttIO("adc");

  
  if (wifi_AP) {
    Serial.println();
    Serial.print("Configuring access point...");
    /* You can remove the password parameter if you want the AP to be open. */
    IPAddress AP_ip(staticAPIP1, staticAPIP2, staticAPIP3, staticAPIP4);
    IPAddress AP_mask(staticAPMask1, staticAPMask2, staticAPMask3, staticAPMask4);
    IPAddress AP_gw(staticAPGw1, staticAPGw2, staticAPGw3, staticAPGw4);

    WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(AP_ip, AP_gw, AP_mask);

    WiFi.softAP(ssidAP.c_str(), passwordAP.c_str());
    uint8_t i = 0;
    while (WiFi.status() != WL_CONNECTED && i++ < 20) {//wait 10 seconds
      delay(500);
    }
    DBG_OUTPUT_PORT.print("Connected! IP address: ");
    DBG_OUTPUT_PORT.println(WiFi.softAPIP());

  } else {
    WiFi.mode(WIFI_STA);
    if (!ipDCHP) {
      IPAddress ip(staticIP1, staticIP2, staticIP3, staticIP4); //static IP address
      IPAddress ip_gate(staticGw1, staticGw2, staticGw3, staticGw4);
      IPAddress ip_subnet(staticMask1, staticMask2, staticMask3, staticMask4);
      IPAddress ip_dns1(dns1_1, dns1_2, dns1_3, dns1_4);
      IPAddress ip_dns2(dns2_1, dns2_2, dns2_3, dns2_4);
      WiFi.config(ip, ip_gate, ip_subnet, ip_dns1, ip_dns2);
    }
    WiFi.begin(ssid.c_str(), password.c_str());
    DBG_OUTPUT_PORT.print("Connecting to ");
    DBG_OUTPUT_PORT.println(ssid);
    DBG_OUTPUT_PORT.print("Pass ");
    DBG_OUTPUT_PORT.println(password);
    // Wait for connection
    uint8_t i = 0;
    while (WiFi.status() != WL_CONNECTED && i++ < 20) {//wait 10 seconds
      delay(500);
    }
    if (i == 21) {
      DBG_OUTPUT_PORT.print("Could not connect to");
      DBG_OUTPUT_PORT.println(ssid);
      while (1) delay(500);
    }
    DBG_OUTPUT_PORT.print("Connected! IP address: ");
    DBG_OUTPUT_PORT.println(WiFi.localIP());

    DBG_OUTPUT_PORT.print("SSID -  ");
    DBG_OUTPUT_PORT.println(WiFi.SSID());
    DBG_OUTPUT_PORT.print("RSSI -  ");
    DBG_OUTPUT_PORT.println(WiFi.RSSI());
    DBG_OUTPUT_PORT.print("macAddress -  ");
    DBG_OUTPUT_PORT.println(WiFi.macAddress());
  }

  //  //WIFI INIT
  //  DBG_OUTPUT_PORT.printf("Connecting to %s\n", ssid_);
  //  // if (String(WiFi.SSID()) != String(ssid)) {
  //  WiFi.begin(ssid_, password_);
  //  // }
  //
  //  while (WiFi.status() != WL_CONNECTED) {
  //    delay(500);
  //    DBG_OUTPUT_PORT.print(".");
  //  }
  DBG_OUTPUT_PORT.println("");
  DBG_OUTPUT_PORT.print("Connected! IP address: ");
  DBG_OUTPUT_PORT.println(WiFi.localIP());
  //
  //  MDNS.begin(host);
  //  DBG_OUTPUT_PORT.print("Open http://");
  //  DBG_OUTPUT_PORT.print(host);
  //  DBG_OUTPUT_PORT.println(".local/edit to see the file browser");
  //

  //SERVER INIT
  //list directory
  server.on("/list", HTTP_GET, handleFileList);
  //load editor
  server.on("/edit", HTTP_GET, []() {
    if (!handleFileRead("/edit.htm")) server.send(404, "text/plain", "FileNotFound");
  });
  //create file
  server.on("/edit", HTTP_PUT, handleFileCreate);
  //delete file
  server.on("/edit", HTTP_DELETE, handleFileDelete);
  //first callback is called after the request has ended with all parsed arguments
  //second callback handles file uploads at that location
  server.on("/edit", HTTP_POST, []() {
    server.send(200, "text/plain", "");
  }, handleFileUpload);


  server.on("/gwifi1", gWiFi1);
  server.on("/gwifi2", gWiFi2);
  server.on("/gwifi3", gWiFi3);
  server.on("/gwifi4", gWiFi4);
   server.on("/gwifi5", gWiFi5);
  server.on("/swifi1",  sWiFi1);
  server.on("/swifi2",  sWiFi2);
  server.on("/swifi3",  sWiFi3);
    server.on("/swifi4",  sWiFi4);
  server.on("/gio", g_io_MQTT);
  server.on("/sio", HTTP_GET, sMqtt);



  //called when the url is not defined here
  //use it to load content from SPIFFS
  server.onNotFound([]() {
    if (!handleFileRead(server.uri()))
      server.send(404, "text/plain", "FileNotFound");
  });

  //get heap status, analog input value and all GPIO statuses in one json call
  server.on("/all", HTTP_GET, []() {
    String json = "{";
    json += "\"heap\":" + String(ESP.getFreeHeap());
    json += ", \"analog\":" + String(analogRead(A0));
    json += ", \"gpio\":" + String((uint32_t)(((GPI | GPO) & 0xFFFF) | ((GP16I & 0x01) << 16)));
    json += "}";
    server.send(200, "text/json", json);
    json = String();
  });
  server.begin();
  DBG_OUTPUT_PORT.println("HTTP server started");


  // Setup MqttClient
  client.setServer(MqttServer.c_str(), MqttPort.toInt());
  client.setCallback(callback);


  // таймер взводит переменную flip ЧЕРЕЗ  0.5s ИНТЕРВАЛ
  // flipper.attach(0.5, flips);
  flipper.attach(60, flips);


  // термо датчик
  // Start up the library
  sensors.begin();
  if (!sensors.getAddress(thermometer1, 0)) Serial.println(F("Unable to find address for Device 0"));
  //if (!sensors.getAddress(thermometer2, 1)) Serial.println("Unable to find address for Device 1");

  sensors.setResolution(thermometer1, 12 ); // максимальная точность
  sensors.setWaitForConversion(true);
  term = sensors.getTempC(thermometer1);

  sensors.setWaitForConversion(false);
  sensors.requestTemperatures();

}



void flips()
{
  //таймер взводит переменную flip ЧЕРЕЗ ЗАДАННЫЙ ИНТЕРВАЛ
  flip = true;
}
