/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 
 
 */


var xmlHttp = createXmlHttpObject();

function onBodyLoad() {
    console.log("we are loaded!!");
   
    getWiFi1();
    getWiFi2();
    getWiFi3();
    getWiFi4();
    getWiFi5();
    

    get_io("io5");
    get_io("io4");
    get_io("io0");
    get_io("io2");
    get_io("io15");
    get_io("io9");
    get_io("io10");
    get_io("io13");
    get_io("io12");
    get_io("io14");
    get_io("io16");
    get_io("adc");

}
function createXmlHttpObject() {
    if (window.XMLHttpRequest) {
        xmlHttp = new XMLHttpRequest();
    } else {
        xmlHttp = new ActiveXObject('Microsoft.XMLHTTP');
    }
    return xmlHttp;
}
//		function getTime() {
//			xmlHttp.open("GET", "/gettime.json", false);
//			xmlHttp.send();
//			if (xmlHttp.status == 200) {
///				//alert(xmlHttp.responseText);
//				strJson = xmlHttp.responseText;
//			}
//			return JSON.parse(xmlHttp.responseText);
//		}
//		function settTime(submit) {
//			var param = "/stime?syear=" + val('syear') + "&smonth=" + val('smonth') + "&sday=" + val('sday') + "&shour=" + val('shour') + "&sminute=" + val('sminute') + "&ssecond=" + val('ssecond');
//			xmlHttp.open("GET", param, true);
//
//			xmlHttp.send(null);
//		}
/*function getWiFi1_() {
 
 xmlHttp.open("GET", "/gwifi1", false);
 xmlHttp.send(null);
 if (xmlHttp.status === 200) {
 //alert(xmlHttp.responseText);
 strJson = xmlHttp.responseText;
 }
 return JSON.parse(xmlHttp.responseText);
 }*/

function getWiFi1() {
    var requestW1 = createXmlHttpObject();

    function responceLoad() {
        if (requestW1.readyState === 4) {
            var status = requestW1.status;
            if (status === 200) {
                let jsn = JSON.parse(requestW1.responseText);
                var mard = document.getElementById('macadress');
                mard.value = jsn.Mac;
                document.getElementById('ssid').value = jsn.ssid;
                document.getElementById('password').value = jsn.password;
                if (jsn.tip_wifi === "AP") {
                    document.getElementById('tip_wifi_ap').checked = true;
                } else {
                    document.getElementById('tip_wifi_cli').checked = true;
                }
                if (jsn.tip_ip === "DCHP") {
                    document.getElementById('tip_ip_dchp').checked = true;
                } else {
                    document.getElementById('tip_ip_stat').checked = true;
                }
                document.getElementById('static_ip1').value = jsn.static_ip1;
                document.getElementById('static_ip2').value = jsn.static_ip2;
                document.getElementById('static_ip3').value = jsn.static_ip3;
                document.getElementById('static_ip4').value = jsn.static_ip4;

            } else {
                document.write("Ответ сервера " + request.statusText);
            }
        }
    }

    requestW1.open("GET", "/gwifi1",false);
    requestW1.onload = responceLoad;
    requestW1.send();
}

function getWiFi2() {
    /*
     xmlHttp.open("GET", "/gwifi2", false);
     xmlHttp.send(null);
     if (xmlHttp.status === 200) {
     //alert(xmlHttp.responseText);
     strJson = xmlHttp.responseText;
     }
     return JSON.parse(xmlHttp.responseText);
     $("#static_mask1").val(wifi.static_mask1);
     $("#static_mask2").val(wifi.static_mask2);
     $("#static_mask3").val(wifi.static_mask3);
     $("#static_mask4").val(wifi.static_mask4);
     
     $("#static_gw1").val(wifi.static_gw1);
     $("#static_gw2").val(wifi.static_gw2);
     $("#static_gw3").val(wifi.static_gw3);
     $("#static_gw4").val(wifi.static_gw4);*/
    var requestW2 = createXmlHttpObject();
    requestW2.open("GET", "/gwifi2",false);
    requestW2.onload = function () {
        if (requestW2.readyState === 4) {
            var status = requestW2.status;
            if (status === 200) {
                let jsn = JSON.parse(requestW2.responseText);
                var mard = document.getElementById('static_mask1');
                mard.value = jsn.static_mask1;
                document.getElementById('static_mask2').value = jsn.static_mask2;
                document.getElementById('static_mask3').value = jsn.static_mask3;
                document.getElementById('static_mask4').value = jsn.static_mask4;
                document.getElementById('static_gw1').value = jsn.static_gw1;
                document.getElementById('static_gw2').value = jsn.static_gw2;
                document.getElementById('static_gw3').value = jsn.static_gw3;
                document.getElementById('static_gw4').value = jsn.static_gw4;

            } else {
                document.write("Ответ сервера " + requestW2.statusText);
            }
        }
    };
    requestW2.send();


}
function getWiFi3() {
    /*  xmlHttp.open("GET", "/gwifi3", false);
     xmlHttp.send(null);
     if (xmlHttp.status === 200) {
     //alert(xmlHttp.responseText);
     strJson = xmlHttp.responseText;
     }
     return JSON.parse(xmlHttp.responseText);
     $("#ssidAP").val(wifi.ssidAP);
     $("#passwordAP").val(wifi.passwordAP);
     
     $("#staticAP_ip1").val(wifi.staticAP_ip1);
     $("#staticAP_ip2").val(wifi.staticAP_ip2);
     $("#staticAP_ip3").val(wifi.staticAP_ip3);
     $("#staticAP_ip4").val(wifi.staticAP_ip4);
     
     $("#staticAP_mask1").val(wifi.staticAP_mask1);
     $("#staticAP_mask2").val(wifi.staticAP_mask2);
     */
    var requestW3 = createXmlHttpObject();
    requestW3.open("GET", "/gwifi3",false);
    requestW3.onload = function () {
        if (requestW3.readyState === 4) {
            var status = requestW3.status;
            if (status === 200) {
                let jsn = JSON.parse(requestW3.responseText);
                var mard = document.getElementById('ssidAP');
                mard.value = jsn.ssidAP;
                document.getElementById('passwordAP').value = jsn.passwordAP;
                document.getElementById('staticAP_ip1').value = jsn.staticAP_ip1;
                document.getElementById('staticAP_ip2').value = jsn.staticAP_ip2;
                document.getElementById('staticAP_ip3').value = jsn.staticAP_ip3;
                document.getElementById('staticAP_ip4').value = jsn.staticAP_ip4;
                document.getElementById('staticAP_mask1').value = jsn.staticAP_mask1;
                document.getElementById('staticAP_mask2').value = jsn.staticAP_mask2;

            } else {
                document.write("Ответ сервера " + requestW3.statusText);
            }
        }
    };
    requestW3.send();
}
function getWiFi4() {

    var requestW4 = createXmlHttpObject();
    requestW4.open("GET", "/gwifi4",false);
    requestW4.onload = function () {
        if (requestW4.readyState === 4) {
            var status = requestW4.status;
            if (status === 200) {
                let jsn = JSON.parse(requestW4.responseText);
                var mard = document.getElementById('staticAP_mask3');
                mard.value = jsn.staticAP_mask3;
                document.getElementById('staticAP_mask4').value = jsn.staticAP_mask4;
                document.getElementById('staticAP_gw1').value = jsn.staticAP_gw1;
                document.getElementById('staticAP_gw2').value = jsn.staticAP_gw2;
                document.getElementById('staticAP_gw3').value = jsn.staticAP_gw3;
                document.getElementById('staticAP_gw4').value = jsn.staticAP_gw4;


            } else {
                document.write("Ответ сервера " + requestW4.statusText);
            }
        }
    };
    requestW4.send();
}

function getWiFi5() {

    var requestW5 = createXmlHttpObject();
    requestW5.open("GET", "/gwifi5",false);
    requestW5.onload = function () {
        if (requestW5.readyState === 4) {
            var status = requestW5.status;
            if (status === 200) {
                let jsn = JSON.parse(requestW5.responseText);
             
                document.getElementById('mqtt_cl_name').value = jsn.MQTT_Cl_Name;
                document.getElementById('mqtt_server').value = jsn.MQTT_Server;
                document.getElementById('mqtt_port').value = jsn.MQTT_Port;
                document.getElementById('mqtt_login').value = jsn.MQTT_Login;
                document.getElementById('mqtt_paswd').value = jsn.MQTT_Paswd;


            } else {
                document.write("Ответ сервера " + requestW5.statusText);
            }
        }
    };
    requestW5.send();
}

function showTime() {
    //   var times = getTime();
    //   $("#curTime").val(times.year + "." + times.month + "." + times.day + "  " + times.hour + ":" + times.minut + ":" + times.secund);
}
function setWiFi1() {
    var wifi = 0; //
    //   if ($("#tip_wifi_ap").prop("checked") === true) {
    //      wifi = 1;
    //  }
    if (document.getElementById('tip_wifi_ap').checked === true) {
        wifi = 1;
    }
    var dchp = 0;

    /*   if ($("#tip_ip_dchp").prop("checked") === true) {
     dchp = 1;
     }*/
    if (document.getElementById('tip_ip_dchp').checked === true) {
        dchp = 1;
    }
    let ssid = val('ssid');
    let ps = val('password');
    let par = `ap=${wifi}&name=${ssid}&ps=${ps}&dchp=${dchp}`;
    let requestw1 = new XMLHttpRequest();
    requestw1.open("GET", "/swifi1?" + par,false);

    requestw1.send();
    /* $.get("/swifi1",
     {
     ap: wifi,
     name: val('ssid'),
     ps: val('password'),
     dchp: dchp
     });*/

}
function setWiFi2() {
    /*  $.get("/swifi2",
     {
     ip1: val('static_ip1'),
     ip2: val('static_ip2'),
     ip3: val('static_ip3'),
     ip4: val('static_ip4'),
     mask1: val('static_mask1'),
     mask2: val('static_mask2'),
     mask3: val('static_mask3'),
     mask4: val('static_mask4'),
     gw1: val('static_gw1'),
     gw2: val('static_gw2'),
     gw3: val('static_gw3'),
     gw4: val('static_gw4')
     });*/
    let ip1 = val('static_ip1');
    let ip2 = val('static_ip2');
    let ip3 = val('static_ip3');
    let ip4 = val('static_ip4');
    let mask1 = val('static_mask1');
    let mask2 = val('static_mask2');
    let mask3 = val('static_mask3');
    let mask4 = val('static_mask4');
    let gw1 = val('static_gw1');
    let gw2 = val('static_gw2');
    let gw3 = val('static_gw3');
    let gw4 = val('static_gw4');

    let par = `ip1=${ip1}&ip2=${ip2}&ip3=${ip3}&ip4=${ip4}$mask1=${mask1}&mask2=${mask2}&`;
    let par1 = `mask3=${mask3}&mask4=${mask4}&gw1=${gw1}&gw2=${gw2}&gw3=${gw3}&gw4=${gw4}`;
    let request = new XMLHttpRequest();
    request.open("GET", "/swifi2?" + par + par1,false);
    request.send();
}
function setWiFi3() {
    let nameAP = val('ssidAP');
    let psAP = val('passwordAP');
    let ipAP1 = val('staticAP_ip1');
    let ipAP2 = val('staticAP_ip2');
    let ipAP3 = val('staticAP_ip3');
    let ipAP4 = val('staticAP_ip4');
    let maskAP1 = val('staticAP_mask1');
    let maskAP2 = val('staticAP_mask2');
    let maskAP3 = val('staticAP_mask3');
    let maskAP4 = val('staticAP_mask4');
    let gwAP1 = val('staticAP_gw1');
    let gwAP2 = val('staticAP_gw2');
    let gwAP3 = val('staticAP_gw3');
    let gwAP4 = val('staticAP_gw4');

    let par = `nameAP=${nameAP}&psAP=${psAP}&ipAP1=${ipAP1}&ipAP2=${ipAP2}&ipAP3=${ipAP3}&ipAP4=${ipAP4}&`;
    let par1 = `maskAP1=${maskAP1}&maskAP2=${maskAP2}&maskAP3=${maskAP3}&maskAP4=${maskAP4}&`;
    let par2 = `gwAP1=${gwAP1}&gwAP2=${gwAP2}&gwAP3=${gwAP3}&gwAP4=${gwAP4}`;

    let request = new XMLHttpRequest();
    request.open("GET", "/swifi3?" + par + par1 + par2,false);
    request.send();
}

function setWiFi4() {
    let mqtt_cl_name = val('mqtt_cl_name');
    let mqtt_server = val('mqtt_server');
    let mqtt_port = val('mqtt_port');
    let mqtt_login = val('mqtt_login');
    let MQTT_Paswd = val('mqtt_paswd');
    

    let par = `MQTT_Cl_Name=${mqtt_cl_name}&MQTT_Server=${mqtt_server}&`;
    let par1 = `MQTT_Port=${mqtt_port}&MQTT_Login=${mqtt_login}&MQTT_Paswd=${MQTT_Paswd}`;
   
    let request = new XMLHttpRequest();
    request.open("GET", "/swifi4?" + par + par1 ,false);
    request.send();
}

function settWiFi() {
    setWiFi1();
    setWiFi2();
    setWiFi3();
    setWiFi4();
    set_all_io();
}


//<!--setTime(printTime(), 1000); -->
/*
 $(document).ready(function () {
 //showTime();
 //	setInterval('showTime()', 1000);
 });
 */

function val(id) {
    var v = document.getElementById(id).value;
    return v;
}

function io_rw(obj) {
    var id = obj.id;
    var pin = id.slice(0, -2);
    if (id === pin + '_r') {
        var sosed = document.getElementById(pin + '_w');
    } else {
        var sosed = document.getElementById(pin + '_r');
    }
    if (obj.checked) {
        sosed.checked = false;
    }
    if (obj.checked || sosed.checked) {
        var edit_mqt = document.getElementById(pin + '_mqtt');
        edit_mqt.disabled = false;
    } else {
        var edit_mqt = document.getElementById(pin + '_mqtt');
        edit_mqt.disabled = true;

    }

}
function set_io(io) {
    let r;
    let w;
    let mqtt;
    r = document.getElementById(io + '_r').checked;
    w = document.getElementById(io + '_w').checked;
    mqtt = document.getElementById(io + '_mqtt').value;
    let par = `io=${io}&r=${r}&w=${w}&mqtt=${mqtt}`;
    let request = new XMLHttpRequest();
    request.open("GET", "/sio?" + par,false);
    request.send();
    /*  $.get("/sio",
     {
     io: io,
     r: r,
     w: w,
     mqtt: mqtt
     
     });*/

}
function set_all_io() {
    set_io("io5");
    set_io("io4");
    set_io("io0");
    set_io("io2");
    set_io("io15");
    set_io("io9");
    set_io("io10");
    set_io("io13");
    set_io("io12");
    set_io("io14");
    set_io("io16");
    set_io("adc");
}
function get_io(io) {
    var request = new XMLHttpRequest();

    function responceLoad() {
        if (request.readyState === 4) {
            var status = request.status;
            if (status === 200) {
                var jsn = JSON.parse(request.responseText);
                if (jsn.r) {
                    document.getElementById(jsn.io + '_r').checked = true;
                } else {
                    document.getElementById(jsn.io + '_r').checked = false;
                }
                if (jsn.w) {
                    document.getElementById(jsn.io + '_w').checked = true;
                } else {
                    document.getElementById(jsn.io + '_w').checked = false;
                }
                document.getElementById(jsn.io + '_mqtt').value = jsn.mqtt;
            } else {
                document.write("Ответ сервера " + request.statusText);
            }
        }
    }

    request.open("GET", "/gio?io=" + io,false);
    request.onload = responceLoad;
    request.send();
}