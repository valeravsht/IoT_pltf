bool loadConfig1() {
  /*  File configFile = SPIFFS.open("/config.json", "r");
    if (!configFile) {
      Serial.println("Failed to open config file");
      return false;
    }*/
  File configFile ;
  String fileName;
  fileName = "/conf1.jsn";

  if (SPIFFS.exists(fileName)) {
    configFile = SPIFFS.open(fileName, "r");
    //  Serial.println("Config file 1 exists ");
  } else {
    Serial.print("Reset config 1 - ");
    if (defConfigFile1()) {
      Serial.println("OK");
    } else {
      Serial.println("BAD !!!!!!!!!!!!!!!!");
    }
    configFile = SPIFFS.open(fileName, "r");
  }

  size_t size = configFile.size();
  if (size > 1024) {
    Serial.println("Config file size is too large");
    return false;
  }
  // Allocate a buffer to store contents of the file.
  std::unique_ptr<char[]> buf(new char[size]);

  // We don't use String here because ArduinoJson library requires the input
  // buffer to be mutable. If you don't use ArduinoJson, you may as well
  // use configFile.readString instead.
  configFile.readBytes(buf.get(), size);

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& json = jsonBuffer.parseObject(buf.get());

  if (!json.success()) {
    Serial.println("Failed to parse config file");
    return false;
  }


  //  sensor = json["sensor"].as<String>();
  ssid = json["ssid"].as<String>(); //имя точки доступа для подключения (режим клиент)
  password = json["password"].as<String>(); // пароль для подключения (режим клиент)
  if ( json["tip_ip"] == "DCHP") {
    ipDCHP = true;
  } else {
    ipDCHP = false;
  }


  if ( json["tip_wifi"] == "AP") {
    wifi_AP = true;
  } else {
    wifi_AP = false;
  }


  ssidAP =  json["ssidAP"].as<String>(); // имя для точки доступа (режим точка доступа)
  passwordAP =  json["passwordAP"].as<String>(); // пароль для точки доступа (режим точка доступа)


  return true;
}

bool loadConfig2() {
  /*  File configFile = SPIFFS.open("/config.json", "r");
    if (!configFile) {
      Serial.println("Failed to open config file");
      return false;
    }*/
  File configFile ;
  String fileName;
  fileName = "/conf2.jsn";

  if (SPIFFS.exists(fileName)) {
    configFile = SPIFFS.open(fileName, "r");
    //   Serial.println("Config file 2 exists ");
  } else {
    Serial.print("Reset config 2 - ");
    if (defConfigFile2()) {
      Serial.println("OK");
    } else {
      Serial.println("BAD !!!!!!!!!!!!!!!!");
    }

    configFile = SPIFFS.open(fileName, "r");
  }
  size_t size = configFile.size();
  if (size > 1024) {
    Serial.println("Config file size is too large");
    return false;
  }
  // Allocate a buffer to store contents of the file.
  std::unique_ptr<char[]> buf(new char[size]);

  // We don't use String here because ArduinoJson library requires the input
  // buffer to be mutable. If you don't use ArduinoJson, you may as well
  // use configFile.readString instead.
  configFile.readBytes(buf.get(), size);

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& json = jsonBuffer.parseObject(buf.get());

  if (!json.success()) {
    Serial.println("Failed to parse config file");
    return false;
  }

  staticIP1 = ( byte)json["static_ip1"];
  staticIP2 = ( byte)json["static_ip2"];
  staticIP3 = ( byte)json["static_ip3"];
  staticIP4 = ( byte)json["static_ip4"];

  staticMask1 = ( byte)json["static_mask1"];
  staticMask2 = ( byte)json["static_mask2"];
  staticMask3 = ( byte)json["static_mask3"];
  staticMask4 = ( byte)json["static_mask4"];

  staticGw1 = ( byte)json["static_gw1"];
  staticGw2 = ( byte)json["static_gw2"];
  staticGw3 = ( byte)json["static_gw3"];
  staticGw4 = ( byte)json["static_gw4"];


  return true;
}


bool loadConfig3() {
  /*  File configFile = SPIFFS.open("/config.json", "r");
    if (!configFile) {
      Serial.println("Failed to open config file");
      return false;
    }*/
  File configFile ;
  String fileName;
  fileName = "/conf3.jsn";

  if (SPIFFS.exists("/conf3.jsn")) {
    configFile = SPIFFS.open("/conf3.jsn", "r");
    //   Serial.println("Config file 3 exists ");
  } else {
    Serial.print("Reset config 3  ");
    if (defConfigFile3()) {
      Serial.println("OK");
    } else {
      Serial.println("BAD !!!!!!!!!!!!!!!!");
    }

    configFile = SPIFFS.open("/conf3.jsn", "r");
  }
  size_t size = configFile.size();
  if (size > 1024) {
    Serial.println("Config file size is too large");
    return false;
  }
  // Allocate a buffer to store contents of the file.
  std::unique_ptr<char[]> buf(new char[size]);

  // We don't use String here because ArduinoJson library requires the input
  // buffer to be mutable. If you don't use ArduinoJson, you may as well
  // use configFile.readString instead.
  configFile.readBytes(buf.get(), size);

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& json = jsonBuffer.parseObject(buf.get());

  if (!json.success()) {
    Serial.println("Failed to parse config file");
    return false;
  }

  staticAPIP1 = ( byte)json["staticAP_ip1"];
  staticAPIP2 = ( byte)json["staticAP_ip2"];
  staticAPIP3 = ( byte)json["staticAP_ip3"];
  staticAPIP4 = ( byte)json["staticAP_ip4"];

  staticAPMask1 = ( byte)json["staticAP_mask1"];
  staticAPMask2 = ( byte)json["staticAP_mask2"];
  staticAPMask3 = ( byte)json["staticAP_mask3"];
  staticAPMask4 = ( byte)json["staticAP_mask4"];

  staticAPGw1 = ( byte)json["staticAP_gw1"];
  staticAPGw2 = ( byte)json["staticAP_gw2"];
  staticAPGw3 = ( byte)json["staticAP_gw3"];
  staticAPGw4 = ( byte)json["staticAP_gw4"];

  return true;
}


bool loadConfig4() {
  /*  File configFile = SPIFFS.open("/config.json", "r");
    if (!configFile) {
      Serial.println("Failed to open config file");
      return false;
    }*/
  File configFile ;

  if (SPIFFS.exists("/conf4.jsn")) {
    configFile = SPIFFS.open("/conf4.jsn", "r");
    //    Serial.println("Config file 3 exists ");
  } else {
    Serial.print("Reset config 4  ");
    if (defConfigFile4()) {
      Serial.println("OK");
    } else {
      Serial.println("BAD !!!!!!!!!!!!!!!!");
    }

    configFile = SPIFFS.open("/conf4.jsn", "r");
  }
  size_t size = configFile.size();
  if (size > 1024) {
    Serial.println("Config file size is too large");
    return false;
  }
  // Allocate a buffer to store contents of the file.
  std::unique_ptr<char[]> buf(new char[size]);

  // We don't use String here because ArduinoJson library requires the input
  // buffer to be mutable. If you don't use ArduinoJson, you may as well
  // use configFile.readString instead.
  configFile.readBytes(buf.get(), size);

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& json = jsonBuffer.parseObject(buf.get());

  if (!json.success()) {
    Serial.println("Failed to parse config file");
    return false;
  }
  MqttClName = json["MQTT_Cl_Name"].as<String>();
  MqttServer = json["MQTT_Server"].as<String>();
  MqttPort = json["MQTT_Port"].as<String>();
  MqttLogin = json["MQTT_Login"].as<String>();
  MqttPaswd = json["MQTT_Paswd"].as<String>();
  return true;
}




bool saveConfig1() {
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();

  if (wifi_AP) {
    root["tip_wifi"] = "AP"; //точка доступа
  } else
  {
    root["tip_wifi"] = "Client"; //точка доступа
  }
  root["ssid"] = ssid;
  root["password"] = password;
  if (ipDCHP) {
    root["tip_ip"] = "DCHP";
  } else {
    root["tip_ip"] = "static";
  }

  root["ssidAP"] = ssidAP;
  root["passwordAP"] = passwordAP;




  SPIFFS.remove("/conf1.jsn");
  // File configFile = SPIFFS.open("/config.json", "w");
  File configFile =  SPIFFS.open("/conf1.jsn", "w");
  if (!configFile) {
    Serial.println("Failed to open config file for writing");
    return false;
  }

  root.printTo(configFile);
  Serial.println("");
  Serial.println("Config1");

  root.printTo(Serial);
  configFile.close();
  return true;
}

bool saveConfig2() {
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();

  root["static_ip1"] = staticIP1;
  root["static_ip2"] = staticIP2;
  root["static_ip3"] = staticIP3;
  root["static_ip4"] = staticIP4;

  root["static_mask1"] = staticMask1;
  root["static_mask2"] = staticMask2;
  root["static_mask3"] = staticMask3;
  root["static_mask4"] = staticMask4;

  root["static_gw1"] = staticGw1;
  root["static_gw2"] = staticGw2;
  root["static_gw3"] = staticGw3;
  root["static_gw4"] = staticGw4;



  SPIFFS.remove("/conf2.jsn");

  // File configFile = SPIFFS.open("/config.json", "w");
  File configFile =  SPIFFS.open("/conf2.jsn", "w");
  if (!configFile) {
    Serial.println("Failed to open config file for writing");
    return false;
  }

  root.printTo(configFile);
  Serial.println("");
  Serial.println("Config2");
  root.printTo(Serial);
  configFile.close();
  return true;
}

bool saveConfig3() {
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();

  root["staticAP_ip1"] = staticAPIP1;
  root["staticAP_ip2"] = staticAPIP2;
  root["staticAP_ip3"] = staticAPIP3;
  root["staticAP_ip4"] = staticAPIP4;

  root["staticAP_mask1"] = staticAPMask1;
  root["staticAP_mask2"] = staticAPMask2;
  root["staticAP_mask3"] = staticAPMask3;
  root["staticAP_mask4"] = staticAPMask4;

  root["staticAP_gw1"] = staticAPGw1;
  root["staticAP_gw2"] = staticAPGw2;
  root["staticAP_gw3"] = staticAPGw3;
  root["staticAP_gw4"] = staticAPGw4;

  SPIFFS.remove("/conf3.jsn");

  // File configFile = SPIFFS.open("/config.json", "w");
  File configFile =  SPIFFS.open("/conf3.jsn", "w");
  if (!configFile) {
    Serial.println("Failed to open config file for writing");
    return false;
  }

  root.printTo(configFile);
  Serial.println("");
  Serial.println("Config3");
  root.printTo(Serial);
  configFile.close();
  return true;
}


bool saveConfig4() {
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();

  root["MQTT_Cl_Name"] = MqttClName.c_str();
  root["MQTT_Server"] = MqttServer.c_str();
  root["MQTT_Port"] = MqttPort.c_str();
  root["MQTT_Login"] = MqttLogin.c_str();
  root["MQTT_Paswd"] = MqttPaswd.c_str();


  SPIFFS.remove("/conf4.jsn");

  // File configFile = SPIFFS.open("/config.json", "w");
  File configFile =  SPIFFS.open("/conf4.jsn", "w");
  if (!configFile) {
    //  Serial.println("Failed to open config file for writing");
    return false;
  }

  root.printTo(configFile);
  Serial.println("");
  Serial.println("Config4");
  root.printTo(Serial);
  configFile.close();
  return true;
}


bool defConfigFile1() {
  /*
      создание файла с настройками WiFi по умолчанию
  */

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();

  root["tip_wifi"] = "AP"; //точка доступа
  root["ssid"] = "";
  root["password"] = "";
  root["tip_ip"] = "DCHP";
  String MAC = WiFi.macAddress();
  String tmp = "vlr_dev_";
  tmp += MAC.substring(9, 11);
  tmp += MAC.substring(12, 14);
  tmp += MAC.substring(15, 17);

  root["ssidAP"] = tmp.c_str();
  root["passwordAP"] = "12345678";



  SPIFFS.remove("/conf1.jsn");
  // File configFile = SPIFFS.open("/config.json", "w");
  File configFile =  SPIFFS.open("/conf1.jsn", "w");
  if (!configFile) {
    Serial.println("Failed to open config file for writing");
    return false;
  }

  root.printTo(configFile);
  configFile.close();
  return true;
}


bool defConfigFile2() {
  /*
      создание файла с настройками WiFi по умолчанию
  */

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();

  String tmpMac =  WiFi.macAddress();

  root["static_ip1"] = ( byte)0;
  root["static_ip2"] = ( byte)0;
  root["static_ip3"] = ( byte)0;
  root["static_ip4"] = ( byte)0;
  root["static_mask1"] = ( byte)255;
  root["static_mask2"] = ( byte)255;
  root["static_mask3"] = ( byte)255;
  root["static_mask4"] = ( byte)0;
  root["static_gw1"] = ( byte)0;
  root["static_gw2"] = ( byte)0;
  root["static_gw3"] = ( byte)0;
  root["static_gw4"] = ( byte)0;

  SPIFFS.remove("/conf2.jsn");
  // File configFile = SPIFFS.open("/config.json", "w");
  File configFile =  SPIFFS.open("/conf2.jsn", "w");
  if (!configFile) {
    Serial.println("Failed to open config file for writing");
    return false;
  }

  root.printTo(configFile);
  configFile.close();
  return true;
}


bool defConfigFile3() {
  /*
      создание файла с настройками WiFi по умолчанию
  */

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();

  String tmpMac =  WiFi.macAddress();

  root["staticAP_ip1"] = ( byte)192;
  root["staticAP_ip2"] = ( byte)168;
  root["staticAP_ip3"] = ( byte)0;
  root["staticAP_ip4"] = ( byte)1;
  root["staticAP_mask1"] = ( byte) 255;
  root["staticAP_mask2"] = ( byte)255;
  root["staticAP_mask3"] = ( byte)255;
  root["staticAP_mask4"] = ( byte)0;
  root["staticAP_gw1"] = ( byte)192;
  root["staticAP_gw2"] = ( byte)168;
  root["staticAP_gw3"] = ( byte)0;
  root["staticAP_gw4"] = ( byte) 1;

  SPIFFS.remove("/conf3.jsn");
  // File configFile = SPIFFS.open("/config.json", "w");
  File configFile =  SPIFFS.open("/conf3.jsn", "w");
  if (!configFile) {
    Serial.println("Failed to open config file for writing");
    return false;
  }

  root.printTo(configFile);
  configFile.close();
  return true;
}


bool defConfigFile4() {
  /*
      создание файла с настройками MQTT по умолчанию
  */

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();

  String MAC = WiFi.macAddress();
  String tmp = "AirCons";//Air_curtain_console Пульт тепловой завесы
  tmp += MAC.substring(9, 11);
  tmp += MAC.substring(12, 14);
  tmp += MAC.substring(15, 17);

  root["MQTT_Cl_Name"] = tmp.c_str();
  root["MQTT_Server"] = "127.0.0.1";
  root["MQTT_Port"] = "1883";
  root["MQTT_Login"] = "";
  root["MQTT_Paswd"] = "";


  SPIFFS.remove("/conf4.jsn");
  // File configFile = SPIFFS.open("/config.json", "w");
  File configFile =  SPIFFS.open("/conf4.jsn", "w");
  if (!configFile) {
    Serial.println("Failed to open config file for writing");
    return false;
  }

  root.printTo(configFile);
  configFile.close();
  return true;
}


void printGlobal() {

  // WiFi
  Serial.print("ssid = "); //имя точки доступа для подключения (режим клиент)
  Serial.println(ssid);
  Serial.print(" password = "); // пароль для подключения (режим клиент)
  Serial.println(password);
  Serial.print(" ipDCHP = "); true; // получение IP адреса по DCHP
  if (ipDCHP)
    Serial.println("true");
  else
    Serial.println(false);

  Serial.print(" wifi_AP = "); true; // режимы wifi  false-клиент, true-точка доступа
  if (wifi_AP)
    Serial.println("true");
  else
    Serial.println(false);
  Serial.print(" ssidAP = "); // имя для точки доступа (режим точка доступа)
  Serial.println(ssidAP);
  Serial.print(" passwordAP = "); // пароль для точки доступа (режим точка доступа)
  Serial.println(passwordAP);
  Serial.print("IP -" ); // статический IP
  Serial.print((int)staticIP1); Serial.print("."); Serial.print( (int)staticIP2); Serial.print("."); Serial.print((int)staticIP3); Serial.print("."); Serial.println((int)staticIP4);
  Serial.print("Mask -" ); // статический Mask
  Serial.print((int)staticMask1); Serial.print("."); Serial.print( (int)staticMask2); Serial.print("."); Serial.print((int)staticMask3); Serial.print("."); Serial.println((int)staticMask4);
  Serial.print("GW -" ); // статический Mask
  Serial.print((int)staticGw1); Serial.print("."); Serial.print( (int)staticGw2); Serial.print("."); Serial.print((int)staticGw3); Serial.print("."); Serial.println((int)staticGw4);

  Serial.println("AP");
  Serial.print("IP -" ); // статический IP
  Serial.print((int)staticAPIP1); Serial.print("."); Serial.print( (int)staticAPIP2); Serial.print("."); Serial.print((int)staticAPIP3); Serial.print("."); Serial.println((int)staticAPIP4);
  Serial.print("Mask -" ); // статический Mask
  Serial.print((int)staticAPMask1); Serial.print("."); Serial.print( (int)staticAPMask2); Serial.print("."); Serial.print((int)staticAPMask3); Serial.print("."); Serial.println((int)staticAPMask4);
  Serial.print("GW -" ); // статический Mask
  Serial.print((int)staticAPGw1); Serial.print("."); Serial.print( (int)staticAPGw2); Serial.print("."); Serial.print((int)staticAPGw3); Serial.print("."); Serial.println((int)staticAPGw4);


}

int get_i_set_mqtt(String io) {
  //возвращает номер в массиве  настроек io

  for (int i = 0; i <= 12 ; i++ ) {
       if (set_mqtt[i].io == io) {
      return i;
    }
  }
  return -1 ;
}


bool defConfigMqttIO(String io) {
  /*
      создание файла с настройками MQTT по умолчанию
  */

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();

  root["io"] = io.c_str();
  root["r"] = (byte)0;
  root["w"] = (byte)0;
  root["mqtt"] = "";



  SPIFFS.remove("/cnf" + io + ".jsn");
  // File configFile = SPIFFS.open("/config.json", "w");
  File configFile =  SPIFFS.open("/cnf" + io + ".jsn", "w");
  if (!configFile) {
    Serial.println("Failed to open config file for writing");
    return false;
  }

  root.printTo(configFile);
  configFile.close();
  return true;
}


bool loadConfigMqttIO(String io) {

  File configFile ;

  if (SPIFFS.exists("/cnf" + io + ".jsn")) {
    configFile = SPIFFS.open("/cnf" + io + ".jsn", "r");
    //  Serial.println("Config file 3 exists ");
  } else {
    Serial.print("Reset config 4  ");
    if ( defConfigMqttIO(io)) {
      Serial.println("OK");
    } else {
      Serial.println("BAD !!!!!!!!!!!!!!!!");
    }

    configFile = SPIFFS.open("/cnf" + io + ".jsn", "r");
  }
  size_t size = configFile.size();
  if (size > 1024) {
    Serial.println("Config file size is too large");
    return false;
  }
  // Allocate a buffer to store contents of the file.
  std::unique_ptr<char[]> buf(new char[size]);

  // We don't use String here because ArduinoJson library requires the input
  // buffer to be mutable. If you don't use ArduinoJson, you may as well
  // use configFile.readString instead.
  configFile.readBytes(buf.get(), size);

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& json = jsonBuffer.parseObject(buf.get());

  if (!json.success()) {
    Serial.println("Failed to parse config file");
    return false;
  }
  int i = get_i_set_mqtt(io);
  set_mqtt[i].io = json["io"].as<String>();
  byte tmp = ( byte)json["r"];
  if ( tmp > 0)
    set_mqtt[i].r = true;
  else
    set_mqtt[i].r = false;
  tmp = ( byte)json["w"];
  if (tmp > 0)
    set_mqtt[i].w = true;
  else
    set_mqtt[i].w = false;

  set_mqtt[i].mqtt = json["mqtt"].as<String>();

  return true;
}
bool saveConfigMqttIO(String io) {

  int i = get_i_set_mqtt(io);

  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();


  root["io"] = set_mqtt[i].io.c_str();
  root["r"] = set_mqtt[i].r ? 1 : 0;
  root["w"] = set_mqtt[i].w ? 1 : 0;
  root["mqtt"] = set_mqtt[i].mqtt.c_str();


  SPIFFS.remove("/cnf" + io + ".jsn");

  File configFile =  SPIFFS.open("/cnf" + io + ".jsn", "w");
  if (!configFile) {
    Serial.println("Failed to open config file for writing");
    return false;
  }

  root.printTo(configFile);
  Serial.println("");
  Serial.println("/cnf" + io + ".jsn");
  root.printTo(Serial);
  configFile.close();
  return true;
}


