#include <WiFi.h>
#include <WiFiUdp.h>
#include <coap-simple.h>

/* CẤU HÌNH KẾT NỐI */
const char* WIFI_SSID = "CUN";      // Điền đúng tên Wi-Fi
const char* WIFI_PASS = "11092006";          // Điền đúng mật khẩu Wi-Fi

/* CẤU HÌNH COAP SERVER */
IPAddress coap_server_ip(192, 168, 1, 20);       // IP máy tính chạy server Node.js
const int coap_port = 5683;
const char* coap_resource = "sensor/temp";

/* CHU KỲ GỬI (5 GIÂY) */
const unsigned long SEND_INTERVAL = 5000;
unsigned long lastSend = 0;

WiFiUDP udp;
Coap coap(udp);

void setup_wifi() {
  Serial.print("Connecting WiFi");
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
  Serial.print("ESP IP: ");
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  
  coap.start();
  Serial.println("CoAP client started");
}

void loop() {
  if (millis() - lastSend >= SEND_INTERVAL) {
    lastSend = millis();
    
    String payload = "temp=30.5";

    // ========================================================
    // TEST 1: GỬI BẢN TIN NON (Non-confirmable)
    // ========================================================
    Serial.print("Sending CoAP NON POST to ");
    Serial.print(coap_resource);
    Serial.print(" payload: ");
    Serial.println(payload);

    coap.send(
      coap_server_ip,
      coap_port,
      coap_resource,
      COAP_NONCON,              // Đã đổi thành COAP_NONCON
      COAP_POST,
      NULL,                     // Token (để trống)
      0,                        // Token length = 0
      (uint8_t*)payload.c_str(),
      payload.length()
    );

   
  }
}