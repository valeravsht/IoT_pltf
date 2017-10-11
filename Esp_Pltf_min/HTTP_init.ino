
void testpp() {
  String message = "TEST\n\n";
  server.sendContent(message);
}


void gWiFiCl1() {
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["Mac"] = WiFi.macAddress();

  if (wifi_Cl) {
    root["wifi_Cl"] = 1; //точка доступа
  } else {
    root["wifi_Cl"] = 0; //точка доступа
  }

  root["ssid"] = ssid;
  root["password"] = password;
  if (ipDCHP) {
    root["tip_ip"] = "DCHP";
  } else {
    root["tip_ip"] = "static";
  }
  root["static_ip1"] = staticIP1;
  root["static_ip2"] = staticIP2;
  root["static_ip3"] = staticIP3;
  root["static_ip4"] = staticIP4;

  String output;
  root.printTo(output);
  server.send(200, "text/json", output);

}
void gWiFiCl2() {
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();


  root["static_mask1"] = staticMask1;
  root["static_mask2"] = staticMask2;
  root["static_mask3"] = staticMask3;
  root["static_mask4"] = staticMask4;
  root["static_gw1"] = staticGw1;
  root["static_gw2"] = staticGw2;
  root["static_gw3"] = staticGw3;
  root["static_gw4"] = staticGw4;

  String output;
  root.printTo(output);
  server.send(200, "text/json", output);

}

void gWiFiAp1() {
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  if (wifi_AP) {
    root["wifi_AP"] = 1; //точка доступа
  } else {
    root["wifi_AP"] = 0; //точка доступа
  }

  root["ssidAP"] = ssidAP;
  root["passwordAP"] = passwordAP;
  // root["Mac"] = WiFi.macAddress();
  root["staticAP_ip1"] = staticAPIP1;
  root["staticAP_ip2"] = staticAPIP2;
  root["staticAP_ip3"] = staticAPIP3;
  root["staticAP_ip4"] = staticAPIP4;
  root["staticAP_mask1"] = staticAPMask1;
  root["staticAP_mask2"] = staticAPMask2;

  String output;
  root.printTo(output);
  server.send(200, "text/json", output);

}
void gWiFiAP2() {
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();

  root["staticAP_mask3"] = staticAPMask3;
  root["staticAP_mask4"] = staticAPMask4;
  root["staticAP_gw1"] = staticAPGw1;
  root["staticAP_gw2"] = staticAPGw2;
  root["staticAP_gw3"] = staticAPGw3;
  root["staticAP_gw4"] = staticAPGw4;

  String output;
  root.printTo(output);
  server.send(200, "text/json", output);

}
void gServMQTT() {
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();

  root["MQTT_Cl_Name"] = MqttClName;
  root["MQTT_Server"] = MqttServer;
  root["MQTT_Port"] = MqttPort;
  root["MQTT_Login"] = MqttLogin;
  root["MQTT_Paswd"] = MqttPaswd;

  String output;
  root.printTo(output);
  server.send(200, "text/json", output);

}
void sWiFiCl1() {

  String message = "";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " NAME:" + server.argName(i) + "\n VALUE:" + server.arg(i) + "\n";
    String sName =  server.argName(i);
    String sVal = server.arg(i);

    if (sName == "wifi_cl") {
      if ( sVal == "1" ) {
        wifi_Cl = true;
      } else {
        wifi_Cl = false;
      }
      continue;
    }
    if (sName == "dchp") {
      if ( sVal == "1" ) {
        ipDCHP = true;
      } else {
        ipDCHP = false;
      }
      continue;
    }
    if (sName == "name") {
      ssid = sVal;
      continue;
    }
    if (sName == "ps") {
      password = sVal;
      continue;
    }
  }
  DBG_OUTPUT_PORT.println("");
  DBG_OUTPUT_PORT.println("set WIFI part1 ");
  DBG_OUTPUT_PORT.print(message);
  DBG_OUTPUT_PORT.println("");
  
  saveConfigWiFiCl1();
  
  server.send(200, "text/json", "");

}
void sWiFiCl2() {
  String message = "";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " NAME:" + server.argName(i) + "\n VALUE:" + server.arg(i) + "\n";
    String sName =  server.argName(i);
    String sVal = server.arg(i);

    if (sName == "ip1") {
      staticIP1 = (byte)sVal.toInt();
      continue;
    }
    if (sName == "ip2") {
      staticIP2 = (byte)sVal.toInt();
      continue;
    }
    if (sName == "ip3") {
      staticIP3 = (byte)sVal.toInt();
      continue;
    }
    if (sName == "ip4") {
      staticIP4 = (byte)sVal.toInt();
      continue;
    }

    if (sName == "mask1") {
      staticMask1 = (byte)sVal.toInt();
      continue;
    }
    if (sName == "mask2") {
      staticMask2 = (byte)sVal.toInt();
      continue;
    }
    if (sName == "mask3") {
      staticMask3 = (byte)sVal.toInt();
      continue;
    }
    if (sName == "mask4") {
      staticMask4 = (byte)sVal.toInt();
      continue;
    }


    if (sName == "gw1") {
      staticGw1 = (byte)sVal.toInt();
      continue;
    }
    if (sName == "gw2") {
      staticGw2 = (byte)sVal.toInt();
      continue;
    }
    if (sName == "gw3") {
      staticGw3 = (byte)sVal.toInt();
      continue;
    }
    if (sName == "gw4") {
      staticGw4 = (byte)sVal.toInt();
      continue;
    }
  }
  DBG_OUTPUT_PORT.println("");
  DBG_OUTPUT_PORT.println("set WIFI part2 ");
  DBG_OUTPUT_PORT.print(message);
  DBG_OUTPUT_PORT.println("");
 
  saveConfigWiFiCl2();
  
  server.send(200, "text/json", "");
}
void sWiFiAP() {
  String message = "";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " NAME:" + server.argName(i) + "\n VALUE:" + server.arg(i) + "\n";
    String sName =  server.argName(i);
    String sVal = server.arg(i);

    if (sName == "wifi_ap") {
      if ( sVal == "1" ) {
        wifi_AP = true;
      } else {
        wifi_AP = false;
      }
      continue;
    }

    if (sName == "ipAP1") {
      staticAPIP1 = (byte)sVal.toInt();
      continue;
    }
    if (sName == "ipAP2") {
      staticAPIP2 = (byte)sVal.toInt();
      continue;
    }
    if (sName == "ipAP3") {
      staticAPIP3 = (byte)sVal.toInt();
      continue;
    }
    if (sName == "ipAP4") {
      staticAPIP4 = (byte)sVal.toInt();
      continue;
    }

    if (sName == "maskAP1") {
      staticAPMask1 = (byte)sVal.toInt();
      continue;
    }
    if (sName == "maskAP2") {
      staticAPMask2 = (byte)sVal.toInt();
      continue;
    }
    if (sName == "maskAP3") {
      staticAPMask3 = (byte)sVal.toInt();
      continue;
    }
    if (sName == "maskAP4") {
      staticAPMask4 = (byte)sVal.toInt();
      continue;
    }
    if (sName == "gwAP1") {
      staticAPGw1 = (byte)sVal.toInt();
      continue;
    }
    if (sName == "gwAP2") {
      staticAPGw2 = (byte)sVal.toInt();
      continue;
    }
    if (sName == "gwAP3") {
      staticAPGw3 = (byte)sVal.toInt();
      continue;
    }
    if (sName == "gwAP4") {
      staticAPGw4 = (byte)sVal.toInt();
      continue;
    }
    if (sName == "nameAP") {
      ssidAP = sVal;
      continue;
    }
    if (sName == "psAP") {
      passwordAP = sVal;
      continue;
    }
  }
  DBG_OUTPUT_PORT.println("");
  DBG_OUTPUT_PORT.println("set WIFI part3 ");
  DBG_OUTPUT_PORT.print(message);
  DBG_OUTPUT_PORT.println("");
  saveConfigAP();
  
  server.send(200, "text/json", "");
}
/*
void sServMQTT() {
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();

  root["staticAP_mask3"] = staticAPMask3;
  root["staticAP_mask4"] = staticAPMask4;
  root["staticAP_gw1"] = staticAPGw1;
  root["staticAP_gw2"] = staticAPGw2;
  root["staticAP_gw3"] = staticAPGw3;
  root["staticAP_gw4"] = staticAPGw4;

  String output;
  root.printTo(output);
  server.send(200, "text/json", output);
  saveConfig1();
  saveConfig2();
  saveConfig3();
  saveConfig4();

}*/
void sServMQTT() {
  String message = "";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " NAME:" + server.argName(i) + "\n VALUE:" + server.arg(i) + "\n";
    String sName =  server.argName(i);
    String sVal = server.arg(i);

    if (sName == "MQTT_Cl_Name") {
      MqttClName = sVal;
      continue;
    }
    if (sName == "MQTT_Server") {
      MqttServer = sVal;
      continue;
    }
    if (sName == "MQTT_Port") {
      MqttPort = sVal;
      continue;
    }
    if (sName == "MQTT_Login") {
      MqttLogin = sVal;
      continue;
    }

    if (sName == "MQTT_Paswd") {
      MqttPaswd = sVal;
      continue;
    }



  }
  DBG_OUTPUT_PORT.println("");
  DBG_OUTPUT_PORT.println("set MQTT part0 ");
  DBG_OUTPUT_PORT.print(message);
  DBG_OUTPUT_PORT.println("");

  server.send(200, "text/json", "");

  saveConfigServMQTT();
  
}



void g_io_MQTT() {
  int indx = 0;
  for (uint8_t i = 0; i < server.args(); i++) {

    String sName =  server.argName(i);
    String sVal = server.arg(i);

    if (sName == "io") {
      indx = get_i_set_mqtt(sVal);
      DBG_OUTPUT_PORT.println("");
      DBG_OUTPUT_PORT.println("get " + sVal);
      DBG_OUTPUT_PORT.print(indx);
      DBG_OUTPUT_PORT.println("");
      continue;
    }
  }
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();

  root["io"] = set_mqtt[indx].io;
  root["r"] = set_mqtt[indx].r;
  root["w"] = set_mqtt[indx].w;
  root["mqtt"] = set_mqtt[indx].mqtt;


  String output;
  root.printTo(output);
  server.send(200, "text/json", output);

}


void sMqtt() {
  String message = "";
  String io;
  String io_r;
  String io_w;
  String io_mqtt;

  for (uint8_t i = 0; i < server.args(); i++) {
    message += " NAME:" + server.argName(i) + "\n VALUE:" + server.arg(i) + "\n";
    String sName =  server.argName(i);
    String sVal = server.arg(i);

    if (sName == "io") {
      io = sVal;
      //      DBG_OUTPUT_PORT.println("io -> " +sVal );
      continue;
    }

    if (sName == "r") {
      io_r = sVal;
      //       DBG_OUTPUT_PORT.println("r -> " +sVal );
      continue;
    }
    if (sName == "w") {
      io_w = sVal;
      //       DBG_OUTPUT_PORT.println("w -> " +sVal );
      continue;
    }
    if (sName == "mqtt") {
      io_mqtt = sVal;
      //       DBG_OUTPUT_PORT.println("mqtt -> " +sVal );
      continue;
    }

  }
  int indx = get_i_set_mqtt(io);
  if (io_r == "true") {
    set_mqtt[indx].r = true;
    //    Serial.println("r=true");
  } else {
    set_mqtt[indx].r = false;
    //   Serial.println("r=false");
  }
  if (io_w == "true") {
    set_mqtt[indx].w = true;
    //Serial.println("w=true");
  } else {
    set_mqtt[indx].w = false;
    //     Serial.println("w=false");
  }
  set_mqtt[indx].mqtt = io_mqtt;

  DBG_OUTPUT_PORT.println("");
  DBG_OUTPUT_PORT.println("set io_mqtt ");
  DBG_OUTPUT_PORT.print(message);
  DBG_OUTPUT_PORT.println("");
  saveConfigMqttIO(io);
  server.send(200, "text/json", "");

  ;
}



void gSta() {
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["Mac"] = WiFi.macAddress();

  String output;
  root.printTo(output);
  server.send(200, "text/json", output);

}


